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
    int m;
    int p=0;
    printf("Enter the element to search:");
    scanf("%d",&m);
     for(int i=0;i<n;i++){
        if(a[i]==m){
            p=1;
            break;
        }

    }
    if(p==1){
        printf("The Element found: %d",m);
    }
    else{
        printf("Not found:");
    }
    return 0;


}