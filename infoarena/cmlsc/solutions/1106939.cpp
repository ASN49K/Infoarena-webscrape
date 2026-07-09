#include <iostream>
#include<stdio.h>
using namespace std;
int lung[1025][1025];
short int diag[1025][1025];
int a[1025],b[1025];
int final[3000];
FILE *f,*g;
int main()
{
    int M,N,i,j,poz;
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d%d",&M,&N);
    for(i=1;i<=M;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=N;i++)
        fscanf(f,"%d",&b[i]);
    for(i=0;i<=M;i++) lung[i][0]=0;
    for(j=0;j<=N;j++) lung[0][j]=0;
    for(i=1;i<=M;++i)
        for(j=1;j<=N;++j)
            {
               if (a[i]==b[j])
                    {
                        lung[i][j]=lung[i-1][j-1]+1;
                        diag[i][j]=0;
                    }
                else
                    {
                        if (lung[i-1][j]>lung[i][j-1])
                            {
                                lung[i][j]=lung[i-1][j];
                                diag[i][j]=1;
                            }
                        else
                            {
                                lung[i][j]=lung[i][j-1];
                                diag[i][j]=2;
                            }
                    }
            }
    i=M;
    j=N; poz=M+N;
    while(i!=0&&j!=0)
        {
          if (diag[i][j]==0)
                {
                    final[poz]=a[i];
                    poz--;
                    i--;
                    j--;
                }
          if (diag[i][j]==1)
            {
                i--;
            }
          if (diag[i][j]==2)
            {
                j--;
            }
        }
    fprintf(g,"%d\n",M+N-poz);
    for(i=poz+1;i<=M+N;i++)
        {
            fprintf(g,"%d ",final[i]);
        }






    return 0;
}
