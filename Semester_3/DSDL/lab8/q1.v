module q1(W, En, Y);
	input [2:0]W;
	input En;
	wire En1, En2;
	output [0:7]Y;
	//reg [0:7]Y;
	assign En1 = (~W[0]&En);
	assign En2 = (W[0]&En);
	dec2to4 stage0(W[2:1], Y[0:3], En1);
	dec2to4 stage1(W[2:1], Y[4:7], En2);
endmodule


module dec2to4(W, Y, En);
	input [1:0]W;
	input En;
	output [0:3]Y;
	reg [0:3]Y;
	integer k;
	always @(W or En)
		for(k=0; k<=3; k=k+1)
			if((W==k)&&(En==1))
				Y[k]=1;
			else
				Y[k]=0;
endmodule