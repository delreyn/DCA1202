#include <stdio.h>
#include <math.h>

int* gerarMatrix(int M, int N, int O);
void desenha(int* A,int M,int N,int O, int r);
int melhRaio(int M, int N, int O); //garante 
int getSmallest(int a, int b, int c);
void print(int *a, int m, int n, int o);


int main()
{
   int M=7;
   int N=7;
   int O=7;
        
    int* A = gerarMatrix(M,N,O);
    int r = melhRaio(M,N,O);
    printf("O melhor raio eh: %d \n", r);
    desenha(A,M,N,O,r);
    print(A,M,N,O);
    free(A);
    
    return 0;
}

void print(int *a, int m, int n, int o){
    int i,j,k;
    int* offset;
    int K = 2;
    
    for(i=0; i<m; i++){
        for(j=0;j<n;j++){
            for(k=0;k<o;k++){
                offset = (a + i*n*o + j*o + k);
                printf("%d ", *offset);
            }
            printf("\n");
        }
       printf("\n");
       break;
    }
    
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

// Cria variaveis e offset tal que: M[offset] == M[i][j[k]
    int* offset; 
    int x0,y0,z0;
//define o ponto x0, y0, z0 de onde começara a desenha a esfera
    x0 = M/2;
    y0 = N/2;
    z0 = O/2;

//percorre todo o array 
    for (int i=0; i<M;i++){
        for(int j=0;j<N; j++){
            for (int k=0; k<O; k++){
                offset = (A + i*N*O + j*O + k);
                //caso a distancia do P(x0,y0,z0) e P(xi,yi,zi) <= raio
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

