#include<fstream>
std::fstream f("nim.in"),g("nim.out");main(){for(int N,x,S;f>>N;g<<(S?"DA\n":"NU\n"))for(S=0;N--;S^=x)f>>x;}
