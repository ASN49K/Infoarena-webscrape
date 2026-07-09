program cmmdc;
var f,g:text;
    a,b,r:longint;
begin
     assign(f,'cmmdc.in');
     assign(g,'cmmdc.out');
     reset(f);
     rewrite(g);
     read(f,a,b);
     r:=a mod b;
     while(r<>0) do
     begin
          a:=b;
          b:=r;
          r:=a mod b;
     end;
     write(g,b);
     close(f);
     close(g);
end.