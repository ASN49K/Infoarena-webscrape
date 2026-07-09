#include <fstream>
#include <vector>
#include <algorithm>

//http://www.infoarena.ro/problema/cmlsc

const char* inFile = "cmlsc.in";
const char* outFile = "cmlsc.out";

std::vector<int> compute_max_substring(std::vector<int>& first, std::vector<int>& second)
{
    std::vector<std::vector<std::pair<int, int>>> partialResults;
    if (first.empty() || second.empty()) return std::vector<int>();

    std::vector<int> prevRow(second.size());
    std::vector<int> currentRow(second.size());

    for (int i = 0; i <  (int) first.size(); ++i)
    {
        for (int j = 0; j < (int) second.size(); ++j)
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
                    if (newLength == partialResults.size() + 1)
                    {
                        partialResults.emplace_back();
                    }
                    partialResults[newLength - 1].emplace_back(i, j);
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

    std::vector<int> substring;
    if (partialResults.empty()) return substring;

    substring.resize(partialResults.size());
    auto prevIJPair = partialResults.back().front();
    substring[partialResults.size() - 1] = first[prevIJPair.first];
    for (int i = (int)(partialResults.size()) - 2; i >= 0; --i)
    {
        for (auto& currentPair : partialResults[i])
        {
            if (currentPair.first < prevIJPair.first && currentPair.second < prevIJPair.second)
            {
                substring[i] = first[currentPair.first];
                prevIJPair = currentPair;
                break;
            }
        }
    }

    return substring;
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