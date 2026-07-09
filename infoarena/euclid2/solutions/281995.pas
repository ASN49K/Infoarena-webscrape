var a,b,r,r1,i,d,t,j:longint;
    f,g:text;
begin
assign (f,'euclid2.in');
assign (g,'euclid2.out');
reset (f);
rewrite (g);
readln (f,t);
for j:=1 to t do
begin
readln (f,a,b);
       if a>b then
          begin
           i:=b;
           d:=a;
          end
          else
          begin
           i:=a;
           d:=b;
          end;
r:=d mod i;
while r<>0 do
      begin
       d:=i;
       i:=r;
       r:=d mod i;
      end;
if i<>1 then
writeln (g,i)
else
writeln (g,'0');
end;
close (f);
close (g);
end.
