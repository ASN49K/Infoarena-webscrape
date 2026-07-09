program euclid2;
var f,g:text;
    a,b,k,i,n:longint;
begin
     assign(f,'euclid2.in');
     assign(g,'euclid2.out');
     reset(f);
     rewrite(g);
     read(f,n);
     for i:=1 to n do
     begin
          read(f,a,b);
          k:=a mod b;
          while(k<>0) do
          begin
               a:=b;
               b:=k;
               k:=a mod b;
          end;
     writeln(g,b);
     end;
     close(f);
     close(g);
end.