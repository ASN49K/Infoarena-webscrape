#include <fstream>
#define maxim(x,y) ((x>y)?x:y)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1025],b[1025],lcs[1025][2025],op[1025][1025];

void citire();
void pd();
void afisare();

int main()
{
    citire();
    pd();
    afisare();
    fout.close();
    return 0;
}

void citire()
{
    int i,j;
    fin>>n>>m;
    for(i=0;i<n;i++)
        fin>>a[i];
    for(j=0;j<m;j++)
        fin>>b[j];
}

void pd()
{
    int i,j;
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
            if(a[i]==b[j])
            {
				lcs[i][j]==1+lcs[i+1][j+1];
				op[i][j]=1;
			}
            else
			{
				lcs[i][j]=maxim(lcs[i+1][j],lcs[i][j+1]);
				if(lcs[i+1][j>=lcs[i][j+1]])
					op[i][j]=2;
				else
					if(lcs[i+1][j]<lcs[i][j+1])
						op[i][j]=3;
			}
}

void afisare()
{
	int i,j;
	fout<<lcs[0][0]<<'\n';
	while(op[i][j]==1)
	{
		fout<<a[i]<<' ';
		i++;
		j++;
		if(op[i][j]==2)
			i++;
		if(op[i][j]==3)
			j++;
	}
}
