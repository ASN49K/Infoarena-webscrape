#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n1,n2,l,a[1025][1025],v[1025],s1[1025],s2[1025];

void sir ()
{
	int i,j;
	l=0;
	for(i=1;i<=n1;i++)
		for(j=1;j<=n2;j++)
		{
			if(s1[i]==s2[j])
				a[i][j]=1+a[i-1][j-1];
			else
			{
				if(a[i][j-1]>=a[i-1][j])
					a[i][j]=a[i][j-1];
				else
					a[i][j]=a[i-1][j];
			}
		}
    l=0;
    i=n1;
    j=n2;
    while(i!=0)
    {
        if(s1[i]==s2[j])
        {
            l++;
            v[l]=s1[i];
            i--;
            j--;
        }
        else if(a[i-1][j]<a[i][j-1])
            j--;
        else
            i--;
    }
}

int main ()
{
	f>>n1;
	f>>n2;
	for(int i=1;i<=n1;i++)
        f>>s1[i];
    for(int i=1;i<=n2;i++)
        f>>s2[i];
	sir();
	g<<l<<"\n";
	for(int i=l;i>=1;i--)
		g<<v[i]<<" ";
	f.close();g.close();
	return 0;
}
