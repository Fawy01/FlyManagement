#include "tabprincipale.h"

TabPrincipale::TabPrincipale(QWidget* parent): QTabWidget(parent){
    v= new QChartView();
    v->setRenderHint(QPainter::Antialiasing, true);
    r = new TableRya(this);
    b= new GraficoBar(r);
    l = new GraficoLine(r);
    p= new GraficoPie(r);
    v->setChart(l->chart);
    setStyleSheet("font : 0 bold 14px;");
    addTab(r, "VIAGGI");
    addTab(v, "STATISTICHE");

}

TabPrincipale::~TabPrincipale(){
    delete l;
    delete r;
    delete p;
    v->deleteLater();
}
void TabPrincipale::addL(const QString& n, const QString& i, int row)
{
    r->addLocazione(n,i,row);
}

void TabPrincipale::showBar(){
    setCurrentIndex(1);
    v->setChart(b->chart);
}

void TabPrincipale::showLine()
{
    setCurrentIndex(1);
    v->setChart(l->chart);
}

void TabPrincipale::showPie(){
    setCurrentIndex(1);
    v->setChart(p->chart);
}

void TabPrincipale::addR()
{
    s = true;
    r->addRow(s);
}
void TabPrincipale::addA()
{
    s = false;
    r->addRow(s);
}

void TabPrincipale::deleteR(int i) const{
    r->deleteRow(i);
}

void TabPrincipale::Update() const{
    b->Aggiorna(r->getV());
    l->Aggiorna(r->getV());
    p->Aggiorna(r->getV());
}

vector<rowViaggio *> TabPrincipale::getV() const{
   return r->getV();
}

void TabPrincipale::AggiornaTable(const vector<const Viaggio*> vi)const{
    r->caricaTable(vi);
}

void TabPrincipale::resetTab(){
    r->resetTable();
    p->defaultSerie();
}
