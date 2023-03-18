#include "locazione.h"

Locazione::Locazione(string n, string i): NomeLoca(n), IndirizzoLoca(i){}

Locazione::~Locazione(){}

string Locazione::getNome() const{
    return NomeLoca;
}
string Locazione::getIndirizzo() const{
    return IndirizzoLoca;
}
void Locazione::setNome(string n){
    NomeLoca = n;
}
void Locazione::setIndirizzo(string i){
    IndirizzoLoca = i;
}
