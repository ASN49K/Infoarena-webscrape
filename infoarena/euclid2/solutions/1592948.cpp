#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdarg>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
struct joj {int a;int b;};

int euclid(int a,int b)
{
    if(a%b==0) return b;
    else euclid(b,a%b);
}

int main()
{
    int load;
    int a;
    int b;
    in>>load;
    for(register int i=1;i<=load;i++)
    {
        in>>a;
        in>>b;
        out<<euclid(a,b);
        out<<endl;
    }
}

