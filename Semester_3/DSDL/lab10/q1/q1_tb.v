`timescale 1ns/1ns
`include "q1.v" 

module q1_tb();
reg D, clk, reset; 
wire Q;
q1 q1(D, clk, reset, Q);
initial
begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);

	D=1; reset=1;clk=0;
	#20;
	D=1; reset=1;clk=1;
	#20;
	D=1; reset=1;clk=0;
	#20;
	D=0; reset=1;clk=1;
	#20;
	$display("Test complete");
end
endmodule