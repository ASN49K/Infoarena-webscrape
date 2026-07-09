#include <fstream>
using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

void solve(){
    int n,rasp=0,i,a;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a;rasp^=a;
    }
    if(rasp==0) cout<<"NU\n";
    else cout<<"DA\n";
}

int main()
{
    int n;cin>>n;
    while(n){
        solve();n--;
    }
    return 0;
}
