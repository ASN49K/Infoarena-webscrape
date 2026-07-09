#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
int n,i;
fin>>n;
for(i=1;i<=n;++i){
int a,b,c;
fin>>a>>b;
while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    fout<<a<<endl;


}    return 0;
}
