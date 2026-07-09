#include <fstream>

using namespace std;

int main()
{ifstream f ("euclid.in");
ofstream g  ("euclid.txt");
int a,b,t,i;
f>>t;

for (i=1;i<=t;i++)
{
    f>>a>>b;
while (a!=b){
    if (a>b)
        a=a-b;
    else b=b-a;}
g<<a<<"\n";
}

    f.close();
    g.close();
}
