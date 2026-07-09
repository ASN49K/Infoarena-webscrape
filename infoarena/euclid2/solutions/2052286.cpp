#include <iostream>
#include <fstream>

using namespace std;

int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T;
f>>T;
int a,b;
for(int i=1;i<=T;i++)
{f>>a>>b;
while(a!=b)
if(a>b)
    b=b-a;
    else a=a-b;
    g<<b;
}




}
