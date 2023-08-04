`timescale 1ns/1ns
`include "q1b.v"

module q1b_tb();
reg Cin, x, y;
wire s, Cout;
q1b q1b(Cin, x, y, s, Cout);

initial
begin

	$dumpfile("q1b_tb.vcd");
	$dumpvars(0, q1b_tb);
	
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