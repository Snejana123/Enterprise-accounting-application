#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QCoreApplication::setOrganizationName("Team 15 Group 9374");
    QCoreApplication::setApplicationName("course_work");
    QCoreApplication::setApplicationVersion("0.1");

    QCoreApplication::setAttribute(Qt::AA_NativeWindows);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(a);

    w.show();
    return a.exec();
}
