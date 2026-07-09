program euclid2;
 var
    f:text;
    a,b,r:word;
begin
 assign(f,'euclid2.in');
 reset(f);
  read(f,a,b);
 close(f);
  r:=a mod b;
   while r<>0 do
    begin
     a:=b;
     b:=r;
     r:=a mod b;
    end;
   assign(f,'euclid2.out');
   rewrite(f);
    write(f,b);
   close(f);
end.