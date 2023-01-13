// #include <iostream>
// using namespace std;
// #include<stdio.h>
// int i,j;

// void cargar(int n, int &vec)
// {
//     for(int x=0;x<n;x++)
//     {
//         printf("Ingrese elemento:");
//         scanf("%i",vec[&x]);
//     }
// }

// void imprimir(int n, int &vec)
// {
//     printf("Contenido completo del vector:");
//     for(int x=0;x<n;x++)
//     {
//         printf("%i ",vec[&x]);
//     }
// }

// void ordenaBurbuja(int n, int &vec ){//Metodo de la burbuja
//   int i,j,aux;
//   for (j=0; j<n-1; j++)
//     for (i=0; i<n-1; i++)
//       if (vec[i]>vec[&i+1]){
//         aux=vec[&i];
//         vec[i]=vec[&i+1];
//         vec[&i+1]=aux;
//         }
// }

// int main()
// {
//     int i,j,n=5;
//     int vector[5];
//     cargar(n, vector);
//     imprimir(n, vector);
//     ordenaBurbuja(n, vector);
//     imprimir(n, vector);
//     return 0;
// }