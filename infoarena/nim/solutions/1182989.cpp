// pb11procon.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "fstream"
#include "iostream"
using namespace std;
int NrGroups;
int Groups[100001];
int main()
{
	ifstream f("11.in");
	int Nrt;
	f>>Nrt;
	for(int q = 0 ; q < Nrt ; q ++)
	{
		f>>NrGroups;
		for(int i = 0 ; i < NrGroups ; i ++)
			f>>Groups[i];
		int x = Groups[0];
		for(int i = 1 ; i < NrGroups ; i ++)
			x = x ^ Groups[i];
		if(x == 0)
			cout<<"DA\n";
		else
			cout<<"Nu\n";
	}
	return 0;
}

