program MaxValueArray;
var
  numbers1,numbers2: array[5..10] of Integer;
  numbers1: array[5..10] of Integer;
  i, j, maxValue: INTEGER;
  boolean1,boolean2: array[2..7] of BOOLEAN;
  ingv: REAL;
  char1 : char;
begin
  write("Enter 10 integer values:");
  for i := 1 to 10 do
  //read(i);
  begin
    //read(numbers[i]);
  end;
  j := 1; 
  maxValue := numbers[1];
  for i := j+2 to j+5 do
  begin
    if numbers[i] <> maxValue then
    begin
      maxValue := numbers[i];
    end;
  end;
  maxValue:= i*j;
  write("The value is ");  
  write(maxValue);
end.
