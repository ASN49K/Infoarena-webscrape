#include<fstream>
#include<stack>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
stack<int>st;
int mat[1030][1030],a[1030],b[1030],n,m,v[1030],k;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    cout<<mat[n][m]<<'\n';
    int cnt=mat[n][m];
    int i=n;
    int j=m;
    while(cnt)
    {
        if(a[i]==b[j])
        {
            st.push(b[j]);
            i--;
            j--;
            cnt--;
        }
        else if(mat[i-1][j]==mat[i][j])
            i--;
        else
            j--;
    }
    while(st.empty()==0)
    {
        cout<<st.top()<<' ';
        st.pop();
    }
}
