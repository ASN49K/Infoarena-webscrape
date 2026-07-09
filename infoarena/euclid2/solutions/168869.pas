program eucld;
var t,i,x,y: longint;
f,g: text;
function euc(a,b: longint): longint;
begin
     if b=0 then euc:=a else
     euc:=euc(b,a mod b);
end;
begin
     assign(f,'euclid2.in');
     reset(f);
     assign(g,'euclid2.out');
     rewrite(g);
     readln(f,t);
     for i:=1 to t do
     begin
          readln(f,x,y);
          writeln(g,euc(x,y));
     end;
     close(g);
end.