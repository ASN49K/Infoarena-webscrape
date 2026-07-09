#include<bits/stdc++.h>
using namespace std;

int Cmmdc(int a, int b)
{
    if (a == 0)
        return b;
    return Cmmdc(b % a, a);
}

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int a, b;
        cin >> a >> b;
        cout << Cmmdc(a, b) << '\n';
    }
}