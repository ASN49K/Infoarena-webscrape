Program p1;
uses math;
var a,b,c:array[1..10010] of extended;
    viz:array [1..10010] of byte;
    mda:array [1..10010,1..10010] of byte;
    n,i,j,k,r,y:longint;
    d:extended;
    f,g:text;
procedure dfs(var x:longint);
          begin
          viz[x]:=1;
          for i:=1 to n do if mda[x,j]=1 then begin
                                              r:=i;
                                              if viz[i]=0 then dfs(r);
                                              end;
          end;
Begin
     assign(f,'cerc.in');
     assign(g,'cerc.out');
     reset(f);
     rewrite(g);
     readln(f,n);
     for i:=1 to n do readln(f,a[i],b[i],c[i]);
     d:=0;
     k:=0;
     for i:=1 to n do for j:=1 to n do if j<>i then begin
                                                    d:=sqrt(sqr(a[i]-a[j])+sqr(b[i]-b[j]));
                                                    if (d<c[i]+c[j]) and (d+min(c[i],c[j])>max(c[i],c[j])) then Begin
                                                                                                                mda[i,j]:=1;
                                                                                                                mda[j,i]:=1;
                                                                                                                end;
                                                    end;
     for i:=1 to n do if viz[i]=0 then begin
                                       inc(k);
                                       y:=i;
                                       dfs(y);
                                       end;
     for i:=1 to n do for j:=1 to n do if mda[i,j]=1 then inc(k);
     writeln(g,k);
     close(g);

end.
