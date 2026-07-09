#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, m, length, matrix[1025][1025], vect_a[1025], vect_b[1025], sir[1025];

	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");

	in >> n >> m;

	for (int i = 0; i <= n; i++)	// zerorizam matricea de lucru
	for (int j = 0; j <= m; j++)
		matrix[i][j] = 0;

	for (int i = 1; i <= n; i++)	// citim elemetele primului vector
		in >> vect_a[i];

	for (int j = 1; j <= m; j++)	// citim elemetele celui de-al doilea vector
		in >> vect_b[j];

	for (int i = 1; i <= n; i++)	// parcurgem fiecare element din fiecare vector
	for (int j = 1; j <= m; j++)
	{
		if (vect_a[i] == vect_b[j])						// daca elementele sunt egale atunci lungimea sirului creste cu +1 de la lungimea celui dinainte lui
			matrix[i][j] = matrix[i - 1][j - 1] + 1;
		else
		if (matrix[i - 1][j] > matrix[i][j - 1])	// daca sunt diferite se alege lungimea cea mai mare dintre elementele determinate inainte (lungimea maxima se propaga)
			matrix[i][j] = matrix[i - 1][j];
		else
			matrix[i][j] = matrix[i][j - 1];
	}

	out << matrix[n][m] << "\n";
	
	length = 0;
	for (int i = n, j = m; j; )
	if (vect_a[i] == vect_b[j])
	{
		sir[++length] = vect_a[i];
		--i;  --j;
	}
	else
	if (matrix[i - 1][j] < matrix[i][j - 1])
		--j;
	else
		--i;

	for (int i = length; i > 0; i--)
		out << sir[i] << " ";

	return 0;
}