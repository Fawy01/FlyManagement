#include "graficoline.h"

int GraficoLine::min = 2000;
int GraficoLine::max = 2030;
GraficoLine::GraficoLine(TableRya * t, QWidget * parent): GraphPrincipale(t,parent){
    chart = new QChart();
    chart->setTitleFont(QFont(0, 10, QFont::DemiBold));
    chart->setTitle("VIAGGI PER ANNO");
    chart->legend()->setVisible(false);
    axisX = new QValueAxis();
    axisX->setRange(min,max);
    axisX->setTickCount(30);
    axisX->setLabelFormat("%d");
    chart->addAxis(axisX, Qt::AlignBottom);
    axisY = new QValueAxis();
    axisY->setRange(0,50);
    axisY->setTickCount(25);
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series = new QLineSeries(chart);
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    for(int i=0; i<31; ++i){
        value.push_back(0);
    }

}

GraficoLine::~GraficoLine(){
    delete chart;
}


void GraficoLine::Aggiorna(const vector<rowViaggio*>& v){
    cancellaSerie();
    AzzeraVett();
    int n=0;
    for(vector<rowViaggio*>::const_iterator cit = v.begin(); cit!= v.end(); ++cit){
        n= value.at((*cit)->getData()->date().year()-min)+1;
        value.erase(value.begin()+((*cit)->getData()->date().year()-min));
        value.insert(value.begin()+((*cit)->getData()->date().year()-min), n);
    }
    for(unsigned int i=0; i<value.size(); ++i){
        if(value.at(i)!=0){
            series->insert(i,QPointF(min+i,value.at(i)));
        }
    }
}


void GraficoLine::AzzeraVett(){
    value.clear();
    for(int i= 0; i<31; ++i){
      value.push_back(0);
    }

}

void GraficoLine::cancellaSerie(){
    series->clear();
}
