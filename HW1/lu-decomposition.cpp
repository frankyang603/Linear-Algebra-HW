#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");
    int num;
    infile>>num;
    for(int i=0;i<num;i++){
        int x,y;
        infile>>x>>y;
        float a[10][10];//U
        float b[10][10]={0};//L
        float c[10][10]={0};//P
        for(int i=0;i<x;i++){//初始化P
            c[i][i]=1;
        }

        for(int i=0;i<x;i++){//輸入陣列
            for(int j=0;j<y;j++){
                infile>>a[i][j];
            }
        }
        if(x>=2&&x<=10&&y>=2&&y<=10){
        int determine=0;//see if need to print out P
        int pivot=0;//find from this one

        for(int j=0;j<y;j++){
            int t=pivot;//the beginning finding one
            while(a[t][j]==0&&t<x){//find new t if needed
                t++;
            }
            if(t<x){//use with determine
            for(int w=0;w<y;w++){//change two row newt and pivot  
                if(t!=pivot){//determine usage
                    determine++;
                    float temp1;//change U
                    temp1=a[t][w];
                    a[t][w]=a[pivot][w];
                    a[pivot][w]=temp1;
                }
                float temp2;//change L
                temp2=b[t][w];
                b[t][w]=b[pivot][w];
                b[pivot][w]=temp2;
                float temp3;//change P
                temp3=c[t][w];
                c[t][w]=c[pivot][w];
                c[pivot][w]=temp3;
            }
            for(int i=pivot+1;i<x;i++){//Gauss elimination
                    float k;
                    k=a[i][j]/a[pivot][j];
                    b[i][pivot]=k;//put into L
                    for(int h=0;h<y;h++){//do the Gauss elimination
                        a[i][h]-=a[pivot][h]*k;
                    }
            }
            pivot++;//if no all zero in the column from pivot
            }
        }
        
        for(int i=0;i<x;i++){//初始化L
            b[i][i]=1;
        }
        
        //輸出
        
        if(determine!=0){//if print out P is needed
            outfile<<"false\n";
            outfile<<x<<" "<<x<<"\n";
            for(int i=0;i<x;i++){
                for(int j=0;j<x;j++){
                    outfile<<fixed<<setprecision(2)<<c[i][j]<<" ";
                }
                outfile<<"\n";
            }
        }
        else{//do not need to print out P
            outfile<<"true\n";
        }
        
        outfile<<x<<" "<<x<<"\n";//print out L
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                outfile<<fixed<<setprecision(2)<<b[i][j]<<" ";
            }
            outfile<<"\n";
        }

        outfile<<x<<" "<<y<<"\n";//print out U
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                outfile<<fixed<<setprecision(2)<<a[i][j]<<" ";
            }
            outfile<<"\n";
        }
        }
        else{
            outfile<<"illegal\n";
        }
    }
    return 0;
}