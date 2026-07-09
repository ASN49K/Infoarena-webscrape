#include<fstream>
using namespace std;

fstream f("euclid2.in",ios::in); //fisierul de intrare
fstream g("euclid2.out",ios::out); //fisierul de iesire

//Algoritmul lui Euclid
//Metoda impartirilor
long cmmdc(long a,long b)
{
    long c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
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
