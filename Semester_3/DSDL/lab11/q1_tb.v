`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg clk;
wire [3:0]A;
q1 q1(clk, A);
intital
begin
	clk=0;
	always #5 clk=~clk;
	end
initial 
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);
	//$monitor($time, "A=%4b", A);
	#20
end 
endmodule

