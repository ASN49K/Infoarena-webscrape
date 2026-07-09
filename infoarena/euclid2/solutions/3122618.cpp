#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int idk(int n, int m){
    while (m != 0) {
        int pls = m;
        m = n % m;
        n = pls;
    }
    return n;


    
}

int main()
{int a,b,c;
fin >> c;

for(int i=1; i<=c;i++)
    {
        fin >> a >> b;
       int  result = idk(a, b);
        fout << result << endl;
    }


    return 0;
}

