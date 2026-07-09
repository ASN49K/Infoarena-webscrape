#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x, int y){
    if (!y) return x;
    return euclid(y,x%y);
}

int a,b,m;

int main()
{
    in >> m;
    for (int i = 0; i<m; i++){
        in >> a >> b;
        out << euclid(a,b) << "\n";
    }
    return 0;
}
