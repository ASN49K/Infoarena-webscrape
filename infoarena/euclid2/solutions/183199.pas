var f,g:text;
    a,b:longint;
    t,i:integer;

function cmmdc(a,b:longint):longint;
begin
     if b=0 then cmmdc:=a
     else cmmdc:=cmmdc(b,a mod b)
end;

begin
     assign(f,'euclid2.in'); reset(f);
     assign(g,'euclid2.out'); rewrite(g);
     readln(f,t);
     for i:=1 to t do
         begin
              read(f,a,b);
              write(g,cmmdc(a,b));
         end;
     close(g);close(f);
end.