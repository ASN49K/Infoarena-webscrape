#include <fstream>

using namespace std;

uint16_t lcs[1025][1025];

uint8_t a[1025];
uint8_t b[1025];
uint8_t s[1025];

int main()
{
	ifstream ifs("cmlsc.in");
	ofstream ofs("cmlsc.out");

	int nn, mm;
	ifs >> nn >> mm;

	// read
	for (int ii = 1; ii <= nn; ++ii)
	{
		int x;
		ifs >> x;
		a[ii] = (uint8_t)x - 1;
	}
	for (int ii = 1; ii <= mm; ++ii)
	{
		int x;
		ifs >> x;
		b[ii] = (uint8_t)x - 1;
	}

	// init
	for (int ii = 0; ii <= nn; ++ii) lcs[ii][0] = 0;
	for (int ii = 1; ii <= mm; ++ii) lcs[0][ii] = 0;

	// calculate
	for (int ii = 1; ii <= nn; ++ii)
	{
		for (int jj = 1; jj <= mm; ++jj)
		{
			if (a[ii] == b[jj])
			{
				lcs[ii][jj] = lcs[ii - 1][jj - 1] + 1;
			}
			else
			{
				lcs[ii][jj] = max(lcs[ii][jj - 1], lcs[ii - 1][jj]);
			}
		}
	}

	// backtrack the solution
	for (int ii = nn, jj = mm, ll = lcs[nn][mm]; ll;)
	{
		if (a[ii] == b[jj])
		{
			s[ll] = a[ii];
			--ii;
			--jj;
			--ll;
		}
		else
		{
			if (lcs[ii][jj - 1] > lcs[ii - 1][jj])
			{
				--jj;
			}
			else
			{
				--ii;
			}
		}
	}

	// write
	ofs << lcs[nn][mm] << endl;
	for (int ii = 1; ii <= lcs[nn][mm]; ++ii)
	{
		ofs << (int)(s[ii] + 1) << " ";
	}

	return 0;
}