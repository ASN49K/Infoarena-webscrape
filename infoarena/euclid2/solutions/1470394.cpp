#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a , int b){
	if (a == 0) {
		return b;
	}else if (b == 0){
		return a;
	}
	if (a > b) {
		a = a - b;
	}else if (b > a) {
		b = b - a;
	}else if (a == b) {
		return a;
	}

	return cmmdc (a,b);

}

int main()
{	
	int x ,a ,b ,result ; 

	fin>> x;
	
	for (int i = 1 ; i <= x ; i ++ ) {
		fin >>a;
		fin >>b;
		result = cmmdc(a,b);
		fout << result << endl;
	}
}





/*#include <iostream>
#include <fstream>
using namespace std;
int gcd(int n,int m){
    return m==0?n:gcd(m,n%m);
}
int main () {
     
    FILE *f;
    FILE *g;
 
    f = fopen ("fractii.in","r");
    g = fopen ("fractii.out", "w");
    int a; //numar citit
    fscanf(f,"%d",&a);
    fclose(f);
    int p = 0;//numar de fractii
 
    for (int x = 1 ; x <= a ; x ++){
 
        for (int y = 1 ; y <= a ; y ++){
            if (gcd(x,y) == 1) {
                p++;
            }
        }
 
    }
    fprintf(g,"%d" , p);
    fclose(g);
	
}	
*/	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	FILE *f;
	FILE *g;
	f = fopen("cmmdc.in","r");
	g = fopen("cmmdc.out","w");


	int  i ,b, A , B , cmmdc;
	bool iteram = true;
	
	fscanf(f,"%d %d" , &A , &B);
	fclose(f);
	cmmdc = 1;
	if (A % B == 0){
		cmmdc = B;
		iteram = false;
	}else if (B % A == 0){
		cmmdc = A;
		iteram = false;
	}else{

		if(A > B) {
			i = B;
			b = A;
		}else if (A < B){
			i = A;
			b = B;
		}
	}
	if(iteram){
		for (int x = 2; x <= i; x++){
			while(true){
				if(i % x == 0 && b % x == 0){
					cmmdc = cmmdc * x;
					b = b / x;
					i = i / x;
				}else {
					break;
				}
			}


		}
	}
	if(cmmdc == 1) {
		cmmdc = 0;
	}
	fprintf(g,"%d",cmmdc);
	fclose(g);
	*/
	//ADUNAREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	/*
	int a,b;

	FILE *f;
	FILE *g;

	f = fopen("adunare.in","r");
	g = fopen("adunare.out","w");

	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);

	fprintf(g,"%d \n" , a + b );



	fclose(f);
	fclose(g);


	return 0;

	*/
	


/*

















*/