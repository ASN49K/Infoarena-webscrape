var  t,t1:  text;
     i,n:longint;
     x,y:  int64;
     aux:  int64;
      begin
       assign(t,'euclid2.in');
       reset(t);
       readln(t,n);
       assign(t1,'euclid2.out');
       rewrite(t1);
       for i:=1 to n do begin
         readln(t,x,y);
         while (y<>0) do begin
           aux:=x mod y;
           x:=y;
           y:=aux;
         end;
         writeln(t1,x);
       end;
       close(t);
       close(t1);
      end.
