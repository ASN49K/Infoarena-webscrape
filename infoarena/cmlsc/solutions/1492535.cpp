#include <fstream>
#include <vector>
using namespace std;
int x,y,i,j,len,z;
vector<int> a(1024);
vector<int> b(1024);
vector<int> d(1024);
int C[1024][1024];
int main()
{
    ifstream intrare ("cmlsc.in");
    ofstream iesire ("cmlsc.out");
    intrare>>x>>y;
    for (i=1; i<=x; i++)
    {
        intrare>>a[i];
    }
    for (i=1; i<=y; i++)
    {
        intrare>>b[i];
    }
    for (i=1;i<=x;i++)
        for (j=1;j<=y;j++)
        {
            if (a[i]==b[j]) C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=(C[i-1][j]>C[i][j-1] ? C[i-1][j]:C[i][j-1]);
        }
    len=C[x][y];
    iesire<<len<<endl;
    int k=0;
    while (k<len)
    {   for (i=x,j=y; i; )
		{
        if (a[i] == b[j])
		{d[++z] = a[i]; --i; --j; k++;}
        else if (C[i-1][j] < C[i][j-1])
            --j;
        else
            --i;
		}
    }
    for (i=z;i>=1;i--)
    {
        iesire<<d[i]<<" ";
    }
    return 0;
}
