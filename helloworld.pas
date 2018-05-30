program Hello;
var i, j: integer;
begin
  writeln ('Hello, world.');
  i := 0;
  j := 0;
  for i := 0 to 100 do
  begin
    j := j + 1;
  end;
  write (j);
end.