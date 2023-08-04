module q5(W, Z, Y);
	input [0:15]W;
	output reg [0:3]Y;
	output reg Z;
	integer k;
	always @(W)
		begin
			Z=0;
			if(W==0)
				Y=0;
			else 
				begin
					for(k=0; k<16; k=k+1)
					begin 
						if(W[k]==1)
							Y=k;
					end
					Z=1;
				end
		end
endmodule