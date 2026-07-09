#include <fstream>
#include <iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int stiva[1025],solutie[1025],lungime,m,n;
int a[1025],b[1025];
int pozANT = -1;
bool check(int a)
{
    for(int i=0; i<n; i++)
        if(a == b[i] && pozANT<i){pozANT = i; return true;}
    return false;
}
int cmlsc(int k,int posA) //k = pozitia in stiva == lungimea
{
    for(int i=posA; i<m; i++)
    {
        if(check(a[i])){ stiva[k] = a[i]; cmlsc(k+1,posA+i); } //verificarea pozitiei SUGE!
    }
    pozANT = -1;
    if(lungime<k)
    {
        lungime = k;
        for(int i=0 ; i<k; i++)
        {
            solutie[i]=stiva[i];
        }
    }
}
int main()
{
    f>>m>>n;
    for(int i=0; i<m; i++) f>>a[i];
    for(int i=0; i<n; i++) f>>b[i];
    cmlsc(0,0);
    g<<lungime<<'\n';
    for(int i=0; i<lungime; i++)
        g<<solutie[i]<<' ';
    g<<'\n';
    return 0;
}
