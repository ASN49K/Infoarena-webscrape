program euclid;
var a,b:text;
 x,y:longint;
 function cmmdc(x,y:longint):longint;
  begin
  if x=0 then exit(y) else
   if y=0 then exit(x) else exit(cmmdc(y, x mod y));
  end;
 begin
  assign(a,'euclid2.in');
  assign(b,'euclid2.out');
  reset(a);
  rewrite(b);
  readln(a);
  while not(eof(a)) do
   begin
    Readln(a,x,y);
    Writeln(b,cmmdc(x,y));
   end;
  close(B);
 end.