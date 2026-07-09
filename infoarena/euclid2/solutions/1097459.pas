var a,b:text;
	m,n:longint;

function f(a,b:longint):longint;
begin
if b=0 then f:=a else f:=f(b, a mod b);
end;

begin
assign(a,'euclid2.in');
reset(a);
assign(b,'euclid2.out');
rewrite(b);
readln(a,m,n);
writeln(b,f(m,n));
close(a);
close(b);
end.
