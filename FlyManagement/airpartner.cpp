#include "airpartner.h"

AirPartner::AirPartner(string cod,double km, unsigned int p,string par, string dest, QDate gma,int n): Viaggio(cod,km,p,par, dest, gma),numTappe(n){
}
AirPartner::AirPartner(const AirPartner* r): Viaggio(r){
    *this = *r;
}

AirPartner::~AirPartner(){
    for(auto sl : Locazioni)delete sl;

}

Locazione* AirPartner::SelectLocazione(string c) const{
    Locazione* v;
    for(vector<const Locazione*>::const_iterator cit=Locazioni.begin(); cit!=Locazioni.end(); ++cit){
        if(c==(*cit)->getNome()){
            v = const_cast<Locazione*>(*cit);
        }
    }
    return v;
}

void AirPartner::DeleteLocazione(int i){
    vector<const Locazione*>::const_iterator it = Locazioni.begin()+i;
    if(*it)
        delete (*it);
    Locazioni.erase(it);
}

void AirPartner::ModificaLoc(string c,string d){
    Locazione*v = SelectLocazione(c);
    v->setNome(d);
}
string AirPartner::getSingolaLoc(string c) const{
    Locazione* v = SelectLocazione(c);
    return v->getNome();
}
void AirPartner::AggiungiTappa(const Locazione& v){
    Locazioni.push_back(&v);
}
int AirPartner::getPostiOcc() const{
    return getPasseggeri();
}

int AirPartner::getTappe() const{
    return numTappe;
}

void AirPartner::setNumTappe(int t){
    numTappe = t;
}

vector<const Locazione *> AirPartner::LocaVett() const
{
    return Locazioni;
}




