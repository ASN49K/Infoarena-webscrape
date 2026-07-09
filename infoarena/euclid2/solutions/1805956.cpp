#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// ilyen egyebkent van mar a std konyvtarban std::pair neven
struct Pair
{
	int a, b;
};


int main()
{
	std::ifstream in_file("input.txt");
	std::ofstream out_file("output.txt");
	std::string   line;

	std::getline(in_file, line);

	int  num_pairs;

    num_pairs = std::stoi(line);
	int  counter   = 0;
	Pair pairs[num_pairs];


	while(std::getline(in_file, line)) {
		// csak c++11-tol mukodik, ha le akarod futtatni
		int a           = std::stoi(line);
		int space_index = line.find(' ');
		int b 			= std::stoi(line.substr(space_index));

		/* ez c++11 elott is jo es hatekonyabb, mert a pointer-t tolod el (majd elmondom):
		int a 			= atoi(line.c_str());
		int space_index = line.find(' ');
		int b 			= atoi(line.c_str() + space_index);
		*/

		//std::cerr << "read in (" << a << ", " << b << ")\n";
		Pair pair;
		pair.a = a;
		pair.b = b;

		pairs[counter++] = pair;
	}


	for(int i = 0; i < num_pairs; ++i) {

		const Pair& pair = pairs[i];
		int   a 	     = pair.a;
		int   b 		 = pair.b;

		while(b != 0) {
			int temp = b;
			b 		 = a % b;
			a		 = temp;
		}
/*
		std::cout << "greatest common divisor for (" << pair.a << ", " << pair.b
				  << "): " << a << '\n';
*/
		out_file << a << '\n';
	}
}
