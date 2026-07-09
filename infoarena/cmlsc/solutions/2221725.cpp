#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int size_first, size_second;

    vector<int> first;
    vector<int> second;

    ifstream input("cmlsc.in");
    ofstream output("cmlsc.out");

    input >> size_first >> size_second;

    for (int i = 0; i < size_first; i++) {
        int temp;
        input >> temp;
        first.push_back(temp);
    }

    for (int i = 0; i < size_second; i++) {
        int temp;
        input >> temp;
        second.push_back(temp);
    }

    int lcs[size_first + 1][size_second + 1];

    for (int i = 0; i <= size_first; i++) {
        for (int j = 0; j <= size_second; j++) {
            lcs[i][j] = 0;
        }
    }

    for (int i = 1; i <= size_first; i++) {
        for (int j = 1; j <= size_second; j++) {
            if (first[i - 1] == second[j - 1])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    output << lcs[size_first][size_second] << endl;

    int row = size_first;
    int column = size_second;
    vector<int> solution;

    while (row > 0 && column > 0) {
        if (first[row - 1] == second[column - 1]) {
            solution.push_back(first[row - 1]);
            row--;
            column--;
        } else if (lcs[row - 1][column] > lcs[row][column - 1]) {
            row--;
        } else {
            column--;
        }
    }

    for (int i = solution.size() - 1; i >= 0; i--) {
        output << solution[i] << " ";
    }

    input.close();
    output.close();

    return 0;
}