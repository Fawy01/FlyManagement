#ifndef LOCAZIONE_H
#define LOCAZIONE_H
#include <string>
using std::string;

class Locazione{
        string NomeLoca;
        string IndirizzoLoca;
    public:
        Locazione(string n, string i);
        ~Locazione();
        string getNome() const;
        string getIndirizzo() const;
        void setNome(string);
        void setIndirizzo(string);
};
#endif // LOCAZIONE_H
