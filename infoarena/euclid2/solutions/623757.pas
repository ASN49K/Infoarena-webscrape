program cmmdc_1;
var fi,fo:text;
    a,b,i,n:longint;
function cmmdc(a,b:longint):longint;
begin
  if a mod b =0 then cmmdc:=b
                 else cmmdc:=cmmdc(b, a mod b);
end;
begin
assign(fi,'euclid2.in');
reset(fi);
assign(fo,'euclid2.out');
rewrite(fo);
readln(fi,n);
for i:=1 to n do begin
 readln(fi,a,b);
 if a>b then writeln(fo,cmmdc(a,b))
        else writeln(fo,cmmdc(b,a));
                 end;
close(fo);
end.



