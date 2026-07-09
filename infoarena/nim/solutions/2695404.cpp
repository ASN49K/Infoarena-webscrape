#include <fstream>
using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            cin >> x;
            sum = sum ^ x;
        }
        if(sum == 0){
            cout << "NU\n";
        }
        else{
            cout << "DA\n";
        }
    }
    return 0;
}
