var n,i,a,b:longint;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out'); rewrite(output);
readln(n);
for i:=1 to n do
 begin
  readln(a,b);
  while a*b<>0 do
   if a>b then a:=a mod b else b:=b mod a;
  writeln(a+b)
 end;
close(input);
close(output)
end.
