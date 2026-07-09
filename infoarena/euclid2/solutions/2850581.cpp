#include <iostream>
#include <fstream>
using namespace std;
int n,a,b;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}
