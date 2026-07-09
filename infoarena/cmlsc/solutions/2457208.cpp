#include <fstream>
#include <stack>
#define x first
#define y second
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,C[1040][1040],A[1040],B[1040];
void scan();
stack <int> st;
pair <int, int> urm[1040][1040];
int main()
{
    scan();

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
             C[i][j]=max(C[i-1][j],max(C[i][j-1],C[i-1][j-1]+(A[i]==B[j])));
             if(max(C[i-1][j],max(C[i][j-1],C[i-1][j-1]+(A[i]==B[j])))==C[i-1][j-1]+(A[i]==B[j]))
                urm[i][j].x=i-1, urm[i][j].y=j-1;
             else if(C[i-1][j]>C[i][j-1])
                urm[i][j].x=i-1, urm[i][j].y=j;
             else urm[i][j].x=i, urm[i][j].y=j-1;
        }

    cout<<C[n][m]<<'\n';
    int i=n, j=m, l=0;
    while(i && j)
    {
        if(A[i]==B[j])
            st.push(A[i]);
        l=i;
        i=urm[i][j].x;
        j=urm[l][j].y;
    }

    while(!st.empty())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<'\n';
    return 0;
}

void scan()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        cin>>A[i];
    for(int j=1; j<=m; ++j)
        cin>>B[j];
}
