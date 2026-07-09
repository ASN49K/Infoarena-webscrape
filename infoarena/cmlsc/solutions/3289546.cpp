#include <fstream>
#include <vector>

std::ifstream fin("Input.in");
std::ofstream fout("Output.out");

std::vector<int> LCS(std::vector<int> firstVector, std::vector<int> secondVector)
{
	std::vector<int> maxLength;
	std::vector<int> auxLength;
	int i = 0;

	loop:
	while (i < firstVector.size())
	{
		for (int j = 0 ; j < secondVector.size(); j++)
		{
			if (firstVector[i] == secondVector[j])
			{
				auxLength.push_back(firstVector[i]);
				i += 1;
				goto loop;
			}
		}

		i++;
	}
	
	if (auxLength.size() > maxLength.size())
	{
		maxLength = auxLength;
		auxLength.clear();
	}
	return maxLength;
}

int main() {
	std::vector<int> firstVector;
	std::vector<int> secondVector;

	int n, m;
	fin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		fin >> x;
		firstVector.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		int x;
		fin >> x;
		secondVector.push_back(x);
	}
	
	std::vector<int> result = LCS(firstVector, secondVector);
	fout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		fout << result[i] << " ";
	}
}