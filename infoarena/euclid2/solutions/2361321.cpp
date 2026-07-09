#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n;

inline int CMMDC(int x , int y)
{
    if(!y)
        return x;
    return CMMDC(y , x % y);
}

int main()
{
    int x , y;
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
