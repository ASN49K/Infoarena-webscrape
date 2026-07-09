#include <bits/stdc++.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

using namespace std;

int main()
{
    int t, a, b;
    fin >> t;
    
    for (int i = t; i >= 1; i--) 
    fin >> a >> b;
    
    if (a < b) swap(a, b);
    
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    
    }
    
    fout << a << endl;
    
    return 0;
}