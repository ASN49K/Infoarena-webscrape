#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, a, b;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	in >> t;
	
	for (int i=0; i<t; i++) {		
		in >> a >> b;
		while (a != 0 && b != 0)  {
			if (a>b) a=a%b;
			else b=b%a;
			
		}
		out << (a+b) << endl;
	}
	

	return 0;
}
