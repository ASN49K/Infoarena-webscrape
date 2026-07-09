var a,b,c,n:longint;
    f,g:text;
begin
assign(f,'euclid2.in');assign(g,'euclid2.out');
reset(f);
rewrite(g);
close(g);
readln(f,n);
append(g);
while n<>0 do
  begin
    read(f,a);readln(f,b);
    c:=b;
    while a mod b<>0 do
      begin
       c:=a mod b;
       a:=b;
       b:=c;
      end;
    writeln(g,c);
    dec(n);
  end;
close(f);
close(g);
end.