// Sorin Davidoi (<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="d5a6baa7bcbbfbb1b4a3bcb1babc95b2b8b4bcb9fbb6bab8">[email protected]</a>) - 2012-09-23 19:08
// http://infoarena.ro/problema/cmlsc
#include <fstream>
using namespace std;

const int MAXSIZE = 1024 + 1;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int first[MAXSIZE], second[MAXSIZE];
int best[MAXSIZE][MAXSIZE];

void backtrack(int row, int column) {
	if(!row || !column) return;

	if(first[row] == second[column]) {
		backtrack(row-1,column-1);
		out << first[row] << ' ';
	}
	else
		if(best[row-1][column] > best[row][column-1])
			backtrack(row-1,column);
		else
			backtrack(row,column-1);
}

int main() {
	in >> first[0] >> second[0];

	for(int i = 1; i <= first[0]; ++i)
		in >> first[i];

	for(int i = 1; i <= second[0]; ++i)
		in >> second[i];

	for(int i = 1; i <= first[0]; ++i)
		for(int k = 1; k <= second[0]; ++k) {
			if(first[i] == second[k])
				best[i][k] = best[i-1][k-1] + 1;
			else
				best[i][k] = max(best[i-1][k],best[i][k-1]);
		}

	/*for(int i = 1; i <= first[0]; ++i) {
		for(int k = 1; k <= second[0]; ++k)
			out << best[i][k] << " ";
		out << endl;
	}*/

	out << best[first[0]][second[0]] << '\n';

	backtrack(first[0],second[0]);

	in.close();
	out.close();

	return (0);
}
