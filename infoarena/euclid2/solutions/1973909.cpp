#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int a,b;
f>>a>>b;
while(a!=b)if(a>b)a-=b; else b-=a;
g<<a;
    return 0;
}
