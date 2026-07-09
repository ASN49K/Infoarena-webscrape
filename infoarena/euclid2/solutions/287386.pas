program euclid;
var a,b,r,t,i:longint;
    f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
read(f,t);
for i:=1 to t do
begin
 read(f,a,b);
 r:=1;
 if b>a then begin
               r:=a;
               a:=b;
               b:=r;
             end;
 while r>0 do
   begin
     r:=a mod b;
     a:=b;
     b:=r;
   end;
 writeln(g,a);
end;
close(f);
close(g);
end.