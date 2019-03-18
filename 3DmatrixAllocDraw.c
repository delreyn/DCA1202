#include <stdio.h>
#include <math.h>

int* gerarMatrix(int M, int N, int O);
void desenha(int* A,int M,int N,int O, int r);
int melhRaio(int M, int N, int O);
int getSmallest(int a, int b, int c);


int main()
{
   int M=4;
   int N=4;
   int O=4;
        
    int* A = gerarMatrix(M,N,O);
    int r = melhRaio(M,N,O);
    desenha(A,M,N,O,r);
    free(A);
    
    return 0;
}

int getSmallest(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<= c) return b;
    else if(c<=a && c<=b) return c;
}

int melhRaio(int M, int N, int O){
    int x0, y0, z0, rx, ry, rz;
    
    x0 = M/2;
    y0 = N/2;
    z0 = O/2;

    rx = sqrt((x0-M)*(x0-M));
    ry = sqrt((y0-N)*(y0-N));
    rz = sqrt((z0-O)*(z0-O));
    
    return getSmallest(rx,ry,rz);
    
}

void desenha(int* A,int M,int N,int O, int r){

    int* offset;
    int x0,y0,z0;
    x0 = M/2;
    y0 = N/2;
    z0 = O/2;


    for (int i=0; i<M;i++){
        for(int j=0;j<N; j++){
            for (int k=0; k<O; k++){
                offset = (A + i*N*O + j*O + k);
                if(sqrt((x0 - i)*(x0 - i) + (y0-j)*(y0-j) + (z0-k)*(z0-k)) <= r ) *offset =  1;
                else *offset = 0;
            }
        }
    }
    
}

int* gerarMatrix(int M,int N,int O){
    int* A = (int*) malloc(M*N*O*sizeof(int));
    return A;
}

