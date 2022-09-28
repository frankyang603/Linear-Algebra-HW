#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");
    int num;
    infile>>num;
    for(int u=0;u<num;u++){
    int x,y;
    infile>>x>>y;//cin the size
    float aa[10][10];
    for(int i=0;i<x;i++){//cin the matrix a
        for(int j=0;j<y;j++){
            infile>>aa[i][j];
        }
    }   
    float bb[10][10];
    for(int i=0;i<y;i++){//change a into aT
        for(int j=0;j<x;j++){
            bb[i][j]=aa[j][i];
        }
    }

    float ytwo[10][10]={0};
    for(int j=0;j<y;j++){//multiply aT and a
        for(int i=0;i<y;i++){
            for(int k=0;k<x;k++){
                ytwo[i][j]+=bb[i][k]*aa[k][j];
            }
        }
    }   
    
    float xtwo[10][10]={0};
    for(int j=0;j<x;j++){//multiply a and aT
        for(int i=0;i<x;i++){
            for(int k=0;k<y;k++){
                xtwo[i][j]+=aa[i][k]*bb[k][j];
            }
        }
    }   
    float lamda1,lamda2;
    if(y==2){
        float f[2][2];
        float a,b,c,dd;
        a=ytwo[0][0];
        b=ytwo[1][0];
        c=ytwo[0][1];
        dd=ytwo[1][1];
        float temp1,temp2;
        temp1=(a+dd)*(a+dd)-4*(a*dd-b*c);
        temp2=sqrt(temp1);
        lamda1=(a+dd+temp2)/2;
        lamda2=(a+dd-temp2)/2;
        float d[10][10]={0};
        float e[10][10]={0};
        d[0][0]=ytwo[0][0]-lamda1;
        d[1][0]=ytwo[1][0];
        d[0][1]=ytwo[0][1];
        d[1][1]=ytwo[1][1]-lamda1;
        a=d[0][0];
        b=d[1][0];
        c=d[0][1];
        dd=d[1][1];
        float x1,x2;
        if(a!=0&&c!=0){
            x2=1;
            x1=-(dd/c);
        }
        else if(a!=0&&c==0){
            x2=1;
            x1=0;
        }
        else if(a==0&&c!=0){
            x1=1;
            x2=0;
        }
        else if(a==0&&c==0){
            x2=0;
            x1=1;
        }
        f[0][0]=x1;
        f[1][0]=x2;
        float tempp;
        tempp=x1*x1+x2*x2;
        tempp=sqrt(tempp);
        f[0][0]=f[0][0]/tempp;
        f[1][0]=f[1][0]/tempp;
        e[0][0]=ytwo[0][0]-lamda2;
        e[1][0]=ytwo[1][0];
        e[0][1]=ytwo[0][1];
        e[1][1]=ytwo[1][1]-lamda2;
        a=e[0][0];
        b=e[1][0];
        c=e[0][1];
        dd=e[1][1];
        
        if(a!=0&&c!=0){
            x2=1;
            x1=-(dd/c);
        }
        else if(a!=0&&c==0){
            x2=1;
            x1=0;
        }   
        else if(a==0&&c!=0){
            x1=1;
            x2=0;
        }
        else if(a==0&&c==0){
            x2=0;
            x1=1;
        }
        f[0][1]=x1;
        f[1][1]=x2;
        tempp=x1*x1+x2*x2;
        tempp=sqrt(tempp);
        f[0][1]=f[0][1]/tempp;
        f[1][1]=f[1][1]/tempp;
        float g[3][3]={0};
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<y;k++){
                    g[i][j]+=f[k][j]*aa[i][k];
                }
            }
        }
        float k[3][3]={0};
        k[0][0]=sqrt(lamda1);
        k[1][1]=sqrt(lamda2);
        outfile<<x<<" "<<x<<"\n";
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                outfile<<fixed<<setprecision(2)<<g[i][j]<<" ";
            }
            outfile<<"\n";
        }
        outfile<<x<<" "<<y<<"\n";
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                outfile<<fixed<<setprecision(2)<<k[i][j]<<" ";
            }
            outfile<<"\n";
        }
        outfile<<y<<" "<<y<<"\n";
        for(int i=0;i<y;i++){
            for(int j=0;j<y;j++){
                outfile<<fixed<<setprecision(2)<<f[i][j]<<" ";
            }
            outfile<<"\n";
        }

    }

    if(x==2){
        float f[2][2];
        float a,b,c,dd;
        a=xtwo[0][0];
        b=xtwo[1][0];
        c=xtwo[0][1];
        dd=xtwo[1][1];
        float temp1,temp2;
        temp1=(a+dd)*(a+dd)-4*(a*dd-b*c);
        temp2=sqrt(temp1);
        lamda1=(a+dd+temp2)/2;
        lamda2=(a+dd-temp2)/2;
        float d[10][10]={0};
        float e[10][10]={0};
        d[0][0]=xtwo[0][0]-lamda1;
        d[1][0]=xtwo[1][0];
        d[0][1]=xtwo[0][1];
        d[1][1]=xtwo[1][1]-lamda1;
        a=d[0][0];
        b=d[1][0];
        c=d[0][1];
        dd=d[1][1];
        float x1,x2;
        if(a!=0&&c!=0){
            x2=1;
            x1=-(dd/c);
        }
        else if(a!=0&&c==0){
            x2=1;
            x1=0;
        }
        else if(a==0&&c!=0){
            x1=1;
            x2=0;
        }
        else if(a==0&&c==0){
            x2=0;
            x1=1;
        }
        f[0][0]=x1;
        f[1][0]=x2;
        float tempp;
        tempp=x1*x1+x2*x2;
        tempp=sqrt(tempp);
        f[0][0]=f[0][0]/tempp;
        f[1][0]=f[1][0]/tempp;
        e[0][0]=xtwo[0][0]-lamda2;
        e[1][0]=xtwo[1][0];
        e[0][1]=xtwo[0][1];
        e[1][1]=xtwo[1][1]-lamda2;
       // cout<<lamda2<<"  "<<e[1][1]<<"\n";
        a=e[0][0];
        b=e[1][0];
        c=e[0][1];
        dd=e[1][1];
        
        if(a!=0&&c!=0){
            x2=1;
           // cout<<dd<<"   "<<c<<"\n";
            x1=-(dd/c);
        }
        else if(a!=0&&c==0){
            x2=1;
            x1=0;
        }   
        else if(a==0&&c!=0){
            x1=1;
            x2=0;
        }
        else if(a==0&&c==0){
            x2=0;
            x1=1;
        }
        f[0][1]=x1;
        f[1][1]=x2;
        tempp=x1*x1+x2*x2;
        tempp=sqrt(tempp);
        f[0][1]=f[0][1]/tempp;
        f[1][1]=f[1][1]/tempp;
        float g[3][3]={0};
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<y;k++){
                    g[i][j]+=f[j][k]*aa[i][k];
                }
            }
        }
        float k[3][3]={0};
        k[0][0]=sqrt(lamda1);
        k[1][1]=sqrt(lamda2);
        outfile<<x<<" "<<x<<"\n";
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                outfile<<fixed<<setprecision(2)<<f[j][i]<<" ";
            }
            outfile<<"\n";
        }
        outfile<<x<<" "<<y<<"\n";
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                outfile<<fixed<<setprecision(2)<<k[i][j]<<" ";
            }
            outfile<<"\n";
        }
        outfile<<y<<" "<<y<<"\n";
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                outfile<<fixed<<setprecision(2)<<g[i][j]<<" ";
            }
            outfile<<"\n";
        }

    }
    }
}





/*
    double zero=0,one=0,two=0,three=0;
    double aa,bb,cc,dd,ee,ff,gg,hh,ii;
    aa=c[0][0];
    bb=c[0][1];
    cc=c[0][2];
    dd=c[1][0];
    ee=c[1][1];
    ff=c[1][2];
    gg=c[2][0];
    hh=c[2][1];
    ii=c[2][2];
    zero=aa*ii*ee+bb*ff*gg+cc*dd*hh-cc*gg*ee-bb*dd*ii-hh*ff*aa;
    one=cc*gg+bb*dd+hh*ff-aa*ee-aa*ii-ee*ii;
    two=aa+ee+ii;
    three=-1.0;
    cout<<zero<<"\n";
    cout<<one<<"\n";
    cout<<two<<"\n";
    cout<<three<<"\n";
    */


    /*
    for(int i=0;i<y;i++){//cout the outcome of the multiplication of aT and a
        for(int j=0;j<y;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    */