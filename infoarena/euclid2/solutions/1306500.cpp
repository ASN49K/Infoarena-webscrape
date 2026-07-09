#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

ll a, b;
int t;

int euclid(ll a, ll b){
    if(b==0)    return a;
    else euclid(b, a%b);
}

int main(){
    fin >> t;
    for(int i=1; i<=t; i++){
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }

    return 0;
}
