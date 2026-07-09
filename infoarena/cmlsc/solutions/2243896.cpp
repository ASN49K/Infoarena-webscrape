#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream intrare("cmlsc.in");
ofstream iesire("cmlsc.out");

long long int sir1[1024],sir2[1024],maxim=-1,g,h,vect[1024];
long long int T[1024][1024],n,m,i,j;


int main()
{
    intrare>>n>>m;
    for(i=1; i<=n; i++)
        intrare>>sir1[i];

    for(i=1; i<=m; i++)
        intrare>>sir2[i];


    for(i=1; i<=n; i++)
    {

        for(j=1; j<=m; j++)
        {
            if(sir1[i]==sir2[j])
            {
                T[i][j]=T[i-1][j-1]+1;

            }

            else
                T[i][j]=max(T[i-1][j],T[i][j-1]);

        }
    }
int k=1;

g=n;
h=m;
maxim=T[g][h];

    while(true)
    {

         if(T[g][h-1]==T[g][h])
            h--;
         else if(T[g-1][h]==T[g][h])
                    g--;
         else {
            vect[k]=sir2[h];
            k++;
            h--;
            g--;
         }
          if(g<=0 || h<=0)
         break;







    }



iesire<<maxim<<endl;
  for(i=k-1;i>=1;i--)
  iesire<<vect[i]<<" ";


    return 0;
}
