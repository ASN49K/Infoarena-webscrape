var a,b,c:array[0..1024] of integer;
    l:array[0..1024,0..1024] of integer;
    k,m,n,i,j:integer;

function max(a,b:integer):integer;
begin
    if a>b then max:=a
    else max:=b;
end;

procedure calcul();
var i,j:integer;
begin
    for i:=0 to n do l[i,0]:=0;
    for j:=1 to m do l[0,j]:=0;
    for i:=1 to n do
     for j:=1 to m do
     if a[i]=b[j] then l[i,j]:=l[i-1,j-1]+1
     else l[i,j]:=max(l[i-1,j],l[i,j-1]);

     //
    // for i:=1 to n do  begin
    // for j:=1 to m do write(l[i,j],' '); writeln;
    // end;
end;

procedure construire(i,j:integer);
begin
      if (i>=1) and (j>=1) then
        if a[i]=b[j] then
        begin
             construire(i-1,j-1);
             k:=k+1;
             c[k]:=a[i];
        end else
            begin
                 if l[i-1,j]>l[i,j-1] then construire(i-1,j)
                 else construire(i,j-1);
            end;
end;

Begin
     assign(input,'cmlsc.in'); reset(input);
     assign(output,'cmlsc.out'); rewrite(output);
     readln(input,n,m);
     for i:=1 to n do read(input,a[i]);
     for i:=1 to m do read(input,b[i]);
     k:=0;
     calcul;
     construire(n,m);
     writeln(output,k);
     for i:=1 to k do write(output,c[i],' ');
    close(input);   close(output);
end.