#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int m,n;
    fin>>m>>n;

    vector<int> A(m),B(n);
    vector< vector<int> > d(m+1,vector<int> (n+1,0));

    for(int i=0;i<m;++i) fin>>A[i];
    for(int i=0;i<n;++i) fin>>B[i];

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            d[i][j] = max(d[i-1][j],d[i][j-1]);
            if(A[i-1]==B[j-1]){
                d[i][j] = max(d[i][j],1+d[i-1][j-1]);
            }
        }
    }

    fout<<d[m][n]<<'\n';

    stack<int> st;
    int ia=m,ib=n;

    while(ia || ib){
        if(ia && d[ia][ib] == d[ia-1][ib]) --ia;
        else if(ib && d[ia][ib] == d[ia][ib-1]) --ib;
        else{
            st.push(A[ia-1]);
            --ia; --ib;
        }
    }

    while(!st.empty()){
        fout<<st.top()<<' ';
        st.pop();
    }
    fout<<'\n';
}
