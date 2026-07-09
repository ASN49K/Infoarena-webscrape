#include<fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n, a, b;
    cin >> n;
    while(n){
        cin >> a >> b;
        n--;
        cout << cmmdc(a, b) << endl;
    }




}