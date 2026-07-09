var a,b:longint;
    f,g:text;
begin
assign(f,'cmmdc.in');reset(f);
assign(g,'cmmdc.out');rewrite(g);
read(f,a,b);
while a<>b do
      if a>b then
         a:=a-b
         else
         b:=b-a;
write(g,a);
close(f);
close(g);
end.

