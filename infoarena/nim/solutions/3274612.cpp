#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main(){
    int T,n,i,x;
    fin>>T;
    while(T--){
        fin>>n;
        x=0;
        while(n--){
            fin>>i;
            x^=i;
        }
        if(x) fout<<"DA\n";
        else fout<<"NU\n";
    }
    return 0;
}
