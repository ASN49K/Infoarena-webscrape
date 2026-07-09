var f,g:text;
    t,x,y,i,n:longint;
function cmd(x,y:longint):longint;
begin

     while (x mod y<>0)and(y mod x<>0) do
     begin
          if x>y then x:=x mod y
                 else y:=y mod x;
     end;
     if x mod y=0 then cmd:=y
                  else cmd:=x;
end;
begin
     assign(f,'euclid2.in'); reset(f);
     assign(g,'euclid2.out'); rewrite(g);
     readln(f,t);
     for i:=1 to t do
     begin
          readln(f,x,y);
          writeln(g,cmd(x,y));
     end;
     close(g);
end.