#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main(){
    int a, b, i, r;
    fin >> i;
    for(int j = 1; j <= i; j++){
        fin >> a >> b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout << a << '\n';
    }
    return 0;
}