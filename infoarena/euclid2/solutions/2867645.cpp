#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{int r;
if (a<b) swap(a,b);
while (b!=0) {r=a%b;
             a=b;
             b=r;

             }
return a;
}

int main()
{int t,x,y;
f>>t;
for (int cases=1;cases<=t;cases++) {f>>x>>y;
                                    g<<euclid(x,y)<<'\n';

                                    }
}
