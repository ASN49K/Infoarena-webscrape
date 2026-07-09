#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

//http://www.infoarena.ro/problema/cmlsc

const char* inFile = "cmlsc.in";
const char* outFile = "cmlsc.out";

void read_partial_solutions_matrix(
	unsigned short int* matrix,
	const std::vector<unsigned char>& first,
	const std::vector<unsigned char>& second,
	size_t first_index, size_t second_index,
	std::vector<unsigned char>& solution)
{
	auto mat = [matrix, &second](size_t i, size_t j) -> unsigned short int
	{
		if (-1 == i || -1 == j) return 0;
		return matrix[i * second.size() + j];
	};

	if (-1 == first_index || -1 == second_index)
	{
		return;
	}

	if (first[first_index] == second[second_index])
	{
		read_partial_solutions_matrix(matrix, first, second, first_index - 1, second_index - 1, solution);
		solution.push_back(first[first_index]);
		return;
	}

	if (mat(first_index, second_index - 1) > mat(first_index - 1, second_index))
	{
		read_partial_solutions_matrix(matrix, first, second, first_index, second_index - 1, solution);
		return;
	}

	read_partial_solutions_matrix(matrix, first, second, first_index - 1, second_index, solution);
}

std::vector<unsigned char> compute_max_substring(const std::vector<unsigned char>& first, const std::vector<unsigned char>& second)
{
	if (first.empty() || second.empty()) return {};

	unsigned short int* matrix = new unsigned short int[first.size() * second.size()];
	
	auto mat = [matrix, &second](size_t i, size_t j) -> unsigned short int&
	{
		return matrix[i * second.size() + j];
	};

	for (size_t i = 0; i < first.size(); ++i)
	{
		for (size_t j = 0; j < second.size(); ++j)
		{
			if (first[i] == second[j])
			{
				unsigned short int upperLeft = (i == 0 || j == 0) ? 0 : mat(i - 1, j - 1);
				mat(i, j) = upperLeft + 1;
			}
			else
			{
				unsigned short int left = (j == 0) ? 0 : mat(i, j - 1);
				unsigned short int up = (i == 0) ? 0 : mat(i - 1, j);

				mat(i, j) = std::max(left, up);
			}
		}
	}

	std::vector<unsigned char> solution;
	read_partial_solutions_matrix(matrix, first, second, first.size() - 1, second.size() - 1, solution);
	return solution;
}

int main()
{
	unsigned firstVecSize = 0;
	unsigned secondVecSize = 0;

	std::ifstream readFile(inFile);
	if (!readFile) return -1;

	readFile >> firstVecSize >> secondVecSize;

	std::vector<unsigned char> vFirst(firstVecSize);
	std::vector<unsigned char> vSecond(secondVecSize);

	for (auto& e : vFirst)
	{
		int i;
		readFile >> i;
		e = i;
	}

	for (auto& e : vSecond)
	{
		int i;
		readFile >> i;
		e = i;
	}

	auto substring = compute_max_substring(vFirst, vSecond);

	{
		std::ofstream writeFile(outFile);
		writeFile << substring.size() << "\n";
		for (auto s : substring)
		{
			writeFile << static_cast<int>(s) << " ";
		}
	}

	return 0;
}

