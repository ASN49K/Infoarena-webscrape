#include <fstream>
#define NMAX 1025

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,i,mx,a[NMAX],b[NMAX],sol[NMAX],poz=1,j,loc,k;

void citire()
{ fin>>m>>n;
  for (i=1; i<=m; i++) fin>>a[i];
  for (i=1; i<=n; i++) fin>>b[i];
}

int solutie(int i, int j)
{ if (i==m+1 && j==n+1) return mx;
    else if (a[i]==b[j]) { mx++; sol[poz]=a[i]; poz++; solutie(i+1, j+1); }
	     else if (j==n) solutie(i+1,1);
		else solutie(i, j+1);


}


int main()
{
  citire();
  fout<<solutie(1,1)<<'\n';
  for (i=1; i<=mx; i++) fout<<sol[i]<<' ';
  fin.close();
  fout.close();
  return 0;

}