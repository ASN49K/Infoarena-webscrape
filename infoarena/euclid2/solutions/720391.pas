var f,g:text;a,n,b,i:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
while a<>b do
if a>b then a:=a-b
       else b:=b-a;
writeln(g,b);end;
close(f);close(g);
end.
