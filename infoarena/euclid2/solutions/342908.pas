program euclid2;
var n,i,a,b,cmmdc:longint;
		f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,n);
for i:=1 to n do
 begin
 readln(f,a,b);
	repeat
	cmmdc:=a mod b;
	a:=b;
	b:=cmmdc;
	until cmmdc=0;
	writeln(g,a);
 end;

close(f);
close(g);
end.