#include<iostream>
#include<fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,i,v,n,j,y,nr=1;

int main ()
{
    f>>n;

    for (i=1;i<=n;i++)
   { f>>x>>y;
    if (x==0||y==0) g<<x+y<<endl;
           else
    {int r=x%y;
    while (r)
    {
         x=y;
        y=r;
        r=x%y;
    }
    g<<y<<endl;
       }
   }
    return 0;
}
