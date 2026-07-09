#include<bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
#define cin fin
#define cout fout

#define N 100005
int n, t, x, y;

int main()
{
    cin >> t;
    for( ; t ; t--)
    {
        cin >> n;
        cin >> x;
        for(int i = 2 ; i <= n ; i++)
        {
            cin >> y;
            x ^= y;
        }
        if(x == 0)cout << "NU\n";
        else cout << "DA\n";
    }
    return 0;
}
