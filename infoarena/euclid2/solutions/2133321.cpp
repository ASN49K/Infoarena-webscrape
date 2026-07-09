#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{

    int n,a,b,i;

    fin >> n;
    for(i=1;i<=n;i++)
        {
        fin >>a >> b;
        fout << euclid(a,b) <<"\n";
        }

        return 0;
}
