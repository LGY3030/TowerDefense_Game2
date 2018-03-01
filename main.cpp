#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        MainWindow w;
        QDesktopWidget wid;
        int screenW = 1500;
        int screenH = 1000;
        w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
        w.setWindowTitle("New Clash Royale");
        w.setWindowIcon(QIcon("../img/icon.png"));
        w.show();
        return a.exec();
}
