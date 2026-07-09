#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int algorrtim_euclid(int a, int b){
    if(!b)
        return a;
    algorrtim_euclid(b,a%b);
}
int t,a,b;
int main() {

    fin>>t;
    for(int i=1;i<=t;i++){
        fin>>a>>b;
        fout<<algorrtim_euclid(a,b)<<endl;
    }
}
