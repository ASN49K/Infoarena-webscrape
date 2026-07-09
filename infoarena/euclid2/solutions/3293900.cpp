#include<fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout("euclid2.out");
int v[1001];
int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i++){
        cin >> v[i];
    }   
    for(int i = 1; i <= n * 2; i += 2){
        cout << cmmdc(v[i], v[i + 1]) << endl;
    }



}