#ifndef MOVE_H
#define MOVE_H

class Move
{
private:
	int r1,c1,r2,c2;
	bool side;
public:
	/**
	constructor :
	arguments are the row and column of the source and destination block ,
	last argument specify the side(true - white, false - black) 	*/
	Move(int r3, int c3, int r4, int c4, bool s)
	{
		r1 = r3;
		c1 = c3;
		r2 = r4;
		c2 = c4;
		side = s;
    }

	Move();
	~Move();
};


#endif
