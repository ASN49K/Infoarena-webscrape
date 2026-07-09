var f,f2:text;
i,t,a,b,r,man:integer;
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
{if a>b then
man:=a;
a:=b;
b:=man;}
while (b<>0) do
begin
      r:=a mod b;
      a:=b;
      b:=r;
      end;
writeln (f2,a);
end;
close (f);
close (f2);
readln;
end.