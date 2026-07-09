var a,b,r:longint;
    f:text;
begin
assign(f,'euclid2.in');reset(f);
read(f,a,b);
close(f);
assign(f,'euclid2.out');rewrite(f);
repeat
     r:=a mod b;
     a:=b;
     b:=r;
until b=0;
write(f,a);
close(f);
end.