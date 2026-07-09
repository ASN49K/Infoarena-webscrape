#include <iostream>
#include <new>
#include <fstream>
using namespace std;

int main()
{
    int m,n,i,j,ok=0;
    int p[100][100];
    int *s1,*s2,*bun;

    s1=new int[n];
    s2=new int[m];

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    bun=new int[min(n,m)];



    p[0][0]=0;
    for(i=1;i<=n;i++)
    {
        f>>s1[i];
       p[i][0]=0;

    }
    for(i=1;i<=m;i++)
    {
        f>>s2[i];
       p[0][i]=0;

    }


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
                p[i][j]=1 + p[i-1][j-1];
            else
                p[i][j]=max(p[i-1][j],p[i][j-1]);
        }
    }
    i=n;
    j=m;



    while(i>0 || j>0)
    {
        if(s1[i]==s2[j])
        {
            bun[ok]=s1[i];
            ok++;
            i--;
            j--;

        }
        else
            if(p[i-1][j]<p[i][j-1])
                j--;
            else
                i--;

    }
   g<<ok<<endl;
    for(i=0;i<(ok);i++)
        g<<bun[i]<<" ";
    delete s1;
    delete s2;
    delete bun;

}


