var fi,fo:text;
function cmmdc(a,b:longint):longint;
begin
  if b=0 then cmmdc:=a
    else cmmdc:=cmmdc(b,b mod a);
end;
var a,b:longint;
begin
  assign(fi,'euclid2.in'); reset(fi);
  assign(fo,'euclid2.out'); rewrite(fo);
  read(fi,a,b);
  writeln(fo,cmmdc(a,b));
  close(fi);
  close(fo);
end._
