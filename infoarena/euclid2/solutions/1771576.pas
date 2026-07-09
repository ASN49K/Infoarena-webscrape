var a,b:qword;
t:qword;i :longint;
f,fout:text;
function cmmdc(n1,n2:qword):qword;
begin
        while n1<>n2 do if n1>n2 then n1:=n1-n2
        else n2:=n2-n1;
        cmmdc:=n1;
end;

begin
        assign(f,'euclid2.in') ;
        assign(fout,'euclid2.out');
        reset(f);
        rewrite(fout);
        readln(f,t);
        for i:=1 to t do begin
        readln(f,a,b);

        writeln(fout,cmmdc(a,b));end;
        close(f);
        close(fout);

end.