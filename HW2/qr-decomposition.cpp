#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
   ifstream infile;
   infile.open("input.txt");
   ofstream outfile;
   outfile.open("output.txt");
   double a[100][100];
   int x,y,p;
   infile>>p;
   for(int i=0;i<p;i++){
   outfile<<p<<"\n";
   infile>>x>>y;
   for(int i=0;i<x;i++){
       for(int j=0;j<y;j++){
           infile>>a[i][j];
       }
   }
   double q[100][100]={0};
   for(int j=0;j<y;j++){// find the column of q matrix
     double scale,temp=0;
     double A[100];// A vector
     for(int k=0;k<x;k++){// find A (for each vector)
        A[k]=a[k][j];// initialize the first
        for(int i=0;i<j;i++){// minus each row of q*naygee                
                double tempp=0;
                for(int n=0;n<x;n++){
                     tempp += q[n][i]*a[n][j];
                }
                A[k] -= tempp*q[k][i];
        }
     }
     for(int i=0;i<x;i++){// q=A/scale
         temp+=A[i]*A[i];
     }
     scale=sqrt(temp);
     for(int i=0;i<x;i++){// fill in the Q by q
         q[i][j]=A[i]/scale;
     }     
   }
   double r[100][100]={0};
   for(int j=0;j<y;j++){
       for(int i=0;i<=j;i++){
          double temp=0;
          for(int h=0;h<x;h++){
              temp += q[h][i]*a[h][j];
          }
          r[i][j]=temp;
       }
   }
   outfile<<x<<" "<<y<<"\n";
   for(int i=0;i<x;i++){
       for(int j=0;j<y;j++){
           if(q[i][j]<0&&q[i][j]>-0.000001){
               outfile<<"0.00 ";
           }
           else{
               outfile<<fixed<<setprecision(2)<<q[i][j]<<" ";
           }
       }
       outfile<<"\n";
   }
   outfile<<y<<" "<<y<<"\n";
   for(int i=0;i<y;i++){
       for(int j=0;j<y;j++){
           if(r[i][j]<0&&r[i][j]>-0.000001){
               outfile<<"0.00 ";
           }
           else{
               outfile<<fixed<<setprecision(2)<<r[i][j]<<" ";
           }
       }
       outfile<<"\n";
   }
   }
}