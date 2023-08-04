module aq1a(a, b, c, f);
	input a, b, c;
	output f;
	assign f= ((a&(~c))|(b&c)|((~b)&(~c)));
endmodule