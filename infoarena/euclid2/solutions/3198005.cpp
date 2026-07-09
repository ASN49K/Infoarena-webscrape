#import<fstream>
std::fstream f("nim.in"),g("nim.out",std::ios::out);main(){int N,x,S;for(f>>N;f>>N;g<<(S?"DA\n":"NU\n"))for(S=0;N--;S^=x)f>>x;}