`timescale 1ns/1ns
`include "q2a.v"

module q2a_tb;
reg a,b,c,d;
wire f,g;

q2a q2a(a,b,c,d,f,g);
initial begin

	$dumpfile("q2a_tb.vcd");
	$dumpvars(0,q2a_tb);
	
	a=0;b=0;c=0;d=0;
	#10;
	
	a=0;b=0;c=0;d=1;
	#10;
	
	a=0;b=0;c=1;d=0;
	#10;
	
	a=0;b=0;c=1;d=1;
	#10;
	
	a=0;b=1;c=0;d=0;
	#10;
	
	a=0;b=1;c=0;d=1;
	#10;
	
	a=0;b=1;c=1;d=0;
	#10;
	
	a=0;b=1;c=1;d=1;
	#10;
	
	a=1;b=0;c=0;d=0;
	#10;
	
	a=1;b=0;c=0;d=1;
	#10;
	
	a=1;b=0;c=1;d=0;
	#10;
	
	a=1;b=0;c=1;d=1;
	#10;
	
	a=1;b=1;c=0;d=0;
	#10;
	
	a=1;b=1;c=0;d=1;
	#10;
	
	a=1;b=1;c=1;d=0;
	#10;
	
	a=1;b=1;c=1;d=1;
	#10;
	
	$display("Test complete");
	
end

endmodule
