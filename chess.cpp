#include "chess.h"
#include "Piece.h"
#include "Board.h"
#include "ui_chess.h"

#include <QDebug>

Chess::Chess(QWidget *parent) : QMainWindow(parent), ui(new Ui::Chess) {
    ui->setupUi(this);

    init();
}

void Chess::init() {
    //Initialize the gui
    ui->status->setText("Score = 0");

    ui->tableWidget->setIconSize(QSize(70, 70));

    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setColumnCount(8);

    ui->tableWidget->horizontalHeader()->setFixedHeight(20);
    ui->tableWidget->verticalHeader()->setFixedWidth(20);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(int x = 0; x < 8; x++) {
        ui->tableWidget->setColumnWidth(x, 70);
        ui->tableWidget->setRowHeight(x, 70);

        ui->tableWidget->setHorizontalHeaderItem(x, new QTableWidgetItem(QString('a' + x)));

        for(int y = 0; y < 8; y++) {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setBackground((((y * 8) + y + x) % 2) ? Qt::white : Qt::gray);

            ui->tableWidget->setItem(y, x, item);
        }
    }

    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(cellSelected(int, int)));

    //continue the init...
    board = new Board();
    board->initboard();

    refresh();
}

void Chess::refresh() {
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            Piece* piece = board->getPiece(y,x);
            if(piece != NULL) {
                ui->tableWidget->item(y, x)->setIcon(QIcon(QString(":/Resources/" + QString::fromStdString(piece->getImageName()))));
            } else {
                ui->tableWidget->item(y, x)->setIcon(QIcon(":/Resources/Blank.GIF"));
            }
        }
    }
}

void Chess::cellSelected(int y, int x) {
    qDebug() << y << "  " << x;

    board->makeMove( y,x);
    ui->status->setText("");

    //update the GUI table
    refresh();

    /*if(board->isCheck(true)) {
        ui->status->setText("Check to White");
        if (board->isCheckMate(true)) {
            ui->status->setText("CheckMate to White");
        }
    }

    if(board->isCheck(false)) {
        ui->status->setText("Check to black");
        if(board->isCheckMate(false)) {
            ui->status->setText("CheckMate to Black");
        }
    }*/
}

Chess::~Chess() {
    delete ui;
}

void Chess::on_newgame_clicked() {
    board = new Board();
    board->initboard();

    refresh();
}
