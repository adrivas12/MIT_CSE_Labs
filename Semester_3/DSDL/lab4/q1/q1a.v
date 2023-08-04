module q1a(x, y, s, Cout);
	input x, y;
	output s, Cout;
	assign s = x^y;
	assign Cout = x&y;
endmodule