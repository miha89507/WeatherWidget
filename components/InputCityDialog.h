#ifndef INPUTCITYDIALOG_H
#define INPUTCITYDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "components/TextClick.h"

class InputCityDialog: public QDialog {
    Q_OBJECT
public:
    InputCityDialog(QWidget* parent=nullptr);

signals:
    void confirmCity(QString inputCity);

private:
    TextClick*      closeDialog;
    QLineEdit*      inputCityField;
    QPushButton*    confirmBtn;
};

#endif // INPUTCITYDIALOG_H
