#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

//http://www.infoarena.ro/problema/cmlsc

const char* inFile = "cmlsc.in";
const char* outFile = "cmlsc.out";

std::vector<int> compute_max_substring(std::vector<int>& first, std::vector<int>& second)
{
	if (first.empty() || second.empty()) return {};

	std::vector<int> prevRow(second.size());
	std::vector<int> currentRow(second.size());

	std::vector<std::vector<std::pair<int, int>>> partial_solutions;
	int best_partial_solution_index = -1;

	//std::ofstream txt("aa.txt");
	for (int i = 0; i < (int)first.size(); ++i)
	{
		//txt << "Line " << i << ": ";
		for (int j = 0; j < (int)second.size(); ++j)
		{
			auto left = j == 0 ? 0 : currentRow[j - 1];

			auto up = prevRow[j];

			if (left != up)
			{
				currentRow[j] = std::max(left, up);
				//txt << currentRow[j] << "  ";
			}
			else
			{
				if (first[i] == second[j])
				{
					if (0 == left)
					{
						partial_solutions.push_back({ {i, j} });

						//Update the best partial solution. A solution with only one element can be "best" only if it's the first.
						if (-1 == best_partial_solution_index) best_partial_solution_index = partial_solutions.size() - 1;
						
						currentRow[j] = 1;
						//txt << currentRow[j] << "! ";
					}
					else
					{
						bool foundAttach = false;
						// find a partial solution to which to attach this (i, j)
						for (int p = 0; p < (int)partial_solutions.size(); ++p)
						{
							if ((int)partial_solutions[p].size() < left) continue;

							// Check if the element can really be attached.
							auto prevAttach = partial_solutions[p][left - 1];
							if (prevAttach.first >= i || prevAttach.second >= j) continue;

							if (left == partial_solutions[p].size())
							{
								partial_solutions[p].push_back({ i, j });

								//Update the best partial solution.
								if (partial_solutions[best_partial_solution_index].size() < partial_solutions[p].size()) best_partial_solution_index = p;
							}
							else
							{
								// Splice partial solution.
								partial_solutions.push_back({});
								std::vector<int> new_partial_solution;
								std::copy(partial_solutions[p].begin(), partial_solutions[p].begin() + left, std::back_inserter(partial_solutions.back()));
								partial_solutions.back().push_back({ i, j });

								//The best partial solution doesn't change here. At most we are equalizing the best.
							}
							foundAttach = true;
							break;
						}
						currentRow[j] = foundAttach ? 1 + left : left;
						//txt << currentRow[j] << (foundAttach ? "!" : " ") << " ";
					}
				}
				else
				{
					currentRow[j] = left;
					//txt << currentRow[j] << "  ";
				}
			}
		}
		//txt << "\n";
		prevRow = std::move(currentRow);
		currentRow.resize(second.size());
	}

	std::vector<int> solution(partial_solutions[best_partial_solution_index].size());
	for (int i = 0; i < (int)partial_solutions[best_partial_solution_index].size(); ++i)
	{
		solution[i] = first[partial_solutions[best_partial_solution_index][i].first];
	}

	return solution;
}

int main()
{
	unsigned firstVecSize = 0;
	unsigned secondVecSize = 0;

	std::ifstream readFile(inFile);
	if (!readFile) return -1;

	readFile >> firstVecSize >> secondVecSize;

	std::vector<int> vFirst(firstVecSize);
	std::vector<int> vSecond(secondVecSize);

	for (auto& e : vFirst)
	{
		readFile >> e;
	}

	for (auto& e : vSecond)
	{
		readFile >> e;
	}

	auto substring = compute_max_substring(vFirst, vSecond);

	{
		std::ofstream writeFile(outFile);
		writeFile << substring.size() << "\n";
		for (auto s : substring)
		{
			writeFile << s << " ";
		}
	}

	return 0;
}

