#include<algorithm>
#include<fstream>

using namespace std;

int main() {
    ifstream fin("euclid.in");
    fstream fout("euclid.out");
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        fin >> a >> b;
        while(b != 0)
        {
         int r = a % b;
         a = b;
         b = r;
        }
        fout << a << endl;
    }
   return 0;
}
