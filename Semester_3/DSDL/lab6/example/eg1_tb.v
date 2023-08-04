`timescale 1ns/1ns
`include "eg1.v"

module eg1_tb();
reg w0, w1, s;
eg1 eg1(w0, w1, s, f);
initial 
begin
	$dumpfile("eg1_tb.vcd");
	$dumpvars(0,eg1_tb);

	s=1'b0;w0=1'b0;w1=1'b0;
	#20;
	s=1'b0;w0=1'b0;w1=1'b1;
	#20;
	s=1'b0;w0=1'b1;w1=1'b0;
	#20;
	s=1'b0;w0=1'b1;w1=1'b1;
	#20;
	s=1'b1;w0=1'b0;w1=1'b0;
	#20;
	s=1'b1;w0=1'b0;w1=1'b1;
	#20;
	s=1'b1;w0=1'b1;w1=1'b0;
	#20;
	s=1'b1;w0=1'b1;w1=1'b1;
	#20;
	
	$display("test complete");
end
endmodule