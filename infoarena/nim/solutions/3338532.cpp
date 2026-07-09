#include<fstream>
int main(){std::fstream f("nim.in"),g("nim.out");for(int N,x,S;f>>N;g<<(S?"DA\n":"NU\n"))for(S=0;N--;S^=x)f>>x;}
