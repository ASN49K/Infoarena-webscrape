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
    for(int i = 1, x, y; i <= n; i++){
        cin>> x >> y;
        while( y ){
            if(x > y)
                x -= y;
            else
                y -= x;
        }
        cout<< x << '\n';
    }
    return 0;
}
