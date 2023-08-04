`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [3:0] x,y;
wire G, L, E;
wire g1, g2, l1, l2, e1, e2;

q4 q4( G, L, E, x, y);
initial
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0, q4_tb);

	x= 4'b0001; y=4'b0011;
	#20;
	x= 4'b0001; y=4'b0111;
	#20;
	x= 4'b0001; y=4'b0101;
	#20;

	$display("Test complete");
end
endmodule