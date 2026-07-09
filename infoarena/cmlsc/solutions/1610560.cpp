#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
FILE* fin=fopen("cmlsc.in","r");
FILE* fout=fopen("cmlsc.out","w");
int n,m,a[1027][1027],s[1027],k;
int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for(int i=0; i<n; i++)
        fscanf(fin,"%d",&a[i+2][0]);
    for(int i=0; i<m; i++)
        fscanf(fin,"%d",&a[0][i+2]);

    for(int i=2; i<n+2; i++)
    {
        for(int j=2; j<m+2; j++)
        {
            if(a[0][j]!=a[i][0])
            {
                if(a[i][j-1]>a[i-1][j])
                    a[i][j]=a[i][j-1];
                else
                    a[i][j]=a[i-1][j];
            }
            else
                a[i][j]=a[i-1][j-1]+1;
        }
    }
    int i=n+1,j=m+1;
    while(a[i][j])
    {
        if(a[i][0]==a[0][j])
        {
            s[k++]=a[i][0];
            i--;
            j--;
        }
        else if(a[i-1][j]>a[i][j-1])
            i--;
        else
            j--;

    }
    fprintf(fout,"%d\n",k-1);
    for(int i=k-1;i>=0;i--)
        fprintf(fout,"%d ",s[i]);
    fprintf(fout,"\n");
    return 0;
}
