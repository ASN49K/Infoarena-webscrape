#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
inline int CMMDC(int x , int y)
{
    int r;
    while(y > 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main()
{
    int n , x , y;
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> x >> y;
        fout << CMMDC(x , y) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
