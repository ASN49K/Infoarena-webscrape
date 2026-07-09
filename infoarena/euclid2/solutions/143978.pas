program euclid;

var a,b:longint;
	f,g:text;

function cmmdc(a:longint;b:longint):longint;
begin
	while((a<>0) and (b<>0))do
	begin
		if(a>b)then
			a:=a mod b
		else
			b:=b mod a;
	end;
	cmmdc:= a or b
end;

begin
assign(f,'euclid2.in');
reset(f);
readln(f,a,b);
close(f);
assign(g,'euclid2.out');
rewrite(g);
writeln(g,cmmdc(a,b));
close(g);
end.
