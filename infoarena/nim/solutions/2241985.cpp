#include <bits/stdc++.h>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int m,n;
int main()
{
    f>>m;
    for(int i=1;i<=m;i++){
        f>>n;
        int xitem,a;
        f>>xitem;
        for(int j=2;j<=n;j++){
            f>>a;
            xitem= (xitem^a);
        }
        if(xitem)g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
