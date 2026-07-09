#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[1025], b[1025], i, j, mat[1025][1025], sol[1025], sol_len;

void read_data() {
	f >> n >> m;
	for (i = 1; i <= n; i++) {
		f >> a[i];
	}
	for (j = 1; j <= m; j++) {
		f >> b[j];
	}
}

void create_matrix() {
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				mat[i][j] = mat[i - 1][j - 1] + 1;
			}
			else {
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
			}
		}
	}
}

void generate_solution() {
	i = n;
	j = m;
	while (j >= 1 && i >= 1) {
		while (mat[i][j] == mat[i - 1][j]) {
			i--;
		}
		while (mat[i][j] == mat[i][j - 1]) {
			j--;
		}
		sol_len++;
		sol[sol_len] = i;
		i--;
		j--;
	}
}

void write_solution() {
	g << sol_len << "\n";
	for (i = sol_len; i >= 1; i--) {
		g << a[sol[i]] << " ";
	}
}

int main() {
	read_data();
	create_matrix();
	generate_solution();
	write_solution();
	return 0;
}