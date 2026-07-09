#include <fstream>
#include <iostream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

unsigned char A[1024], B[1024], C[1024], sir[1024];
int M, N, i, P;

int subsir(int nr) // daca sir[1..nr] este subsir pentru B[1..N]
{
    int i, j = 0;

    for (i = 0; i < nr && j < N; i++)
        for (; j < N && B[j] != sir[i]; ++j);
    return j < N;
}

void back(int nivel, int len)
{
    int i;

    if (nivel == M)
    {
        if (subsir(len)) // daca sir este subsir si pentru B
            if (len > P)
            {
                P = len;
                for (i = 0; i < P; i++)
                    C[i] = sir[i];
            }

        return ;
    }

    // nu folosim A[nivel]
    back(nivel+1, len);
    // folosim A[nivel] in solutie
    sir[len] = A[nivel]; back(nivel+1, len+1);
}

int main()
{
    in>>M>>N;
	for (i=0; i<M; i++)
	{
		in>>A[i];
	}
	for (i=0; i<N; i++)
    {
        in>>B[i];
    }

    back(0,0);

    out<<P<<'\n';
    for(i=0; i<P; i++)
    {
       out<<C[i]<<" ";
    }
    out<<'\n';

	return 0;
}
