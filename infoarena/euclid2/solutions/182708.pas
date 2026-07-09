program euclid;
var t,i:1.. 100000;
a,b,c:1..2000000000;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out');
rewrite(output);
readln(t);
for i:=1 to t do
 begin
 readln(a,b);
 while a<>b do
  if a>b then dec(a,b)
   else dec(b,a);
 writeln(a);
 end;
close(input);
close(output);
end.
