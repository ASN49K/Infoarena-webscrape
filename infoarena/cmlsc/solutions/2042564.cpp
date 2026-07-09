#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,i,j,x[1024],y[1025],a[1025][1025],d[1025],k;

int main()
{f>>N>>M;
for(i=1;i<=N;i++) f>>x[i];
for(j=1;j<=M;j++) f>>y[j];
for(i=1;i<=N;i++)
    for(j=1;j<=M;j++)
        {
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
               else if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
                        else a[i][j]=a[i][j-1];

        }
g<<a[N][M]<<'\n';

i=N;j=M;k=0;
while(a[i][j])
if(x[i]==j[y]){k++;
                d[k]=x[i];
                i--;j--;}
    else if(a[i-1][j]>a[i][j-1]) i--;
            else j--;
for(i=k;i>0;i--)
    g<<d[i]<<" ";
    f.close();
    g.close();
    return 0;

}
