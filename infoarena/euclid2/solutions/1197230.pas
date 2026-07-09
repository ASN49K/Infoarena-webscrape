var x,y:  int64;
   t,t1:   text;
    i,n:longint;
      function cmmd(x,y:int64):int64;
       begin
        while (x<>0)or(y<>0) do begin
          if x>y then x:=x mod y else y:=y mod x;
        end;
        if x=0 then cmmd:=y else cmmd:=x;
       end;
         begin
          assign(t,'euclid2.in');
          reset(t);
          assign(t1,'euclid2.out');
          rewrite(t1);
          readln(t,n);
          for i:=1 to n do begin
            readln(t,x,y);writeln(t1,cmmd(x,y));
          end;
          close(t);
          close(t1);
         end.