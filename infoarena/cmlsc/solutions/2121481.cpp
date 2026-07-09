#include <fstream>

#define MAX(a, b) (a > b) ? a : b

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

enum DIRECTION : unsigned char
{
	UP = 0U, LEFT, DIAG
};

int A[1024], B[1024], M[1024][1024], sir[1024];
int n, m, index;
unsigned char dir[1024][1024];

void Read()
{
	f >> n >> m;

	int i;

	for (i = 0; i < n; i++) 
		f >> A[i];

	for (i = 0; i < m; i++) 
		f >> B[i];
}

void Decide(int i, int j)
{
	if (A[i] == B[j])
	{
		if (i == 0 && j == 0) {
			M[i][j] = 1;
		}
		else if (i == 0 && j != 0) {
			M[i][j] = 1;
		}
		else if (i != 0 && j == 0) {
			M[i][j] = 1;
		}
		else {
			M[i][j] = 1 + M[i - 1][j - 1];
		}

		dir[i][j] = DIRECTION::DIAG;
	}
	else {
		if (i == 0 && j == 0) {
			M[i][j] = 0;
		}
		else if (i == 0 && j != 0) {
			M[i][j] = M[i][j - 1];
			dir[i][j] = DIRECTION::LEFT;
		}
		else if (i != 0 && j == 0) {
			M[i][j] = M[i - 1][j];
			dir[i][j] = DIRECTION::UP;
		}
		else {
			M[i][j] = MAX(M[i][j - 1], M[i - 1][j]);
			
			if (M[i][j - 1] > M[i - 1][j]) {
				dir[i][j] = DIRECTION::LEFT;
			}
			else {
				dir[i][j] = DIRECTION::UP;
			}
		}
	}
}

void Solve()
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			Decide(i, j);
		
	i = n - 1;
	j = m - 1;

	while(i >= 0 && j >= 0) { 
		if (A[i] == B[j]) {
			sir[index++] = A[i];
		}

		switch (dir[i][j])
		{
		case DIRECTION::DIAG: {
			--i;
			--j;
			break;
		}
		case DIRECTION::UP: {
			--i;
			break;
		}
		case DIRECTION::LEFT: {
			--j;
			break;
		}
		}
	}

	g << index << "\n";

	for (int k = index - 1; k >= 0; k--) {
		g << sir[k] << " ";
	}

	g << "\n";
}

int main()
{
	Read();
	Solve();

	return 0;
}