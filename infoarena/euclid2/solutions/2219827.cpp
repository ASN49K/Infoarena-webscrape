/*Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din
fiecare pereche in parte.*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{   int a,b,rest,T,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=0;i<T;i++)
    {
    f>>a;
    f>>b;
    while(b)
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
