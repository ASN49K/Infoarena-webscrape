uses    math;
const   tfi='cmlsc.in';
        tfo='cmlsc.out';
        maxn=1025;
var     fi,fo:text;
        cnt,n,m:longint;
        kq,a,b,t:array[0..maxn] of longint;
        f:array[0..maxn,0..maxn] of longint;

procedure enter;
var i,j:integer;
     x:byte;
begin
 readln(fi,n,m);
 for i:=1 to n do
   begin
    read(fi,a[i]);
    t[ a[i] ]:= $0F;
   end;
 j:=0;
 for i:=1 to m do
   begin
    read(fi,x);
    if t[x] <> 0 then
        begin
         inc(j);
         b[j]:=x;
         t[x]:=$ff;
        end;
   end;
 m:=j;
 j:=0;
 for i:=1 to n do
   if t[ a[i] ] = $ff then
      begin
       inc(j);
       a[j]:=a[i];
      end;
 n:=j;
end;

procedure trace(u,v:longint);
begin
        if (u=0) or (v=0) then exit;
        if a[u]=b[v] then
         begin
          inc(cnt);
          kq[cnt]:=a[u];
          trace(u-1,v-1)
         end
        else
        if f[u,v]=f[u-1,v] then trace(u-1,v) else trace(u,v-1);
end;

procedure process;
var     i,j:longint;
begin
        for i:=1 to n do
         for j:=1 to m do
          if a[i]=b[j] then f[i,j]:=f[i-1,j-1]+1
          else f[i,j]:=max(f[i-1,j],f[i,j-1]);
         writeln(fo,f[n,m]);
        trace(n,m);
        for i:= cnt downto 1 do write(fo,kq[i],' ');
end;

begin
        assign(fi,tfi); reset(fi);
        assign(fo,tfo); rewrite(fo);
        enter;
        process;
        close(fi); close(fo);
end.
