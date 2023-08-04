module q1a(a, b, c, d, f);
	input a, b, c, d;
	output f;
	and(g, a, b);
	or(h, g, c);
	not(k, h);
	and(m, k, d);
	or(n, h, d);
	and(f, n, m);
endmodule