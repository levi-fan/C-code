int* twoSum(int num[],int numsize,int target,int *pp){
    int i,j;
    int*p=(int*)malloc(sizeof(int)*2);
    for(i=0;i<numsize-1;i++){
        for(j=i+1;j<numsize;j++){
            if((num[i]+num[j])==target){
                p[0]=i;
                p[1]=j;
               // *retSize=2;
               *pp=2;
                return p;
            }
        }
    }//retSize=0;
   return NULL;
       
}/*
//函数，leetcode-Hot-100，第一个
