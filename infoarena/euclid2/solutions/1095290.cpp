// Cmmdc - functoa gcd - alternativa __gcd() din STl
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in"); ofstream g("euclid2.out");

int T,A,B;


int gcd(int x,int y)
{
     if(!y)return x;
     return gcd(y , x % y);
}

int main()
{
     f>>T;
     for(int i=1;i<=T;++i)f>>A>>B , g<<gcd(A,B)<<'\n';
     f.close();g.close();
     return 0;
}
