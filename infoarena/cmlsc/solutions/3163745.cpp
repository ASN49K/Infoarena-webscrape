#include <fstream>
#include <iostream>
#include <utility>

using namespace std;
int a[1025];
int b[1025];
pair<int, string> result[1025][1025];
int subsequence[1025];

int main() 
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int sizeA, sizeB;
    fin >> sizeA >> sizeB;

    for (int i = 1; i <= sizeA; ++i) {
        fin >> a[i];
    }

    for (int j = 1; j <= sizeB; ++j) {
        fin >> b[j];
    }

    for (int j = 0; j <= sizeA; ++j) {
        result[0][j].first = 0;
    }

    for (int i = 0; i <= sizeB; ++i) {
        result[i][0].first = 0;
    }

    for (int i = 1; i <= sizeA; ++i) {
        for (int j = 1; j <= sizeB; ++j) {
            if (a[i] == b[j]) {
                result[i][j].first = result[i-1][j-1].first + 1;
                result[i][j].second = "up-left";
            } else {
                if (result[i - 1][j].first >= result[i][j - 1].first) {
                    result[i][j].first = result[i-1][j].first;
                    result[i][j].second = "up";
                } else {
                    result[i][j].first = result[i][j-1].first;
                    result[i][j].second = "left";
                }
            }
        }
        fout << "\n";
    }

    int i = sizeA, j = sizeB, sizeSubsequence = 1;
    while(j != 0 && i != 0) {
        if (result[i][j].second.compare("up") == 0) {
            i -= 1;
        }
        if (result[i][j].second.compare("left") == 0) {
            j -= 1;
        }
        if (result[i][j].second.compare("up-left") == 0) {
            subsequence[sizeSubsequence] = a[i];
            sizeSubsequence += 1;
            i -= 1;
            j -= 1;
        }
    }

    fout << result[sizeA][sizeB].first << "\n";
    for (int i = sizeSubsequence - 1; i >= 1; --i) {
        fout << subsequence[i] << " ";
    }

}