
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");


long long n,a,b,i;


int euclid(int a ,int b)
{while(b)
{int r=a%b;
a=b;
b=r;
}
return a;
}

int main()
{
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;
g<<euclid(a,b)<<'\n';
}

}
