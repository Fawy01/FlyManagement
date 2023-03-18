#ifndef GRAPHPRINCIPALE_H
#define GRAPHPRINCIPALE_H
#include "tableRya.h"
#include <QHBoxLayout>
#include "QtCharts/QChartGlobal"
#include <QStringList>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class GraphPrincipale: public QWidget{
    Q_OBJECT
public:
    GraphPrincipale(TableRya*,QWidget* =0);
    ~GraphPrincipale();
    TableRya*t;
    QChart*chart;
    virtual void Aggiorna(const vector<rowViaggio*>&) =0;

};

#endif // GRAPHPRINCIPALE_H
