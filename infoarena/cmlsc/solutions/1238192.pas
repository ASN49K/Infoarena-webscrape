program cmlsc;

var
 i,j,n,m,con:word;
 a,b,c:array[1..1024] of smallint;
 f:text;


begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 for i:=1 to n do read(f,a[i]);
 for i:=1 to m do read(f,b[i]);
 close(f);

 for i:=1 to n-1 do for j:=i+1 to n do if a[i]=a[j] then a[j]:=-1;
 con:=0;
 for i:=1 to n do for j:=1 to m do if a[i]=b[j] then
                                begin
                                 con:=con+1;
                                 c[con]:=a[i];
                                 end;
 assign(f,'cmlsc.out');
 rewrite(f);
 writeln(f,con);
 for i:=1 to con do write(f,c[i],' ');
 close(f);
 end.