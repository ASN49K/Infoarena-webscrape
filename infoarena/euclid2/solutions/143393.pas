var a,b,r,aux:longint;
    f,g:text;
begin
     assign(f,'euclid2.in');
     reset(f);
     read(f,a,b);
     close(f);

     assign (g,'euclid2.out');
     rewrite(g);
     if b>a then
     begin
          aux:=a;
          a:=b;
          b:=aux;
     end;  r:=1;
     while r<>0 do
     begin
          r:=a mod b;
          a:=b;
          b:=r;
     end;
     write(g,a);
     close(g);
end.