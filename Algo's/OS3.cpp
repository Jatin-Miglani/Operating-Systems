#include <iostream>
#include <iomanip>
using namespace std;
class Process{
    public:
    int B[3]={24,3,4};
    int TQ=3;
    int n1=sizeof(B)/sizeof(B[0]);
    int W[sizeof(B)/sizeof(B[0])];

    int Processing(){
        int count=0;
        cout<<"P1|P2|P3|"<<endl;
        for(int i=0;i<n1;i++){
            if(B[i]!=0){
                count=count+1;
                B[i]=B[i]-TQ;
                if(B[i]<0){
                    B[i]=0;
                }
                W[i]=B[i];
                cout<<setw(2)<<B[i]<<"|";
            }
            else{
                int j=0;
                cout<<setw((j+1)*2)<<B[i]<<"|";
            }
        }
        cout<<endl;
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