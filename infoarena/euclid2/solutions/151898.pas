var f,g:text;
    a,b,c:longint;
begin
     assign(f,'euclid2.in');
     assign(g,'euclid2.out');
     reset(f);
     rewrite(g);
     read(f,a,b);
     repeat
           c:=a mod b;
           a:=b;
           b:=c;
     until c=0;
     write(g,a);
     close(f);
     close(g);
end.