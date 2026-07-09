#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int la, lb, a[1024], b[1024], sub[1024], lsub=0;
    in>>la>>lb;
    for(int i=0; i<la; i++)
        in>>a[i];
    for(int i=0; i<lb; i++)
        in>>b[i];
    for(int i=0; i<la; i++)
        for(int j=0; j<lb; j++)
            if(a[i]==b[j])
                sub[lsub++]=a[i];
    out<<lsub<<'\n';
    for(int i=0; i<lsub; i++)
        out<<sub[i]<<' ';
    in.close();
    out.close();
    return 0;
}
