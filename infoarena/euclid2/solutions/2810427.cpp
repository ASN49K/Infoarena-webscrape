#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c;
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> a >> b;
        if(a < b)
            swap(a, b);
        while(b != 0){
            c = b;
            b = a % b;
            a = c;
        }
        fout << a << '\n';
    }
    return 0;
}