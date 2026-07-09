#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
long long n,t,i,j,x,sol;
int main() {
    cin>>t;
    for (i=1;i<=t;i++) {
        cin>>n; sol=0;
        for (j=1;j<=n;j++) {
            cin>>x;
            sol^=x;
        }
        if (sol==0)
            cout<<"NU\n";
        else
            cout<<"DA\n";
    }
    return 0;
}
