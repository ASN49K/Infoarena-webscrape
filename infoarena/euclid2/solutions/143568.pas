program euclid2;
var f,g:text;
    a,b:longint;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,a,b);
if (a=0)then write(g,b) else
if (b=0)then write(g,a) else
begin
  while (a<>b)do
    if (a>b)then
      a:=a-b else
      b:=b-a;
  write(G,a);
end;
close(f);
close(G);
end.