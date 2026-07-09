#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
long long a1,b1;
int euclid(long long a,long long b)
{
    int rest=0;
    while(b)
        rest=a%b,a=b,b=rest;
    return a;
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        {
            f>>a1>>b1;
            g<<euclid(a1,b1)<<"\n";
        }
    return 0;
}
