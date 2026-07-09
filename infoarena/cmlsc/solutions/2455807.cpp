#include <fstream>
#define MAX 110000
using namespace std;
int best[MAX],poz[MAX],a[MAX],sol[MAX];
int n,lg=1;
int cautbin(int x);
ifstream fin("scmax.in");
ofstream fout("scmax.out");
int main()
{
    int i,pozitie,cine;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    best[1]=a[1];
    for(i=2;i<=n;i++)
        if(a[i]>best[lg])
        {
            best[++lg]=a[i];
            poz[i]=lg;
        }
        else
        {
         pozitie=cautbin(a[i]);
         best[pozitie]=a[i];
         poz[i]=pozitie;
        }
    cine=lg;
    for(i=n;i>=1;i--)
        if(poz[i]==cine)
        {sol[cine]=a[i];
        cine--;}
    fout<<lg<<'\n';
    for(i=1;i<=lg;i++)
        fout<<sol[i]<<' ';
    return 0;
}
int cautbin(int x)
{
    int st=0,dr=lg+1,mij;
    while(dr-st>1)
    {
        mij=(st+dr)/2;
        if(best[mij]>=x)
            dr=mij;
        else
            st=mij;
    }
    return dr;
}
