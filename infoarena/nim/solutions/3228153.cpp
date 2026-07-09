#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int n,i,j;
int main()
{
    for(F>>n;F>>n;G<<(j?"DA\n":"NU\n"))
        for(j=0;n--;F>>i,j^=i);
    return 0;
}
