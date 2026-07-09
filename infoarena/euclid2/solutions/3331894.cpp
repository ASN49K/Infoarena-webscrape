#include <bits/stdc++.h>
#define int long long
#define cin fin
#define cout fout
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    int r=0;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int32_t main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
    }
}
#include <bits/stdc++.h>
#define int long long
#define cin fin
#define cout fout
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    int r=0;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int32_t main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
    }
}
