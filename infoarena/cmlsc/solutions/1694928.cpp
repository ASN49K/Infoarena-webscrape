#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025];
int b[1025];

int mat[1025][1025];

stack <int> s;

int main()
{
    int n, m;

    fin >> n >> m;

    for(int i=1; i<=n; i++)
        fin >> a[i];

    for(int i=1; i<=m; i++)
        fin >> b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);

    int ct=0;

//    fout << "  ";
//
//    for(int i=1; i<=m; i++)
//        fout << b[i] << " ";
//
//    fout << '\n';
//
//    for(int i=1; i<=n; i++)
//    {
//        fout << a[i] << " ";
//        for(int j=1; j<=m; j++)
//            fout << mat[i][j] << " ";
//        fout << '\n';
//    }
//
//    fout << '\n';
//    fout << '\n';

    for(int i=n, j=m; i>0;)
    {
        if(a[i]==b[j])
        {
            s.push(a[i]);
            ct++;
            i--;
            j--;
        }
        else
        {
            if(mat[i-1][j]<mat[i][j-1])
                j--;
            else
                i--;
        }
    }

    fout << ct << '\n';

    while(!s.empty())
    {
        fout << s.top() << " ";
        s.pop();
    }
}
