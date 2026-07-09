#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#define dimmax 2000000000
#include <string.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{   int r;
    r=a%b;
    while(r)
        {a=b;
        b=r;
        r=a%b;
        }
    return b;
}

int main()
{   int n,a,b,i;
    f >> n;
    for(i=1;i<=n;i++)
        {f >> a >> b;
        g << cmmdc(a,b) << '\n';
        }
    return 0;
}
