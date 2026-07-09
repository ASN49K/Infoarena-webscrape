#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ifstream in_file("cmlsc.in");
	short length1, length2, *array1, *array2, **matrix;
	int i, j;
	in_file >> length1 >> length2;
	array1 = new short[length1];
	array2 = new short[length2];
	for (i = 0; i < length1; ++i)
		in_file >> array1[i];
	for (i = 0; i < length2; ++i)
		in_file >> array2[i];
	in_file.close();
	matrix = new short*[length1];
	for (i = 0; i < length1; ++i)
		matrix[i] = new short[length2];
	for (i = 0; i < length1; ++i)
		for (j = 0; j < length2; ++j)
			if (array1[i] == array2[j])
				matrix[i][j] = (i - 1 >= 0) && (j - 1 >= 0) ? matrix[i - 1][j - 1] + 1 : 1;
			else
				if (i - 1 >= 0)
					matrix[i][j] = j - 1 >= 0 ? max(matrix[i - 1][j], matrix[i][j - 1]) : matrix[i - 1][j];
				else
					matrix[i][j] = j - 1 >= 0 ? matrix[i][j - 1] : 0;
	vector<short> solution;
	i = length1 - 1;
	j = length2 - 1;
	while (i >= 0 && j >= 0)
		if (array1[i] == array2[j])
		{
		solution.push_back(array1[i]);
		--i;
		--j;
		}
		else
			if (i - 1 >= 0)
				if (j - 1 >= 0)
					if (matrix[i - 1][j] > matrix[i][j - 1])
						--i;
					else
						--j;
				else
					--i;
			else
				--j;
	delete[] array1;
	delete[] array2;
	for (int i = 0; i < length1; ++i)
		delete[] matrix[i];
	delete[] matrix;
	ofstream out_file("cmlsc.out");
	out_file << solution.size() << '\n';
	for (i = solution.size() - 1; i >= 0; --i)
		out_file << solution[i] << ' ';
	return 0;
}