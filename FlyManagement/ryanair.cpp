#include "ryanair.h"


Ryanair::Ryanair(string cod, double km, unsigned int p, string par,string dest, QDate gma, int equi): Viaggio(cod,km,p,par,dest,gma), equipaggio(equi){
}
Ryanair::Ryanair(const Ryanair* r): Viaggio(r){
    *this = *r;
}
int Ryanair::getPostiOcc()const {
    return getPasseggeri() + equipaggio;
}
int Ryanair::getEquipaggio() const{
    return equipaggio;
}
void Ryanair::setEquipaggio(int e){
    equipaggio = e;
}
