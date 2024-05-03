#include "InputCityDialog.h"

InputCityDialog::InputCityDialog(QWidget* parent): QDialog(parent){
    setWindowTitle("Input city");
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowOpacity(0.8);
    setStyleSheet("QDialog { "
                  "background: qlineargradient(x1:0, y1:0, "
                  "x2:1, y2:1, stop:0 #8DB9EB, stop:1 #3B517D); }");
    resize(300, 100);

    confirmBtn = new QPushButton(this);
    confirmBtn->setText("Confirm");
    confirmBtn->setStyleSheet("background-color: #E5E5E5; "
                              "color: #FFFFFF; "
                              "border-radius: 2px;");
    confirmBtn->setFixedSize(50, 20);
    confirmBtn->move(250, 80);

    closeDialog = new TextClick(this);
    closeDialog->setText("x");
    closeDialog->setAlignment(Qt::AlignCenter);
    closeDialog->setFont(QFont("Arial bold", 20));
    closeDialog->setStyleSheet("color: #E5E5E5");
    closeDialog->move(280, 0);

    inputCityField = new QLineEdit(this);
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(
                QRegularExpression("^[a-zA-Z\\-]*$"), inputCityField);
    inputCityField->setFont(QFont("Arial", 12));
    inputCityField->setStyleSheet("background-color: #CFE3F0; "
                                  "color: #000000; "
                                  "border-radius: 1px;");
    inputCityField->setValidator(validator);
    inputCityField->setFixedSize(280, 25);
    inputCityField->move(10, 40);

    connect(closeDialog, &TextClick::textClicked, this, [this]{
        close();
    });

    connect(confirmBtn, &QPushButton::clicked, this, [this]{
        close();
        emit confirmCity(inputCityField->text());
    });
}
