module q2(t, clk, reset, Q);
	input t, clk, reset; 
	output Q;
	reg Q;
	always @(posedge reset or negedge clk)
	begin
	if(!reset)
	Q<=0;
	else
	Q<=~Q;
	end
endmodule