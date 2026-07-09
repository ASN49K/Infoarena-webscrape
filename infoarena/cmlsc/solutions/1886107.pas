Program p2;
Var a,b:array[1..1025] of integer;
    d:array[1..1025,1..1025] of integer;
    n,m,i,j:integer;
    u:boolean;
    f,g:text;
Begin
     assign(f,'cmlsc.in');
     assign(g,'cmlsc.out');
     reset(f);
     rewrite(g);
     readln(n,m);
     if n<m then begin
                 n:=n+m;
                 m:=n-m;
                 n:=n-m;
                 end;
     for i:=2 to n+1 do read(a[i]);
     for i:=2 to m+1 do read(b[i]);
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
     for i:=1 to n do begin
                      u:=false;
                      if i=1 then  begin for j:=1 to m do if d[i,j]=1 then u:=true ; end
                                                                  else for j:=1 to m do if d[i,j]>d[i-1,j] then u:=true;
                      if u then write(g,a[i],' ');
                      end;
     close(g);
end.
