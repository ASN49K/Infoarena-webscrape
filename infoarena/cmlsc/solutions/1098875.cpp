#include <iostream>
#include <stdio.h>

using namespace std;

int a[1025],b[1025],n,m,rez[1025][1025];
int d[1025],u;

void citire()
{
    FILE *f1 =fopen("cmlsc.in","r");
    fscanf(f1,"%d %d",&n, &m);
    for(int i=0;i<n;i++)
    {
        fscanf(f1,"%d",&a[i]);
    }

    for(int i=0;i<m;i++)
    {
        fscanf(f1,"%d",&b[i]);
    }

}
int maxim=0;
void drum()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            rez[i][j]=max(max(rez[i-1][j],rez[i][j-1]),rez[i-1][j-1]);
            if(a[i-1]==b[j-1])
            {

                d[u++]=a[i-1];
                rez[i][j]++;
                if(maxim<rez[i][j])
                    maxim=rez[i][j];
            }
        }
    }


}


int main()
{
    citire();
    drum();
    FILE *f2 = fopen("cmlsc.out","w");
    fprintf(f2,"%d\n",maxim);
    for(int i=0;i<u;i++)
    {
        fprintf(f2,"%d ",d[i]);
    }

    return 0;
}
