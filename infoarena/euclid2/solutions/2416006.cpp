#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n, x, y;
    fin >> n;
    while(n){
        fin >> x >> y;
        fout << euclid(x, y) << "\n";
        n--;
    }
    return 0;
}
