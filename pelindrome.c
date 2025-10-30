#include<stdio.h>
int main()
{
int n;
int r;
    int m=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    int p=n;
    while(n!=0){
        r=n%10;
        m=(m*10)+r;
        n=n/10;
    }
   if(m==p){
    printf("The given number is a pelindrome number:%d",p);
   }
   else{
    printf("Not a pelindrome.");
   }
   return 0;
}