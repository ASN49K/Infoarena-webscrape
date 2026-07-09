#include <bits/stdc++.h>
 
using namespace std;
 

 
int Euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    int t, a, b;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cout << Euclid(a, b) << "\n";
    }

}
 
