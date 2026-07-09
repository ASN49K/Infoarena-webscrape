#include <iostream>
#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

int main()
{ifstream f1("euclid2.in");
ofstream f2("euclid2.out");int n,a,b;
f1>>n;
while(n)
{f1>>a>>b;
f2<<cmmdc(a,b)<<'\n';
   n--;
}

    return 0;
}
