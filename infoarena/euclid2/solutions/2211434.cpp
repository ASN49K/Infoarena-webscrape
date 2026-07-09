#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long Euclid(long long x,long long y)
{ if(x%y==0)
return y;
else  Euclid(y,x%y);
}
int main()
{long long i,n,x,y;
f>>n;
 for(i=1;i<=n;i++)
 { f>>x>>y;
    g<<Euclid(x,y)<<endl;
 }

f.close();
g.close();
    return 0;
}
