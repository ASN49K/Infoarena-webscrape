#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const int NMAX = 100;
	int n, m, length, matrix[NMAX][NMAX], vect_a[NMAX], vect_b[NMAX], sir[NMAX];

	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");

	in >> m >> n;

	for (int i = 0; i <= m; i++)	// zerorizam matricea de lucru
	for (int j = 0; j <= n; j++)
		matrix[i][j] = 0;

	for (int i = 1; i <= m; i++)	// citim elemetele primului vector
		in >> vect_a[i];

	for (int j = 1; j <= n; j++)	// citim elemetele celui de-al doilea vector
		in >> vect_b[j];

	for (int i = 1; i <= m; i++)	// parcurgem fiecare element din fiecare vector
	for (int j = 1; j <= n; j++)
	{
		if (vect_a[i] == vect_b[j])						// daca elementele sunt egale atunci lungimea sirului creste cu +1 de la lungimea celui dinainte lui
			matrix[i][j] = matrix[i - 1][j - 1] + 1;
		else
		if (matrix[i - 1][j] > matrix[i][j - 1])	// daca sunt diferite se alege lungimea cea mai mare determinata anterior
			matrix[i][j] = matrix[i - 1][j];
		else
			matrix[i][j] = matrix[i][j - 1];
	}

	out << matrix[m][n] << "\n";
	
	length = 0;
	int i = m, j = n;

	while (i && j)									// adaugam in sir elemente pana cand cel putin unul se termina
	{
		if (vect_a[i] == vect_b[j])					// daca elementele sunt egale atunci adaugam elemetul respectiv
		{
			sir[length++] = vect_a[i--];
			j--;
		}
		else										// daca sunt diferite verificam dintre elementul anterior din vect_a si cel curent din vect_b si invers, iar din cel mai mare scadem o unitate
		if (matrix[i - 1][j] > matrix[i][j - 1])
			i--;
		else
			j--;
	}

	while (length)									// afisam sirul invers
		out << sir[--length] << " ";

	return 0;
}