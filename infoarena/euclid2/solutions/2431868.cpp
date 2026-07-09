/*
 * main.cpp
 *
 *  Created on: Jun 19, 2019
 *      Author: stefan
 */

#include <bits/stdc++.h>
using namespace std;
int main(){

	ifstream f("Euclid2.in");
	ofstream g("Euclid2.out");

	int t;
	f>>t;
	while(t--){

		int a,b;
		f>>a>>b;
		int div =0;
		vector<int> vec1;
		if(a<=b){
		while(div<=a){

			div++;
			if(a % div == 0 && b%div==0){

				vec1.push_back(div);

			}

		}}
		else{

			while(div<=b){

				div++;
				if(a % div == 0 && b%div==0){

					vec1.push_back(div);

				}

			}

		}
		g<<vec1[vec1.size()-1];

	}

}


