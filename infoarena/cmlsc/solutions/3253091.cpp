    #include <cstring>
    #include <stack>
    #include <fstream>
    using namespace std;
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int lcs[1025], cnt=0;
    int C[1025][1025]={};
        int LCSLength(int x[],int y[], int n, int m) {
            for(int i=0;i<=n;i++)
                C[i][0]=0;
            for(int j=0;j<=m;j++)
                C[0][j]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(x[i]==y[j])
                        C[i][j]=C[i-1][j-1]+1;
                    else
                        C[i][j]=max(C[i-1][j],C[i][j-1]);
            return C[n][m];
        }
    void LCS(int x[],int y[], int i, int j ) {
        if(i==0 || j==0)
            return;
        if(x[i]==y[j]) {
            lcs[++cnt]=x[i];
            LCS(x, y, i - 1, j - 1);
        }
        else {
            if(C[i][j-1]>C[i-1][j])
                LCS(x,y,i,j-1);
            else
                LCS(x,y,i-1,j);
        }
    }
    int main() {
        int x[1025],y[1025],n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
            cin >> x[i];
        for(int i=1;i<=m;i++)
            cin >> y[i];
        cout<<LCSLength(x,y,n,m)<<endl;
        LCS(x,y,n,m);
        for(int i=cnt;i>=1;i--)
            cout<<lcs[i]<<" ";
    }
