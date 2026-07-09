#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

const int nmax=1035;

stack<int> st;
vector<int> a(nmax),b(nmax);
int d[nmax][nmax];

inline int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,i,j,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(i=1;i<=m;++i)
        scanf("%d",&b[i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    printf("%d\n",d[n][m]);
    for(i=n,j=m;j;)
        if(a[i]==b[j])
            st.push(a[i]),--i,--j;
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    while(!st.empty())
    {
        printf("%d ",st.top());
        st.pop();
    }
    return 0;
}
