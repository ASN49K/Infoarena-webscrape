#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int n,t,a,b;
int main()
{
    for(F>>t;t--;G<<(b?"DA\n":"NU\n"))
        for(F>>n,b=0;n--;F>>a,b^=a);
    return 0;
}
