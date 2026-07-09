program euclid2;
var f,g:text;
n,i,a,b,r:longint;
begin
 assign (f,'euclid2.in'); reset (f);
 assign (g,'euclid2.out'); rewrite (g);
 read (f,n);
 for i:=1 to n do
   begin
   read (f,a,b);
    while (a<>b) and (a<>0) and (b<>0) do
     begin
      r:=a mod b;
      a:=b;
      b:=r;
     end;
   writeln (g,b);
   end;
 close (f);
 close (g);
 end.
