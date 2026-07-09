#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int d(int a,int b)
{if(b==0)
return a;
return d(b,a%b);
}

int main()
{int n,i,a,b;
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;
g<<d(a,b)<<"\n";
}
    return 0;
}
