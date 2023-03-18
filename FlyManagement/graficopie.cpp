#include "graficopie.h"

GraficoPie::GraficoPie(TableRya* t, QWidget* parent): GraphPrincipale(t,parent){
    chart = new QChart();
    series = new QPieSeries(chart);
    defaultSerie();
    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitleFont(QFont(0, 10, QFont::DemiBold));
    chart->setTitle("PASSEGGERI PER VIAGGIO");
    slice->setColor(QColor(1, 108, 225,255));

}

GraficoPie::~GraficoPie(){ delete chart;}


void GraficoPie::Aggiorna(const vector<rowViaggio *> & v){
    cancellaSerie();
    for(vector<rowViaggio*>::const_iterator cit = v.begin(); cit!= v.end(); ++cit){
        if((*cit)->getTipo() == 1){
            if((*cit)->getPass()->text().toInt()+(*cit)->getEqui()->text().toInt()!=0){
                series->append((*cit)->getCod()->text(), ((*cit)->getPass()->text().toInt()+(*cit)->getEqui()->text().toInt()));

            }
        }else{
            if((*cit)->getPass()->text().toInt()!=0){
                series->append((*cit)->getCod()->text(), ((*cit)->getPass()->text().toInt()));
            }
        }
    }
}


void GraficoPie::cancellaSerie(){
    series->clear();
}

void GraficoPie::defaultSerie(){
    if(series->isEmpty()){
        slice = series->append("WELCOME", 1);
    }
}
