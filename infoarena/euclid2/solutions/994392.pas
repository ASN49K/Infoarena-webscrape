Program euclid2;
var fi,fo :text;
    n,i,a,b : longint;
function cmmdc(a,b:longint):longint;
begin
     if a mod b = 0 then cmmdc:=b
                    else cmmdc:=cmmdc(b, a mod b);
end;
begin
     assign(fi,'euclid2.in'); reset(fi); readln(fi,n);
     assign(fo,'euclid2.out'); rewrite(fo);
     for i:=1 to n do begin read(fi,a,b); 
     writeln(fo,cmmdc(a,b));
     close(fi); close(fo);
end.