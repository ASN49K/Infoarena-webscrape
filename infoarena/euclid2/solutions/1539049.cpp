#include<iostream>
#include<fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,v,n,j,nr=1;
int x,y;
int euclid(int x,int y)
{
    if (y==0) return x;
    return euclid(y,x%y);
}

int main ()
{
    f>>n;

    for (i=1;i<=n;i++)
   { g>>x>>y;

    g<<euclid(x,y)<<endl;

   }
    return 0;
}
