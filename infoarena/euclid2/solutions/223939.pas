program euclid_edu;
var f,g:text;
    a,b,x,i,n:longint;
begin
   assign(f,'euclid2.in');
   assign(g,'euclid2.out');
   reset(f);
   rewrite(g);
   read(f,n);
   for i:=1 to n do
    begin
     read(f,a,b);
     x:=a mod b;
     while(x<>0) do
     begin
       a:=b;
       b:=x;
       x:=a mod b;
     end;
   writeln(g,b);
   end;
   close(f);
   close(g);
end.