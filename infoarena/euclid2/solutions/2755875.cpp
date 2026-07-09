#include <bits/stdc++.h>
using namespace std;

int eucl(int x, int y){
    int r;
    while(y){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T, x, y;
    fin >> T;
    for(;T;T--){
        fin >> x >> y;
        fout << eucl(x, y) << '\n';
    }

}
