module q3(j, k, clk, reset, Q);
	input j, k, clk, reset;
	output Q;
	reg Q;
	always @(posedge clk)
	begin
	casex({reset, j, k})
	3'b0xx: Q<=0;
	3'b101: Q<=0;
	3'b110: Q<=1;
	3'b111: Q<=~Q;
	3'b100: Q<=Q;
	endcase
	end
endmodule