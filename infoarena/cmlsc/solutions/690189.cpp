#include<fstream>
#define f(i,a,b) for(i=a;i<=b;i++)
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
short x[1025], y[1025], mat[1025][1025];
short max(short a, short b)
{
	if(a>b)return a;
	return b;
}
void refac(int i, int j)
{
    if(i==0||j==0)return;
    if(x[i]==y[j])
    {
        refac(i-1, j-1);
        out<<x[i]<<" ";
        return;
    }
    if(mat[i-1][j]>mat[i][j-1])refac(i-1,j);
    else refac(i,j-1);
}
int main()
{
	short m,n,i,j;
	in>>m>>n;
	f(i,1,m)in>>x[i];
	f(i,1,n)in>>y[i];
	f(i,1,m)
		f(j,1,n)
			if(x[i]==y[j])mat[i][j]=1+mat[i-1][j-1];
			else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
	out<<mat[m][n]<<"\n";
	refac(m,n);
}