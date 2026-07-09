#include <fstream>
#define lgmax 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();
int maxim(int a, int b);
void afisare();

int x[lgmax],y[lgmax];
int lcs[lgmax][lgmax];
int s[lgmax];
int lg,m,n;

int main()
{
    citire();
    pd();
    afisare();

    fout.close();
    return 0;
}

void citire()
{
    int i;
    fin>>m>>n;
    for(i=1;i<=m;i++) fin>>x[i];
    for(i=1;i<=n;i++) fin>>y[i];
}

void pd()
{
   int i,j;
   for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        if(x[i]==y[j])
           lcs[i][j]=1+lcs[i-1][j-1];
        else
           lcs[i][j]=maxim(lcs[i-1][j],lcs[i][j-1]);
    i=m;j=n;
   // for(i=m,j=n;i>0;)
        while(i>0)
        if(x[i]==y[j])
            {s[++lg]=x[i];i--;j--;}
        else
            if(lcs[i-1][j]<lcs[i][j-1]) j--;
            else i--;
}

int maxim(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void afisare()
{
    int i;
    fout<<lg<<'\n';
    for (i=lg;i!=0;i--) fout<<s[i]<<' ';

    fout.close();
}
