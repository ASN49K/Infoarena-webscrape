// http://infoarena.ro/problema/cmlsc
#include <fstream>
#include <algorithm>
using namespace std;

#define maxSize 1024

struct stuff {
	int lenght;
	int content[maxSize];
};

stuff first,second;
int best[maxSize][maxSize],
solution[maxSize],longest;

void read();
void solve();
void write();

int main() {
	read();
	solve();
	write();

	return (0);
}

void read() {
	ifstream in("cmlsc.in");

	in >> first.lenght >> second.lenght;

	for(int i=1;i<=first.lenght;i++)
		in >> first.content[i];

	for(int i=1;i<=second.lenght;i++)
		in >> second.content[i];

	in.close();
}

void solve() {
	int row,collumn;

	// matricea se completeaza element cu element
	for(row=1;row<=first.lenght;row++)
		for(collumn=1;collumn<=second.lenght;collumn++)
			if(first.content[row] == second.content[collumn])
				best[row][collumn] = best[row-1][collumn-1] + 1;
			else
				best[row][collumn] = max(best[row-1][collumn],best[row][collumn-1]);

	// se incepe de pe ultima pozitie din matrice
	row = first.lenght;
	collumn = second.lenght;

	while(row)	// pana se ajunge pe primul rand
		if(first.content[row] == second.content[collumn]) {
			solution[++longest] = first.content[row];
			
			// se face deplasarea pe diagonala
			row--;
			collumn--;
		}
		else
			if(best[row-1][collumn] < best[row][collumn-1])
				// deplasare pe coloana
				collumn--;
			else
				// deplasare pe rand
				row--;
}

void write() {
	ofstream out("cmlsc.out");

	out << longest << "\n";

	for(int i=longest;i;i--)
		out << solution[i] << " ";

	out.close();
}
