#ifndef RYANAIR_H
#define RYANAIR_H

#include "viaggio.h"
#include <string>
using std::string;

class Ryanair: public Viaggio{
    int equipaggio;
public:
    Ryanair(string cod,double km,unsigned int p,string par,string dest, QDate gma, int equi=0);
    Ryanair(const Ryanair* r);
    ~Ryanair()=default;
    int getPostiOcc()const override;
    int getEquipaggio() const;
    void setEquipaggio(int);

};

#endif // RYANAIR_H
