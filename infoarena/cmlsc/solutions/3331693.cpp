#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream input ("cmlsc.in");
std::ofstream output ("cmlsc.out");

struct dp {
    int lcs;
    int startN;
    int endN;
    int startM;
    int endM;
};

int main () {

    int nLength, mLength;
    input >> nLength >> mLength;

    std::vector<int> nArray(nLength);
    for (int i = 0; i < nLength; i++) {
        input >> nArray[i];
    }

    std::vector<int> mArray(mLength);
    for (int i = 0; i < mLength; i++) {
        input >> mArray[i];
    }

    std::vector<std::vector<dp>> dpArr(nLength + 1, std::vector<dp>(mLength + 1, {0, -1, -1, -1, -1}));

    for (int i = 1; i <= nLength; i++) {
        for (int j = 1; j <= mLength; j++) {
            dpArr[i][j].lcs = std::max(dpArr[i][j-1].lcs, dpArr[i-1][j].lcs);
            if (dpArr[i][j-1].lcs > dpArr[i-1][j].lcs) {
                dpArr[i][j] = dpArr[i][j-1];
            }
            else {
                dpArr[i][j] = dpArr[i-1][j];
            }
            if (nArray[i-1] == mArray[j-1] && dpArr[i][j].lcs < dpArr[i-1][j-1].lcs + 1) {
                dpArr[i][j].lcs = dpArr[i-1][j-1].lcs + 1;
                if (dpArr[i][j].lcs == 1) {
                    dpArr[i][j].startN = i;
                    dpArr[i][j].endN = i;
                    dpArr[i][j].startM = j;
                    dpArr[i][j].endM = j;
                } else {
                    dpArr[i][j].startN = dpArr[i-1][j-1].startN;
                    dpArr[i][j].endN = i;
                    dpArr[i][j].startM = dpArr[i-1][j-1].startM;
                    dpArr[i][j].endM = j;
                }
            }
        }
    }

    output << dpArr[nLength][mLength].lcs << '\n';

    // Reconstruct one LCS by backtracking the dp array and output it
    int i = nLength, j = mLength;
    std::vector<int> lcsSeq;
    while (i > 0 && j > 0) {
        if (nArray[i-1] == mArray[j-1]) {
            lcsSeq.push_back(nArray[i-1]);
            --i; --j;
        } else if (dpArr[i-1][j].lcs >= dpArr[i][j-1].lcs) {
            --i;
        } else {
            --j;
        }
    }

    std::reverse(lcsSeq.begin(), lcsSeq.end());
    for (size_t k = 0; k < lcsSeq.size(); ++k) {
        output << lcsSeq[k];
        if (k + 1 < lcsSeq.size()) output << ' ';
    }

    return 0;
}