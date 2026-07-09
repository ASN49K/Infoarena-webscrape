var f,g:text;n,a,b,i:longint;
function cmmdc(x,y:longint):longint;
begin
while x<>y do
if x>y then x:=x-y else y:=y-x;
cmmdc:=x;
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do
begin
readln(f,a,b);
c:=cmmdc(a,b);
writeln(g,cmmdc(a,b));
end;
close(f);close(g);
end.
