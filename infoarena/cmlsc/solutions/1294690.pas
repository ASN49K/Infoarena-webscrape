type
 sir=array[1..1100] of byte;
 mat=array[0..1100,0..1100] of byte;
var
f:text;
a,b:sir;
n,m,i,j:integer;
lcs:mat;

procedure sol(i,j:integer);
        begin
        if lcs[i][j]<>0 then
         if a[i]=b[j] then
                begin
                sol(i-1,j-1);
                write(f,a[i],' ');
                end
         else
          if lcs[i][j]=lcs[i-1][j] then sol(i-1,j)
          else if lcs[i][j]=lcs[i][j-1] then sol(i,j-1);
         end;

begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 for i:=1 to n do read(f,a[i]);
 for i:=1 to m do read(f,b[i]);
 close(f);

 for i:=1 to n do
        for j:=1 to m do
                if a[i]=b[j] then lcs[i][j]:=1+lcs[i-1][j-1]
                else
                 if lcs[i-1][j]>lcs[i][j-1] then lcs[i][j]:=lcs[i-1][j]
                 else lcs[i][j]:=lcs[i][j-1];
 assign(f,'cmlsc.out');
 rewrite(f);
 writeln(f,lcs[n][m]);
 sol(n,m);
 close(f);

end.