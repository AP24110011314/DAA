#include<iostream>
using namespace std;
int powfun(int x,int n){
   
    if(n==0){
        return 1;
    }
    int temp=powfun(x,n/2);
        if(n%2==0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
    

}
int add(int x,int n){
    if(x==1){
        return n+1;
    }
    int power=powfun(x,n);
   int  sum=(power-1)/(x-1);
    return sum;

}
int main(){
    int x,n;
    cout<<"Enter the base X : ";
    cin>>x;
    cout<<endl<<"Enter the length of series :";
    cin>>n;
    int power;
    cout<<endl;
    int sum;
    
    sum=add(x,n);
     
   
        cout<<endl<<"The total sum :";
        cout<<sum;
    return 0;
}