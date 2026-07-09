#include <iostream>
#include <fstream>

using namespace std;

int g, w, i, j, a[1001], b[1001], d[5001];

int main(){
	ifstream in("energii.in");
	ofstream out("energii.out");
	
	in >> g >> w;
	
	for(i = 1; i <= g; i++)
		in >> a[i] >> b[i];
		
	for(i = 1; i <= w; i++)
		d[i] = 1e9;
		
	for(i = 1; i <= g; i++)
		for(j = w; j >= 1; j--)
			if(j < a[i])
				d[j] = min(d[j], b[i]);
			else
				d[j] = min(d[j], d[j - a[i]] + b[i]);
		
	if(d[w] != 1e9)
		out << d[w];
	else
		out << "-1";
		
	return 0;
}
