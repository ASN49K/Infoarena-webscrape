program euclid;
var a,b,t,i:longint;f,g:text;
function cmmdc(a,b:longint):longint;
var t:longint;
begin
     while b<>0 do
           begin
                t:=b;
                b:=a mod b;
                a:=t;
           end;
     cmmdc:=a;
end;
begin
     assign(f,'euclid2.in');
     reset(f);
     assign(g,'euclid2.out');
     rewrite(g);
     readln(f,t);
     for i:=1 to t do
         begin
              readln(f,a,b);
              write(g,cmmdc(a,b));
         end;
end.


end.