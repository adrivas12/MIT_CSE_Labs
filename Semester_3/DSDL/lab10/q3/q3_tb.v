`timescale 1ns/1ns
`include "q3.v" 

module q3_tb();
reg j, k, clk, reset; 
wire Q;
q3 q3(j, k, clk, reset, Q);
initial
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0, q3_tb);

	j=0;k=0; reset=0;clk=0;
	#20;
	j=0;k=1; reset=1;clk=1;
	#20;
	j=1;k=0; reset=1;clk=0;
	#20;
	j=1;k=1; reset=1;clk=1;
	#20;
	j=0;k=0; reset=1;clk=0;
	#20;
	$display("Test complete");
end
endmodule