#ifndef GRAFICOBAR_H
#define GRAFICOBAR_H
#include <QObject>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include "mainwindow.h"
#include "graphprincipale.h"

class GraficoBar: public GraphPrincipale {
    QBarCategoryAxis* axisX;
    QValueAxis *axisY;
public:
    GraficoBar(TableRya*, QWidget* =0);
    ~GraficoBar();
    vector<int> air;
    vector<int> rya;
    QBarSet *set0;
    QBarSet *set1;
    QBarSeries* serie;
    QStringList mesi;
    void Aggiorna(const vector<rowViaggio*>&) override;
    void AzzeraVett();
};

#endif // GRAFICOBAR_H

