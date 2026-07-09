var
i,a,b,t,d:longint;  f1,f2:text;
begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);
rewrite(f2);
readln(f1,t);
for i:=1 to t do
begin
readln(f1,a,b);
 while (a<>0) and(b<>0) do
 begin
 if a<b then
b:=b mod a else a :=a mod b;
end;
if a=0 then  writeln(f2,b) else writeln(f2,a);
end;
close(f1);
close(f2);
end.

