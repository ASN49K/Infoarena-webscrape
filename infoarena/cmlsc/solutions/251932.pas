var f,g:text;
    n,m,i,j:integer;
    a,b:array[1..2000] of integer;
    v:array[0..2000,0..2000] of integer;
function max(a,b:integer):integer;
begin
     if a>b then max:=a
            else max:=b;
end;
begin
     assign(f,'cmlsc.in'); reset(f);
     assign(g,'cmlsc.out'); rewrite(g);
     readln(f,n,m);
     for i:=1 to n do read(f,a[i]);
     for i:=1 to m do read(f,b[i]);
     fillchar(v,sizeof(v),0);
     for i:=1 to n do
          for j:=1 to m do
               if a[i]=b[j] then v[i,j]:=v[i-1,j-1]+1
                            else v[i,j]:=max(v[i,j-1],v[i-1,j]);
     for i:=0 to m do v[0,i]:=-2;
     for i:=0 to n do v[i,0]:=-2;
     writeln(g,v[n,m]);
     for i:=1 to n do
          for j:=1 to m do
               if a[i]=b[j] then
               begin
                    write(g,a[i],' ');
                    break;
               end;
     close(g);
end.