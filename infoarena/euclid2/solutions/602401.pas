Program euclid;
 var t,a,b,i,r:longint;
     fi,fo: text;
begin
 assign(fi,'euclid2.in');
  reset(fi);
 assign(fo,'euclid2.out');
  rewrite(fo);
 readln(fi,t);
 for i:=1 to t do begin
 readln(fi,a,b);
 repeat
  r:=a mod b;
  a:=b; b:=r;
  until r=0;
  writeln(fo,a);
  end;
 close(fo);
end.
