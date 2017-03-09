#include "widget.h"
#include "ui_widget.h"
#include <QtGui>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
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
