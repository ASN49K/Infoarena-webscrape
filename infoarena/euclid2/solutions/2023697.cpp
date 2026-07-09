#include <fstream>
using namespace std;

int gcd(int a, int b){
    return (a == 0) ? b : gcd(b%a, a);
}

int main(){
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t, a, b;

    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }

    cin.close();
    cout.close();
    return 0;
}
