#include <iostream>
#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[100][100],l1,l2,v3[100];

int main()
{
    int i,j,n,m,aux;
    int v1[100],v2[100];
    in>>n>>m;
    for(i=1;i<=n;i++)
    {
        in>>v1[i];
    }
    for(i=1;i<=m;i++)
    {
        in>>v2[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                if(a[i-1][j]>a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                }
                else
                {
                    a[i][j]=a[i][j-1];
                }
            }
        }
    }
            out<<a[n][m];
    aux=1;
    for(i=1;i<=n;i++)
    {
        j=aux;
        while(j<=m)
        {

            if(v1[i]==v2[j])
            {
                out<<v2[j]<<" ";
                aux=j+1;
                break;
            }
            j++;
        }
    }
}
