#include "controller.h"
#include "mainwindow.h"
#include "model.h"

Controller::Controller(QObject *parent) :QObject(parent){
    IO = new ReadWriteXML();
}

Controller::~Controller(){
    delete IO;
}


void Controller::setView(MainWindow * v)
{
    view = v;
}

void Controller::setModel(Model * mo)
{
    m = mo;
}

void Controller::salva(const vector<rowViaggio *>& v){
    string cod;
    double km;
    unsigned int pass;
    string par;
    string dest;
    QDate data;
    int equi;
    int nloca;
    string nome;
    string indirizzo;
    m->clearVettore();
    try{
        for(vector<rowViaggio*>::const_iterator cit = v.begin(); cit!= v.end(); ++cit){
            if((*cit)->getTipo() == 1){
                cod = (*cit)->getCod()->text().toStdString();
                km = (*cit)->getKm()->text().toInt();
                pass = (*cit)->getPass()->text().toInt();
                par = (*cit)->getPartenza()->text().toStdString();
                dest = (*cit)->getDestinazione()->text().toStdString();
                data = (*cit)->getData()->date();
                equi = (*cit)->getEqui()->text().toInt();
                m->addRya(cod,km,pass,par,dest,data,equi);
            }else{
                cod = (*cit)->getCod()->text().toStdString();
                km = (*cit)->getKm()->text().toInt();
                pass = (*cit)->getPass()->text().toInt();
                par = (*cit)->getPartenza()->text().toStdString();
                dest = (*cit)->getDestinazione()->text().toStdString();
                data = (*cit)->getData()->date();
                nloca = (*cit)->getnumLoc()->text().toInt();
                m->addAir(cod,km,pass,par,dest,data,nloca);
                for(int i=0; i<nloca; ++i){
                    nome = (*cit)->getNameLoca()->itemText(i).toStdString();
                    indirizzo = (*cit)->getIndLoca()->itemText(i).toStdString();
                    m->addLoc(cod, nome,indirizzo);
                }
            }
        }
        IO->Save(m->getVector());
    }catch(const std::invalid_argument& e){
        QMessageBox::warning(view,tr("Attenzione!"), tr("Codice Viaggio duplicato"));
    }


}

void Controller::carica(const QString & f){
    m->caricaDati(IO->read(f));
    view->AggiornaTable(m->getVector());
}

void Controller::newFile(const vector<rowViaggio *>& v){
        salva(v);
        m->clearVettore();
        IO->resetFileName();

}

void Controller::saveName(const vector<rowViaggio *>& v){
    if(!IO->SaveWithName()){
        salva(v);
    }
}
