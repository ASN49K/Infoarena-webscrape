#include <fstream.h>
#include <iostream.h>

	std::ifstream in("euclid2.in");
	std::ofstream out("euclid2.out");

/* Test
	Luam numerele 12 si 42
	12 = 42 | 42 = 12
	42 = 12 | 12 = 6
	r = 6   | r = 0
*/
	

int euclid(int a, int b){
	int r;
	r = a%b;
	while(r != 0)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

int main(){
	int lines;
	int a,b;
	
	in >> lines;
	
	for(int i = 0; i<lines; i++){
		
		in >> a >> b;
		out << euclid(a,b) << "\n";
	}
	
	in.close();
	out.close();
	return 0;
}

