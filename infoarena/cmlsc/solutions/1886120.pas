Program p2;
Var a,b:array[1..1025] of integer;
    d:array[1..1025,1..1025] of integer;
    n,m,i,j,k:integer;
    u:boolean;
    f,g:text;
Begin
     assign(f,'cmlsc.in');
     assign(g,'cmlsc.out');
     reset(f);
     rewrite(g);
     readln(f,n,m);
     for i:=2 to n+1 do read(f,a[i]);
     for i:=2 to m+1 do read(f,b[i]);
     writeln;
     for i:=2 to n+1 do for j:=2 to m+1 do if a[i]=b[j] then d[i,j]:=1+d[i-1,j-1]
                                                    else if d[i-1,j]>d[i,j-1] then d[i,j]:=d[i-1,j]
                                                                              else d[i,j]:=d[i,j-1];
     for i:=2 to n+1 do begin
                      writeln;
                      for j:=2 to m+1 do write(d[i,j],' ');
                      end;
     for i:=2 to n+1 do for j:=2 to m+1 do d[i,j-1]:=d[i,j];
     for j:=1 to m do for i:=2 to n+1 do d[i-1,j]:=d[i,j];
     for i:=2 to n+1 do a[i-1]:=a[i];
     for i:=2 to m+1 do b[i-1]:=b[i];
     writeln;
     writeln(g,d[n,m]);
     k:=0;
     for i:=1 to n do for j:=1 to m do if d[i,j]>k then begin
                                                        write(g,a[i],' ');
                                                        inc(k);
                                                        end;
     close(g);
end.
