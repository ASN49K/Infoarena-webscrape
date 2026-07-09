var t,a,b,i:integer;
function cmmdc(a,b:integer);
var c:integer;
begin
        while b>0 do begin
        c:=b;
        b:a mod b;
        a:=c;end;
        cmmdc(a,b):=a;
end;
begin
        assign(f,'euclid2.in') ;
        assign(fout,'euclid2.out');
        reset(f);
        rewrite(fout);
        readln(f,t);
        for i:=1 to t do begin
        readln(a,b);
        writeln(fout,cmmdc(a,b));
        close(f);
        close(fout);

end