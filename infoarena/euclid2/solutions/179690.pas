var n,a,b,r,i:longint;
    f,g:text;
function cmmdc(var a,b:longint):longint;
         begin
              while b<>0 do begin
                    r:=b;
                    b:=a mod b;
                    a:=r
                    end;
              writeln(g,a)
         end;
begin
     assign(f,'euclid2.in');
     reset(f);
     assign(g,'euclid2.out');
     rewrite(g);
     read(f,n);
     for i:=1 to n do begin
                 read(f,a,b);
                 cmmdc(a,b)
                 end;
     close(f);
     close(g)
end.