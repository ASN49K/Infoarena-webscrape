#include <fstream>
#include <vector>
#include <algorithm>

//http://www.infoarena.ro/problema/cmlsc

const char* inFile = "cmlsc.in";
const char* outFile = "cmlsc.out";

struct partial_result_node
{
	int i;
	int j;
	int len;
	partial_result_node* parent;
	partial_result_node(int ii, int jj, int llen, partial_result_node* p) : i(ii), j(jj), len(llen), parent(p)
	{
	}
};

std::vector<int> compute_max_substring(std::vector<int>& first, std::vector<int>& second)
{
	if (first.empty() || second.empty()) return std::vector<int>();

	std::vector<int> prevRow(second.size());
	std::vector<int> currentRow(second.size());


	std::vector<partial_result_node*> list_heads;

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
						// Memory leak.
						list_heads.push_back(new partial_result_node(i, j, 1, nullptr));
						currentRow[j] = 1;
						//txt << currentRow[j] << "! ";
					}
					else
					{
						// Check if a node exists to attach this one.
						int index_attach = -1;
						for (int l = 0; l < (int)list_heads.size(); ++l)
						{
							partial_result_node* curr = list_heads[l];
							while (nullptr != curr && (curr->i >= i || curr->j >= j || curr->len != left))
							{
								curr = curr->parent;
							}
							if (nullptr != curr)
							{
								// Another memory leak.
								auto new_partial_result_node = new partial_result_node(i, j, 1 + left, curr);
								index_attach = l;
								if (list_heads[l] == curr)
								{
									list_heads[l] = new_partial_result_node;
								}
								else
								{
									list_heads.push_back(new_partial_result_node);
								}
								break;
							}
						}
						currentRow[j] = (-1 != index_attach) ? 1 + left : left;
						//txt << currentRow[j] << ((-1 != index_attach) ? "!" : " ") << " ";
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
	int best_head = -1;
	int best_head_index = -1;
	for (int h = 0; h < (int)list_heads.size(); ++h)
	{
		if (best_head < list_heads[h]->len)
		{
			best_head = list_heads[h]->len;
			best_head_index = h;
		}
	}

	std::vector<int> solution(best_head);
	partial_result_node* current = list_heads[best_head_index];
	for (int i = solution.size() - 1; i >= 0; --i)
	{
		solution[i] = first[current->i];
		current = current->parent;
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

