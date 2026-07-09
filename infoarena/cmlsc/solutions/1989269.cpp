#include <bits/stdc++.h>

using namespace std;

int c[1024][1024]={};

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n,s=0;
    f>>m>>n;
    vector <int> a(m);
    vector <int> b(n);
    vector <int> v(0);
    for (int i=0;i<m;++i) f>>a[i];
    for (int i=0;i<n;++i) f>>b[i];
    for (int i=0;i<m;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (a[i]==b[j])
            {
                s++;
                c[i][j]=1;
                v.push_back(a[i]);
                break;
            }
        }
    }
    g<<s<<endl;
    for (int i=0;i<v.size();++i) g<<v[i]<<" ";
    return 0;
}
