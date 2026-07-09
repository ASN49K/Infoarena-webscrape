#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream gout("cmlsc.out");
int vm[1025],vn[1025],mat[1025][1025],MAX;

void cmlsc(int M, int N)
{


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
		{
			if (vn[i] == vm[j])
				mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
		}
	}
}

void trackback(int a, int b)
{
    if(mat[a][b]>mat[a-1][b]&&mat[a][b]>mat[a][b-1])
    {
        trackback(a-1,b-1);
        gout<<vn[a];
    }
    else if(mat[a][b]==mat[a-1][b])
        trackback(a-1,b);
    else if(mat[a][b]==mat[a][b-1])
        trackback(a,b-1);
}
int main()
{
    int M, N;
	fin >> M >> N;
   for (int i = 1; i <= M; i++)
		fin >> vm[i];
	for (int i = 1; i <= N; i++)
		fin >> vn[i];

    cmlsc(M,N);
    gout<<mat[N][M]<<endl;
    trackback(N,M);

    return 0;
}
