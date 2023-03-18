#ifndef GRAFICOLINE_H
#define GRAFICOLINE_H
#include <QObject>
#include <QtCharts/QLineSeries>
#include "mainwindow.h"
#include "graphprincipale.h"

class GraficoLine: public GraphPrincipale{
    QValueAxis *axisY;
    QValueAxis* axisX;
    QStringList mesi;
    static int min;
    static int max;
    vector<int> value;
public:
    GraficoLine(TableRya*, QWidget* =0);
    ~GraficoLine();
    QLineSeries* series;
    void Aggiorna(const vector<rowViaggio*>&) override;
    void AzzeraVett();
    void cancellaSerie();

};

#endif // GRAFICOLINE_H
