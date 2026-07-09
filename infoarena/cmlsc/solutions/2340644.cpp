// Cel mai lung subsir comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int  m, n;
	int temp;
	fin >> m >> n;

	vector<int> numere,remain;
	while (m-- != 0) {
		fin >> temp;
		numere.push_back(temp);
	}
	
	while(n--!=0){
		fin >> temp;
		auto it = find(numere.begin(), numere.end(), temp);
		if(it!=numere.end()){
			remain.push_back(temp);
			numere.erase(it);
		}		
	}
	fout << remain.size()<<'\n';
	for (auto it : remain)
		fout << it <<' ';
}
