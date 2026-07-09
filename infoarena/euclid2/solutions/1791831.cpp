#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int T, r;
    int a[100001];
    int b[100001];
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> T;
    for (int i = 0; i < T; i++){
        f >> a[i] >> b[i];
        r = a[i] % b[i];
        while(r){
            a[i] = b[i];
            b[i] = r;
            r = a[i] % b[i];
        }
        g << b[i] << "\n";
    }


    return 0;
}
