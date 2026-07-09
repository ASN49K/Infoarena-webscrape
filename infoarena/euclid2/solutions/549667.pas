program cmmdc;
var a,b,d,n,i:integer;
    f,g:text;
function cmmdc(a,b:integer):integer;
    begin
       if b=0 then cmmdc:=a
         else cmmdc:=cmmdc(b,a mod b);
    end;
begin
    assign(f,'cmmdc.in');
    reset(f);
    assign(g,'cmmdc.out');
    rewrite(g);
    read(f,n);
    for i:=1 to n do
      begin
        read(f,a,b);
        d:=cmmdc(a,b);
        writeln(g,d);
      end;
    close(f);close(g);
end.
