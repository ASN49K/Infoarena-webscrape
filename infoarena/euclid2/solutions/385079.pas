program pe2;
var   f,g:text;p,q,x,t,i:longint;
function cmmdc(d,i:longint):longint;
var r:longint;
  begin
  r:= d mod i;
    while r<>0 do begin
    d:=i;i:=r;r:=d mod i; end;cmmdc:=i;end;
  begin
  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
   readln(f,t);
    for i:=1 to t do begin
     readln(f,p,q);
     writeln(g,cmmdc(p,q));end;
     close(f);close(g);
    end.