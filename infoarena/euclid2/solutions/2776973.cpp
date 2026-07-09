#include<bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
#define cin fin
#define cout fout

#define N 100005
int n, x, y;

int cmmdc(int a, int b)
{
    if(b == 0)return a;
    else return cmmdc(b,a%b);
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y;
        cout << cmmdc(x,y) << '\n';
    }
    return 0;
}
