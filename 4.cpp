#include <iostream>
#include <string>
using namespace std;


void Z(string &a){
    int i=a.size();
    for(int x=0;x<i/2;x++){
        char temp = a[x];
        a[x]=a[i-1-x];
        a[i-1-x]=temp;
    }
}

void double_my(string &a){
    int num=a.find(".");
    int i = a.size();
    for(int i1=0;i1<num/2;i1++){
        char temp = a[i1];
        a[i1]=a[num-i1-1];
        a[num-i1-1]=temp;
    }
    for(int i2=num+1;i2<((i+num)/2);i2++){
        char temp = a[i2];
        a[i2]=a[i+num-i2];
        a[i+num-i2]=temp;
    }

}

void fenshu(string &a){

    int num=a.find("/");
    int i = a.size();
    for(int i1=0;i1<num/2;i1++){
        char temp = a[i1];
        a[i1]=a[num-i1-1];
        a[num-i1-1]=temp;
    }
    for(int i2=num+1;i2<((i+num)/2);i2++){
        char temp = a[i2];
        a[i2]=a[i+num-i2];
        a[i+num-i2]=temp;
    }

}

void baifenshu(string &a){
    int i = a.size()-1;
    for(int x=0;x<i/2;x++){
        char temp = a[x];
        a[x]=a[i-x-1];
        a[i-x-1]=temp;
    }
}

int main(){
    string a;

    cin>>a;
    int num = a.size();
    int point =0;
    for(int i=0;i<num;i++){
        if(a[i]=='.'){
            point =1;
        }
        else if(a[i]=='/'){
            point =2;
        }
        else if(a[i]=='%'){
            point =3;
        }
        else{
            continue;
        }

    }
    if(point == 1){
        double_my(a);
    }
    else if(point == 2){
    fenshu(a);
    }
    else if(point == 3){
        baifenshu(a);
    }
    else{
        Z(a);
    }
    if(sizeof(a)>1){
        for(int i =0;i<a.size();i++){
            if(a[i]=='0'){
                char *p =&a[i];
                p=nullptr;
            }
            else{
                break;

            }
        }
    }
    cout<<a;

    return 0;
}