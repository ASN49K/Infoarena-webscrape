#include<iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;

int euclid(int a,int b)
{if (!b) return a;
    return euclid(b, a % b);
}

int main()
{int a,b;
f>>n;
while(n--){f>>a>>b;g<<euclid(a,b)<<'\n';}
f.close();
g.close();


return 0;
}

