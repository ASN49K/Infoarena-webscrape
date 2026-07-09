#include<fstream>
#include<algorithm>
using namespace std;
ifstream F("euclid2.in");
ofstream G("euclid2.out");
int a,b,t;
int main()
{
    for(F>>t;t;--t,F>>a>>b,G<<__gcd(a,b)<<'\n');
    return 0;
}
