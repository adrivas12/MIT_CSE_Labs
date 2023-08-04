module q1a(a, b, c, d, f);
	input a, b, c, d;
	output f;
	assign f = ((~c&~d&b)|(b&~a)|(c&d)|(~b&c));
endmodule