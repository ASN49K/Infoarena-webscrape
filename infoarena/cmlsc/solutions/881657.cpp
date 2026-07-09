#include <iostream>
#include <fstream>
using namespace std;

int const N=1024;
int n,m,i,j;
int a[N],b[N];//a-primul sir, b-al doilea sir
int L[N][N];//matricea in care calculez lungimea celui mai lung subsir
int s[N];

void construireL(int a[],int b[])
{
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]= L[i-1][j] >= L[i][j-1] ? L[i-1][j] : L[i][j-1] ;
}

void construireSol(int a[],int b[])
{
    int k=L[m][n];
    i=m;
    j=n;
    while(i!=0 && j!=0)
        if(a[i]==b[j])
        {
            s[k]=a[i];
            k--;
            i--;
            j--;
        }
        else if(L[i-1][j]<L[i][j-1])
                j--;
             else
                i--;
}

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(j=1;j<=n;j++)
        in>>b[j];
    construireL(a,b);
    construireSol(a,b);
    out<<L[m][n]<<"\n";
    for(i=1;i<=L[m][n];i++)
        out<<s[i]<<" ";
    in.close();
    out.close();
}
