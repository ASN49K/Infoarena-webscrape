var i,t,r,a,b:longint;
f,g:text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,t);
for i:=1 to t do begin
   read(f,a,b);
      while b<>0 do begin
         r:=a mod b;
         a:=b;
         b:=r;
         end;
   writeln(g,a);
   end;
close(f);
close(g);
end.

