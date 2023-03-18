#ifndef TABPRINCIPALE_H
#define TABPRINCIPALE_H
#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include "tableRya.h"
#include "graphprincipale.h"
#include "graficobar.h"
#include "graficoline.h"
#include "graficopie.h"
#include <QPushButton>
class TabPrincipale: public QTabWidget{
    Q_OBJECT
private:
    bool s;

public:
    TableRya* r;
    GraficoBar*b;
    GraficoLine*l;
    QChartView* v;
    GraficoPie*p;
    TabPrincipale(QWidget* parent = 0);
    ~TabPrincipale();
    void showBar();
    void showLine();
    void showPie();
    void addL(const QString&, const QString&, int);
    void addR();
    void addA();
    void deleteR(int) const;
    void Update() const;
    vector<rowViaggio *> getV() const;
    void AggiornaTable(const vector<const Viaggio *> vi) const;
    void resetTab();

};

#endif // TABPRINCIPALE_H
