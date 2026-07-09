#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main(){
    int x, a,b,r;
    cin >> x;
    for(int i = 1; i <= x; i++){
        cin >> a >> b;
        while(b){
        r = a % b;
        a = b;
        b = r;
    }
    cout << a<< endl;
}

    return 0;
}
