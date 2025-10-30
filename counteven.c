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
    int even=0;
    int odd=0;
     for(int i=0;i<n;i++){
        if(a[i]%2==0){
            even++;
        }
        else{
            odd++;
        }

    }
    printf("No's of even numer: %d\n",even);
    printf("No's of odd numer: %d",odd);
    return 0;


}