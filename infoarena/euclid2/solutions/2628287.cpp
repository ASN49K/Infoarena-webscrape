#include<iostream>
#include<fstream>

using namespace std;

int n,i,a,b;

int d(int a,int b)
{if(!b)
return a;
return d(b,a%b);
}

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;
g<<d(a,b)<<endl;
}
f.close();
g.close();
    return 0;
}
