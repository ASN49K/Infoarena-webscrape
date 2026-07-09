#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,v[2000],w[1000],nr[300],t[10000],q;
int main()
{f>>n>>m;
 for(i=1;i<=n;i++) {f>>v[i];nr[v[i]]++;}
 for(i=1;i<=m;i++) {f>>w[i];
 if(nr[w[i]]>0){
q++;
   t[q]=w[i];
 }
 }
g<<q<<'\n';
for(i=1;i<=q;i++)g<<t[i]<<" ";

}
