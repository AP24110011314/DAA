#include<iostream>
using namespace std;
int main(){
    
    int power;
    cout<<endl;
    int sum;
   
    
    for(int i=0;i<10;i++){
        if(i==0){
            sum=1;
            power=1;

            cout<<power<<" ";
        }
        else{
            power=power*2;
            cout<<power<<" ";
            sum+=power;

        }
        
    }
    cout<<endl<<"The total sum :";
        cout<<sum;
    return 0;
}