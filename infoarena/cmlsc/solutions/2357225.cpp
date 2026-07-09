#include <iostream>
#include <fstream>
using namespace std;

int lm,a[1001],b[1001],c[500],d[500],n,m;

int main(){
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f >>n>>m;
    for(int i = 1; i<=n; ++i)
        f>>a[i], c[a[i]]++;
    for(int j = 1; j<=m; ++j)
        f>>b[j], d[b[j]]++;
    for(int i = 1; i<=256; ++i)
        if(c[i] == d[i])
            lm+=c[i];
        else if(c[i]>d[i])
            lm+=d[i];
        else lm+=c[i];
        g<<lm<<endl;
        for(int i = 1; i<=256; ++i)
            if(c[i]==d[i])
                while(c[i])g<<i<<" ",c[i]--;
            else if(c[i]>d[i])
                    while(d[i])g<<i<<" ",d[i]--;
            else while(c[i])g<<i<<" ",c[i]--;

return 0;}
