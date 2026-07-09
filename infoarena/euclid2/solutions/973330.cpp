#include<fstream>
using namespace std;

fstream f("euclid2.in",ios::in); //fisierul de intrare
fstream g("euclid2.out",ios::out); //fisierul de iesire

//Algoritmul lui Euclid
//Metoda scaderilor succesive
long cmmdc(long a,long b)
{
    while(a!=b)
        a>b ? (a-=b) : (b-=a);
    return a;
}

int main()
{
    long i,a,b,T;
    f>>T;
    for(i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    f.close(); g.close(); //inchiderea fisierelor
    return 0;
}
