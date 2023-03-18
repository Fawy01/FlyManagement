#ifndef ROWVIAGGIO_H
#define ROWVIAGGIO_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include "airpartner.h"
#include "ryanair.h"
#include <QCalendarWidget>
#include <QDateEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QFormLayout>
class rowViaggio: public QWidget{
    Q_OBJECT
private:
    bool t;
    QLineEdit* cod;
    QLineEdit* km;
    QLineEdit* npass;
    QLineEdit* nequi;
    QLineEdit* partenza;
    QLineEdit* destinazione;
    QDateEdit* data;
    QSpinBox* numLoca;
    QComboBox*nameLoca;
    QComboBox*indLoca;
    int posLoca;
public:
    rowViaggio(bool = 1,QWidget* parent = 0);
    ~rowViaggio();
    QLineEdit* getCod() const;
    QLineEdit* getKm() const;
    QLineEdit* getPass() const;
    QLineEdit* getEqui() const;
    QLineEdit* getPartenza() const;
    QLineEdit* getDestinazione() const;
    QDateEdit* getData() const;
    QSpinBox* getnumLoc() const;
    void addLoc(const QString&, const QString&);
    QComboBox* getNameLoca() const;
    QComboBox* getIndLoca() const;
    void setTipo(bool);
    bool getTipo() const;
    QLineEdit* setCod(const QString &);
    QLineEdit* setKm(const QString &);
    QLineEdit* setPass(const QString &);
    QLineEdit* setEqui(const QString &);
    QLineEdit* setPartenza(const QString &);
    QLineEdit* setDestinazione(const QString &);
    QDateEdit* setData(const QDate &);
    QSpinBox* setnumLoc(int);
};

#endif // ROWVIAGGIO_H
