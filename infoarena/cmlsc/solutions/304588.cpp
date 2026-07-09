#include<iostream>
#include<fstream>

using namespace std;

int c[1024][1024],drum[1024][1024];


void leng( int a[1024],int b[1024], int m, int n)
{
    int i,j;
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(i=1;i<=n;i++)
        c[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
           {
               if(a[i]==b[j])
                   {c[i][j]=c[i-1][j-1]+1;
                    drum[i][j]=a[i];}
                 else
                    if (c[i-1][j]>=c[i][j-1])
                            c[i][j]=c[i-1][j];
                    else
                        c[i][j]=c[i][j-1];
           }
}



int main()
{
ifstream f ("cmlsc.in");
ofstream o ("cmlsc.out");
int i,j,n,m;
int a[1024], b[1024];

f>>m>>n;

for(i=1;i<=m;i++)
    f>>a[i];

for(j=1;j<=n;j++)
    f>>b[j];

 leng (a,b,m,n);

for(i=1;i<=m;i++)
    {for(j=1;j<=n;j++)
        if(drum[i][j]!=0 && c[i][j] != 0)
                o<<drum[i][j]<<" ";}








return 0;}
