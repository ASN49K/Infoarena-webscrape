#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    int T, x, y;
    fin >> T;
    for(int i=1;i<=T;i++){
        fin >> x >> y;
        while(y!=0){
            int r = x % y;
            x = y;
            y = r;
        }
    }
    fout << y << "\n";

    return 0;
}
