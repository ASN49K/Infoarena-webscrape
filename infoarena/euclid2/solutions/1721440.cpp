#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int T, i;
long long a, b, r, aux;
int main()
{f>>T;
for(i=1; i<=T; i++)
    {f>>a>>b;
    r=a%b;
    while(r!=0)
        {a=b;b=r;r=a%b;}
    g<<b<<endl;
}
f.close();
g.close();
    return 0;
}
