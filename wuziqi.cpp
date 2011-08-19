#include "wuziqi.h"
#include <stdio.h>
#include <stdlib.h>

int WorB[16][16];

CHESS *cur = NULL;
CHESS *pre = NULL;

//bool restart = false;

Wuziqi::Wuziqi(QWidget *parent):QWidget(parent)
{
	this->setFixedSize(480,256);
	//this->setAttribute(Qt::WA_PaintOutsidePaintEvent);
	QPushButton *restart = new QPushButton(this);
	restart->setGeometry(QRect(280,50,60,30));
	restart->setText("Restart");
	QObject::connect(restart, SIGNAL(clicked()), this, SLOT(Restart()));
        QPushButton *retract = new QPushButton(this);
        retract->setGeometry(QRect(280,100,60,30));
        retract->setText("Retract");
        QObject::connect(retract, SIGNAL(clicked()), this, SLOT(Retract()));
        for(int i=0;i<16;i++)
                for(int j=0;j<16;j++)
                        WorB[i][j] = 2;
	printf("set Fixed Size!\n");
}

void Wuziqi::Restart()
{	printf("REPAINT!\n");
        CHESS *node;
        node = pre;
        while(node!=NULL){
                pre = pre->last;
                free(node);
                node = pre;
        }
        for(int i=0;i<16;i++)
                for(int j=0;j<16;j++)
                        WorB[i][j] = 2;
	update();
}	

void Wuziqi::Retract()
{
	printf("RETRACT!\n");
	CHESS *node;
	node = pre;
	if(pre!=NULL)
	{
		pre = pre->last;
		WorB[node->x][node->y] = 2;
		free(node);
	}
	update();
}

void Wuziqi::paintEvent(QPaintEvent *event)
{	printf("paintEvent!\n");
        QPainter painter(this);
        drawChessBoard(&painter);
	drawchesses(&painter);
}

void Wuziqi::drawchess(CHESS *abc, QPainter *painter,int WhiteOrBlack)//draw the chess
{
	printf("drawchess!\n");
        painter->setBrush(QBrush(WhiteOrBlack ? Qt::white : Qt::black,Qt::SolidPattern));
        painter->setPen(Qt::black);
        painter->drawEllipse((abc->x)*16 - chessWidth / 2, (abc->y)*16 - chessWidth / 2, chessWidth, chessWidth);//draw the ellipse
}

void Wuziqi::drawchesses(QPainter *painter)
{
	CHESS *node;
	node = pre;
	printf("drawchesses!\n");
	while(node!=NULL)
	{
		drawchess(node,painter,node->color);
		node = node->last;
	}
	//cur = NULL;
}

void Wuziqi::drawChessBoard(QPainter *painter)//画棋盘
{
	//QPainter painter(this);
        painter->setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter->drawRect(0, 0, 256, 256);
        painter->setPen(QPen(Qt::black, 1));//Set the painter "BLACK"
        painter->setBrush(QBrush(Qt::black,Qt::SolidPattern));
        painter->drawEllipse(16*4-3, 16*4-3, 6, 6);
        painter->drawEllipse(240-16*3-3, 240-16*3-3, 6, 6);
        painter->drawEllipse(16*4-3, 240-16*3-3, 6, 6);
        painter->drawEllipse(240-16*3-3, 16*4-3, 6, 6);
        painter->drawEllipse(16*8-3, 16*8-3, 6, 6);

        for(int i = 1; i < 16; i++)
        {
                painter->setPen(QPen(Qt::black,1));//Set the painter "BLACK"
                painter->drawLine(16,cubeWidth * (i), 240, cubeWidth * (i));//draw HORIZONTAL line
                painter->drawLine(cubeWidth * (i), 16, cubeWidth * (i), 240);//draw VERTICAL line
        }
}

void Wuziqi::mousePressEvent(QMouseEvent *event)//event of touching the screen
{
	printf("touching the screen\n");
        QPoint point = event->pos();
        int x = cubeWidth * qRound(float(point.x()) / cubeWidth);
        int y = cubeWidth * qRound(float(point.y()) / cubeWidth);
	if(x <= 240 && x >= 16 && y<=240 && y>= 16){
	        point.setX(x);
        	point.setY(y);
		getchess(point);
		update();
		if(checkWin(cur)){
		        QMessageBox::about(this, "Result", cur->color ? "White win.     ^__^" : "Black win.     ^__^");
			Restart();
		}
	}
}

bool Wuziqi::checkWin(CHESS *node)
{
	int color = node->color;
	int a = node->x;
	int b = node->y;
	int count;
	int c1, c2, c3, c4;
	c1 = c2 = c3 = c4 = 0;
	count = 1;
	while(b-count>=1){
		if(WorB[a][b-count]==color)
		count++;
		else break;
	}
	c1 = count;
	count = 1;
	while(b+count<=15){
                if(WorB[a][b+count]==color)
                count++;
                else break;
	}//VERTICAL
	c1 = c1 + count;
	count = 1;
        while(a-count>=1){
                if(WorB[a-count][b]==color)
                count++;
                else break;
        }
	c2 = count;
	count = 1;
        while(a+count<=15){
                if(WorB[a+count][b]==color)
                count++;
                else break;
        }//HORIZONCIAL
	c2 = c2 + count;
	count = 1;
        while((a-count>=1)&&(b-count>=1)){
                if(WorB[a-count][b-count]==color)
                count++;
                else break;
        }
	c3 = count;
	count = 1;
        while((a+count<=15)&&(b+count<=15)){
                if(WorB[a+count][b+count]==color)
                count++;
                else break;
        }//S1
	c3 = c3 + count;
	count = 1;
        while((a-count>=1)&&(b+count<=15)){
                if(WorB[a-count][b+count]==color)
                count++;
                else break;
        }
        c4 = count;
        count = 1;
        while((a+count<=15)&&(b-count>=1)){
                if(WorB[a+count][b-count]==color)
                count++;
                else break;
        }//S2
	c4 = c4 + count;
	count = 1;
        if(c1>=6 || c2>=6 || c3>=6 || c4>=6) return true;
        else return false;

}
void Wuziqi::getchess(QPoint point)
{
	printf("getchess!\n");
	int i=0;
	CHESS *node;
	node = pre;
	if(pre==NULL)
	{
		cur = (CHESS *)malloc(sizeof(CHESS));
		if(cur!=NULL){
			cur->x = point.x()/16;
			cur->y = point.y()/16;
			cur->next = NULL;
			cur->last = NULL;
			cur->color = 0;
			pre = cur;
			WorB[cur->x][cur->y] = cur->color;
		}
	}
	else
	{
		while(node!=NULL)
		{                
			if(node->x==(point.x()/16) && node->y==(point.y()/16))
                	i++;
                	node = node->last;
		}
		if(i==0){
			cur = (CHESS *)malloc(sizeof(CHESS));
			if(cur!=NULL){
				cur->x = point.x()/16;
				cur->y = point.y()/16;
				cur->next = NULL;
				cur->last = pre;
				if(pre->color!=0) cur->color = 0;
				else cur->color = 1;
				pre->next = cur;
				pre = cur;
				WorB[cur->x][cur->y] = cur->color;
			}
		}
	}	
}

