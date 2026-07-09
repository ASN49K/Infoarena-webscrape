var a,b,i,r,t:longint;
begin
assign(input,'euclid2.in');
reset(input);
assign(output,'euclid2.out');
rewrite(output);
readln(t);
for i:=1 to t do
begin
readln(a,b);
while b<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
writeln(a);
end;
end.
