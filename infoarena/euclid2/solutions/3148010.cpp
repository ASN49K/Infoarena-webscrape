#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int a,b;
    fin>>a;
    while(fin>>a>>b){
        while(b!=0){
            int r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<'\n';
    }
    return 0;
}