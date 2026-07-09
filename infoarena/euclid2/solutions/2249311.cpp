#include <iostream>
#include <fstream>
using namespace std;

int main()
{int a,b,T,i,c;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(i=1;i<=T;i++)while(f>>a>>b){ while (b) {
        c = a % b;
        a = b;
        b = c;}
                                g<<a<<'\n';
                                }
f.close();
g.close();
    return 0;
}
