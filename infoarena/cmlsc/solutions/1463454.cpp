#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// --- basics
#define int16 short
#define int32 int
#define int64 int long long
#define uint16 unsigned int16
#define	uint32 unsigned int32
#define uint64 unsigned int64

// --- prototypes
vector<uint16>* lcs(vector<uint16>* a, vector<uint16>* b);

/// --- input/output files
#define INPUT_FILE	"cmlsc.in"
#define	OUTPUT_FILE	"cmlsc.out"

int main()
{
	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);

	uint16 M, N;
	scanf("%hd %hd", &M, &N);
	
	vector<uint16> a, b;
	for (uint16 i = 0; i < M; i++)
	{
		uint16 x;
		scanf("%hd", &x);
		a.push_back(x);
	}
	for (uint16 i = 0; i < N; i++)
	{
		uint16 x;
		scanf("%hd", &x);
		b.push_back(x);
	}

	vector<uint16>* c = lcs(&a, &b);
	
	uint16 c_size = c->size();
	printf("%hd\n", c_size);
	for (uint16 i = 0; i < c_size; i++)
	{
		printf("%hd ", (*c)[i]);
	}

	delete(c);

	return 0;
}


// --- functions
vector<uint16>* lcs(vector<uint16>* a, vector<uint16>* b)
{
	uint16 size_a = a->size();
	uint16 size_b = b->size();

	uint16** matrix = new uint16*[size_a];
	for (uint16 i = 0; i < size_a; i++)
	{
		matrix[i] = new uint16[size_b];
	}

	for (uint16 i = 0; i < size_a; i++)
	{
		for (uint16 j = 0; j < size_b; j++)
		{
			if ((*a)[i] == (*b)[j])
			{
				if (i == 0 || j == 0)
				{
					matrix[i][j] = 1;
				}
				else
				{
					matrix[i][j] = matrix[i - 1][j - 1] + 1;
				}
			}
			else
			{
				uint16 max_value = 0;
				if (i != 0)
				{
					max_value = matrix[i - 1][j];
				}
				if ((j != 0) && (matrix[i][j - 1] > max_value))
				{
					max_value = matrix[i][j - 1];
				}

				matrix[i][j] = max_value;
			}
		}
	}


	vector<uint16>* result = new vector<uint16>();
	uint16 i = size_a - 1;
	uint16 j = size_b - 1;
	uint16 elements_to_be_added_to_result = matrix[i][j];

	while (elements_to_be_added_to_result != 0)
	{
		if ((*a)[i] == (*b)[j])
		{
			result->push_back((*a)[i]);
			i -= 1;
			j -= 1;
			elements_to_be_added_to_result -= 1;
		}
		else
		{
			uint16 max_value = 0;
			if (i != 0)
			{
				max_value = matrix[i - 1][j];
			}
			if ((j != 0) && (matrix[i][j - 1] > max_value))
			{
				max_value = matrix[i][j - 1];
			}

			if (i != 0 && max_value == matrix[i - 1][j])
			{
				i -= 1;
			}
			else
			{
				j -= 1;
			}
		}
	}

	for (uint16 i = 0; i < size_a; i++)
	{
		delete(matrix[i]);
	}
	delete(matrix);

	reverse(result->begin(), result->end());

	return result;
}











