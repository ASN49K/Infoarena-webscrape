#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int vec1[1025];
int vec2[1025];
int aux[1025], bottom, top;
bool succesor[1025];
int best, sol[1025];
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++) fin>>vec1[i];
    for(int i=1; i<=m; i++) fin>>vec2[i];
    while(!succesor[0])
    {
        int i=n;
        while(succesor[i])  succesor[i--]=0;
        succesor[i]=1;
        bottom=1;
        top=0;
        for(int i=1; i<=n; i++)
            if(succesor[i])
            {
                aux[++top]=vec1[i];
            }
        for(int i=1; i<=m && bottom<=top; i++)
            if(vec2[i]==aux[bottom])    bottom++;
        if(bottom>top)
        {
            bottom=1;
            if(top-bottom+1>best)
            {
                best=top-bottom+1;
                for(int i=1; i<=top; i++)   sol[i]=aux[i];
            }
        }
    }
    fout<<best<<'\n';
    for(int i=1; i<=best; i++)  fout<<sol[i]<<' ';
    return 0;
}
