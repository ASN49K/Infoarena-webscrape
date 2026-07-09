var n,i,x,y,r:longint;
f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(n);
for i:=1 to n do begin
    readln(f,x,y);
    while x<>y do begin
          r:=x mod y;
          x:=y;
          y:=r;
          end;
    writeln(g,x);
    end;
close(f);
close(g);
end.