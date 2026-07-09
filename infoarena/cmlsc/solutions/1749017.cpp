#include <fstream>
#include <vector>
#include <iostream>

int main()
{
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");
	int la, lb;
	std::vector<int> a, b;
	fin >> la >> lb;
	a.reserve(la);
	b.reserve(lb);
	for (int i = 0; i < la; ++i) {
		int x;
		fin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < lb; ++i) {
		int x;
		fin >> x;
		b.push_back(x);
	}

	std::vector<std::vector<int>> best;
	best.reserve(la);
	for (int i = 0; i < la; ++i) {
		std::vector<int> line;
		line.reserve(lb);
		for (int j = 0; j < lb; ++j) {
			int newbest = 0;
			if (a[i] == b[j]) {
				if (i != 0 && j != 0) {
					newbest = best[i - 1][j - 1] + 1;
				}
				else {
					newbest = 1;
				}
			}
			else {
				if (i != 0 ) {
					newbest = std::max(newbest, best[i - 1][j]);
				}
				if (j != 0) {
					newbest = std::max(newbest, line[j - 1]);
				}
			}
			line.push_back(newbest);
		}
		best.emplace_back(std::move(line));
	}
	int length = best[la - 1][lb - 1];
	fout << length << "\n";

	std::vector<int> solution;
	solution.reserve(length);
	int lastLine = la - 1;
	int lastColumn = lb - 1;
	for (int k = length; k > 0; --k) {
		while (a[lastLine] != b[lastColumn]) {
			if (lastLine == 0 || best[lastLine - 1][lastColumn] < k)
				break;
			else
				lastLine--;
		}
		while (a[lastLine] != b[lastColumn]) {
			if (lastColumn == 0 || best[lastLine][lastColumn - 1] < k)
				break;
			else
				lastColumn--;
		}
		solution.push_back(a[lastLine]);
		--lastLine, --lastColumn;
	}

	for (auto it = solution.rbegin(); it != solution.rend(); ++it) {
		fout << *it << " ";
	}

	fin.close();
	fout.close();
	return 0;
}