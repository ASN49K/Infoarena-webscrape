// gcd - O(log N) , N=max(a,b)
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,a,b;

int gcd(int a,int b)
{
     if(!b)return a;
     return gcd(b , a % b);
}

int main()
{
     f>>t;
     for(int i=1;i<=t;++i)
        f>>a>>b , g << gcd(a,b) << '\n' ;
     f.close();g.close();
     return 0;
}
