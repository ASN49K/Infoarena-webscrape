Program  cmlsc;
var c :array [0..1024,0..1024] of longint;
    a,b,SOL:array [0..1024] of longint;
    n,m,i,j,K :longint;
function maxim(a,b :longint) :longint ;
    begin
         if b>a then maxim:=b
                else maxim:=a;
    end;
begin
     assign(input,'cmlsc.in'); reset(input);
     assign(output,'cmlsc.out'); rewrite(output);
     readln(n,m);
     for i:=1 to n do read(A[i]);
     for j:=1 to m do read(B[j]);
     for i:=1 to n do c[i,0]:=0;
     for j:=1 to m do c[0,j]:=0;
     for i:=1 to n do
           for j:=1 to m do begin
                                  if A[i]=B[j] then c[i,j]:=c[i-1,j-1]+1
                                               else c[i,j]:=maxim(c[i,j-1],c[i-1,j]);
                            end;
    writeln(c[n,m]);
    i:=n; j:=m; k:=1;
    while (i>0) and (j>0) do begin
                                     if A[i]=B[j] then begin
                                                              SOL[K]:=b[J];
                                                              k:=k+1;
                                                              i:=i-1;
                                                              j:=j-1;
                                                        end
                                                   else
                                                            if c[i,j]=c[i-1,j] then i:=i-1
                                                                              else j:=j-1;
                              end;
     FOR I:=k-1 downto 1 do write(sol[i],' ');

     close(input); close(output);

  end.
