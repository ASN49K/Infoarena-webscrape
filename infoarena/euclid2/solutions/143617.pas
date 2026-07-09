var r,a,b:int64;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a,b);
repeat
r:=a mod b;
a:=b;
b:=r;
until b=0;
write(g,a);
close(f);
close(g);
end.
