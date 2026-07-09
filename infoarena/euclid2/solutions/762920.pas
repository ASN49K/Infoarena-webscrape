program euclid2;
var a,b,i,n:longint;
      fi,fo:text;
function cmmdc(a,b:longint):longint;
begin
if a=b then cmmdc:=a
       else begin
       if a>b then cmmdc:=cmmdc(b,a-b)
                else cmmdc:=cmmdc(a,b-a);
                end;
       end;
begin
assign(fi,'euclid2.in');reset(fi);
assign(fo,'euclid2.out');rewrite(fo);
read(fi,n);
for i:=1 to n do begin read(fi,a,b);
             write(fo,cmmdc(a,b));writeln(fo);
             end;
close(fi); close(fo);
end.