#include <fstream>
#define NMAX 1025
#define maxim(x,y) ((x>y)?x:y)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[NMAX], b[NMAX], LCS[NMAX][NMAX], op[NMAX][NMAX];

void citire();
void pd();
void afisare();

int main()
{
    citire();
    pd();
    afisare();
    return 0;
}

void citire()
{
    int i, j;
    fin>>n>>m;
    for(i=0; i<=n-1; i++)
        fin>>a[i];
    for(j=0; j<=m-1; j++)
        fin>>b[j];
}

void pd()
{
    int i, j;
    for(i=n-1; i>=0; i--)
        for(j=m-1; j>=0; j--)
            {
                if(a[i]==b[j])
                    {
                        LCS[i][j]=1+LCS[i+1][j+1];
                        op[i][j]=1;
                    }
                else
                    {
                        LCS[i][j]=maxim(LCS[i+1][j], LCS[i][j+1]);
                        if(LCS[i][j]==LCS[i+1][j]) op[i][j]=2;
                        else
                            if(LCS[i][j]==LCS[i][j+1]) op[i][j]=3;
                    }
            }
}

void afisare()
{
    int i=0, j=0;
    fout<<LCS[0][0]<<'\n';
    while(i<n && j<m)
		if(op[i][j]==1)
		{
			fout<<a[i]<<' ';
			i++; j++;
		}
		else
			if(op[i][j]==2)
				i++;
			else
				if(op[i][j]==3)
					j++;
    fout.close();
}

