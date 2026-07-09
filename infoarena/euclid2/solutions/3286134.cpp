#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a , int b){
int r;
while(b){
    r = a % b;
    a = b;
    b = r;
}
return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("euclid2.in" , "r" , stdin);
    freopen("euclid2.out" , "w" , stdout);
    int t;
    cin >> t;
    while(t--){
        int x , y;
        cin >> x >> y;
        cout << cmmdc(x , y) << "\n";
    }
}
