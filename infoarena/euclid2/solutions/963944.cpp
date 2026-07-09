#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

/* 
 * File:   euclid.h
 * Author: Victor
 *
 * Created on June 19, 2013, 5:12 PM
 */

#ifndef EUCLID_H
#define	EUCLID_H

pair<int,int> operator-(pair<int,int> a, pair<int,int> b){
	return make_pair(a.first-b.first,a.second-b.second);
}

pair<int,int> operator*(int q, pair<int,int> a){
	return make_pair(q*a.first,q*a.second);
}

class euclid{
public:
	int gcd(pair<int,int>&dd,int a,int b){
		int q,r;
		pair<int,int> v, v0(1,0), v1(0,1);
		while(b!=0){
			q=a/b;
			r=a%b;
			a=b;
			b=r;
			v=v0;
			v0=v1;
			v1=v-q*v1;
		}
		dd=v0;
		return a;
	}
};

#endif	/* EUCLID_H */
	
euclid a;
int n;

int main(){
	int x,y;
	pair<int,int>pp;
	f >> n;
	while(n--){
		f >> x >> y;
		g << a.gcd(pp,x,y) << endl;
	}
	return 0;
}
