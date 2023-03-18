#include "model.h"

Model::Model(): vettore(new Vettore){}

Model::~Model(){
    delete vettore;
}

void Model::addRya(string cod,double km,unsigned int p,string par,string dest, QDate gma, int equi=0) const{
    CreateViaggio creator;
    try{
        ControllaCOD(cod);
        vettore->AggiungiNewViaggio(creator.createRyanair(cod,km,p,par,dest,gma,equi));
    }catch(const std::invalid_argument& e){
        throw e;
    }
}

void Model::addAir(string cod,double km, unsigned int p,string par, string dest, QDate gma,int n) const{
    CreateViaggio creator;
    try{
        ControllaCOD(cod);
        vettore->AggiungiNewViaggio(creator.createAirPartner(cod,km,p,par,dest,gma,n));
    }catch(const std::invalid_argument& e){
        throw e;
    }
}

void Model::addLoc(string c,string n, string i) const{
    CreateViaggio creator;
    vettore->AggiungiAirLoc(c,creator.createLocazione(n,i));
}

Viaggio* Model::getV(string c) const{
    return vettore->getViaggio(c);
}

void Model::DeleteViaggio(int i) const{
    vettore->DeleteViaggio(i);
}

void Model::DeleteLoc(string c, int i) const{
    vettore->DeleteAirLoc(c, i);
}

int Model::getVectorSize() const{
    return vettore->getSize();
}

vector<const Viaggio*> Model::getVector() const{
    return vettore->getVettore();
}

void Model::ControllaCOD(string c) const{
    try{
        vettore->ControllaCod(c);
    }catch(const std::invalid_argument& e){
        throw e;
    }
}

void Model::clearVettore() const{

    vettore->distruggiVettore(vettore->getVettore());
    vettore->clearV();

}

void Model::caricaDati(const Vettore* vR){
    if(vR){
        vettore = const_cast<Vettore*>(vR);
    }
}
