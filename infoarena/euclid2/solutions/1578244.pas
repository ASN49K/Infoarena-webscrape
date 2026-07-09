program euclid;
var a,b,i,n:longint;
f1,f2:text;
function euclid(a,b:longint):longint;
var aux,r:longint;
begin
	r:=a mod b;
	while r>0 do
	begin
		a:=b;
		b:=r;
		r:=a mod b;
	end;
	euclid:=b;
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
