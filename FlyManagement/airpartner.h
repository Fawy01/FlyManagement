#ifndef AIRPARTNER_H
#define AIRPARTNER_H

#include "viaggio.h"
#include <string>
#include <vector>
#include "locazione.h"
#include <iostream>
using std::string;
using std::vector;
using std::cout;

class AirPartner: public Viaggio{
    int numTappe;

public:
    AirPartner(string cod,double km, unsigned int p,string par, string dest, QDate gma,int n =0);
    AirPartner(const AirPartner *r);
    ~AirPartner();
    vector<const Locazione*> Locazioni;
    Locazione* SelectLocazione(string)const;
    void DeleteLocazione(int);
    void ModificaLoc(string ,string );
    string getSingolaLoc(string) const;
    void AggiungiTappa(const Locazione& v);
    int getPostiOcc() const override;
    int getTappe() const;
    void setNumTappe(int);
    vector<const Locazione*> LocaVett() const;


};

#endif // AIRPARTNER_H
