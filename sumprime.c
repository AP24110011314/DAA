#include<stdio.h>
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
   
    int sum=0;
    for(int i=1;i<n;i++){
        int m=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                m++;
            }
        }
        if(m==2){
            sum=sum+i;
        }
        
    }
    printf("The sum of prime number: %d",sum);
    return 0;


}