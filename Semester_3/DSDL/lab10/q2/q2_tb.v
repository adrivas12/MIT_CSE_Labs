`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg t, clk, reset; 
wire Q;
q2 q2(t, clk, reset, Q);
initial
begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0, q2_tb);

	t=0; reset=0;clk=0;
	#20;
	t=0; reset=0;clk=1;
	#20;
	t=1; reset=0;clk=0;
	#20;
	t=0; reset=1;clk=1;
	#20;
	$display("Test complete");
end
endmodule