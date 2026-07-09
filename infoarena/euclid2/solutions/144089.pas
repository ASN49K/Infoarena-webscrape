program aa;
var f,g:text;
    a,b,d:int64;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(g,a,b);
while(a<>b) do begin
if (a>b) then a:=a-b
         else if (b>a) then b:=b-a;
end;
d:=a;
write(f,d);
close(f);
close(g);
end.