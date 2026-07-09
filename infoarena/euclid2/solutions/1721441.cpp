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
    if(a<b){x=a;y=b;}
    else
    {x=b;y=a;}
    r=y%x;
    while(r!=0)
        {y=x;x=r;r=y%x;}
    g<<x<<endl;
}
    return 0;
}
