#include "rowviaggio.h"

rowViaggio::rowViaggio(bool i,QWidget* parent): QWidget(parent), t(i){
    cod = new QLineEdit();
    cod->setText("");
    cod->setMaximumWidth(150);
    km = new QLineEdit();
    km->setText("");
    km->setMaximumWidth(150);
    npass = new QLineEdit();
    npass->setText("");
    npass->setMaximumWidth(150);
    nequi = new QLineEdit();
    nequi->setText("");
    nequi->setMaximumWidth(150);
    partenza = new QLineEdit();
    partenza->setText("");
    partenza->setMaximumWidth(150);
    destinazione = new QLineEdit();
    destinazione->setText("");
    destinazione->setMaximumWidth(150);
    data = new QDateEdit();
    data->setMinimumDate(QDate(2000,01,01));
    data->setMaximumDate(QDate(2030,12,31));
    data->setMaximumWidth(150);
    numLoca = new QSpinBox();
    numLoca->setStyleSheet("background-color: lightgray");
    numLoca->setValue(0);
    numLoca->setMaximumWidth(150);
    nameLoca = new QComboBox();
    indLoca = new QComboBox();
    nameLoca->setStyleSheet("background-color: lightgray");
    indLoca->setStyleSheet("background-color: lightgray");
    nameLoca->setCurrentIndex(0);
    nameLoca->setMaximumWidth(150);
    indLoca->setCurrentIndex(0);
    indLoca->setMaximumWidth(150);
}

rowViaggio::~rowViaggio(){}
void rowViaggio::setTipo(bool i){
    t = i;
}
QLineEdit *rowViaggio::getCod() const
{
    return cod;
}

QLineEdit *rowViaggio::getKm() const
{
    return km;
}

QLineEdit *rowViaggio::getPass() const
{
    return npass;
}

QLineEdit *rowViaggio::getEqui() const
{
    return nequi;
}

QLineEdit *rowViaggio::getPartenza() const
{
    return partenza;
}

QLineEdit* rowViaggio::getDestinazione() const{
    return destinazione;
}

QDateEdit *rowViaggio::getData() const
{
    return data;
}

QSpinBox *rowViaggio::getnumLoc() const
{
    return numLoca;
}

void rowViaggio::addLoc(const QString& n, const QString&i){
    nameLoca->addItem(n);
    indLoca->addItem(i);
}

QComboBox* rowViaggio::getNameLoca() const{
    return nameLoca;
}
QComboBox* rowViaggio::getIndLoca() const{
    return indLoca;
}

bool rowViaggio::getTipo() const{
    return t;
}


QLineEdit* rowViaggio::setCod(const QString & c)
{
    cod->setText(c);
    return cod;
}

QLineEdit* rowViaggio::setKm(const QString & n)
{
    km->setText(n);
    return km;
}

QLineEdit* rowViaggio::setPass(const QString & p)
{
    npass->setText(p);
    return npass;
}

QLineEdit* rowViaggio::setEqui(const QString & e)
{
    nequi->setText(e);
    return nequi;
}

QLineEdit* rowViaggio::setPartenza(const QString & par)
{
    partenza->setText(par);
    return partenza;
}

QLineEdit* rowViaggio::setDestinazione(const QString & dest) {
    destinazione->setText(dest);
    return destinazione;
}

QDateEdit* rowViaggio::setData(const QDate& date)
{
    data->setDate(date);
    return data;
}

QSpinBox* rowViaggio::setnumLoc(int num)
{
    numLoca->setValue(num);
    return numLoca;
}
