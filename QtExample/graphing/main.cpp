#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
