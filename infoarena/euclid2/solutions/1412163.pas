Program euclid2;
 var mi, mo : text;
     a, b, y, t, i : longint;
 function dc(a,b : int64):longint;
  var r: longint;
  begin r:=b;
  while r<>0 do begin
                r:=a mod b;
                a:=b;
                b:=r;
                end;
  dc:=a;
  end;



begin
 assign(mi,'euclid2.in'); reset(mi);
 assign(mo,'euclid2.out');rewrite(mo);
 readln(mi,t);
 for i:=1 to t do begin
                  readln(mi,a,b);
 if b=0 then
             b:=a;

 y:=dc(a,b);
 if y=1 then writeln(mo,'0') else write(mo,y);
 end;
 close(mi);
 close(mo);
end.
