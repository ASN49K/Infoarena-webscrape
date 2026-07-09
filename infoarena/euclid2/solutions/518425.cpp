# include <fstream>
  using namespace std;
    std :: ifstream f ("euclid2.in");
	std :: ofstream g ("euclid2.out");
    int t, a, b;
	inline int cmmdc (int a, int b){
		while (b){
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	int main (){
		f >> t;
		while ( t-- ){
			f >> a >> b;
			g << cmmdc (a, b) << '\n';
		}
		g.close ();
		return 0;
	}