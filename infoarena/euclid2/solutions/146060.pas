program euclid;
var f,g:text;
		a,b:longint;
begin
assign(f,'euclid2.in');reset(f);assign(g,'euclid2.out');rewrite(g);
read(f,a);read(f,b);
while a<>b do
	 if a>b then a:=a-b
	 else b:=b-a;
write(g,a);
close(f);close(g);
end.