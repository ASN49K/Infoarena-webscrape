#include <bits/stdc++.h>

using namespace std;
int n, a, b, r;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int i;
    fin >> n;
    for(i = 1; i <= n; ++i)
    {
        fin >> a >> b;
        while(b != 0)
        {
            r =  a % b;
            a = b;
            b = r;
        }
        fout << a <<"\n";
    }
    fout.close();
    fin.close();
    return 0;
}
