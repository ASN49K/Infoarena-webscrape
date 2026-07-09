#include<iostream>
#include<fstream>

using namespace std;

int c[1024][1024],drum[1024][1024];
ifstream f ("cmlsc.in");
ofstream o ("cmlsc.out");

int leng( int a[1024],int b[1024], int m, int n)
{
    int i,j,len=-1000;
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(i=1;i<=n;i++)
        c[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
           {
               if(a[i]==b[j])
                   {
                    c[i][j]=c[i-1][j-1]+1;

                    if(len<c[i][j])
                            len=c[i][j];

                    drum[i][j]=2;
                    }
                 else
                    if (c[i-1][j]>=c[i][j-1])
                            {
                                c[i][j]=c[i-1][j];
                                drum[i][j]=1;
                            }
                    else
                        {
                            c[i][j]=c[i][j-1];
                            drum[i][j]=4;
                        }
           }
return len;
}

void afis_misto(int a[1024],int i, int j)
{
    if(i!=0 && j!=0)
        {
            if(drum[i][j]==2)
                    {
                        afis_misto(a,i-1,j-1);
                        o<<a[i]<<" ";
                    }
              else
                if(drum[i][j]==1)
                    afis_misto(a,i-1,j);
                else
                    afis_misto(a,i,j-1);
        }
}



int main()
{

int i,j,n,m;
int a[1024], b[1024];

f>>m>>n;

for(i=1;i<=m;i++)
    f>>a[i];

for(j=1;j<=n;j++)
    f>>b[j];

 o<<leng (a,b,m,n)<<"\n";

afis_misto(a,m,n);







return 0;}
