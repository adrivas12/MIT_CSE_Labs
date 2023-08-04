`timescale 1ns/1ns
`include "q1c.v"

module q1c_tb();
reg x, y, Cin;
wire s, Cout;
q1c q1c(Cin, x, y, s, Cout);

initial
begin

	$dumpfile("q1c_tb.vcd");
	$dumpvars(0, q1c_tb);
	
	x=0; y=0; Cin=0;
	#10;
	x=0; y=0; Cin=1;
	#10;
	x=0; y=1; Cin=0;
	#10;
	x=0; y=1; Cin=1;
	#10;
	x=1; y=0; Cin=0;
	#10;
	x=1; y=0; Cin=1;
	#10;
	x=1; y=1; Cin=0;
	#10;
	x=1; y=1; Cin=1;
	#10;
	
	
	$display("Test complete");
	
end
endmodule