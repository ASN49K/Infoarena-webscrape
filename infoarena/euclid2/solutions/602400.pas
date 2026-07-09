Program euclid;
 var t,a,b,i:longint;
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
   if a>b then a:=a-b
    else b:=b-a;
     until (a=0) or (b=0);
 if a=0 then writeln(fo,b)
  else writeln(fo,a);
  end;
 close(fo);
end.
