Program Euclid;
var f1,f2:text;
    a,b,t,c:longint;
begin
     assign(f1,'euclid2.in');
     assign(f2,'euclid2.out');
     reset(f1);
     rewrite(f2);
     read(f1,t);
     repeat
     read(f1,a,b);
     repeat
           c:=a mod b;
           a:=b;
           b:=c;
     until c=0;
     writeln(f2,a);
     dec(t);
     until t=0;
     close(f1);
     close(f2);
end.