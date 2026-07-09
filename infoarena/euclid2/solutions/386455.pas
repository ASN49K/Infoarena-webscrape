var f,g:text; i,n,a,b,c:integer;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,n);

for i:=1 to n do begin
read(f,a);
readln(f,b);
c:=1;
 while b>0 do
  begin
    c:=a mod b;
    a:=b;
    b:=c;
  end;
writeln(g,a);
end;
close(f);
close(g);
end.
