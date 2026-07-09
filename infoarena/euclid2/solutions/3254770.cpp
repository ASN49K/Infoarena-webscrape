#include <bits/stdc++.h>
using namespace std;
int euclidGCD(int a,int b)
{
    while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    fin>>T;
    for(int i=0;i<T;++i)
    {
        int a,b;
        fin>>a>>b;
        fout<<euclidGCD(a,b)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
