`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg Cin;
reg [3:0]x, y;
wire [3:0]s;
wire Cout;
q4 q4(Cin, x, y, s, Cout);

initial
begin

	$dumpfile("q4_tb.vcd");
	$dumpvars(0, q4_tb);
	
	Cin=1'b0; x= 4'b0001; y=4'b0011;
	#20;
	Cin=1'b0; x= 4'b0001; y=4'b0111;
	#20;
	Cin=1'b0; x= 4'b0001; y=4'b0101;
	#20;
	
	$display("Test complete");
	
end
endmodule