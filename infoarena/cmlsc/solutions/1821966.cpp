#include <fstream>
using namespace std;
#define dim 10002
int n, m, A[dim], B[dim], L[dim][dim];
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
void Afiseaza(int i, int j)
{
	if ( i == 0  ||  j == 0 ) return;
	if ( A[i] == B[j] )
	{
		Afiseaza( i - 1, j - 1 );
		cout << A[i] << " ";
	}
	else
		if ( L[i-1][j] > L[i][j-1] ) Afiseaza( i - 1, j );
		else                         Afiseaza( i, j - 1 );
}
void SCMaximal()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> A[i];
    cin >> m;
    for (int j = 1; j <= m; j++)
        cin >> B[j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i] == B[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);

    cout << L[n][m] << '\n';
}
int main()
{
    SCMaximal();
    Afiseaza(n, m);
}

