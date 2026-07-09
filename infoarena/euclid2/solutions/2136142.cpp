#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x, int y){
    int mn,mx;
    mn = min(x,y);
    mx = max(x,y);
    while (mn!=mx){
        mx = mx-mn;
        int f = mn;
        mn = min(mn,mx);
        mx = max(f,mx);
    }
    return mx;
}

int a,b,m;

int main()
{
    in >> m;
    for (int i =1; i<=m; i++){
        in >> a >> b;
        out << euclid(a,b) << endl;
    }
    return 0;
}
