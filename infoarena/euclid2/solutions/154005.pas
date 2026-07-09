var f,g:text;
    a,b,c:longint;
begin
     assign(f,'euclid2.in');
     assign(g,'euclid2.out');
     reset(f);
     rewrite(g);
     read(f,t);
     repeat
     read(f,a,b);
     repeat
           c:=a mod b;
           a:=b;
           b:=c;
     until c=0;
     writeln(g,a);
     dec(t);
     until t=0;
     close(f);
     close(g);
end.
