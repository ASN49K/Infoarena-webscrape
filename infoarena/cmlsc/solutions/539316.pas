program lungime;
var lsc:array[0..1025,0..1025]of longint;
    x,y,d:array[0..1025]of longint;
    i,j,n,m,cont:longint;
    t:text;

function max(x,y:longint):longint;
begin
 if x<y then max:=y else max:=x;
end;


begin
 assign(t,'cmlsc.in'); reset(t);
 readln(t,n,m);

 for i:=1 to n do read(t,x[i]);
 readln(t);
 for i:=1 to m do read(t,y[i]);

 close(t);


 for i:=1 to n do begin
        for j:=1 to m do
                if x[i]=y[j] then lsc[i,j]:=lsc[i-1,j-1]+1
                else lsc[i,j]:=max(lsc[i-1,j],lsc[i,j-1]);
 end;


 i:=n;
 cont:=0;
 j:=m;
 repeat
        if x[i]=y[j] then begin inc(cont); d[cont]:=x[i]; dec(i); dec(j); end
        else if lsc[i,j]=lsc[i-1,j] then dec(i) else
               if lsc[i,j]=lsc[i,j-1] then dec(j);
 until cont=lsc[n,m];

 assign(t,'cmlsc.out'); rewrite(t);
 writeln(t,lsc[n,m]);
 for i:=cont downto 1 do write(t,d[i],' ');
 close(t);
end.