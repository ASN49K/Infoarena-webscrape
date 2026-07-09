Program p1;
{algoritmul lui euclid}
var f1,f2:text;i,k,s,a,b:integer;
function p(m, n :integer):integer;
begin
while m<>n do
if m>n then m:=m-n else n:=n-m;
p:=m;
end;
begin
assign(f1,'euclid2.in');
reset(f1);
readln(f1,k);
assign(f2,'euclid2.out');
rewrite(f2);
for i:=1 to k do begin readln(f1,a,b);
s:=p(a,b); writeln(f2,s);
end;
close(f1);
close(f2);
end.