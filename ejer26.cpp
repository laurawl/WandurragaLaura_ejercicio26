#include <fstream>
#include <iostream>
#include <string.h>
using namespace std; 

/*Inicializo los metodos*/
void relleno(int l,float *m);
void imprime(int l,float *m);
float * read_file(string filename, int *n_points);
void escribe(string filename,float* z, int n_points);
float* multiplicacion(float *x,float *y, int n_points);



int main(){
/* Este metodo, pide al usuario un numero que va a ser el tamaño del arreglo, luego lo crea con esa dimensión y finalmente lo rellena con los factoriales del metodo "relleno" y los imprime con el metodo "imprime"*/
float *arreglo = NULL;
cout<<"Escriba el tamaño del arreglo:"<<endl;

int l=0;

cin>>l;
arreglo =new float[l];    
relleno(l,arreglo);
imprime(l,arreglo);
float *x=NULL;
float *y=NULL;
float *z=NULL;
int n_x=0;
int n_y=0;

 x = read_file("valores_x.txt", &n_x);
 y = read_file("valores_y.txt", &n_y);
 z = multiplicacion(x,y,n_x);
 
escribe("Multiplicaciones.dat",z, n_x);

}
/* Este metodo, rellena el arreglo definido en el main recibiendo el tamaño del arreglo y el arreglo de tamaño l de el main. Tiene 2 for, el primero recorre las posiciones del arreglo mientras que el segundo hace el factorial de la posición que es lo que se pide que tenga el arreglo de relleno*/
void relleno(int l,float *M){
    for(int i=0; i<l;i++)
    {
        int a=1;
        for(int j=1; j<i+1; j++)
        {
            a=a*j;
        }
        M[i]=a;
    }
}
/* Este metodo, imrpime el arreglo, le entra el tamaño del arreglo -entero- y el arreglo de tamaño l del main. Tiene un for que recorre el arreglo posición por posición para imprimir cada numero del arreglo en orden ascendente.*/
void imprime(int l,float *m){
    int i;

for (i=0; i <l;i++)
{

cout<<" "<<m[i]<<endl;

}

}
float* read_file(string filename, int *n_points){
  int n_lines=0;
  ifstream infile; 
  string line;
  int i;
  float *array;

  /*cuenta lineas*/
  infile.open(filename); 
  getline(infile, line);
  while(infile){
    n_lines++;
    getline(infile, line);
  }
  infile.close();
  *n_points = n_lines;

  /*reserva la memoria necesaria*/
  array = new float[n_lines];

  /*carga los valores*/
  i=0;
  infile.open(filename); 
  getline(infile, line);  
  while(infile){
    array[i] = atof(line.c_str());
    i++;
    getline(infile, line);
  }
  infile.close();

  return array;
}

void escribe(string filename,float* z, int n_points){
  ofstream outfile;
  outfile.open(filename);
  for (int i=0; i < n_points; i++){
    outfile << z[i] << endl;
  }
  outfile.close();
}
float* multiplicacion(float *x,float *y, int n_points){
  int i;
  float *arreglo = NULL;
  arreglo =new float[n_points];
  for(i=0;i<n_points;i++){
    arreglo[i]=x[i]*y[i];
  }
  return arreglo;
}