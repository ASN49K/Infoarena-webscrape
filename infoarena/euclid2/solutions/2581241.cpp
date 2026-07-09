#include<fstream>
using namespace std;fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);int main(){int a,b;f>>a;while(f>>a>>b)while(a!=b)a>b?a=a-b:b=b-a;g<<b;}