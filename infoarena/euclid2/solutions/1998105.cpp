#include <fstream>

using namespace std;

int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,i,T;
f >> T;
for(i=1;i<=T;i++)
{
f >> a >> b;
while(b!=0)
{
r = a%b;
a = b;
b = r;
}
g << a << endl;
}

    return 0;
}
