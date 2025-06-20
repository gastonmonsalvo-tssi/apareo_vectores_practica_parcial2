/*
 2) Realizar diagrama del procedimiento intersección que dados dos arreglos 
    de entrada uno de N y otro de M elementos genere un nuevo arreglo de 
    salida sólo con los elementos que  están en ambos conjuntos ordenado en 
    forma ascendente. 
Ejemplo: vecA = {0, 2, 4, 9} y vecB = {9, 5, 3, 2, 1) => vecC = {2, 9} 

Consideraciones: Ambos arreglos de entrada están ordenados pero el primero 
en forma ascendente y el segundo en forma descendente. Ambos son conjuntos 
sin elementos repetidos 
Restricciones: Sólo se puede recorrer una vez cada vector de entrada
*/

#include <iostream>
using namespace std;

//apareo 
void apareo(int vec_a[], int n,
            int vec_b[], int m,
            int vec_c[], int &k)
{
    int i = 0;
    int j = m-1;    //comienzo en el ultimo elemento, recordar bajar 1 por que debo tener en cuenta
                    //que m es el tamaño total del vector, y el indice arranca en 0
    k=0;
    /*
        i=0 
        {0, 2, 4, 9}; 
                j=m  
        {9, 5, 3, 2, 1};
    */
    while (i < n && j > -1)
    {
        if (vec_a[i]<vec_b[j])
        {
            i++;
        } else if (vec_a[i]>vec_b[j]){
            j--;
        }else {
            vec_c[k] = vec_a[i];
            j--;
            i++;
            k++;
        }
        
    }
    
}
void mostrar_vector_c(int vector_c[], int tamaño_c){
    cout << "{";
    for (int i = 0; i < tamaño_c; i++)
    {
        
       if (i > 0){
        cout << ", ";
       } 
        cout << vector_c[i]; 
    }
    cout << "}" << endl;
}
int main () {
 
    int vector_a[]={0, 2, 4, 9};   //ascendente
    int vector_b[]={9, 5, 3, 2, 1};    //descendente
                    //solucion, recorro a B al reves para hacer apareo
    int tamaño_a = sizeof(vector_a)/sizeof(vector_a[0]);
    int tamaño_b = sizeof(vector_b)/sizeof(vector_b[0]);
  
    //tamaño maximo vector c => tamaño_a + tamaño_c
    
    int tamaño_c = tamaño_a+tamaño_b;
  
    int vector_c[tamaño_c];

    apareo(vector_a, tamaño_a, vector_b, tamaño_b, vector_c, tamaño_c);  
    mostrar_vector_c(vector_c,tamaño_c);
 
    return 0;
}