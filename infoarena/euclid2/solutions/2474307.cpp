#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

#define cin fin
#define cout fout

int cazuri, a, b;

int cmmdc(int a, int b)
{
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main()
{
    cin >> cazuri;
    while(cazuri--)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << endl;
    }
}
