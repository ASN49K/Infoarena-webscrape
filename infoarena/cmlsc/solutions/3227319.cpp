#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, a[1025], b[1025], dp[1025], l[1025];
unordered_map<int, int> um;
vector<int> sol;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

    if(m<n){
        swap(n, m);
        swap(a, b);
    }

    for(i=1;i<=m;i++){
        um[b[i]]=i;
    }

    for(i=1;i<=n;i++){
        if(um[a[i]]==0){
            dp[i]=0;
            l[i]=0;
            continue;
        }

        for(j=i-1;j>=1;j--){
            if(um[a[j]]<um[a[i]]){
                if(dp[j]>=dp[i]){
                    dp[i]=dp[j]+1;
                    l[i]=j;
                }
            }
        }
        if(dp[i]==0){
            dp[i]=1;
            l[i]=0;
        }
    }

    int MAX=0, poz;
    for(i=1;i<=n;i++){
        if(dp[i]>MAX){
            MAX=dp[i];
            poz=i;
        }
    }

    for(i=poz;i>0;){
        sol.push_back(a[i]);
        i=l[i];
    }

    fout<<MAX<<'\n';
    for(i=sol.size()-1;i>=0;i--){
        fout<<sol[i]<<" ";
    }




    return 0;
}
