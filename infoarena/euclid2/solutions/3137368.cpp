#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a, b, n;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(a<b)
            {
                b=b-a;
                continue;
            }
            if(a>b)
            {
                a=a-b;
                continue;
            }
        }
        fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
