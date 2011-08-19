#ifndef WUZIQI_H
#define WUZIQI_H

#include <QtGui>

struct CHESS{
	struct CHESS *next;
	struct CHESS *last;
	int x;
	int y;
	int color;
};

class Wuziqi : public QWidget
{
	Q_OBJECT

public:
	Wuziqi(QWidget *parent = 0);
	//~Wuziqi();
	void drawChessBoard(QPainter *painter);
	void paintEvent(QPaintEvent *event);
	//void restart();
	void drawchess(CHESS *abc, QPainter *painter, int WorB);
	void drawchesses(QPainter *painter);
	//void drawEggFrame(QPainter *painter);
	void getchess(QPoint point);

	void mousePressEvent(QMouseEvent *event);
	bool checkWin(CHESS *node);
private slots:
	void Restart();
	void Retract();
private:
	//QList<QPoint> eggs;
};
const int cubePerLine = 14;
const int cubeWidth = 16;//30;
const int chessWidth = 16;//24;
const int wuziqiWidth = cubePerLine * cubeWidth; 
const int halfCubeWidth = 16;//2 * cubeWidth / 3;
const int frameWidth = 16;//cubeWidth / 6;


#endif // WUZIQI_H
