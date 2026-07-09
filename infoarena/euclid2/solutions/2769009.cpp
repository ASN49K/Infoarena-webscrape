#include <bits/stdc++.h>
 
 using namespace std;

int a, b, r, t;
 
int main()
{
    
   // freopen("euclid2.in", "r", stdin);
    // freopen("euclid2.out", "w", stdout);
    
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << "\n";
    }
   
}