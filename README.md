# Data Analysis by using Qt

This C++ program reads a .csv file and display the data to the user in the form of a graph.

1. Open, compile and run this project in Qt. The project file to open is: `QtExample\graphing\graphing.pro`
2. The input .csv file is: `QtExample\build-graphing-Desktop_Qt_5_2_0_MinGW_32bit-Debug\patients.csv`. The input .csv file should be in this type of format:

```csv
annie,80,160
brian,100,175
lola,135,170
guy,90,180
```
3. There will be a GUI output, displaying the data as a graph

## Here is the important part of the code: </label>						

```cpp
#include "widget.h"
#include "ui_widget.h"
#include &lt;QtGui&gt;
#include &lt;QPainter&gt;

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui-&gt;setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::paintEvent(QPaintEvent *event){

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::black);
	painter.drawLine(50, 50, 50, 400);
	painter.drawLine(50, 400, 400, 400);

	QFile in("patients.csv");
	in.open(QFile::ReadOnly);
	QTextStream inStream(&in);
	while(!inStream.atEnd()){
		QString line = inStream.readLine(40);
		QStringList token = line.split(",");

		painter.drawEllipse(token.at(1).toInt()+52, token.at(2).toInt()+52, 4, 4);
		painter.drawText(token.at(1).toInt()+52, token.at(2).toInt()+52, token.at(0));

	}
	in.close();
}				
```
