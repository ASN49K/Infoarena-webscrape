#include<fstream>
using namespace std;
ifstream F("euclid2.in");
ofstream G("euclid2.out");
int a,b,r,t;
int main()
{
    F>>t;
    while(t--) {
        F>>a>>b;
        for(;r=a%b;a=b,b=r);
        G<<b<<"\n";
    }
    return 0;
}
