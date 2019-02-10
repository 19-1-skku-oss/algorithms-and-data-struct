//--- Preprocesador
#include <cstdlib> // Para conversión de cadena a doble
#include <complex.h> // Biblioteca para números complejos
#include <iostream>
#include <fstream>

//--- Namespaces
using namespace std;

//--- Prototipos
int mand(complex<double> z0, int lim);

//--- MAIN
int main(int argc, char const *argv[])
{

        if (argc > 3) {
                cout << "Faltan operandos en el programa" << endl;
                cout << "Pruebe 'fract -h' para mas información" << endl;
                return 1;
        } else if (std::string(argv[0]) == "-h") {
                cout << "Modo de empleo: fract [X0] [Y0] [SIZE]\
                        [NxN dimensions]" << endl;
                cout << "Estados de salida:" << endl;
                cout << "0 -- Todo fue bien" << endl;
                cout << "1 -- Problema menor" << endl;
                cout << "2 -- Problema mayor" << endl;
                return 0;
        }

        // El fractal estará centrado en...
        double xC = atof(argv[0]);
        double yC = atof(argv[1]);
        double tam = atof(argv[2]);
        int n = atoi(argv[3]); // Dimensiones de la imágen (De nxn)
        int max = 255; // Número de iteraciones

        ofstream mandelbrot("fractal.pgm");
        // Escribir la cabecera del archivo pgm
        mandelbrot << "P2" << endl << n << "" << n << endl << tam << endl;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        double x0 = xC - tam/2 + tam * i/n;
                        double y0 = yC - tam/2  + tam * j/n;

                }
        }

        mandelbrot << 
        return 0;
}

//--- Funciones externas

//-- Retornar el número de iteraciones para revisar si c = a + ib pertenece al
//-- conjunto de mandelbrot
int mand(complex<double> z0, int lim)
{
        complex<double> Z = z0;

        for (int i = 0; i < lim; i++) {
                if (abs(Z) > 2.0) return i;
                Z = Z * Z + z0; //FIXME: Arreglar la precedencia de op aquí.
        }
        return lim;
}
