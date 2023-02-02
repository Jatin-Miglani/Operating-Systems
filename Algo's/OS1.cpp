#include <iostream>
#include <iomanip>
using namespace std;
class Process{
    public:
    int B[3]= {24,3,3};
    int n1=sizeof(B)/sizeof(B[0]);
    int W[sizeof(B)/sizeof(B[0])];
    
    
    void Time(){
        int p=0;
        int sum=0;
        for(int i=0;i<n1;i++){
            W[i]=p;
            p=p+B[i];
            sum=sum+W[i];
        }
        cout<<"The average time is "<<sum/3<<endl;
    }

    void Print(){
        cout<<"Process|CPU Burst Time|Waiting Time|"<<endl;
        for(int i=0;i<n1;i++){
            cout<<setw(6);
            cout<<"P"<<i+1<<"|"<<setw(14)<<B[i]<<"|"<<setw(12)<<W[i]<<"|"<<endl;
        }
    }


};
int main(){
    Process p;
    p.Time();
    p.Print();
    return 0;
}