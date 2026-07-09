var f,g:text;
    a,b,t,i,r:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,t);
for i:=1 to t do begin
 read(f,a,b);
 r:=a mod b;
 if r<>0 then
  repeat
  a:=b;
  b:=r;
  r:=a mod b;
  until r=0;
 writeln(g,b);
end;
close(f);
close(g);
end.