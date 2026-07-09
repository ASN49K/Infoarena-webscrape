program euclid2;
var f,g:text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,a,b);
while (a<>b)do
  if (a>b)then
    a:=a-b else
    b:=b-a;
write(G,a);
close(f);
close(G);
end.