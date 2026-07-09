// gcd - O(log N) , N=max(A,B)
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,A,B;

int gcd(int a,int b)
{
     if(!b)return a;
     return gcd(b , a % b);
}

int main()
{
     f>>T;
     for(int i=1;i<=T;++i)
        f>>A>>B , g << gcd(A,B) << '\n' ;
     f.close();g.close();
     return 0;
}
