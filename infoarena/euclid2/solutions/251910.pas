var f,g:text;
    i,t,a,b:longint;
function cmmdc(a,b:longint):longint;
begin
     if a=0 then cmmdc:=b;
     if b=0 then cmmdc:=a;
     if (a<>0)and(b<>0) then
          if a=b then cmmdc:=a
                 else cmmdc:=cmmdc(a mod b,b mod a);
end;
begin
     assign(f,'euclid2.in'); reset(f);
     assign(g,'euclid2.out'); rewrite(g);
     readln(f,t);
     for i:=1 to t do
     begin
          readln(f,a,b);
          writeln(g,cmmdc(a,b));
     end;
     close(g);
end.