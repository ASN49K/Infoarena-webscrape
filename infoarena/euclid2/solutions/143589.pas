program cmmdc;
uses dos;
var f,g:text;
    a,b,r:longint;
begin
     assign(f,'cmmdc.in');
     assign(g,'cmmdc.out');
     reset(f);
     rewrite(g);
     read(f,a,b);
     begin
          while(b<>0)do
          begin
               r:=a mod b;
               a:=b;
               b:=r;
          end;
     end;
     writeln(g,a);
     close(f);
     close(g);
end.


