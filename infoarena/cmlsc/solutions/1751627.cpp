#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct matrice
{
    int l,c,v;
};
matrice M[1025][1025]={0,0,0};
int s[1025];
int main()
{
    int a[1025],b[1025],i,j,m,n,mm=0,st=1025,d=1024;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                M[i][j].v=M[i-1][j-1].v+1;
                M[i][j].l=i-1;
                M[i][j].c=j-1;
                if(M[i][j].v>mm)
                {
                    mm=M[i][j].v;
                }
            }
            else
                if(M[i-1][j].v>=M[i][j-1].v)
            {
                M[i][j].v=M[i-1][j].v;
                M[i][j].l=i-1;
                M[i][j].c=j;
            }
            else
            {
                M[i][j].v=M[i][j-1].v;
                M[i][j].l=i;
                M[i][j].c=j-1;
            }
  i=n;j=m;
  g<<mm<<endl;
   while(i>=0 && j>=0)
   {
       if(M[i][j].l==i-1 && M[i][j].c==j-1)
       {
           s[--st]=b[j];
           i--;
           j--;
       }
       else
        if(M[i][j].l==i-1)
           i--;
       else
        j--;
   }
    for(i=st;i<=d;i++)
        g<<s[i]<<" ";
    f.close();
    g.close();
    return 0;
}
