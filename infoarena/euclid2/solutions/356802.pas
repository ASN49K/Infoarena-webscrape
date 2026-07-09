program euclid;

var
    t,i:longint;
    a,b:longint;
    f,g:text;
procedure diviz(a,b:longint);
   begin
   if a=b then writeln(g,a)
          else
        if a>b then diviz(a-b,b)
               else diviz(a,b-a);
   end;

begin

assign(f,'euclid2.in');
reset (f);
read(f,t);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to t do
   begin
   read(f,a,b);
   diviz(a,b);
   end;
close(f);
close(g);
end.
