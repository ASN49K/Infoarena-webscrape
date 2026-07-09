#include <fstream>
#include <vector>

using namespace std;

vector <short> l;

short a[1025],b[1025],M[1025][1025];
int n,m,i,j;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;

    for(i=1;i<=n;i++)
        f >> a[i];

    for(i=1;i<=m;i++)
        f >> b[i];

    for(i=1;i<=n;++i)
       for(j=1;j<=m;++j){
         if(a[i]!=b[j]) M[i][j] = max(M[i-1][j],M[i][j-1]);
         else M[i][j] = M[i-1][j-1] + 1;
    }

    g << M[n][m] << "\n";

    while(i!=0&&j!=0){
          if (a[i] == b[j])
            {l.push_back (a[i]); --i; --j;}
        else if (M[i-1][j] < M[i][j-1])
            --j;
        else
            --i;}

    for(i=l.size()-1;i>0;i--)
                g << l[i] << " ";

    return 0;
}
