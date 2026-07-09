#include<stdio.h>

//var a,b,r:longint;
int a,b,r;

//procedure citire;
void citire()
//begin
{
//assign(input,'euclid2.in');
freopen("euclid2.in","r",stdin);
//reset(input);
//read(a,b);
scanf("%d%d", &a, &b);
fclose(stdin);
//end;
}

/*procedure cmmdc;
var w,q:longint;
begin
w:=a;
q:=b;
repeat
       r:=w mod q;
       w:=q;
       q:=r;
       until q=0;
//if (w=1) and (a<>1) and (b<>1) then
//   write(0)
  { else} write(w);
end;*/
void cmmdc()
{
	int w=a;
	int q=b;
	do
	{
		r=w/q;
		w=q;
		q=r;
	}
	while (q!=0);
	printf("%d", w);
}

/*begin
citire;
assign(output,'euclid2.out');
rewrite(output);
cmmdc;
close(output);
end.
  */
int main()
{
	freopen("euclid2.out","w",stdout);
	cmmdc();
	fclose(stdout);
	return 0;
}