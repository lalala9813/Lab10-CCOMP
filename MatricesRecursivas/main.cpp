#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
//Profesor use librerias externas para poder dar vida a mi intro para que se viera mas bonito :)
void intro()
{//Funcion que crea un intro para el programa
    system("TITLE Matrices");
    int posFil=10;
    char marco[30][40];
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<40;j++)
        {

            marco[posFil][12]='C';
            marco[posFil][13]='A';
            marco[posFil][14]='L';
            marco[posFil][15]='C';
            marco[posFil][16]='U';
            marco[posFil][17]='L';
            marco[posFil][18]='A';
            marco[posFil][19]='D';
            marco[posFil][20]='O';
            marco[posFil][21]='R';
            marco[posFil][22]='A';

            marco[posFil+1][12]='D';
            marco[posFil+1][13]='E';
            marco[posFil+1][14]=' ';
            marco[posFil+1][15]='M';
            marco[posFil+1][16]='A';
            marco[posFil+1][17]='T';
            marco[posFil+1][18]='R';
            marco[posFil+1][19]='I';
            marco[posFil+1][20]='C';
            marco[posFil+1][21]='E';
            marco[posFil+1][22]='S';

            marco[posFil+4][8]='-';
            marco[posFil+4][9]='R';
            marco[posFil+4][10]='E';
            marco[posFil+4][11]='N';
            marco[posFil+4][12]='Z';
            marco[posFil+4][13]='O';
            marco[posFil+4][14]=' ';
            marco[posFil+4][15]='G';
            marco[posFil+4][16]='O';
            marco[posFil+4][17]='N';
            marco[posFil+4][18]='Z';
            marco[posFil+4][19]='A';
            marco[posFil+4][20]='L';
            marco[posFil+4][21]='E';
            marco[posFil+4][22]='S';

            marco[posFil+8][6]='P';
            marco[posFil+8][7]='R';
            marco[posFil+8][8]='E';
            marco[posFil+8][9]='C';
            marco[posFil+8][10]='I';
            marco[posFil+8][11]='O';
            marco[posFil+8][12]='N';
            marco[posFil+8][13]='E';
            marco[posFil+8][14]=' ';
            marco[posFil+8][15]='A';
            marco[posFil+8][16]=' ';
            marco[posFil+8][17]='P';
            marco[posFil+8][18]='A';
            marco[posFil+8][19]='R';
            marco[posFil+8][20]='A';
            marco[posFil+8][21]=' ';
            marco[posFil+8][22]='C';
            marco[posFil+8][23]='O';
            marco[posFil+8][24]='N';
            marco[posFil+8][25]='T';
            marco[posFil+8][26]='I';
            marco[posFil+8][27]='N';
            marco[posFil+8][28]='U';
            marco[posFil+8][29]='A';
            marco[posFil+8][30]='R';

            if(i==0 || i==29)
            {
                marco[i][j]='=';
            }
            else
            {
                marco[i][j]=' ';
            }
            if(i!=0 && j==0)
            {
                marco[i][j]='*';
                if(i==29)
                {
                    marco[i][j]='=';
                }
            }
            if(i!=0 && j==39)
            {
                marco[i][j]='*';
                if(i==29)
                {
                    marco[i][j]='=';
                }
            }

        }
    }

    for(int i=0;i<30;i++)
    {
        for(int j=0;j<40;j++)
        {
            cout << marco[i][j];
        }cout <<"\n";
    }

}
void inicio(int**matriz,int f,int c,int i=0)
{//Funcion que inicializa mis matrices con punteros
    if(i==f){
        return;
    }
    *(matriz+i)=new int[c];
    return inicio(matriz,f,c,i+1);
}

void ceros(int**matriz,int f,int c,int i=0,int j=0)
{//Funcion que rellena de ceros a cada eleento de mi matriz para luego eliminarla
    if(j==c){
        return ceros(matriz,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(matriz+i)+j)=0;
    return ceros(matriz,f,c,i,j+1);
}

void darValores(int**matriz,int f,int c,int i=0, int j=0)
{//Funcion que le pide al usuario dar los valores de mis matrices
    if(j==c){
        return darValores(matriz,f,c,i+1,0);
    }
    if(i==f){
        return;
    }

    int valor;
    cout<<"Dame mis valores HUMANO ["<<i<<"] ["<<j<<"] --> ";
    cin>>valor;

    *(*(matriz+i)+j)=valor;

    return darValores(matriz,f,c,i,j+1);
}

void mayor(int**m1, int**m2, int**m3,int f, int c,int i=0, int j=0)
{//Funcion que calcula el elemento mayor de mi matriz
    if(j==c){
        return mayor(m1,m2,m3,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(m3+i)+j)= (*(*(m1+i)+j) > *(*(m2+i)+j))? *(*(m1+i)+j): *(*(m2+i)+j);
    return mayor(m1,m2,m3,f,c,i,j+1);

}

void menor(int**m1, int**m2, int**m3,int f, int c,int i=0, int j=0)
{//Funcion que calcula el elemento menor de mi matriz
    if(j==c){
        return menor(m1,m2,m3,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(m3+i)+j)= (*(*(m1+i)+j) < *(*(m2+i)+j))? *(*(m1+i)+j): *(*(m2+i)+j);
    return menor(m1,m2,m3,f,c,i,j+1);

}

void prom(int**m1, int**m2, int**m3,int f, int c,int i=0, int j=0)
{//Funciom que calcula el promedio de mi matriz
    if(j==c){
        return prom(m1,m2,m3,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(m3+i)+j)= (*(*(m1+i)+j) + *(*(m2+i)+j))/2;
    return prom(m1,m2,m3,f,c,i,j+1);
}

void suma(int**m1, int**m2, int**m3,int f, int c,int i=0, int j=0)
{//Funcion que suma mis matrices y las almacena en una tercera matriz
    if(j==c){
        return suma(m1,m2,m3,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(m3+i)+j)= *(*(m1+i)+j) + *(*(m2+i)+j);
    return suma(m1,m2,m3,f,c,i,j+1);
}

void resta(int**m1, int**m2, int**m3,int f, int c,int i=0, int j=0)
{//Funcion que resta mis matrices y las almacena en una tercera matriz
    if(j==c){
        return resta(m1,m2,m3,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(m3+i)+j)= *(*(m1+i)+j) - *(*(m2+i)+j);
    return resta(m1,m2,m3,f,c,i,j+1);
}

void multiplicacion(int**m1, int**m2, int**m3,int f1, int c1,int f2,int c2,int i=0, int j=0,int k =0)
{//Funcion que multiplica mis matrices y las almacena en una tercera matriz
    if(f1!=c2){
        cout<<"No puedo operar estas dos  Matrices ERROR Muerto XP "<<"\n";
        return;
    }
    if(k==f2){
        return multiplicacion(m1,m2,m3,f1,c1,f2,c2,i,j+1,0);
    }
    if(j==c2){
        return multiplicacion(m1,m2,m3,f1,c1,f2,c2,i+1,0,k);
    }
    if(i==f1){
        return;
    }
    *(*(m3+i)+j)=*(*(m3+i)+j)+(*(*(m1+i)+j) * *(*(m2+i)+j));
    return multiplicacion(m1,m2,m3,f1,c1,f2,c2,i,j,k+1);

}

void imprimir(int**matriz,int f,int c,int i=0, int j=0)
{//Funcion que imprime mis matrices
    if(j==c){
        cout<<"\n";
        return imprimir(matriz,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    cout<<*(*(matriz+i)+j)<<" ";
    return imprimir(matriz,f,c,i,j+1);
}

void deletes(int**matriz,int f,int i=0)
{//Funcion que elimina el espacio de memoria reservado
    if(i==f){
        delete []matriz;
        return;
    }
    delete [] matriz[i];
    return deletes(matriz,f,i+1);
}

int operaciones(int f1,int c1,int f2,int c2,int **m1,int **m2)
{//Funcion que contiene todo lo que se operara y que contiene a mi puntero funcion
    void (*ptrCalculadora)(int**,int**,int**,int,int,int,int);//Puntero funcion
    int des=0;
    cin>>des;
    if(des==0){
        ptrCalculadora=mayor;
    }
    else if(des==1){
        ptrCalculadora=menor;
    }
    else if(des==2){
        ptrCalculadora=prom;
    }
    else if(des==3){
        ptrCalculadora=suma;
    }
    else if(des==4){
        ptrCalculadora=resta;
    }

    if(des!=5)
    {
        if(f1!=f2 || c1!=c2){ //Comprobamos si las matrices tienen el mismo tamaño
            cout<<"No puedo operar estas dos  Matrices ERROR Muerto XP"<<"\n";
            deletes(m1,f1);
            deletes(m2,f2);
            return 0;
        }
        int**m3= new int*[c1];
        inicio(m3,f1,c1);
        ptrCalculadora(m1,m2,m3,f1,c1,0,0);
        imprimir(m3,f1,c1);
        deletes(m3,f1);
    }

    if(des==5){
        int**m3= new int*[c1];
        inicio(m3,f1,c2);
        ceros(m3,f1,c2);
        multiplicacion(m1,m2,m3,f1,c1,f2,c2);
        imprimir(m3,f1,c2);
        deletes(m3,f1);
    }

    deletes(m1,f1);
    deletes(m2,f2);
}
int main()
{

    intro();
    char v;
    v=getch();
    if(v=='a' || v=='A')
    {
        system("cls");
        int f1,c1,f2,c2;

        cout<<"Ingresa el numero de filas de la primera matriz --> ";
        cin>>f1;
        cout<<"Ingresa el numero de columnas de la primera matriz --> ";
        cin>>c1;
        cout<<"Ingresa el numero de filas de la segunda matriz --> ";
        cin>>f2;
        cout<<"Ingresa el numero de columnas de la segunda matriz --> ";
        cin>>c2;

        int**m1= new int*[f1];
        int**m2= new int*[f2];


        inicio(m1,f1,c1);
        inicio(m2,f2,c2);

        cout<< "\n" <<"Ingresa los elementos de la  Matriz 1"<<"\n";
        darValores(m1,f1,c1);
        cout<< "\n" <<"Ingresa los elementos de la  Matriz 2"<<"\n";
        darValores(m2,f2,c2);

        cout<< "\n" <<"BIENVENIDO HUMANO"<<"\n";
        cout<<"Selecciona tu Operacion"<<"\n";
        cout<<"Presiona 0 para hallar los Mayores Elementos"<<"\n";
        cout<<"Presiona 1 para hallar los Menores Elementos"<<"\n";
        cout<<"Presiona 2 para hallar el Promedio de los Elementos"<<"\n";
        cout<<"Presiona 3 para hallar la Suma de Matrices"<<"\n";
        cout<<"Presiona 4 para hallar la Resta de Matrices"<<"\n";
        cout<<"Presiona 5 para hallar la Multiplicacion de Matrices"<<"\n";
        cout<<"Y tu eleccion es? --> ";

        operaciones(f1,c1,f2,c2,m1,m2);

    }

    return 0;

}
