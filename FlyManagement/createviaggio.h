#ifndef CREATEVIAGGIO_H
#define CREATEVIAGGIO_H
#include "ryanair.h"
#include "airpartner.h"
#include "locazione.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class CreateViaggio
{
public:
    CreateViaggio();
    ~CreateViaggio();
    Ryanair* createRyanair(string ,double ,unsigned int ,string ,string , QDate , int)const;
    AirPartner* createAirPartner(string , double , unsigned int , string , string , QDate , int )const;
    Locazione* createLocazione(string , string ) const;
};

#endif // CREATEVIAGGIO_H
