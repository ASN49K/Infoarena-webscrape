/*
 * main.cpp
 *
 *  Created on: Jun 19, 2019
 *      Author: stefan
 */

#include <bits/stdc++.h>
using namespace std;
int main(){

	ifstream cin;
	    cin.open("euclid2.in");
	    ofstream cout;
	    cout.open("euclid2.out");

	int t;
	cin>>t;
	while(t--){

		int a,b;
		cin>>a>>b;
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
		cout<<vec1[vec1.size()-1]<<endl;

	}

}


