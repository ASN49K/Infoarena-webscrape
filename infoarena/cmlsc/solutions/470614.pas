program cmlsc;
var f, g:text;
    j, i, n, m:longint;
    a, b:array[1..1030] of longint;
    nr:array[1..1030,1..1030] of longint;

procedure citire;
  begin
    readln(f,n,m);
    for i:=1 to n do
      read(f,a[i]);
    for i:=1 to m do
      read(f,b[i]);
  end;

function max(x,y:longint):longint;
  begin
    if x>y then
      max:=x
     else
       max:=y;
  end;

procedure reconstituire;
  begin
    i:=1;
    j:=1;
    while nr[1,1]>0 do
      if a[i]=b[j] then
        begin
          write(g,a[i],' ');
          nr[1,1]:=nr[1,1]-1;
          i:=i+1;
          j:=j+1;
        end
       else
         if nr[i,j]=nr[i,j+1] then
           j:=j+1
          else
            i:=i+1;
  end;

procedure rezolvare;
  begin
    for i:=n downto 1 do
      for j:=m downto 1 do
        if a[i]=b[j] then
          nr[i,j]:=nr[i+1,j+1]+1
         else
           nr[i,j]:=max(nr[i+1,j],nr[i,j+1]);
    writeln(g,nr[1,1]);
    reconstituire;
  end;

  begin
    assign(f,'cmlsc.in'); reset(f);
    assign(g,'cmlsc.out'); rewrite(g);
    citire;
    rezolvare;
    close(f);
    close(g);
  end.