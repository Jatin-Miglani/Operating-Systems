#include <iostream>
using namespace std;
class Process{
    public:
    int B[3]={24,3,4};
    int TQ=3;
    int n1=sizeof(B)/sizeof(B[0]);
    int W[sizeof(B)/sizeof(B[0])];

    int Processing(){
        int count=0;
        for(int i=0;i<n1;i++){
            if(B[i]!=0){
                count=count+1;
                B[i]=B[i]-TQ;
                if(B[i]<0){
                    B[i]=0;
                }
                W[i]=B[i];
                cout<<"P"<<i+1<<" ->";
            }
        }
        if(count!=0){
            return Processing();
        }
        else{
            return 0;
        }
    }
};
int main(){
    Process p;
    p.Processing();
    return 0;
}