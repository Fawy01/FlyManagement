#include "createviaggio.h"

CreateViaggio::CreateViaggio(){}

CreateViaggio::~CreateViaggio(){}

Ryanair* CreateViaggio::createRyanair(string cod,double km,unsigned int p,string par,string dest, QDate gma, int equi=0) const{
    return new Ryanair(cod,km,p,par,dest,gma,equi);
}

AirPartner* CreateViaggio::createAirPartner(string cod, double km, unsigned int p ,string par,string dest, QDate gma, int n) const{
    return new AirPartner(cod,km,p,par,dest,gma,n);
}

Locazione* CreateViaggio::createLocazione(std::string n, std::string i) const{
    Locazione* loc = new Locazione(n,i);
    return loc;
}
