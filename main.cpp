#include "wuziqi.h"
#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QPushButton button("Restart");
	//button.show();
	//QObject::connect(&button,SIGNAL(clicked()),&a,SLOT(painterEvent()));
	Wuziqi w;
	w.show();
	return a.exec();
}
