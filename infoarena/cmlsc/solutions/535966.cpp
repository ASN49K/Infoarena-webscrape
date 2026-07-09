// http://infoarena.ro/problema/cmlsc
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;

#define maxSize 1024

int matrix[maxSize][maxSize],array[maxSize],best;
list<int> solution;

struct {
	int lenght;
	int content[maxSize];
} first, second;

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
	int i,k;

	for(i=1;i<=first.lenght;i++)
		for(k=1;k<=second.lenght;k++)
			if(first.content[i] == second.content[k]) {
				matrix[i][k] = matrix[i-1][k-1] + 1;
				solution.push_back(first.content[i]);
				best++;
			}
			else
				matrix[i][k] = max(matrix[i-1][k],matrix[i][k-1]);

	/*for(i=first.lenght, k=second.lenght;i;)	// i si k nu merg declarate in for
		if(first.content[i] == second.content[k]) {
			array[++best] = first.content[i];
			
			i--;
			k--;
		}
		else
			if(matrix[i-1][k] < matrix[i][k-1])
				k--;
			else
				i--;*/
}

void write() {
	ofstream out("cmlsc.out");

	out << best << "\n";

	/*for(int i=best;i;i--)
		out << array[i] << " ";*/

	list<int>::iterator it;
	for(it=solution.begin();it!=solution.end();++it)
		out << *it << " ";

	out.close();
}
