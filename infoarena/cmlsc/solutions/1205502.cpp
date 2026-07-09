#include <iostream>
#include<fstream>
using namespace std;
int l[6][1029],v[259];
int main()
{ int a[1025],b[1025],m,n,max=0,maxi=0,i,k,s[1025],ok;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
      f>>a[i];
     for(i=1;i<=n;i++)
     {
         f>>b[i];
         v[b[i]]=i;

     }

     for(i=1;i<=m;i++)
       {
           if(v[a[i]]!=0)
           {
               l[2][i]=v[a[i]]; ok=0;
               for(k=i-1;k>=1&&ok==0;k--)
                  if(l[2][k]!=0&&l[2][i]>l[2][k])
                  {
                      l[3][i]=l[3][k]+1;
                      l[1][i]=k;
                      ok=1;
                  }
                  if(ok==0)
                  {
                      l[1][i]=0;
                      l[3][i]=1;
                  }
                if(l[3][i]>max)
                 {max=l[3][i];
                  maxi=i; }
           }

       }
       g<<max<<'\n';ok=k=0;
    for(i=maxi;i>=1&&ok==0;i--)
    {
        k=k+1;
        s[k]=b[l[2][i]];
        if(l[1][i]==0)
         ok=1;
         else
        i=l[1][i]+1;

    }
    for(i=k;i>=1;i--)
       g<<s[i]<<" ";
    f.close();
    g.close();
    return 0;
}
