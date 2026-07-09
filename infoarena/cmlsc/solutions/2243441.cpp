#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream intrare("cmlsc.in");
ofstream iesire("cmlsc.out");

long long int sir1[1024],sir2[1024],maxim=-1,g,h;
long long int T[1024][1024],n,m,i,j;


int main()
{
    intrare>>n>>m;
    for(i=1; i<=n; i++)
        intrare>>sir1[i];

    for(i=1; i<=m; i++)
        intrare>>sir2[i];


    for(i=1; i<=n; i++)
    {

        for(j=1; j<=m; j++)
        {
            if(sir1[i]==sir2[j])
            {
                T[i][j]=T[i-1][j-1]+1;
                if(T[i][j]>maxim)
                    maxim=T[i][j];
                g=i;
                h=j;
            }

            else
                T[i][j]=max(T[i-1][j],T[i][j-1]);

        }
    }

    int numar=0;
    while(true)
    {
        if(T[g-1][h-1]!=T[g][h] && g-1>=1 && h-1>=1)
        {
            numar=numar*10+sir2[h];
            g--;
            h--;
        }
        else if(h==1)
            g--;
        else if(T[g-1][h-1]==T[g][h])
            h--;

        if(g==1)
        {
            numar=numar*10+sir2[h];
            break;
        }


    }

    long long int o=0;
    while(numar>0)
    {
        int c=numar%10;
        o=o*10+c;
        numar/=10;
    }
    iesire<<maxim<<endl<<o;


    return 0;
}
