uses    math;
const   tfi='cmlsc.in';
        tfo='cmlsc.out';
        maxn=1025;
var     fi,fo:text;
        cnt,n,m:longint;
        kq,a,b:array[0..maxn] of longint;
        f:array[0..maxn,0..maxn] of longint;

procedure enter;
var     i:longint;
begin
        read(fi,n,m);
        for i:=1 to n do read(fi,a[i]);
        for i:=1 to m do read(fi,b[i]);
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
