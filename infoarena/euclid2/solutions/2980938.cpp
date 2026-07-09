#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main(){
        int n;
        f >> n;
        for(int i = 1; i <= n; ++i){
            int a, b;
            f >> a >> b;
            while(b){
                int c = a % b;
                a = b;
                b = c;
            }
            g << a;
            g << endl;
        }
        f.close();
        g.close();
        return 0;

}
