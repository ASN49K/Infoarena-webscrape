// Sorin Davidoi (<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="087b677a6166266c697e616c6761486f65696164266b6765">[email protected]</a>) - 2012-09-23 17:35
// http://infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
	int tests,first,second;

	in >> tests;

	for(int i = 0; i < tests; i++) {
		in >> first >> second;
		
		while(second) {
			old_first = first;
			first = second;
			second = old_first % second;
		}

		out << first << '\n';
	}

	in.close();
	out.close();

	return (0);
}
