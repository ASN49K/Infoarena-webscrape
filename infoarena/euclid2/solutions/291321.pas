program pascal;
var f,g:text; a,b,n,i,r:longint;

   procedure euclid(x,y:longint);
   begin
   while y<>0 do
     begin
     r:=x mod y;
     x:=y;
     y:=r;
     end;
    writeln(g,x);
   end;

begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
  begin
  read(f,a,b);
  euclid(a,b);
  end;
close(f);
close(g);
end.