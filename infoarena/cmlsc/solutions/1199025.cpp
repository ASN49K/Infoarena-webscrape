#include <fstream>
#include <cstring>

const int 	MAX_SIZE = 1025;
const int 	INFINITE = 257;
using namespace std;

int main()
{
	ifstream 	f("cmlsc.in");
	ofstream 	g("cmlsc.out");
	int 		A[MAX_SIZE], B[MAX_SIZE];
	int 		LEN[MAX_SIZE], PREV[MAX_SIZE], END[MAX_SIZE];
	int 		M, N;
	int 		BEST[MAX_SIZE];
	int 		maxLen, maxIdx;

	f >> M >> N;
	for (int i = 0; i < M; f >> A[i++]);
	for (int i = 0; i < N; f >> B[i++]);

	memset(LEN, 0, sizeof(LEN));
	memset(PREV, 0, sizeof(PREV));
	for (int i = 0; i < N; END[i++] = INFINITE);

	for (int i = 0; i < M; i++)
	{
		int prev = -1;
		int len  =  0;
		for (int j = 0; j < N; j++)
		{
			int origLen = LEN[j];

			if ( (A[i] == B[j]) && (len + 1 > LEN[j]) && (A[i] <= END[len + 1]) )
			{
				LEN[j]			= len + 1;
				PREV[j]			= prev;
				END[len + 1]	= A[i];
			}

			if (origLen > len)
			{
				len 	= origLen;
				prev 	= j;
			}
		}
	}

	maxIdx = maxLen = -1;
	for (int i = 0; i < N; i++)
	{
		if (LEN[i] > maxLen)
		{
			maxLen = LEN[i];
			maxIdx = i;
		}
	}

	for (int i = maxLen - 1; i >= 0; i--)
	{
		BEST[i] = B[maxIdx];
		maxIdx  = PREV[maxIdx];
	}

	g << maxLen << endl;
	for (int i = 0; i < maxLen; g << BEST[i++] << " ");

	return 0;
}
