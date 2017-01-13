#include <QApplication>

#include "lightmapwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LightMapWidget w;
    w.show();

    return a.exec();
}
