var  t,t1:  text;
     i,n:longint;
     x,y:  int64;
    function euclid(x,y:int64):int64;
     begin
      if y=0 then
         euclid:=x
            else
         euclid:=euclid(y,x mod y);
     end;
      begin
       assign(t,'euclid2.in');
       reset(t);
       readln(t,n);
       assign(t1,'euclid2.out');
       rewrite(t1);
       for i:=1 to n do begin
         readln(t,x,y);
         writeln(t1,euclid(x,y));
       end;
       close(t);
       close(t1);
      end.
