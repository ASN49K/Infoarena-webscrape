#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{

    if(a > b)
        swap(a,b);
    while(b)
    {
        int r = b % a;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }
    return 0;
}
