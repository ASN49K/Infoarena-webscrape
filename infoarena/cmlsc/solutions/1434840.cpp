#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

#define MAX_ARR_SIZE 1024

#define INPUT_FILE "cmlsc.in"
#define OUTPUT_FILE "cmlsc.out"

std::fstream in(INPUT_FILE, std::fstream::in);
std::fstream out(OUTPUT_FILE, std::fstream::out);

using namespace std;

void printLCS(int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE], vector<int> a, vector<int> b,int i,int j) {
    if (i == (int) a.size()+1 || j == (int) b.size()+1) {
	return;
    }
    if (a[i-1] == b[j-1]) {
	out << a[i-1] << " ";
	return printLCS(matrix, a, b, i+1, j+1);
    }
    if (matrix[i][j+1] > matrix[i+1][j]) {
	return printLCS(matrix, a, b, i, j+1);
    } else {
	return printLCS(matrix, a, b, i+1, j);
    }
}

int main(int argc, char const *argv[])
{
	int resMatrix[MAX_ARR_SIZE][MAX_ARR_SIZE];
	int len_a, len_b;
	in >> len_a >> len_b;
	vector<int> a(len_a);
	vector<int> b(len_b);
	for (int i = 0; i < len_a; i++) {
		in >> a[i];
	}
	for (int i = 0; i < len_b; i++) {
		in >> b[i];
	}
	
	for (int i = 0; i <= len_a; i++) {
	    resMatrix[i][0] = 0;
	}
	for (int j = 0; j <= len_b; j++) {
	    resMatrix[0][j] = 0;
	}
	for (int i = 1; i <= len_a; i++) {
	    for (int j = 1; j <= len_b; j++) {
		if (a[i-1] == b[j-1]) {
		    resMatrix[i][j] = resMatrix[i-1][j-1] + 1;
		} else {
		    resMatrix[i][j] = max(resMatrix[i][j-1], resMatrix[i-1][j]);
		}
	    }
	}
	int len = resMatrix[len_a][len_b];
	if (len == 0) {
	    out << len;
	} else {
	    out << len << "\n";
	    printLCS(resMatrix, a, b, 0, 0);
	}
	
	out.close();
	in.close();
	return 0;
}
