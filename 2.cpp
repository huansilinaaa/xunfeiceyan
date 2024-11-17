#include<iostream>
using namespace std;
#include<iomanip>
int n=0;
double jianyan(double**array,int n){
    if(n==1){
        return array[0][0];

    }
    else if(n==2){
        return array[0][0]*array[1][1]-array[0][1]*array[1][0];   

    }
    else{
        double D_value=0;
        for(int k=0;k<n;k++)
        {
            double **D_temp=new double *[n-1];
            int i2=1;
            for(int i1=0;i1<n-1;i1++)
            {
                D_temp[i1]=new double[n-1];
                int j2=0;
                for(int j1=0;j1<n-1;j1++)
                {
                    if(j2==k)
                    {
                        j2++;
                    }
                    D_temp[i1][j1]=array[i2][j2++];
                }
                i2++;
            }
            D_value+=((k&0x0001)?(-1):1)*array[0][k]*jianyan(D_temp,n-1);
        }
        return D_value;
    }
}
void Adjoint_matrices(double **A,double **A_adj,int n)
{
    double **A_AlgebraicRemainder=new double *[n-1];//暂时存放代数余子式的矩阵
    for (int i = 0; i < n-1;i++)
    {
        A_AlgebraicRemainder[i]=new double[n-1];
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            int i1 = 0;
            for (int i = 0; i < n-1; i++)
            {
                if(i1==x)
                {
                    i1++;
                }
                int j1 = 0;
                for (int j = 0; j < n-1; j++)
                {
                    if(j1==y)
                    {
                        j1++;
                    }
                    A_AlgebraicRemainder[i][j]=A[i1][j1++];
                }
                i1++;
            }
            //实现了转置
            A_adj[y][x]=((x+y)&0x0001?(-1):1)*jianyan(A_AlgebraicRemainder, n - 1);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        delete[] A_AlgebraicRemainder[i];
    }
    delete[] A_AlgebraicRemainder;
}
void matrix_inverse(double **A,double **A_inverse,int n)
{
    double A_D=jianyan(A,n);
    
    if (A_D == 0.0f)
        {
            std::cout << "该矩阵不可逆" << std::endl;
            return;
        }
        else{
            if(n==1)
            {
                A_inverse[0][0]=1/A[0][0];
                return;
            }
            
            double **A_adj=new double *[n];
            for (int i = 0; i < n;i++)
            {
                A_adj[i]=new double[n];
            }
            Adjoint_matrices(A, A_adj, n);
            for (int i = 0; i < n;i++)
            {
                for (int j = 0; j < n;j++)
                {
                    A_inverse[i][j]=A_adj[i][j]/A_D;
                }
            }
            for (int i = 0; i < n; i++)
            {
                delete[] A_adj[i];
            }
            delete[] A_adj;
    }

}
int main(){

    cin>>n;

  double **A=new double *[n];
    //std::cout<<"Enter the coefficient matrix:"<<std::endl;
    for(int i=0;i<n;i++)
    {
        A[i]=new double[n];
        for(int j=0;j<n;j++)
        {
            std::cin>>A[i][j];//每次输入一个数字都用空格隔开,输入样例
           
        }
    }

    double **A_inverse=new double *[n];
    for(int i=0;i<n;i++)
    {
        A_inverse[i]=new double[n];
    }
    matrix_inverse(A, A_inverse, n);
    //std::cout<<"The inverse matrix is:"<<std::endl;
    for(int i1=0;i1<n;i1++){
        for (int i2=0;i2<n;i2++){
            cout<<setprecision(1)<<A[i1][i2]<<" ";
        }
    }
 



    return 0;
}

