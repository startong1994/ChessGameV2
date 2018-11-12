#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>
#include "Board.h"

namespace Ui {
    class Chess;
}

class Chess : public QMainWindow {
    Q_OBJECT

    public:
        explicit Chess(QWidget *parent = nullptr);
        ~Chess();

        void init();
        void refresh();

    public slots:
        void cellSelected(int y, int x);

private slots:
        void on_newgame_clicked();
private:
        Ui::Chess *ui;
        Board* board;
        Piece *Selected = NULL;
};

#endif // CHESS_H
