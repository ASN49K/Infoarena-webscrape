#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T;
    fin>>T;
    long long a, b;
    while(T)
    {
        fin>>a>>b;
        while(b)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
        T--;
    }

    return 0;
}
