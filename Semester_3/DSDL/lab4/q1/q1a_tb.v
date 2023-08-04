`timescale 1ns/1ns
`include "q1a.v"

module q1a_tb();
reg x, y;
wire s, Cout;
q1a q1a(x, y, s, Cout);

initial
begin

	$dumpfile("q1a_tb.vcd");
	$dumpvars(0, q1a_tb);
	
	x=0; y=0; 
	#10;
	x=0; y=1;
	#10;
	x=1; y=0;
	#10;
	x=1; y=1;
	#10;
	
	$display("Test complete");

end
endmodule
