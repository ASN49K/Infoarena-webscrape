#include <iostream>
#include <fstream>
using namespace std;
ifstream f1("nim.in");
ofstream f2("nim.out");

int t,n, config[10005];

void solve(){
    int suma = 0;
    for(int i=0;i<n;i++){
        suma = suma ^ config[i];
    }
    if(suma == 0){
        f2<<"NU"<<"\n";
        return;
    }
    f2<<"DA"<<"\n";
}

int main() {
    f1>>t;
    for(int i=0;i<t;i++){
        f1>>n;
        for(int j=0;j<n;j++){
            f1>>config[j];
        }
        solve();
    }
    return 0;
}