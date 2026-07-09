program euclid2;
var f,g:text;
a,b,n,i:longint;
begin
 assign (f,'euclid2.in'); reset (f);
 assign (g,'euclid2.out'); rewrite (g);
 read (f,n);
 for i:=1 to n do
  begin
   read (f,a,b);
   while (a<>b) and (a<>0) and (b<>0) do
   if (a>b) then a:=a-b
            else b:=b-a;
   writeln (g,a);
  end;
 close (f);
 close (g);
 end.
