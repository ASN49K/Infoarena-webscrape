#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");


void solve(){

    int n ; cin >> n;

    int ans = 0 , a;

    while(n--){

        cin >> a;

        ans ^= a;
    }

    if(ans) cout << "DA";
    else cout << "NU";

    cout << '\n';

}

int main()
{

    int t ; cin >> t;

    while(t--){

        solve();
    }


    return 0;
}
