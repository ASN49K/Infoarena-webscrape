var f,g:text;a,b,i,n:integer;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,n);
for i:=1 to n do
begin
readln(f,a,b);
while a<>b do if a>b then a:=a-b else b:=b-a;
writeln(g,a);
end;
close(f);close(g);
end.

