var x,y,cmmdc:longint;
    f,g:text;
begin
assign(f,'cmmdc.in');reset(f);
assign(g,'cmmdc.out');rewrite(g);
read(f,x,y);
while x<>y do
      if x>y then x:=x-y
             else y:=y-x;
cmmdc:=x;
if cmmdc=1 then cmmdc:=0;
write(g,cmmdc);
close(f);
close(g);
end.

