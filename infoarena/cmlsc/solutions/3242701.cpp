#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> buildSequence(const vector<vector<int>>& lengths, const vector<int>& A) {
    vector<int> sequence;
    int i = lengths.size() - 1;
    int j = lengths[0].size() - 1;

    while (i != 0 && j != 0) {
        if (lengths[i][j] == lengths[i - 1][j]) {
            i--;
        } else if (lengths[i][j] == lengths[i][j - 1]) {
            j--;
        } else {
            sequence.insert(sequence.begin(), A[j - 1]);
            i--;
            j--;
        }
    }

    return sequence;
}

vector<int> longestCommonSubsequence(const vector<int>& A, const vector<int>& B) {
    vector<vector<int>> lengths(B.size() + 1, vector<int>(A.size() + 1, 0));

    for (int i = 1; i <= B.size(); i++) {
        for (int j = 1; j <= A.size(); j++) {
            if (B[i - 1] == A[j - 1]) {
                lengths[i][j] = lengths[i - 1][j - 1] + 1;
            } else {
                lengths[i][j] = max(lengths[i][j - 1], lengths[i - 1][j]);
            }
        }
    }

    return buildSequence(lengths, A);
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int M, N;
    fin >> M >> N;

    vector<int> A(M), B(N);

    for (int i = 0; i < M; i++) {
        fin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        fin >> B[i];
    }

    vector<int> result = longestCommonSubsequence(A, B);

    fout << result.size() << endl;
    for (int num : result) {
        fout << num << " ";
    }
 

    return 0;
}

