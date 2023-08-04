`timescale 1ns/1ns
`include "q3.v"

module q3_tb();
reg clk;
wire [3:0]q;
q3 q3(clk, q);
always #5 clk=~clk;
initial
begin
clk=1;
#150 $finish;
end 
initial 
begin
$dumpfile("q3_tb.vcd");
$dumpvars(0, q3_tb);
$monitor($time, "q=%4b", q);
#12;
end
endmodule
