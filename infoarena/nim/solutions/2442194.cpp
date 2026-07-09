#include <fstream>
using namespace std;
int sumxor,N,t,a;
ifstream cin("nim.in");
ofstream cout("nim.out");

void solve(){
    sumxor=0;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>a;
        sumxor^=a;
    }
    if(sumxor)
        cout<<"DA\n";
    else
        cout<<"NU\n";
}


int main()
{
    cin>>t;
    for(int i=1; i<=t; i++)
        solve();
    return 0;
}
