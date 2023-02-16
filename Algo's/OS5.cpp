#include <iostream>
#include <iomanip>
using namespace std;
class Process{
    int *B;
    int *N;
    int *P;

    public:
    Process(){
        B=new int[3];
        N=new int[3];
        P=new int[3];
    }

    void Create(){
        for(int i=0;i<3;i++){
            cout<<"Enter Process, Burst Time and Priority Number."<<endl;
            cin>>P[i]>>B[i]>>N[i];
        }
    }

    void Sort(){
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                if(N[j]>N[j+1]){
                    int temp1=N[j];
                    N[j]=N[j+1];
                    N[j+1]=temp1;
                    int temp2=P[j];
                    P[j]=P[j+1];
                    P[j+1]=temp2;
                    int temp3=B[j];
                    B[j]=B[j+1];
                    B[j+1]=temp3;
                }
            }
        }
    }

    void Display(){
        cout<<"Process|Burst Time|Priority Number"<<endl;
        for(int i=0;i<3;i++){
            cout<<setw(7)<<"P"<<P[i]<<setw(11)<<B[i]<<setw(16)<<N[i]<<endl;
        }
    }

    void Commute(){
        float p=0;
        float waiting=0;
        float TAT=0;
        for(int i=0;i<3;i++){
            waiting=waiting+p;
            p=p+float(B[i]);
            TAT=TAT+p;
        }
        cout<<"The Average Waiting time of this process is "<<waiting/3<<endl<<"The Turn Around Time of this Algoritm is "<<TAT/3<<endl;
    }

    ~Process(){
        delete []P;
        delete []B;
        delete []N;
    }
};
int main(){
    Process p;
    p.Create();
    p.Display();
    p.Sort();
    p.Display();
    p.Commute();
    return 0;
}