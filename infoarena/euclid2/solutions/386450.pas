var f,g:text; i,t,a,b,c:integer;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,t);

for i:=1 to t do begin
read(f,a,b);
 while b<>0 do
  begin
    c:=a mod b;
    a:=b;
    b:=c;
    if b=0 then writeln(g,a);
  end;
end;
close(f);
close(g);
end.