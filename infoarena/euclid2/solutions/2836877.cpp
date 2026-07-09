#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    int n,a,b;
    for (fin>>n; n; --n){
        fin>>a>>b;
        if (b>a){
            int c=a;
            a=b;
            b=c;
        }
        while (b){
            int c=a;
            a=b;
            b=c%b;
        }
    fout<<a<<'\n';
    }


}
