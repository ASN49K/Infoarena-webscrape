#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

void solve() {

    int n, s = 0;
    cin>>n;
    
    for(int i = 1; i<=n; i++) {
        int x; cin>>x;
        s = s ^ x;
    }
    if(s)
        cout<<"DA\n";
    else
        cout<<"NU\n";   

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; 
    cin>>t;

    for(; t; t--) {
         solve();
    }

    return 0;
}