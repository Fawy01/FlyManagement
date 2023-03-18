#include "graficobar.h"

GraficoBar::GraficoBar(TableRya* t, QWidget*parent):GraphPrincipale(t,parent){
    mesi <<"Gennaio" <<"Febbraio" << "Marzo" << "Aprile" << "Maggio" <<"Giugno" <<"Luglio" << "Agosto" <<"Settembre" <<"Ottobre" <<"Novembre" << "Dicembre";
    serie = new QBarSeries();
    set0 = new QBarSet("Ryanair");
    set1 = new QBarSet("AirPartner");
    serie->append(set0);
    serie->append(set1);
    chart = new QChart();
    chart->addSeries(serie);
    chart->setTitleFont(QFont(0, 10, QFont::DemiBold));
    chart->setTitle("VIAGGI AL MESE");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    axisX = new QBarCategoryAxis();
    axisX->append(mesi);
    chart->addAxis(axisX, Qt::AlignBottom);
    serie->attachAxis(axisX);
    axisY = new QValueAxis();
    axisY->setRange(0,50);
    axisY->setTickCount(25);
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    serie->attachAxis(axisY);
    chart->legend()->setAlignment(Qt::AlignBottom);
    for(int i= 0; i<12; ++i){
      air.push_back(0);
    }
    for(int i= 0; i<12; ++i){
      rya.push_back(0);
    }
}

GraficoBar::~GraficoBar(){
    delete chart;
}


void GraficoBar::Aggiorna(const vector<rowViaggio*>& v){
        int p=0;
        int n=0;
        AzzeraVett();
        set0->remove(0,11);
        set1->remove(0,11);
        for(vector<rowViaggio*>::const_iterator cit = v.begin(); cit!= v.end(); ++cit){
            if((*cit)->getTipo() == 1){
                p = ((*cit)->getData()->date().month())-1;
                n = rya.at(p) +1;
                rya.erase(rya.begin()+p);
                rya.insert(rya.begin() +p, n);
            }else{
                p = ((*cit)->getData()->date().month())-1;
                n = air.at(p) +1;
                air.erase(air.begin()+p);
                air.insert(air.begin() +p, n);
            }
        }
        for(int i=0; i<12; ++i){
            set0->insert(i, rya.at(i));
            set1->insert(i, air.at(i));
        }
}


void GraficoBar::AzzeraVett(){
    air.clear();
    rya.clear();
    for(int i= 0; i<12; ++i){
      air.push_back(0);
    }
    for(int i= 0; i<12; ++i){
      rya.push_back(0);
    }
}
