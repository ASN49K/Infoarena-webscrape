#include <iostream>
#include <stdio.h>

using namespace std;

int a[1025],b[1025],n,m,rez[1025][1025];
int d[1025],u;

void citire()
{
    FILE *f1 =fopen("cmlsc.in","r");
    fscanf(f1,"%d %d",&n, &m);
    for(int i=0; i<n; i++)
    {
        fscanf(f1,"%d",&a[i]);
    }

    for(int i=0; i<m; i++)
    {
        fscanf(f1,"%d",&b[i]);
    }

}

FILE *f2 = fopen("cmlsc.out","w");

void drum()
{
    int l=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int v=0;
            if(a[i-1]==b[j-1])
                v=1;

            rez[i][j]=max(max(rez[i-1][j],rez[i][j-1]),rez[i-1][j-1]+v);
            if(l<rez[i][j])
                l=rez[i][j];
        }
    }

fprintf(f2,"%d\n",rez[n][m]);
}
void bak()
{
    int i=n,j=m;
    while(i && j)
    {
        if(a[i-1]==b[j-1])
        {
            d[rez[i][j]]=a[i-1];
            i--;
            j--;
        }
        if(rez[i-1][j]>rez[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=1; i<=rez[n][m]; i++)
        fprintf(f2,"%d ",d[i]);
}

int main()
{
    citire();
    drum();
    bak();



    return 0;
}
