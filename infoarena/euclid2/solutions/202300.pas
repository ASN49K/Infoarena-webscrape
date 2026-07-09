var f,g:text;
    t,i,a,b,r:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
 begin
  readln(f,a,b);
  if a<b then begin r:=a;a:=b;b:=r;end;
  repeat
   r:=a mod b;
   a:=b;
   b:=r;
  until r=0;
  writeln(g,a);
 end;
close(f);
close(g);
end.