#include<stdio.h>
int main(){
    int n;
    printf("Enter the no's of Number you want to enter: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter number %d:",i+1);
        scanf("%d",&a[i]);
    }
    int largest=0;
     for(int i=0;i<n;i++){
        if(a[i]>largest){
            largest=a[i];
        }

    }
    printf("Largest Number: %d",largest);
    return 0;


}