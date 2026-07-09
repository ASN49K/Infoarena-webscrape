#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1024],b[1024],lcs[1024][1024],op[1024][1024];

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
				lcs[i][j]=1+lcs[i+1][j+1];
				op[i][j]=1;
			}
            else
			{

				if(lcs[i+1][j]>=lcs[i][j+1])
				{
					lcs[i][j]=lcs[i+1][j];
					op[i][j]=2;
				}
				else
					if(lcs[i+1][j]<lcs[i][j+1])
						{
						    lcs[i][j]=lcs[i][j+1];
                            op[i][j]=3;
						}
			}
}

void afisare()
{
	int i=0,j=0;
	fout<<lcs[0][0]<<'\n';
	while(i<n && j<m)
	if(op[i][j]==1)
	{
		fout<<a[i]<<' ';
		i++;
		j++;
	}
	else
	{
        if(op[i][j]==2)
			i++;
        else
            j++;
	}
}
