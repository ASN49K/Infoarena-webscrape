#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    int t,a,b;
    fin >> t;
    for(int i = 1; i<=t; i++){
        fin >> a >> b;
        if(b > a) swap(a,b);
        int r = a%b;
        while(b != 0){ 
            r = a%b;
            a = b;
            b = r;
           
        }
        fout << a << '\n';
    }
}