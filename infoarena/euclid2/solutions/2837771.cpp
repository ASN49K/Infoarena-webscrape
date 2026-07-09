#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int cm,int cn){

    int m = cm;
    int n = cn;
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main()
{
    unsigned int x, y, n;
    cin>>n;
    while(n!=0)
    {
        cin>>x>>y;
        fout<<cmmdc(x, y)<<endl;
        n--;
    }
    return 0;
}
