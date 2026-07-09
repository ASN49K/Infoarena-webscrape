#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int n;
    fin >> n;
    for(int i=1; i <= n; i++){
        int a, b;
        fin >> a >> b;
        if(a == 0 || b == 0) fout << max(a, b) << " \n";
        while(a != b){
            if(a > b) a -= b;
            else b -= a;
        }
        fout << a << "\n";
    }
}