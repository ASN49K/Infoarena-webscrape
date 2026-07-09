#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define lop(x,n) for(int x = 1; x <= n; ++x)
#define loop(x,st,n) for(int x = st; x <= n; ++x)

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.in");

int main()
{
    int t;
    fin >> t;
    int a,b;
    lop(i,t){
        fin >> a >> b;
        fout << __gcd(a,b)__ << "\n";
    }

}
