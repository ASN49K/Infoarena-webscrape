#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n , a , b;
void read(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        while (b){
            int r = a % b;
            a = b;
            b = r;
        }
        cout << a << '\n';
    }
}
void solve(){

}
int main(){
    read();
    solve();

    return 0;      
    
}