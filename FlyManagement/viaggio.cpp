#include "viaggio.h"

Viaggio::Viaggio(string cod,double km, unsigned int p,string par, string d, QDate gma): COD(cod),Km(km),Passeggeri(p), Partenza(par),Destinazione(d), data(gma) {}

Viaggio::Viaggio(const Viaggio* vN){
    *this = *vN;
}

double Viaggio::getKM() const{return Km;}

string Viaggio::getCod() const{return COD;}

int Viaggio::getPasseggeri() const{
    return Passeggeri;
}
string Viaggio::getDestinazione() const{
    return Destinazione;
}
string Viaggio::getPartenza() const{
    return Partenza;
}
QDate Viaggio::getData() const{
    return data;
}
void Viaggio::setCOD(string c){
    COD = c;
}
void Viaggio::setPass(int p){
    Passeggeri = p;
}
void Viaggio::setPart(string par){
    Partenza = par;
}
void Viaggio::setDest(string d){
    Destinazione = d;
}
void Viaggio::setKM(double k){
    Km = k;
}
void Viaggio::setData(QDate gma){
    data = gma;
}
