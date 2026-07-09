#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
int n,t,a,l;
int main()
{
    F>>t;
    while(t--) {
        F>>n,l=0;
        while(n--)
            F>>a,l^=a;
        G<<!l?"NU\n":"DA\n";
    }
    return 0;
}
