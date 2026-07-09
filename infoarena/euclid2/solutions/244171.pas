program cmmdc;
var n,i,a,b:integer;
		f,g:text;
begin
assign(f,'cmmdc.in'); reset(f);
assign(g,'cmmdc.out'); rewrite(g);
read(f,n);
for i:=1 to n do
 begin
 readln(f,a,b);
	while (a<>b) and (a<>1) and (b<>1) do
		if a>b then a:=a-b
		else b:=b-a;
	if (a=b) and (a<>1) and (b<>1)  then writeln(g,a)
	else writeln(g,0);
 end;

close(f);
close(g);
end.