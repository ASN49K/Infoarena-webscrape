#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <ctime>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream ff("nim.in");
ofstream gg("nim.out");

int t, n, s, x;

int main(){
	ff >> t;
	while(t--){
		ff >> n;
		s=0; for(int i=0;i<n;i++){ff >> x; s^=x;}
		if(s==0) gg << "NU\n"; else gg << "DA\n";
	}
	return 0;
}
