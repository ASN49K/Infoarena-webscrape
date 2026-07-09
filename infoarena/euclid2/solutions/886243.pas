var a,b:text;
c,d:longint;
m,n,r:longint;
begin
assign(a,'euclid2.in');
assign(b,'euclid2.out');
reset(a);
rewrite(b);
read(a,c);
for d:=1 to c do
begin
	read(a,m);
	read(a,n);
	while n>0 do
	begin
		r:=m mod n;
		m:=n;
		n:=r;
	end;
	writeln(b,m);
end;
close(b);
end.

