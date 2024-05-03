#include <QApplication>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVector>

#include "GradientWidget.h"
#include "NetworkMananger.h"
#include "QueryDataStruct.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GradientWidget* widget = new GradientWidget();
    widget->resize(400, 450);
    widget->show();

    return app.exec();
}
