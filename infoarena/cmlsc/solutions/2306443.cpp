#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int v1[1026],v2[1026],d[1025][1025],rez[1026];
int n1,n2,cnt;

int main()
{
    in>>n1>>n2;
    for (int i = 1;i <= n1;++i) in>>v1[i];
    for (int i = 1;i <= n2;++i) in>>v2[i];
    for (int i = 1;i <= n1;++i)
         for (int j = 1;j <= n2;++j)
              if (v1[i] == v2[j])
                 d[i][j] = 1 + d[i - 1][j - 1];
              else
                 d[i][j] = max(d[i - 1][j],d[i][j - 1]);
    for (int i = n1,j = n2;i,j;)
    {
        if (v1[i] == v2[j])
            {rez[++cnt] = v1[i];
            --i; --j;}
        else
            {if (d[i - 1][j] < d[i][j - 1])
                --j;
            else
                --i;}
    }
    out<<cnt<<"\n";
    for (int i = cnt;i;--i)
          out<<rez[i]<<" ";
    return 0;
}
