#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Trabajo en grupo realizado con Maynor Morales
//Tomadas algunas anotaciones de http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto

void escribirNumeroTexto(string nombre_archivo, int num)
{
    //Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
    ofstream out(nombre_archivo.c_str());//Se hace un ofstream para escribir en el archivo
    out<<num<<endl;//se escribe el num en el archivo
    out.close();//Se cierra el archivo
}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str());//Se hace un ifstream para leer el archivo
    int num;//Se hace una variable int para leerla en el archivo
    archivo>>num;//se lee la variable
    return num;//devuelve num
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    //Tomando ejemplo de http://jsbsan.blogspot.com/2012/01/c-ejemplo-de-guardar-texto-en-un.html
    //Se aplica exactamente al anterior solo que con string.
    ofstream out(nombre_archivo.c_str());//Se hace un ofstream para escribir en el archivo
    out<<str<<endl;//se escribe el str en el archivo
    out.close();//Se cierra el archivo
}

string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//Se hace un ifstream para leer el archivo
    string str;//Se hace una variable string para leerla en el archivo
    in>>str;//se lee la variable
    return str;//devuelve str
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    //Tomado de explicacion en clase https://github.com/Ceutec/ArchivosBinarios/blob/master/main.cpp
    //y  http://informatica.uv.es/iiguia/AED/oldwww/2004_05/AED.Tema.07.pdf
    // Seccion 7.7
    ofstream out(nombre_archivo.c_str());//Se hace un ofstream para escribir en el archivo
    out.write((char*)&num,4);//se escribe el int convertido a char en el archivo
    out.close();//se cierra el archivo
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//Se hace un ifstream para leer el archivo
    int num;//Se hace una variable int para leerla en el archivo
    in.read((char*)&num, 4);//se lee la variable de tipo int convertida a char
    return num;//devuelve num
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());//Se hace un ofstream para escribir en el archivo
    out.write(str.c_str(),4);//Se escribe c_str para declarar que lo que escribimos en el archivo es una string ya que
                                //si solo ponemos el nombre de la variable el programa nos tira un error en la escritura
    out.close();//Se cierra el archivo
}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//Se hace un ifstream para leer el archivo
    char leido[4];//Se hace una variable char, ya que el conjunto de char hacen una string
    in.read(leido,4);//Se lee la variable hecha
    return leido;//Devuelve leido
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream in(nombre_archivo.c_str());//Se hace un ifstream para leer el archivo
    string palabra;//Se hace una variable string para compararla con la palabra a buscar
    int cant;//Se hace una variable int para establecer el limite del ciclo
    for(int i=0;i < cant;i++)//Se hace un ciclo for para establecer un contador e ir comparando las palabras
    {
        in>>palabra;//Se introduce la palabra a comparar
        if(palabra == str)//Se hace un if para establecer parametros de comparacion
        {
            return true;//Si la condicion en verdadera devuelve true
        }
    }
    return false;//Si la condicion es falsa devuelve false
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    //Ejercicio realizado en clase
    ifstream in(nombre.c_str());//Se hace un ifstream para leer el archivo
    in.seekg(0,ios::end);//Con seekg se hace para modificar el archivo
    int tamano = in.tellg();//se hace una variable int para definir el tamaño de cada entrada del archivo
    in.seekg(0,ios::beg);//Se vuelve al poner al inicio el seekg

    int mayor = -999;//Se hace una variable int para comparar numeros
    while(in.tellg()<tamano)//Se hace un ciclo while para establecer una condicion
    {
        int num;//Se hace una variable int
        in.read((char*)&num,4);//Se convierte la variable int a char

        if(mayor<num)//Se hace una condicion en un if para comparar las dos variables int hechas anteriormente
        mayor=num;//Si se cumple la condicion la variable mayor se convierte en la variable num

    }
    return mayor;//Devuelve mayor

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
