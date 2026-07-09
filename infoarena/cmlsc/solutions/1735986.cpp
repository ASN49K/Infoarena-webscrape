#include <fstream>
#include <vector>
#include <algorithm>

//http://www.infoarena.ro/problema/cmlsc

const char* inFile = "cmlsc.in";
const char* outFile = "cmlsc.out";

std::vector<int> compute_max_substring(std::vector<int>& first, std::vector<int>& second)
{
    std::vector<int> result;
    if (first.empty() || second.empty()) return result;

    result.reserve(std::min(first.size(), second.size()) / 2);

    std::vector<int> prevRow(second.size());
    std::vector<int> currentRow(second.size());

    for (size_t i = 0; i < first.size(); ++i)
    {
        for (size_t j = 0; j < second.size(); ++j)
        {
            auto left = j == 0 ? 0 : currentRow[j - 1];

            auto up = prevRow[j];

            if (left != up)
            {
                currentRow[j] = std::max(left, up);
            }
            else
            {
                if (first[i] == second[j])
                {
                    auto newLength = left + 1;
                    currentRow[j] = newLength;

                    if (newLength > (int) result.size())
                    {
                        result.push_back(first[i]);
                    }
                }
                else
                {
                    currentRow[j] = left;
                }
            }
        }

        prevRow = std::move(currentRow);
        currentRow.resize(second.size());
    }

    return result;
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