#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{long a,b;
f>>a>>b;
while(a!=b)
if(a>b)
a=a-b;
else
b=b-a;
if(a!=1)
g<<a;
else
g<<"0";


    return 0;
}
