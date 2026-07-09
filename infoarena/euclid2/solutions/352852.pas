var f,f2:text;
i,t,a,b,r:integer;
begin
assign (f,'euclid2.in');
assign (f2,'euclid2.out');
reset (f);
rewrite (f2);
readln (f,t);
for i:=1 to t do
begin
read (f,a);
readln (f,b);
while (a<>0) do
      begin
      r:=a mod b;
      a:=b;
      b:=r;
      end;
writeln (f2,a);
end;
readln;
end.