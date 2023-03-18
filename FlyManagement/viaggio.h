
#ifndef VIAGGIO_H
#define VIAGGIO_H

#include <string>
#include <QDate>
#include <QString>

using std::string;

class Viaggio{
private:
    string COD;
    double Km;
    unsigned int Passeggeri;
    string Partenza;
    string Destinazione;
    QDate data;
public:
    Viaggio(string cod=0, double km=0, unsigned int p=0, string Partenza=0,string d=0, QDate gma = QDate());
    Viaggio(const Viaggio* );
    virtual ~Viaggio() = default;
    double getKM() const;
    string getCod() const;
    int getPasseggeri() const;
    virtual int getPostiOcc() const = 0;
    string getDestinazione()const;
    string getPartenza() const;
    QDate getData() const;
    void setCOD(string);
    void setPass(int);
    void setPart(string);
    void setDest(string);
    void setKM(double);
    void setData(QDate);

};

#endif
