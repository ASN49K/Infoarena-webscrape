program euclid2;
type numar=0..2000000000 ;
var a,b,c:numar;
    t,i:numar;
    f,g:text;
begin
   assign(f,'euclid2.in');reset(f);
   assign(g,'euclid2.out');rewrite(g);
     readln(f,t);
     for i:=1 to t do
       begin
         readln(f,a,b);
         while a mod b<>0 do
           begin
           c:=a;
           a:=b;
           b:=c mod b;
           end;
           writeln(g,b);
       end;
   close(f);
   close(g);
end.