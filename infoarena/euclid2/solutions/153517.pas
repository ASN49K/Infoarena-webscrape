var a,b,i,r,t:longint;
    f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
for i:=1 to t do
 begin
 read(f,a,b);
 r:=a mod b;
 while r<>0 do
  begin
  a:=b;
  b:=r;
  r:=a mod b;
  end;
 writeln(g,b);
 end;
close(f);
close(g);
end.