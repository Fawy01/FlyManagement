#ifndef GRAFICOPIE_H
#define GRAFICOPIE_H
#include <QObject>
#include "mainwindow.h"
#include "graphprincipale.h"
#include <QPieSeries>
#include <QPieSlice>

class GraficoPie: public GraphPrincipale{
public:
    GraficoPie(TableRya*, QWidget* =0);
    ~GraficoPie();
    QPieSeries*series;
    QPieSlice* slice;
    void Aggiorna(const vector<rowViaggio*>&) override;
    void cancellaSerie();
    void defaultSerie();
};

#endif // GRAFICOPIE_H
