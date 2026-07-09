#include <iostream>
#include <fstream>
#include <algorithm>

#define INPUT_FILE "cmlsc.in"
#define OUTPUT_FILE "cmlsc.out"

std::fstream in(INPUT_FILE, std::fstream::in);
std::fstream out(OUTPUT_FILE, std::fstream::out);

using namespace std;

void print_v(vector<int> v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		cout << "v[" << i << "] = " << v[i] << "\n";
	}
}

vector<int> cmlsc(vector<int> a, vector<int> b) {
	unsigned int a_end = a.size();
	unsigned int b_end = b.size();
	unsigned int a_b_min = (a_end < b_end) ? a_end : b_end;
	print_v(a);
	print_v(b);
	cout << a_end << "\n";
	cout << b_end << "\n";

	int sol[a_end+1][b_end+1];
	int precomputed_solution[a_b_min];
	unsigned int ps_size = 0;
	for (unsigned int i = 0; i <= a_end; i++) {
		sol[i][0] = 0;
	}
	for (unsigned int j = 0; j <= b_end; j++) {
		sol[0][j] = 0;
	}
	for (unsigned int i = 1; i <= a_end; i++) {
		for (unsigned int j = 1; j <= b_end; j++) {
			if (a[i-1] == b[j-1]) {
				sol[i][j] = sol[i-1][j-1] + 1;
				precomputed_solution[ps_size] = a[i-1];
				ps_size++;
			} else {
				sol[i][j] = (sol[i][j-1] > sol[i-1][j]) ? sol[i][j-1] : sol[i-1][j];
			}
		}
	}

	for (unsigned int i = 0; i <= a_end; i++) {
		for (unsigned int j = 0; j <= b_end; j++) {
			cout << sol[i][j] << " ";
		}
		cout << "\n";
	}

	int solution_len = sol[a.size()][b.size()];
	cout << "Len is : " << solution_len << "\n";
	cout << "Alternate len is : " << ps_size << "\n";
	vector<int> solution(ps_size);
	for (unsigned int i = 0; i < ps_size; i++) {
		solution[i] = precomputed_solution[i];
	}
	print_v(solution);
	return solution;
}


int main(int argc, char const *argv[])
{
	int len_a, len_b;
	in >> len_a >> len_b;
	vector<int> a(len_a);
	vector<int> b(len_b);
	for (int i = 0; i < len_a; i++) {
		in >> a[i];
	}
	for (int i = 0; i < len_b; i++) {
		in >> b[i];
	}

	vector<int> result = cmlsc(a, b);
	out << result.size() << "\n";
	for (unsigned int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) {
			out << result[i];
		} else {
			out << result[i] << " ";
		}
	}
	out.close();
	in.close();
	return 0;
}