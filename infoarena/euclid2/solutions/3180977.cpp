#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    fin >> n;
    
    while(n > 0)
    {
        fin >> a >> b;
        
        fout << __gcd(a, b) << '\n';
        
        n --;
    }
    
    return 0;
}