program euclid;
var a,b,n,i:longint;
f1,f2:text;
function euclid(a,b:longint):longint;
var aux,r:longint;
begin
	if b>a then 
	begin
		aux:=a; a:=b; b:=aux;	
	end;
	r:=1;
	while b<>0 do
	begin
		r:=a mod b;
		a:=b;
		b:=r;
	end;
	euclid:=a;
end;
begin
	assign(f1,'euclid2.in');
	assign(f2,'euclid2.out');
	reset(f1); rewrite(f2);
	read(f1,n);
	for i:=1 to n do
	begin
		read(f1,a,b);
		writeln(f2,euclid(a,b));
	end;
	close(f1); close(f2);
end.
