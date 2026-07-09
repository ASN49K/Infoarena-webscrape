
#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[100001],b[100001],M[1025][1025];
stack<int> st;
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;++i){
        fin>>a[i];
    }
    for(int i=1;i<=m;++i){
        fin>>b[i];
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]){
                M[i][j]=M[i-1][j-1]+1;
            }else{
                M[i][j]=max(M[i-1][j],M[i][j-1]);
            }
        }
    }
    fout<<M[n][m]<<"\n";
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i]==b[j]){
            st.push(a[i]);
            i--;
            j--;
        }else{
            if(M[i-1][j]>M[i][j-1]){
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