module q4(G, L, E, x,y);
	input [3:0] x,y;
	output G, L, E;
	wire l1,g1,e1,l2,g2,e2;
	comp2bit stage0(x[0],y[0],x[1],y[1],l1,g1,e1);
	comp2bit stage1(x[2],y[2],x[3],y[3],l2,g2,e2);
	assign E = e1 & e2;
	assign G = g2|(e2&g1);
	assign L = l2|(e2&l1);
endmodule

module comp2bit(x0, x1, y0, y1, l, g, e);
	input x0,y0,x1,y1;
	output l,g,e;
	assign e = (~(x1^y1))&(~(x0^y0));
	assign g = (x1&~y1)|(~(x1^y1)&x0&y0);
	assign l = ~(g|e);
endmodule



/*module q4(G, L, E, x, y);
	input [3:0]x, y;
	output G, L, E;
	wire g1, g2, l1, l2, e1, e2;
	2bit comp1(x[0], x[1], y[0], y[1], g1, l1, e1);
	2bit comp2(x[2], x[3], y[2], y[3], g2, l2, e2);
	assign E=(e1)&(e2);
	assign G=(g2)|(e2&g1);
	assign L=(l2)|(e2&l1);
endmodule

module 2bit(x0, x1, y0, y1, g, l, e);
	input x0, x1, y0, y1;
	output g, l, e;
	assign g=((x1)&(~y1))|(~((x1)^(y1))&(x0)&(y0));
	assign e=(~(x1^y1))&(~(x0^y0));
	assign l=~(g|e);
endmodule*/

