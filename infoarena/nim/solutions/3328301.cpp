#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <stack>
#include <cmath>
// #include <bits/stdc++.h>
#define in  fin
#define out fout

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

signed main(){
    ios_base::sync_with_stdio(false);
    in.tie(NULL);

    int t; in >> t;
    for(int ii = 0; ii < t; ii++){
        int n; in >> n;
        int xr = 0;
        for(int i = 0; i < n; i++){
            int x; in >> x;
            xr ^= x;
        }
        if(xr == 0) out << "NU\n";
        else out << "DA\n";
    }

    return 0;
}