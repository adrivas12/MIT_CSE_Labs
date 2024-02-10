__kernel void str_chgcase (__global char *A, __global int *B, __global char *C)
{
    int i = get_global_id(0);
    int n = B[0]; 
    size_t len = 0;
    while(A[len] != '\0') {
        len++;
    }
    for(int j = 0; j<n; j++){
        C[i+j*len] = A[i]; 
    }
}
