var a , b : longint ;
    f , g : text ;
function cmmdc(a , b : longint) : longint ;
 begin
  if a=b then cmmdc:=a
   else if a>b then cmmdc:=cmmdc(a-b,b)
    else cmmdc:=cmmdc(a,b-a) ;
 end ;
begin
 assign(f,'cmmdc.in') ;
 reset(f) ;
 read(f,a) ;
 readln(f,b) ;
 close(f);
 assign(g,'cmmdc.out') ;
 rewrite(g) ;
 writeln(g,cmmdc(a,b)) ;
 close(g) ;
end.

