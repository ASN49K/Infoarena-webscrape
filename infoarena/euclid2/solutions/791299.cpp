// Sorin Davidoi (<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="770418051e19591316011e13181e37101a161e1b5914181a">[email protected]</a>) - 2012-09-23 17:35
// http://infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
	int tests,old_first,first,second;

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
