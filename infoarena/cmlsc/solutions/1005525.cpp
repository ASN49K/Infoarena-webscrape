#include <fstream>
#include <vector>

using namespace std;

int a[1025],b[1025],D[1025][1025],N,M;
vector <int> ans;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in>>N>>M;
    for(int i = 1;i <= N; ++i)
        in>>a[i];
    for(int i = 1;i <= M; ++i)
        in>>b[i];

    for(int i=1;i<=N;++i)
        for(int j = 1;j <= M;++j)
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    int i=N,j=M;
    while(i)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else
            D[ i - 1 ][ j ] < D[ i ][ j - 1 ] ? --j : --i ;

    }
    out<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;--i)
        out<<ans[i]<<" ";
    return 0;
}
