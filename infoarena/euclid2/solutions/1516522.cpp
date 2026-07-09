#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b;
void read()
{
    f>>a>>b;
}
int main()
{int n;
    f>>n;
for(int i=1;i<=n;i++)
{read();
while(a!=b)
    {if(a>b)
    a=a-b;
    else
        b=b-a;}
        g<<a<<endl;
}
}
