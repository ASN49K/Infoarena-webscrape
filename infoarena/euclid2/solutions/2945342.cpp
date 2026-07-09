#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a , int b)
{
    int r;
    while(b != 0)
    {
        r = b % a;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int t , a , b;
    fin >> t;
    while(t --)
    {
        fin >> a >> b;
        fout << cmmdc(a , b) << "\n";
    }
    return 0;
}
/**
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 0 0 1 0 1 0 1 1 1  0  1   0 1   1
0 1 2 2 3 3 4 4 4 4  5  5   6 6   6
*/
