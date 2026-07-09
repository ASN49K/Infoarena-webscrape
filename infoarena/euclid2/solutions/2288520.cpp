#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r;
int main()
{
    for(f>>a;f>>a>>b;g<<b<<'\n')
        for(;r=a%b;a=b,b=r);
    return 0;
}
