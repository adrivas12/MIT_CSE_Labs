module q1 (D, clk, reset, Q);
	input D, clk, reset;
	output Q;
	reg Q;
	always @(posedge clk or negedge reset)
	if (reset)
	Q <= D;
	else
	Q <= 0;
endmodule