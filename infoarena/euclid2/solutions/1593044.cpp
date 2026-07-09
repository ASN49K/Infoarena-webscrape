#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdarg>
using namespace std;

ifstream in("euclid2.in");

struct joj {int a;int b;};

int euclid(int a,int b)
{
    if(b==0) return a;
    else return euclid(b,a%b);
}

int main()
{
    freopen("euclid2.out","w",stdout);
    int load;
    int a;
    int b;
    in>>load;
    for(register int i=1;i<=load;i++)
    {
        in>>a;
        in>>b;
        printf("%d\n",euclid(a,b));
    }
}

