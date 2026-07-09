#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int t,a,b,x,c;
f>>t;
for(x=1;x<=t;x++)
{f>>a>>b;
    while(b)
{c=a%b;
 a=b;
 b=c;
}
g<<a<<'\n';
}


    return 0;
}
