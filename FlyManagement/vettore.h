#ifndef VETTORE_H
#define VETTORE_H
#include "viaggio.h"
#include "airpartner.h"
#include "ryanair.h"
#include <typeinfo>
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::string;
class Vettore{
    vector<const Viaggio*> v;
public:
    Vettore();
    ~Vettore();
    void AggiungiNewViaggio(const Viaggio*);
    void AggiungiAirLoc(string, const Locazione*);
    Viaggio* getViaggio(string);
    void DeleteAirLoc(string,int);
    void DeleteViaggio(int);
    int getSize() const;
    void ControllaCod(string c) const;
    vector<const Viaggio *> getVettore() const;
    void clearV();
    void caricaDati(const vector<const Viaggio *> &vR);
    vector<const Viaggio *>& copiaVettore(vector<const Viaggio *> vR);
    Vettore &operator =(const Vettore &vR);
    Vettore(const Vettore&);
    void distruggiVettore(vector<const Viaggio *> vD);
};

#endif
