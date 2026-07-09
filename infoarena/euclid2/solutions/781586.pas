var f,g:text;
    a,b,i,t:longint;
function cmmdc(a,b:longint):longint;
begin
  if b=0 then cmmdc:=a
                else cmmdc:=cmmdc(b,a mod b);
  end;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,t);
 for i:=1 to t do begin
  readln(f,a,b);
  if a>b then writeln(g,cmmdc(a,b))
         else writeln(g,cmmdc(b,a));
         end;
         close(f);close(g);
 end.
