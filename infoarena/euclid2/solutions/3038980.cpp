#include <bits/stdc++.h>

using namespace std;
int q,a,b;
int main() {
    ofstream cout("euclid2.out");
    ifstream cin("euclid2.in");
    cin >> q;
    for(int i =1;i<=q;i++)
    {
        cin >> a >> b;
        int r = 0;
        while(b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }
}
