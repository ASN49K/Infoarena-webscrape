#include <fstream>
using namespace std;


int main(){
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t;
    cin >> t;
    while(t--){
        unsigned int a, b;
        cin >> a >> b;

        if(b > a){
            a ^= b;
            b ^= a;
            a ^= b;
        }
        while(a % b != 0){
            int aux = b;
            b = a%b;
            a = aux;
        }

        cout << b << '\n';
    }
    cin.close();
    cout.close();

    return 0;
}
