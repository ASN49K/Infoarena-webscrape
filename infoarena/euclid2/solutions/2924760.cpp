//
//  main.cpp
//  Proiect_oregatire
//
//  Created by Steve Warlock on 05.10.2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cmath>
#define ll long long
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
ll n,m;
int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    return cmmdc(b,a%b);
}
void solve()
{
    fin >> n;
    fin >> m;
    fout << cmmdc(n, m) << '\n';
}
int main() {
 
    fin >> t;
    while(t--)
    {
        solve();
    }
    fin.close(),fout.close();
    return 0;
}
