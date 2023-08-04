`timescale 1ns/1ns
`include "aq1a.v"

module aq1a_tb;
reg a,b,c;
wire f;

aq1a aq1a(a,b,c,f);
initial begin

	$dumpfile("aq1a_tb.vcd");
	$dumpvars(0,aq1a_tb);
	
	a = 0; b = 0; c = 0; 
	#20;
	a = 0; b = 0; c = 1; 
	#20;
	a = 0; b = 1; c = 0; 
	#20;
	a = 0; b = 1; c = 1; 
	#20;
	a = 1; b = 0; c = 0; 
	#20;
	a = 1; b = 0; c = 1; 
	#20;
	a = 1; b = 1; c = 0; 
	#20;
	a = 1; b = 1; c = 1; 
	#20;

	
	$display("Test complete");
	
end

endmodule
