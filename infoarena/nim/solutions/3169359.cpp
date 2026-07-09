#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int t,n,i,o;
int main()
{
    for(F>>t;t--;G<<(o?"DA\n":"NU\n"))
        for(F>>n,o=0;n--;F>>i,o^=i);
    return 0;
}