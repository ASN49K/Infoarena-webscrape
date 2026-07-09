program euclid11;
var n,i,a,b,cmmdc,r:longint;
f1,f2:text;
begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);
rewrite(f2);
readln(f1,n);
for i:=1 to n do
begin
readln(f1,a,b);
while (b>0) do
  begin
   r:=a mod b;
   a:=b;
   b:=r;
   end;
cmmdc:=a;
writeln(f2,cmmdc);
end;
close(f1);
close(f2)
end.
