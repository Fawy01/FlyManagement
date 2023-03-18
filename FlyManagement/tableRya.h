#ifndef TABLERYA_H
#define TABLERYA_H
#include <QWidget>
#include <QTableWidget>
#include "viaggio.h"
#include "ryanair.h"
#include "vettore.h"
#include "rowviaggio.h"
#include <QLabel>
#include <QLineEdit>
#include <QHeaderView>
#include <QPushButton>
#include <QMessageBox>
class TableRya: public QTableWidget{
    Q_OBJECT
public:
    TableRya(QWidget *parent = 0);
    ~TableRya();
    vector<rowViaggio*> v;
    QPushButton* addLoc;
    void deleteRow(int);
    void addRow(bool);
    void addLocazione(const QString& , const QString& , int );
    int getSizeTable() const;
    vector<rowViaggio*> getV() const;

    void caricaTable(const vector<const Viaggio *> &vM);
    void resetTable();

};

#endif // TABLE_H
