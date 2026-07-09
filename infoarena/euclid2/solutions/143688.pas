var x,y,cmmdc:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,x,y);
while x<>y do
      if x>y then x:=x-y
             else y:=y-x;
cmmdc:=x;
if cmmdc=0 then cmmdc:=1;
write(g,cmmdc);
close(f);
close(g);
end.
