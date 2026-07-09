#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[100001],w[100001];
int a[1001][1001];
stack<int> st;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;++i){
        fin>>v[i];
    }
    for(int i=1;i<=m;++i){
        fin>>w[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(v[i]==w[j]){
                a[i][j]=a[i-1][j-1]+1;
            }else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    fout<<a[n][m]<<endl;
    int i=n,j=m;
    while(i>0 && j>0){
        if(v[i]==w[j]){
            st.push(v[i]);
            i--;j--;
        }else{
            if(a[i-1][j]>a[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    while(!st.empty()){
        fout<<st.top()<<" ";
        st.pop();
    }
   
   return 0;
}