program euclid2;
var f,g:text;
    a,b,k:longint;
begin
     assign(f,'euclid2.in');
     assign(g,'euclid2.out');
     reset(f);
     rewrite(g);
     read(f,a,b);
     k:=a mod b;
     while(k<>0) do
     begin
          a:=b;
          b:=k;
          k:=a mod b;
     end;
     write(g,b);
     close(f);
     close(g);
end.