#include "vettore.h"

Vettore::Vettore(){}

Vettore::~Vettore(){
    for(auto sl : v)delete sl;
}
void Vettore::AggiungiNewViaggio(const Viaggio* vi){
    v.push_back(vi);
}

Viaggio* Vettore::getViaggio(string cod){
    AirPartner* air;
    Ryanair* rya;
    for(vector<const Viaggio*>::const_iterator cit = v.begin(); cit != v.end(); ++cit){
        Viaggio* vi = const_cast<Viaggio*>(*cit);
        if(dynamic_cast<AirPartner*>(vi)){
            air = static_cast<AirPartner*>(vi);
            if(cod == air->getCod())
                return air;
        }
        if(dynamic_cast<Ryanair*>(vi)){
            rya = static_cast<Ryanair*>(vi);
            if(cod == rya->getCod())
                return rya;
        }
    }
    return 0;
}

void Vettore::AggiungiAirLoc(string c, const Locazione* v){
    Viaggio* vi = getViaggio(c);
    AirPartner* air;
    if(dynamic_cast<AirPartner*>(vi)){
        air = static_cast<AirPartner*>(vi);
        air->AggiungiTappa(*v);
    }
}

void Vettore::DeleteAirLoc(string c, int i){
    Viaggio* vi = getViaggio(c);
    AirPartner* air;
    if(dynamic_cast<AirPartner*>(vi)){
        air = static_cast<AirPartner*>(vi);
        air->DeleteLocazione(i);
    }else{}

}


void Vettore::DeleteViaggio(int i){
    vector<const Viaggio*>::const_iterator cit = v.begin()+i;
        if(*cit)
            delete (*cit);
        v.erase(cit);
}

void Vettore::ControllaCod(string c) const{
    for(vector<const Viaggio*>::const_iterator cit = v.begin(); cit != v.end(); ++cit){
        if(c == (*cit)->getCod()){
            throw std::invalid_argument( "Codice Viaggio già esistente" );
        }
    }
}
int Vettore::getSize() const{
    return v.size();
}
vector<const Viaggio*> Vettore::getVettore() const{
    return v;
}

void Vettore::clearV(){
    v.clear();

}

vector<const Viaggio*>& Vettore::copiaVettore(vector<const Viaggio*> vR){
    if(!vR.empty()){
        Ryanair* vA;
        AirPartner* vP;
        for(vector<const Viaggio*>::const_iterator cit = vR.begin(); cit != vR.end(); ++cit){
            Viaggio* vC = const_cast<Viaggio*>(*cit);
            if(dynamic_cast<Ryanair*>(vC)){
                vA =  static_cast<Ryanair*>(vC);
                v.push_back(new Ryanair(vA));
            }else{
                vP = static_cast<AirPartner*>(vC);
                v.push_back(new AirPartner(vP));
            }
        }
    }
    return v;
}

void Vettore::distruggiVettore(vector<const Viaggio*> vD){
    if(!vD.empty()){
        for(vector<const Viaggio*>::const_iterator cit = vD.begin(); cit != vD.end(); ++cit){
            delete (*cit);
        }
    }
}

Vettore &Vettore::operator=(const Vettore &vR)
{
        if(this != &vR){
            distruggiVettore(v);
            v = copiaVettore(vR.getVettore());
        }
        return *this;
}

