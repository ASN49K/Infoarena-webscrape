#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int i,n,a,b;
int f(int a,int b)
{if(!b) return a;
return f(b,a%b);
}
int main()
{in>>n;
for(i=1;i<=n;i++)
{in>>a>>b;
out<<f(a,b)<<"\n";
}
    return 0;
}
