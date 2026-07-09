#include <fstream>
using namespace std;

const int N=1025;
int v[N][N],a[N],b[N];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

inline int min(int a,int b)
{
    return a<b ? a : b;
}

void cmlsc()
{
    for (int i=1;i<=a[0];i++)
        for (int j=1;j<=b[0];j++)
            if (a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
}

void print(int x,int y)
{
    if (!v[x][y])
        return;
    if (a[x]==b[y])
    {
        print(x-1,y-1);
        out<<a[x]<<" ";
        return;
    }
    if (v[x][y]==v[x-1][y])
        print(x-1,y);
    else
        print(x,y-1);

}

int main()
{
    in>>a[0]>>b[0];
    for (int i=1;i<=a[0];i++)
        in>>a[i];
    for (int i=1;i<=b[0];i++)
        in>>b[i];
    cmlsc();
    out<<v[a[0]][b[0]]<<"\n";
    print(a[0],b[0]);
    out<<"\n";
    return 0;
}
