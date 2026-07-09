#include<fstream>
#include<vector>
using namespace std;

const int N = 1025;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,x[N],y[N],rez[N][N];
vector<int> v;

int main() {
    int i,j;

    in >> n >> m;

    for(i=1;i<=n;++i)
        in >> x[i];
    for(j=1;j<=m;++j)
        in >> y[j];

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j) {

            if(x[i]==y[j])
                rez[i][j]=rez[i-1][j-1] + 1;
            else
                rez[i][j]=max(rez[i-1][j],rez[i][j-1]);
        }

    out << rez[n][m] << "\n";

    i=n; j=m;
    while(rez[i][j]!=0) {

        if(x[i]==y[j]) {
            v.push_back(x[i]);
            --i; --j;
        }
        else {
            if(rez[i-1][j]>rez[i][j-1])
                --i;
            else
                --j;
        }

    }

    for(i=v.size()-1;i>=0;--i)
        out << v[i] << " ";

    return 0;
}
