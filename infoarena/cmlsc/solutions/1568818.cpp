#include <fstream>

using namespace std;

int a[1030],b[1030],na,nb,t[1030],k;
int d[1030][1030];
///d[i][j]=lungimea maxima a unui subsir comun  obtinut din
///a[1..i] si b[1..j]
///Rec:
/// d[i,j] = 1+d[i-1,j-1], daca a[i]=b[j]
///          max(d[i-1][j], d[i,j-1])
/// sol: d[na][nb]

inline void Citire()
{
    int i;
    ifstream fin("cmlsc.in");
    fin>>na>>nb;
    for(i=1;i<=na;++i)
        fin>>a[i];
    for(i=1;i<=nb;++i)
        fin>>b[i];
    fin.close();
}

inline void Solutie()
{
    int i,j;
    for(i=1;i<=na;++i)
        for(j=1;j<=nb;++j)
        {
            if(a[i]==b[j])  d[i][j]=1+d[i-1][j-1];
            else    d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    i=na;
    j=nb;
    while(d[i][j]>0)
    {
        if(a[i]==b[j])
        {
            t[++k] =a[i];
            i--; j--;
        }
        else
            if(d[i-1][j]<d[i][j-1]) j--;
            else    i--;
    }
    ofstream fout("cmlsc.out");
    fout<<d[na][nb]<<"\n";
    for(i=k;i>=1;--i)
        fout<<t[i]<<" ";
    fout<<"\n";
    fout.close();

}

int main()
{
    Citire();
    Solutie();
    return 0;
}
