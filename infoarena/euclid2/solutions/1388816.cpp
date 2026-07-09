#include <iostream>
#include <fstream>

using namespace std;

fstream in("euclid2.in", ios::in);    // fisierul din care extrag datele
fstream out("euclid2.out", ios::out); // fisierul in care scriu datele

int cmmdc(int nr1, int nr2)
{
    // caz in care nr2 este cmmdc-ul celor 2 numere, nu are rost sa folosesc memorie in plus, deci trebuie verificat primul
    if (nr1 % nr2 == 0)
        return nr2;

    // iar daca nu, folosindu-ma de recursivitate apel iar functia pana gasesc ceea ce caut
    return cmmdc(nr2, nr1%nr2);
}

int main()
{
    int contor = 0,                    // variabila care va retine prima linie din
        nr1,                           // variabila in care citesc primul numar din pereche
        nr2,                           // variabila in care voi citi al doilea numar din pereche
        aux;                           // variabila in care voi retine rezultatul intors de cmmdc
    in >> contor;
    while (contor)
    {
        in >> nr1 >> nr2;
        aux = cmmdc(nr1, nr2);
        out << aux << '\n';
        contor--;
    }
    in.close();
    out.close();
    return 0;
}

