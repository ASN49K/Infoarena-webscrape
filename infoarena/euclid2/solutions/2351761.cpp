#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned int n , a , b , c ;

int main()
{
    fin >> n ;
    for(int i=1; i<=n; i++)
    {
        fin >> a >> b ;
        while(b)
        {
            c = a % b ;
            a = b ;
            b = c ;
        }
        fout << a << "\n" ;
    }

    return 0;
}
