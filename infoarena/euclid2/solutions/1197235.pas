var x,y:  int64;
   t,t1:   text;
    i,n:longint;
      function cmmd(x,y:int64):int64;
       begin
         if y=0 then
            cmmd:=x
          else
            cmmd:=cmmd(y,x mod y);
       end;
         begin
          assign(t,'euclid2.in');
          reset(t);
          assign(t1,'euclid2.out');
          rewrite(t1);
          readln(t,n);
          for i:=1 to n do begin
            readln(t,x,y);
            writeln(t1,cmmd(x,y));
          end;
          close(t);
          close(t1);
         end.