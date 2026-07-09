#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ifstream fout("euclid2.out");

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
    fout << mx;
    return 0;
}

int a,b,m;

int main()
{
    fin >> m;
    for (int i =1; i<=m; i++){
        fin >> a >> b;
        euclid(a,b);
    }
    return 0;
}
