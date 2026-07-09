#include <fstream>
#include <vector>

#define MAX 1030
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int sol[MAX];
int k;

inline void solution(vector<vector<int>>& A, int n) {
	for (int i = 0;i < n;i ++)
		if (sol[i] == 1)
			A[k].push_back(1);
		else
			A[k].push_back(0);
	k ++;
}
inline void reset() {
	for (int i = 0;i < 1030;i ++)
		sol[i] = 0;
	k = 0;
}
void backtracking(vector<vector<int>>& A, int k, int n) {
	if (k == n)
		solution(A, n);
	else {
		for (int i = 0;i < 2;i ++) {
			sol[k] = i;
			backtracking(A, k + 1, n);
		}
	}
}
inline vector<int> transformSetInVector(const vector<int>& set, int arr[]) {
	vector<int> toReturn;
	int len = set.size();
	for (int i = 0;i < len;i ++)
		if (set[i] == 1)
			toReturn.push_back(arr[i]);

	return toReturn;
}
inline vector<int> subArraysAreEqual(const vector<int>& A, const vector<int>& B,
		int a[], int b[]) {
	vector<int> temp1 = transformSetInVector(A, a);
	vector<int> temp2 = transformSetInVector(B, b);

	int len1 = temp1.size();
	int len2 = temp2.size();

	if (len1 != len2)
		return {};

	for (int i = 0;i < len1;i ++)
		if (temp1[i] != temp2[i])
			return {};
	return temp1;
}
vector<int> getSolution(const vector<vector<int>>& A, const vector<vector<int>>& B,
		int a[], int b[]) {
	vector<int> sol;
	int len1 = A.size();
	int len2 = B.size();
	for (int i = 0;i < len1;i ++)
		for (int j = 0;j < len2;j ++) {
			vector<int> temp = subArraysAreEqual(A[i], B[j], a, b);
			if (temp.size() > sol.size()) {
				sol = temp;
			}
		}
	return sol;
}
int main() {
	vector<vector<int>> A;
	vector<vector<int>> B;
	int a[MAX], b[MAX];

	int n, m;
	fin >> n >> m;

	for (int i = 0;i < n;i ++)
		fin >> a[i];
	for (int i = 0;i < m;i ++)
		fin >> b[i];

	A.resize(1 << n);
	B.resize(1 << m);

	backtracking(A, 0, n);
	reset();
	backtracking(B, 0, m);
	
	vector<int> sol = getSolution(A, B, a, b);

	int solutionLength = sol.size();

	fout << solutionLength << '\n';

	for (int i = 0;i < solutionLength;i ++)
		fout << sol[i] << ' ';
	return 0;
}