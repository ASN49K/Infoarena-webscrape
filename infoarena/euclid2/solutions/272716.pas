var a,b:integer;
    f:text;
begin
assign(f,'cmmdc.in');
reset(f);
read(f,a,b);
close(f);
while a<>b do
      if a>b then a:=a-b
         else if a<b then b:=b-a;
assign(f,'cmmdc.out');
rewrite(f);
if a=1 then write(f,0)
   else write(f,a);
close(f);
end.