__kernel void ones_complement(__global int *A) {
  int thd = get_global_id(0);
  int oct = 0;
  if(thd%2==0){
    oct = A[thd];
    A[thd]=A[thd+1];
    A[thd+1]=oct;
  }  
}