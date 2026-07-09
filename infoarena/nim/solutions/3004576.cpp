#include <fstream>
using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int t , n , x;

int main(){

    cin >> t;

    while(t--){

        cin >> n;

        int xorsum = 0;

        while(n--){

            cin >> x;

            xorsum^=x;
        }

        if(!xorsum) cout << "NU";
        else cout << "DA";

        cout << '\n';
    }

    return 0;
}
