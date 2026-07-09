#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int maxi(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int t,i,j,r=1,aux,a,b;
int main()
{f>>t;
for(i=1;i<=t;i++)
{r=1;
    f>>a>>b;
    if(a>b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    for(j=1;j*j<=a*a;j++)
    {
        if(a%j==0)
        {
            if(b%j==0)
                r=maxi(r,j);
             if(b%(a/j)==0)
            r=maxi(r,(a/j));


        }
    }
    g<<r<<"\n";
}


    return 0;
}
