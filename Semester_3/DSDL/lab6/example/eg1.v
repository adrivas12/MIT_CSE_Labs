module eg1(w0, w1, s, f);
	input w0, w1, s;
	output f;
	reg f;
	always @(w0 or w1 or s)
		 f = s?w1:w0;
endmodule