#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
stack<int> st;
long long int n, i, v[1025], e[1025], k, j, m, maxx1, maxx, c, a[1025][1025], poz;
long long int inf=INT_MIN;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++){fin>>v[i]; a[i][0]=0;}
    for(j=1; j<=m; j++){fin>>e[j];}
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(v[i]==e[j]){a[i][j]=a[i-1][j-1]+1;}
            else {
                a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    fout<<a[n][m]<<endl;
    i=n; j=m;
    while(i>0&&j>0){
        if(v[i]==e[j]){st.push(v[i]); i--; j--;}
        else{
            if(a[i-1][j]>a[i][j-1])i--;
            else j--;
        }
    }
    while(!st.empty()){
        fout<<st.top()<<' ';
        st.pop();
    }
}