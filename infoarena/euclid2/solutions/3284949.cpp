#include<bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n , x , y;

int main()
{
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> x >> y;
        while(y)
        {
            int r = x % y;
            x = y;
            y = r;
        }
        fout << x <<'\n';
    }
    return 0;
}
