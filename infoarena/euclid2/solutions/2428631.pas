var n,i,a,b:longint;
begin
readln(n);
for i:=1 to n do
 begin
  readln(a,b);
  while a*b<>0 do
   if a>b then a:=a mod b else b:=b mod a;
  writeln(a+b)
 end
end.
