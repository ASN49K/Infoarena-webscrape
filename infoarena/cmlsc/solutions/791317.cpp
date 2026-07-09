// Sorin Davidoi (<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="275448554e49094346514e43484e67404a464e4b0944484a">[email protected]</a>) - 2012-09-23 19:08
// http://infoarena.ro/problema/cmlsc
#include <fstream>
using namespace std;

const int MAXSIZE = 1024 + 1;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int first[MAXSIZE], second[MAXSIZE];
int map[MAXSIZE][MAXSIZE];

void backtrack(int row, int column) {
	if(!row || !column)	return;

	if(map[row][column] == map[row-1][column-1] + 1) {
		backtrack(row-1,column-1);
		out << second[column] << " ";
	}
	else
		if(map[row-1][column] > map[row][column])
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
				map[i][k] = map[i-1][k-1] + 1;
			else
				map[i][k] = max(map[i-1][k],map[i][k-1]);
		}

	/*for(int i = 1; i <= first[0]; ++i) {
		for(int k = 1; k <= second[0]; ++k)
			out << map[i][k] << " ";
		out << endl;
	}*/

	out << map[first[0]][second[0]] << '\n';

	backtrack(first[0],second[0]);

	in.close();
	out.close();

	return (0);
}
