#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int t,n,i,j;
int main()
{
    for(F>>t;t--;G<<(j?"DA\n":"NU\n"))
        for(F>>n,j=0;n--;F>>i,j^=i);
    return 0;
}
