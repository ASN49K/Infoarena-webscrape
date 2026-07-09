program euclid;
var f,g:text;
    a,b,d:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,a,b);
while(a<>b)do begin
if(a>b) then a:=a-b;
if(b>a) then b:=b-a;
end;
d:=a;
write(g,d);

close(f);
close(g);
end.