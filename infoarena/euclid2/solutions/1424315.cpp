#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char *in_file_name = "euclid2.in";
const char *out_file_name = "euclid2.out";

void die(bool assertion, const char *message)
{
	if (assertion) {
		fprintf(stderr, "(%s, %d): ",__FILE__, __LINE__);
		perror(message);
		exit(EXIT_FAILURE);
	}
}

int cmmdc(int a, int b)
{
	if (b == 0)
		return a;
	else
		return cmmdc(b, a % b);
}


int main()
{
	int pairs, a , b;

	ifstream in_file;
	ofstream out_file;

	in_file.open(in_file_name, ios::in);
	die(!in_file, "Error opening file for reading");

	out_file.open(out_file_name, ios::out);
	die(!out_file, "Error opening file for writing");

	in_file >> pairs;

	for (int i = 0; i < pairs; i++) {
		in_file >> a >> b;
		out_file << cmmdc(a, b) << endl;
	}

	return 0;
}

