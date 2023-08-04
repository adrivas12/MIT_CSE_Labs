`timescale 1ns/1ns
`include "q2.v"

module q2_tb();
reg Cin;
reg [3:0]x, y;
wire [3:0]s,z;
wire Cout;
wire [3:1]c;
q2 q2(Cin, x, y, s, Cout);

initial
begin

	$dumpfile("q2_tb.vcd");
	$dumpvars(0, q2_tb);
	
	Cin=1'b0; x= 4'b0001; y=4'b0011;
	#20;
	Cin=1'b0; x= 4'b0001; y=4'b0111;
	#20;
	Cin=1'b0; x= 4'b0001; y=4'b0101;
	#20;
	
	$display("Test complete");
	
end
endmodule