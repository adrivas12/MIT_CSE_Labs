//Write an OpenCL program which takes N intergers as input. It converts these integers into 
//their corresponding octal values and stores the result in another array in parallel

#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#define MAX_SOURCE_SIZE (0x100000) //Max source size of kernel string 

int main(void){
	//Create 2 input vectors  
	int i; 
	int LIST_SIZE; 
	printf("Enter how many elements: "); 
	scanf("%d", &LIST_SIZE); 

	//initialize input vectors 
	int *A = (int*)malloc(sizeof(int)*LIST_SIZE); 
	printf("Enter %d elements: ", LIST_SIZE); 
	for(i = 0; i<LIST_SIZE; i++){
		scanf("%d", &A[i]); 
	}

	//load the kernel source code into the array source_str
	FILE *fp; 
	char *source_str; 
	size_t source_size; 
	fp = fopen("vectorCLKernel1.cl", "r"); 
	if(!fp){
		fprintf(stderr, "Failed to load kernel. \n"); 
		getchar(); 
		exit(1); 
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE); 
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp); 
	fclose(fp); 

	//platform and device information
	cl_platform_id platform_id = NULL; 
	cl_device_id device_id = NULL; 
	cl_uint ret_num_devices; 
	cl_uint ret_num_platforms; 
	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms); 
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices); 
	
	//Create OpenCL context
	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret); 
	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret); 

	//Create memory bufferes on the device for each vector A, B, and C
	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE*sizeof(int), NULL, &ret); 
	cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE*sizeof(int), NULL, &ret); 
	
	//copy A and B to respective memory buffers
	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE*sizeof(int), A, 0, NULL, NULL); 

	//Create program from kernel source 
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret); 

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL); //build program
	cl_kernel kernel = clCreateKernel(program, "octal", &ret); //create OpenCL kernel object

	//set arguments of the kernel
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj); 	
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&c_mem_obj); 	

	//execute OpenCL kernel on teh array 
	size_t global_item_size = LIST_SIZE; 
	size_t local_item_size = 1; 

	cl_event event; 
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL); 
	ret = clFinish(command_queue); 
	//read memory buffer
	int *C = (int*)malloc(sizeof(int)*LIST_SIZE); 
	ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, LIST_SIZE*sizeof(int), C, 0, NULL, NULL); 
	
	for(i = 0; i<LIST_SIZE; i++)
		printf("A = %d C=%d\n", A[i], C[i]);


	//clean up
	ret = clFlush(command_queue); 
	ret = clReleaseKernel(kernel); 
	ret = clReleaseProgram(program); 
	ret = clReleaseMemObject(a_mem_obj); 
	ret = clReleaseMemObject(c_mem_obj); 
	ret = clReleaseCommandQueue(command_queue); 
	ret = clReleaseContext(context); 

	free(A); 
	free(C); 
	getchar(); 
	return 0; 
}

