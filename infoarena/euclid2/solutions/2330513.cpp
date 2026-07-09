#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T , x , y;
int cmmdc(int a , int b)
{
    int r;
    while(b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> x >> y;
        cout << cmmdc(x , y) << "\n";
    }
    return 0;
}
