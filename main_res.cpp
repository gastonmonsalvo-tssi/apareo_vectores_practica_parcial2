/**
 * Alumno:……………………………….                    Fecha:……………………………
    1) Una agencia de reparto posee dos canales para recibir pedidos, uno es 
    la página web de la empresa y el otro un operador que atiende la línea 
    telefónica. La operatoria es que al finalizar el horario de toma de 
    pedidos (de 6.00hs a 12.00hs), se juntan todos los pedidos por orden 
    de llegada (menor hora -> a mayor hora) y se genera un listado único con los repartos del día. De 
    cada pedido se tiene la siguiente información:
    • Hora Pedido (hora en formato HHMM)
    • Codigo de cliente (numérico)
    • Tipo de paquete: (1-Liviano / 2-Medio / 3-Pesado)
    • Origen(texto)
    • Destino(texto)

La capacidad de reparto varía según cuántos móviles disponga la empresa en el 
momento y las horas que se dispongan para realizar repartos, por lo cual la 
cantidad máxima de pedidos que puede tener el listado unificado resultará de 
un cálculo: 

Pedidos_Max = Móviles * Horas_Reparto * 3

    a. Definir las estructuras necesarias para el enunciado descrito y para 
    los puntos siguientes:
    b. Realizar codificación de un procedimiento que reciba los pedidos de 
    ambos canales de atención y genere un listado de pedidos unificado a 
    atender y otro de los que no entran en el reparto diario por la capacidad 
    máxima.
    c. Realizar diagrama de un procedimiento que reciba el listado de pedidos 
    a realizar en el día y genere el siguiente listado agrupado por hora del pedido recibido:
HORA	LIVIANOS	MEDIO		PESADO	TOTAL X HORA
  6		2	        0		            1			         3
    d. Al finalizar el listado imprimir los siguientes datos de reporte:
TOTAL LIVIANOS: 99 	TOTAL MEDIO: 99	TOTAL PESADOS: 99
HORA CON MENOS ENVIOS: 13

Consideraciones: Los listados de ambos canales de atención se encuentran 
ordenados en forma ascendente por hora de pedido.
Restricciones: Solo se puede recorrer secuencialmente una vez cada vector

    2) Realizar diagrama del procedimiento intersección que dados dos arreglos 
    de entrada uno de N y otro de M elementos genere un nuevo arreglo de 
    salida sólo con los elementos que  están en ambos conjuntos ordenado en 
    forma ascendente. 
Ejemplo: vecA = {0, 2, 4, 9} y vecB = {9, 5, 3, 2, 1) => vecC = {2, 9} 

Consideraciones: Ambos arreglos de entrada están ordenados pero el primero 
en forma ascendente y el segundo en forma descendente. Ambos son conjuntos 
sin elementos repetidos 
Restricciones: Sólo se puede recorrer una vez cada vector de entrada

 * 
 */

 #include <iostream>
 using namespace std;
 
//MACROS

/*
estilo viejo, los macros no ocupan memoria ni tiempo de procesamiento
#define TIPO_PAQUETE_LIVIANO 1
#define TIPO_PAQUETE_MEDIO 2
#define TIPO_PAQUETE_PESADO 3

pueden haber macros de conversion de tipo, como funciones
que hacen formulas

lo agarra el procesador y no consume memoria ni tiempo de procesado
*/
//FORMA QUE TRABAJAMOS, CON VAR GLOBALES

const int TIPO_PAQUETE_LIVIANO  = 1;
const int TIPO_PAQUETE_MEDIO    = 2;
const int TIPO_PAQUETE_PESADO   = 3;
const int MAX_CANTIDAD_PEDIDOS = 100;

struct Pedido
{
    int hora;
    long codigo_cliente;
    int tipo_paquete;
    string origen;
    string destino;
};
void apareo_aceptados(Pedido web[], int n, Pedido telefono[], int m, Pedido aceptados[], int &k ,int &i , int &j , int k_limite)
{
    i = 0;
    j = 0;
    k = 0;
                                    //PEDIDOS_MAX
     while (i < n && j < m && k < k_limite)
    {
        if (web[i].hora < telefono[j].hora)
        {
            aceptados[k++] = web[i++];
        }
        else
        {
            aceptados[k++] = telefono[j++];
        }
    }

}
void apareo_rechazados(Pedido web[], int n, Pedido telefono[], int m, Pedido rechazados[], int &k ,int &i , int &j)
{
    k = 0;

    while (i < n && j < m)
    {
        if (web[i].hora < telefono[j].hora)
        {
            rechazados[k] = web[i];
            i++;
        }
        else
        {
            rechazados[k] = telefono[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        rechazados[k++] = web[i++];
    }

    while (j < m)
    {
        rechazados[k] = telefono[j];
        j++;
        k++;
    }

}
int main () {
    int moviles = 2;
    int horas_reparto = 2;
    //asumimos tamaño
    Pedido pedidos_web[MAX_CANTIDAD_PEDIDOS] = 
    {   { 6, 1001, TIPO_PAQUETE_LIVIANO, "Buenos Aires", "Rosario" },
        { 7, 1002, TIPO_PAQUETE_MEDIO,   "Córdoba",      "Mendoza" },
        { 8, 1003, TIPO_PAQUETE_PESADO,  "Salta",        "Tucumán" },
        { 9, 1008, TIPO_PAQUETE_LIVIANO, "Rosario",      "Buenos Aires" },
        { 10, 1004, TIPO_PAQUETE_MEDIO,   "Mar del Plata","La Plata" },
        { 11, 1005, TIPO_PAQUETE_PESADO,  "Mendoza",      "San Juan" },
        { 12, 1011, TIPO_PAQUETE_LIVIANO, "Córdoba",      "Rosario" },
        { 13, 1006, TIPO_PAQUETE_MEDIO,   "La Plata",     "Santa Fe" },
        { 14, 1007, TIPO_PAQUETE_PESADO,  "Tucumán",      "Salta" }
    };

    Pedido pedidos_telefonicos[MAX_CANTIDAD_PEDIDOS]=
    {
        {  7, 2001, TIPO_PAQUETE_MEDIO,   "Neuquén",      "Bariloche" },
        {  8, 2002, TIPO_PAQUETE_PESADO,  "Jujuy",        "Salta" },
        {  9, 2003, TIPO_PAQUETE_LIVIANO, "Corrientes",   "Resistencia" },
        { 10, 2004, TIPO_PAQUETE_LIVIANO, "Bahía Blanca", "Tandil" },
        { 11, 2005, TIPO_PAQUETE_PESADO,  "San Luis",     "Mendoza" },
        { 12, 2006, TIPO_PAQUETE_MEDIO,   "Río Cuarto",   "Córdoba" },
        { 13, 2007, TIPO_PAQUETE_LIVIANO, "Posadas",      "Corrientes" },
        { 14, 2008, TIPO_PAQUETE_MEDIO,   "Paraná",       "Santa Fe" },
        { 15, 2009, TIPO_PAQUETE_PESADO,  "San Juan",     "La Rioja" }
    };

    Pedido pedidos_a_atender[MAX_CANTIDAD_PEDIDOS*2];
    //los que no entran
    Pedido pedidos_rechazados[MAX_CANTIDAD_PEDIDOS*2];
    
    int Pedidos_Max = moviles * horas_reparto * 3;
    int i_guardado;
    int j_guardado;
    int k;

    apareo_aceptados(pedidos_web, 9 , pedidos_telefonicos, 9, pedidos_a_atender, k ,i_guardado,j_guardado,Pedidos_Max);
    apareo_rechazados(pedidos_web, 9 , pedidos_telefonicos, 9, pedidos_rechazados, k ,i_guardado,j_guardado);
    
    cout << "arranca aceptados" << endl;

    for (int i = 0; i < Pedidos_Max; i++)
    {
        cout << "Hora " << pedidos_a_atender[i].hora;
        cout << " " << pedidos_a_atender[i].codigo_cliente << endl;
    }
    cout << endl;

    cout << "arranca rechazados" << endl;
    for (int i = 0; i < k; i++)
    {   
        cout << "Hora " << pedidos_rechazados[i].hora;
        cout << " " << pedidos_rechazados[i].codigo_cliente << endl;
    }
    

    //apareo de pedidos_web y pedidos_telefonicos
    
  
  
  
    return 0;
}