var n,i:integer;
a,b:int64;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
repeat
if a>b then a:=a-b
else b:=b-a;until b=a;
writeln(g,a);end;
close(g);close(f);end.