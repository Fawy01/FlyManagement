#ifndef MODEL_H
#define MODEL_H
#include "vettore.h"
#include "viaggio.h"
#include "createviaggio.h"
#include <stdexcept>
#include <string>
#include <string.h>
using std::string;

class Model{
    Vettore* vettore;
public:
    Model();
    ~Model();

    void addRya(string,double,unsigned int,string,string, QDate, int) const;
    void addAir(string ,double , unsigned int ,string , string , QDate ,int ) const;
    void addLoc(string ,string , string ) const;
    Viaggio* getV(string) const;
    void DeleteViaggio(int) const;
    void DeleteLoc(string, int) const;
    int getVectorSize() const;
    void ControllaCOD(string) const;
    vector<const Viaggio *> getVector() const;
    void clearVettore() const;
    void caricaDati(const Vettore*);

};

#endif // MODEL_H
