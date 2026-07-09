var f,g:text;
    t,a,b,i:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,t);
for i:=1 to t do begin
 read(f,a,b);
 while a<>b do
  if a<b then dec(b,a)
   else dec(a,b);
 writeln(g,a);
end;
close(f);
close(g);
end.