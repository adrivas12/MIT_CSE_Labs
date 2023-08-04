module q3(W, En, f);
	input [2:0]W;
	input En;
	wire en1, en2;
	wire [0:3]f1, f2;
	output f;
	assign en1= ~W[0]&En;
	assign en2= W[0]&En;
	dec2to4 stage0(W[2:1], en1, f1[0:3]);
	dec2to4 stage1(W[2:1], en2, f2[0:3]);
	assign f=(f1[1]|f1[2]|f2[0]|f2[4]);
endmodule

module dec2to4(W, En, Y);
	input [1:0]W;
	input En;
	output [0:3]Y;
	reg [0:3]Y;
	always @(W or En)
	begin
	if(En==0)
		Y=4'b1111;
	else
	begin
	case(W)
		0:Y=4'b0111;
		1:Y=4'b1011;
		2:Y=4'b1101;
		3:Y=4'b1110;
	endcase	
	end
	end
endmodule