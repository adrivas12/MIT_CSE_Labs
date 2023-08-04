module q4(W, I, En, f);
	input [2:0]W;
	input [0:7]I;
	input En;
	wire [0:7]f1;
	output f;
	dec3to8 stage0(W[2:0], En, f1[0:7]);
	assign f=(I[0]&f1[0])|(I[1]&f1[1])|(I[2]&f1[2])|(I[3]&f1[3])|(I[4]&f1[4])|(I[5]&f1[5])|(I[6]&f1[6])|(I[7]&f1[7]);
endmodule

module dec3to8(W, En, Y);
	input [2:0]W;
	input En;
	output [0:7]Y;
	reg [0:7]Y;
	integer k;
	always @(W or En)
		for(k=0; k<=7; k=k+1)
			if((W==k)&&(En==1))
				Y[k]=1;
			else 
				Y[k]=0;

endmodule