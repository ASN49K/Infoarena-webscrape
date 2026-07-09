#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> find_longest_sustr(vector<int> v1, vector<int> v2, int pos1, int pos2, vector<int> sol) {
	//v1 < v2
	int l1 = v1.size(), l2 = v2.size();
	vector<int>::iterator it;
	vector<int> maxsol;


	if (pos1 == l1 || l2 == pos2)
		return sol;

	for (unsigned int i = pos1; i < v1.size(); i++) {
		it = find(v2.begin(), v2.end(), v1[i]);
		if (it !=  v2.end() && pos2 < it - v2.begin()) {
			sol.push_back(v1[i]);
			vector<int> m = find_longest_sustr(v1, v2, i + 1, it - v2.begin() + 1, sol);
			if (m.size() > maxsol.size()) {
				maxsol = m;
			}
			sol.erase(sol.end()-1);
		}
	}


	return maxsol;

}

int main(int argc, char const *argv[])
{
	ifstream inFile;
	inFile.open("cmlsc.in");
	ofstream outf("cmlsc.out");

	int nums, x, y;
	vector<int> v1, v2, sol;
	inFile >> x >> y;

	for (int i = 0; i < x; ++i) {
		inFile >> nums;
		v1.push_back(nums);
	}

	for (int i = 0; i < y; ++i) {
		inFile >> nums;
		v2.push_back(nums);
	}

	if (v1.size() < v2.size()) 
		sol = find_longest_sustr(v1, v2, 0, 0, sol);
	else
		sol = find_longest_sustr(v2, v1, 0, 0, sol);

	for (unsigned int i = 0; i < sol.size(); ++i) {
		outf << sol[i] << " ";
	}
	outf.close();
	inFile.close();
	return 0;
}