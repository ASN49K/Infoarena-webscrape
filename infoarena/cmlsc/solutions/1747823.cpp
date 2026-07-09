#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;

int main() {
    int n, m;

    ifstream myfile;
    myfile.open ("cmlsc.in");
    myfile>>n>>m;
    n++;
    m++;
    vector <int> a(n), b(m);
    vector <vector <int>> mat(n, vector <int>(m, 0));
    vector <vector <char>> dir(n, vector <char>(m, 0));
    vector <int> rez;
    
    for (int i = 1; i < n; i++)
    	myfile>>a[i];
    
    for (int i = 1; i < m; i++)
    	myfile>>b[i];
    	
    myfile.close();	
    
    if (n && m) {
     	int x, y;
     	for(int i = 1; i < n; i++) {
     		for(int j = 1; j < m; j++) {
     			x = mat[i-1][j-1] + (a[i] == b[j]);
     			y = 0;
     			//if (a[i] == b[j])
     				//x++;
     			if (mat[i][j-1] > x) {
     				x = mat[i][j-1];
     				y = 1;
     			}
     			if (mat[i-1][j] > x) {
     				x = mat[i-1][j];
     				y = 2;
     			}
     			
     			dir[i][j] = y;
     			mat[i][j] = x;
     			//cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
     		}
     	}
     	
     	x = n-1;
     	y = m-1;
     	int d;
     	while (x && y) {
     		d = dir[x][y];
     		if (!d) {
     			if (a[x] == b[y])
     				rez.push_back(a[x]);
     			x--;
     			y--;
     		}
     		else if(d == 1)
     			y--;
     		else
     			x--;
     	}
     	   
    }
    
	ofstream f2;
	f2.open ("cmlsc.out");
	n = rez.size();
	f2<<n<<endl;
	for (int i = n-1; i >= 0; i--) {
		f2<<rez[i]<<" ";
	}
		f2<<endl;
	f2.close();
    
    return 0;
}
