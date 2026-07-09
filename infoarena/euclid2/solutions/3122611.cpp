#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int idk(int n, int m){
    while(n != m)
    {
        if(n > m)
            n -= m;
    
        else
            m -= n;
        
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