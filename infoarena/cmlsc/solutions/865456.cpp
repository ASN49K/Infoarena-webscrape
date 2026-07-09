#include <iostream>
#include <fstream>

short v1[1024],v2[1024],vf[1024],n,m,i,L[1000],maxq,mx,k,t;

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
    f>>v1[i];
    for(i=1;i<=m;i++)
    f>>v2[i];

    short c=1;
    for(i=1;i<=n;i++)
    {
        for(short j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                vf[c]=v1[i];
                c++;
            }
        }
    }

    L[c]=1;
    for(k=c-1;k>0;k--)
       {
       mx=0;
       for(i=k+1;i<=c;i++)
          if(vf[i]>=vf[k] && L[i]>mx)
             mx=L[i];
       L[k]=mx+1;
       if(L[k]>maxq)
          {
              maxq=L[k];
              t=k;
          }
       }
    g<<maxq<<"\n";

    g<<vf[t]<<' ';
    for(i=t+1;i<=c;i++)
      if ((vf[i]>=vf[t]) && (L[i]==maxq-1))
         {g<<vf[i]<<' ';
         maxq--;}
    return 0;
}
