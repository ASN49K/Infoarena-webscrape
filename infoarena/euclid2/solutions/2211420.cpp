#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int Euclid(int x,int y)
{int c=y;
    while(x%y!=0)
    { c=x%y;
       x=y;
       y=c;
    }
    return y;
}
int main()
{int i,n,x,y;
f>>n;
 for(i=1;i<=n;i++)
 { f>>x>>y;
    g<<Euclid(x,y)<<endl;
 }

f.close();
g.close();
    return 0;
}
