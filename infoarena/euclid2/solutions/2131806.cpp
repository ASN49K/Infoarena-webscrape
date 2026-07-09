#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>> n;
    for(int i = 1, x, y, aux; i <= n; i++){
        cin>> x >> y;
        while( y ){
            aux = x;
            x = y;
            y = aux % y;
        }
        cout<< x << '\n';
    }
    return 0;
}
