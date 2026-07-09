program p1;
var a,b,r,:int64;
    n,i:longint;
    f,g:text;
Begin
     assign(f,'euclid2.in');
     assign(g,'euclid2.out');
     reset(f);
     rewrite(g);
     readln(f,n);
     for i:=1 to n do begin
                      readln(f,a,b);
                      if a<b then begin
                                  a:=a+b;
                                  b:=a-b;
                                  a:=a-b;
                                  end;

                      r:=a mod b;
                      while r<>0 do begin
                                    a:=b;
                                    b:=r;
                                    r:=a mod b;
                                    end;
                      writeln(g,b);
                      end;
     close(f);
     close(g);
end.
