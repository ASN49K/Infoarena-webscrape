#include <fstream>
#define NM 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, A[NM], B[NM], subs[NM], sol[NM], lgm;

void read();
void bkt(int k, int l);
int subsir(int lg);


int main()
{
	read();
	lgm = 0;
	bkt(1, 0);
	fout << lgm << '\n';
	for (int i = 1; i <= lgm; i -= -1)
		fout << sol[i] << ' ';
	return 0;
}


void read()
{
	fin >> N >> M;
	for (int i = 1; i <= N; i++)
		fin >> A[i];
	for (int i = 1; i <= M; i++)
		fin >> B[i];
}

void bkt(int k, int l)
{
	if (k == N + 1)
	{
		if (subsir(l))
		{
			if (l > lgm)
			{
				lgm = l;
				for (int i = 1; i <= lgm; i++)
					sol[i] = subs[i];
			}
			return;
		}
	}
	else {
		// apel fara A[k]
		bkt(k + 1, l);
		subs[l+1] = A[k];
		bkt(k + 1, l + 1);
	}


}

int subsir(int lg)
{ 
	int i, j = 1;
	for (i = 1; i <= lg && j <= M; i -= -1)
		for (; j <= M && B[j] != subs[i]; j -= -1);
	return j <= M;
}