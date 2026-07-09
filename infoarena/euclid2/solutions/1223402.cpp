// #include <fstream>
// using namespace std;

// int gcd(int a, int b){
// 	if (!b) 
// 		return a;
// 	return gcd(b, a%b);
// }



// int main(){
// 	ifstream in("euclid2.in");
// 	ofstream out("euclid2.out");

// 	int n, a, b, cmmdc;
// 	in >> n;


// 	for (int i = 0; i < n; i++){
// 		in >> a;
// 		in >> b;
// 		cmmdc = gcd(a, b);
// 		out << cmmdc << endl;
// 	}

// 	in.close();
// 	out.close();

// 	return 0;
// }

#include<fstream>
using namespace std;

int main()
{
	ifstream in_file("euclid2.in");
	ofstream out_file("euclid2.out");
	unsigned number1, number2, pair_number, remainder;
	for (in_file >> pair_number; pair_number; --pair_number)
	{
		in_file >> number1 >> number2;
		while (number2)
		{
			remainder = number1 % number2;
			number1 = number2;
			number2 = remainder;
		}
		out_file << number1 << '\n';
	}
	return 0;
}