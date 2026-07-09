#include <iostream>
#include <fstream>
#include <vector>;


int greatestCommonDivisor(const int& a, const int& b) {
    int maxValue{ std::max(a, b) };
    int minValue{ std::min(a, b) };
    int remainder{ maxValue % minValue };

    if (!remainder) {
        return minValue;
    }

    return greatestCommonDivisor(remainder, minValue);
}

int main()
{
    int numPairs{};
    std::vector<std::pair<int, int>> pairs;

    std::ifstream inFile{ "euclid2.in" };
    std::ofstream outFile{ "euclid2.out" };

    if (!outFile || !inFile) {
        return -1;
    }

    inFile >> numPairs;
    pairs.reserve(numPairs);

    for (int x1, x2; inFile >> x1 >> x2;) {
        pairs.push_back(std::make_pair(x1, x2));
    }

    for (const auto& pair : pairs) {
        outFile << greatestCommonDivisor(pair.first, pair.second) << '\n';
    }
}
