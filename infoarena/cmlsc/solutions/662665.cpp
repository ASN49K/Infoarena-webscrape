// http://infoarena.ro/problema/cmlsc
#include <fstream>
using namespace std;

#define MAXSIZE 1025

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int m,n;
int A[MAXSIZE],B[MAXSIZE],solution[MAXSIZE];
int best[MAXSIZE][MAXSIZE];

int main()
{
	in >> m >> n;

	for(int i=1;i<=m;i++)
		in >> A[i];

	for(int i=1;i<=n;i++)
		in >> B[i];

	in.close();

	for(int i=1;i<=m;i++)
		for(int k=1;k<=n;k++)
			if(A[i] == B[k])
				best[i][k] = best[i-1][k-1] + 1;
			else
				best[i][k] = max(best[i-1][k],best[i][k-1]);

	out << best[m][n] << "\n";

	// incepem de la ultima pozitie din matrice
	int row = m,column = n;

	// pana cand ajungem pe primul rand
	while(row)
		if(A[row] == B[column])
		{
			solution[++solution[0]] = A[row];
			row--; column--;	// deplasare pe diagonala
		}
		else
			// se deplaseaza unde este valoarea mai mare
			if(best[row][column-1] > best[row-1][column])
				column--;
			else
				row--;

	for(int i=solution[0];i!=0;i--)
		out << solution[i] << " ";
	out << "\n";

	out.close();

	return (0);
}
