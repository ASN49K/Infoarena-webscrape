#include <fstream>

using namespace std;
ifstream fin ("cmmdc.in");
ofstream fout ("cmmdc.out");
int main()
{int a,b;
fin>>a>>b;
int r;
while(b>0){
    r = a%b;
    a = b;
    b = r;
}
    fout<<a;


}
