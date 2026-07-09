program cmlsc;

var fi,fo:text;
    m,n,nr:integer;
    a,b,v:array[1..1024]of integer;
    mat:array[0..1024,0..1024]of integer;

    procedure citire;
    var i:integer;
    begin
        readln(fi,n,m);
        for i:=1 to n do read(fi,a[i]);
        for i:=1 to m do
          read(fi,b[i]);
    end;

      function max(a,b:integer):integer; begin max:=a; if b>max then max:=b; end;

    procedure cmlsc;
    var i,j:integer;
    begin
        for i:=1 to n do
          for j:=1 to m do
            begin
                if a[i]=b[j] then
                  mat[i,j]:=mat[i-1,j-1]+1
                else
                  mat[i,j]:=max(mat[i-1,j],mat[i,j-1]);
            end;
        writeln(fo,mat[n,m]);
    end;

    procedure drum;
    var i,j,nr2:integer;
    begin
        i:=n; j:=m;
        nr:=mat[n,m];
        nr2:=nr;
        repeat
          if a[i]=b[j] then
            begin
                v[nr]:=a[i];
                dec(nr);
                dec(i); dec(j);
            end
          else
            if mat[i-1,j]>mat[i,j-1] then
              begin
                  dec(i);
              end
            else
              begin
                  dec(j);
              end;
        until nr=0;

       for i:=1 to nr2 do
         write(fo,v[i],' ');
    end;

begin
    assign(fi,'cmlsc.in'); reset(fi);
    assign(fo,'cmlsc.out'); rewrite(fo);

      citire;

      cmlsc;

      drum;

    close(Fi); close(Fo);
end.