`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [3:0]w;
reg s0, s1;
wire f;

q1 q1(w, s0, s1, f);
initial 
begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);

	w=4'b0011;s0=1'b0;s1=1'b0;
	#10;
	w=4'b0011;s0=1'b0;s1=1'b1;
	#10;
	w=4'b0011;s0=1'b1;s1=1'b0;
	#10;
	w=4'b0011;s0=1'b1;s1=1'b1;
	#10;

	w=4'b1010;s0=1'b0;s1=1'b0;
	#10;
	w=4'b1010;s0=1'b0;s1=1'b1;
	#10;
	w=4'b1010;s0=1'b1;s1=1'b0;
	#10;
	w=4'b1010;s0=1'b1;s1=1'b1;
	#10;

	$display("test complete");
end
endmodule