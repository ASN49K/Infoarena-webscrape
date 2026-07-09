#include <fstream>
#include <string>
#include <vector>

using namespace std;


typedef unsigned short ushort;


string const inFile = "cmlsc.in";
string const outFile = "cmlsc.out";

ifstream Read(inFile);
ofstream Write(outFile);


void ReadInput(vector<ushort> &first, vector<ushort> &second) {
    unsigned m;
    Read >> m;

    unsigned n;
    Read >> n;

    first.resize(m);
    second.resize(n);

    ushort value;

    for (unsigned i = 0; i < m; ++i) {
        Read >> value;
        first[i] = value;
    }

    for (unsigned i = 0; i < n; ++i) {
        Read >> value;
        second[i] = value;
    }
}


void LCS(vector<ushort> &first, vector<ushort> &second, vector<vector<ushort>> &matrix) {
    unsigned i, j;

    for (i = 1; i <= first.size(); ++i)
    for (j = 1; j <= second.size(); ++j) {
        if (first[i - 1] == second[j - 1]) {
            matrix[i][j] = matrix[i - 1][j - 1] + 1;
        }
        else {
            matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
}


void PrintLCS(vector<ushort> &first, vector<ushort> &second, vector<vector<ushort>> &matrix) {
    vector<ushort> path;
    unsigned i = first.size();
    unsigned j = second.size();

    Write << matrix[i][j] << '\n';

    while (i > 0 && j > 0) {
        if (matrix[i][j] == matrix[i - 1][j]) {
            --i;
        }
        else if (matrix[i][j] == matrix[i][j - 1]) {
            --j;
        }
        else {
            path.push_back(first[i - 1]);

            --i;
            --j;
        }
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        Write << path[i] << ' ';
    }
}


void CloseFiles(ifstream &Read, ofstream &Write) {
    Read.close();
    Write.close();
}


int main() {
    vector<ushort> first;
    vector<ushort> second;

    ReadInput(first, second);

    vector<vector<ushort>> matrix(first.size() + 1, vector<ushort>(second.size() + 1, 0));

    LCS(first, second, matrix);

    PrintLCS(first, second, matrix);

    CloseFiles(Read, Write);

    return 0;
}
