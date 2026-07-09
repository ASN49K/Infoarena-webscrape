program euclid2;
type numar=0..2000000000 ;
var a,b,c:numar;
    t,i:numar;
    f,g:text;
function cmmdc(a,b:numar):numar;
begin
   if b=0 then
       cmmdc:=a
   else
      cmmdc:=cmmdc(b,a mod b);
end;
begin
   assign(f,'euclid2.in');reset(f);
   assign(g,'euclid2.out');rewrite(g);
     readln(f,t);
     for i:=1 to t do
       begin
         readln(f,a,b);

           writeln(g,cmmdc(a,b));
       end;
   close(f);
   close(g);
end.