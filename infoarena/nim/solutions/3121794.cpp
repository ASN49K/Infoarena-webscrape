#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int t,n,m,a;
int main()
{
    for(F>>t;t--;G<<(n?"DA\n":"NU\n"))
        for(n=0,F>>m;m--;F>>a,n^=a);
    return 0;
}
