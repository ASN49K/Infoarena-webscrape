#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

vector<vector<int>> DP(
        const vector<int>& A,
        const vector<int>& B) {
    vector<vector<int>> D(A.size() + 1, vector<int>(B.size() + 1, 0));
    int i = 1, j;
    for (int a : A) {
        j = 1;
        for (int b : B) {
            if (a == b) D[i][j] = 1 + D[i-1][j-1];
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
            j++;
        }
        i++;
    }
    return D;
}

vector<int> findLongestSubsequence(
        const vector<int>& A, const vector<int>& B,
        const vector<vector<int>>& D) {
    int i = A.size(), j = B.size();
    vector<int> sol;
    
    while (i && j) {
        if (A[i-1] == B[j-1]) sol.push_back(A[i-1]), i--, j--;
        else if (D[i-1][j] > D[i][j-1]) i--;
        else j--;
    }
    return sol;
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    
    int n, m; fin >> n >> m;
    
    vector<int> a, b;
    
    copy_n(istream_iterator<int>(fin), n, back_inserter(a));
    copy_n(istream_iterator<int>(fin), m, back_inserter(b));
    
    vector<vector<int>> D = DP(a, b);
    vector<int> subseq =  findLongestSubsequence(a, b, D);
    
    fout << D[a.size()][b.size()] << '\n';
    copy(subseq.rbegin(), subseq.rend(), ostream_iterator<int>(fout, " ")), fout << endl;  
    
    return 0;
}
