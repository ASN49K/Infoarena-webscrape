var f,g:text;t,i,a,b:longint;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);read(f,t);
for i:=1 to t do begin
readln(f,a,b);
while a<>b do
if a>b then a:=a-b
else b:=b-a;
writeln(g,a);  end;
end.