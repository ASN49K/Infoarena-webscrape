#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int n,t,a,b;
int main()
{
    for(F>>t;t--;G<<(a?"DA\n":"NU\n"))
        for(F>>n,a=0;n--;F>>b,a^=b);
    return 0;
}
