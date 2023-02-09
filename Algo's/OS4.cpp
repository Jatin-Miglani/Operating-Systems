#include <iostream>
#include <iomanip>
using namespace std;
class Array{
    int *P;
    int *B;
    int *O;
    int *L;
    int *T;

    public:
    Array(){
        P=new int[3];
        B=new int[3];
        O=new int[3];
        L=new int[3];
        T=new int[3];
    }

    void Allocate(){
        for(int i=0;i<3;i++){
            cout<<"Enter "<<i<<endl;
            cin>>P[i]>>B[i]>>O[i];
        }
    }

    void Sort(){
        for(int i=0;i<3;i++){
            for(int j=i;j<2;j++){
                if(O[j]>O[j+1]){
                    int temp=O[j];
                    O[j]=O[j+1];
                    O[j+1]=temp;
                    int temp1=P[j];
                    P[j]=P[j+1];
                    P[j+1]=temp1;
                    int temp2=B[j];
                    B[j]=B[j+1];
                    B[j+1]=temp2;
                }
            }
        }
    }

    void Display(){
        cout<<"Process|Burst Time|Arrival Time|Leaving Time|Turn-Around-Time"<<endl;
        for(int i=0;i<3;i++){
            cout<<setw(7)<<"P"<<P[i]<<setw(10)<<B[i]<<setw(12)<<O[i]<<setw(12)<<L[i]<<setw(16)<<T[i]<<endl;
        }
    }

    void Waitingtime(){
        int p=0;
        int sum=0;
        int LT=0;
        for(int i=0;i<3;i++){
            sum=sum+p;
            p=B[i];
            LT=LT+p;
            L[i]=LT;
        }
        cout<<"Average Waiting time is "<<sum/3<<endl;
    }

    void TAT(){
        for(int i=0;i<3;i++){
            T[i]=L[i]-(O[i]-1);
        }
    }
    ~Array(){
        delete []P;
        delete []B;
        delete []O;
        delete []L;
        delete []T;

    }
};
int main(){
    Array a;
    a.Allocate();
    a.Sort();
    a.Waitingtime();
    a.TAT();
    a.Display();
    return 0;
}