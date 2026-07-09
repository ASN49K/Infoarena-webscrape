#include <iostream>
#include <fstream>

using namespace std;

fstream in("cmlsc.in",ios::in);
fstream out("cmlsc.out",ios::out);

int maxim(int,int); // functie care returneaza max a 2 nr

int main()
{
    int a[1025],b[1025],c[1026][1026],i,j,n,m,d[1025],k=0;
    in>>n>>m;

    for(i=0;i<n;i++)
    {
        c[0][i]=0;
        c[i][0]=0;
        in>>a[i];
    }                       //scriete vector 1 si initilizare prima inie si coloana ca nula

    for(i=0;i<m;i++)
        in>>b[i];           //scriere vector 2

    for(i=1;i<=n;i++)       //formarea tabelului de referinte
        for(j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
                c[i][j]=maxim(c[i-1][j],c[i][j-1])+1;
            else
                c[i][j]=maxim(c[i-1][j],c[i][j-1]);
        }

    i=n;
    j=m;
    while(c[i][j]!=0)
    {
        if((c[i-1][j]==c[i][j-1])&&c[i][j]>maxim(c[i-1][j],c[i][j-1]))
        {
            i--;
            j--;
            d[k++]=a[i];
        }
        else if(c[i][j-1]<c[i][j])
            i--;
        else if(c[i-1][j]<=c[i][j])
            j--;
    }

    out<<c[n][m]<<"\n";
    for(i=k-1;i>=0;i--)
        out<<d[i]<<" ";



    return 0;
}


int maxim(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
