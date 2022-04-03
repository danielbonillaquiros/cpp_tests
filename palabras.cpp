#include <iostream>
using namespace std;

// Si letra existe en palabra, modifica letrasEncontradas con 1s en las posiciones
// en las que letra existe en palabra
void encontrarLetra(char* palabra, int letrasEncontradas[], char letra) {
    for (int i = 0; i< strlen(palabra); ++i) {
        if (palabra[i] == letra) {
            letrasEncontradas[i] = 1;
        }
    }
}

// Recibe la palabra que hay que descubrir y un array de int en el que
// 0 indica que la letra no ha sido encontrada y 1 que si
char* procesarPalabraParaImprimir(const char* palabra, int letrasEncontradas[]) {
    char palabraProcesada[256];
    char* palabraRetornar = new char[256];
    int contador = 0;
    
    for(int i = 0; i < strlen(palabra); ++i) {
        if(letrasEncontradas[i] == 0) {
            palabraProcesada[contador] = '?'; // este sería el ? que va al reves - no lo puedo cambiar en mi teclado, cambielo
            palabraProcesada[contador + 1] = '?';
            contador += 2;
        } else {
            palabraProcesada[contador] = palabra[i];
            contador += 1;
        }
    }
    strcpy(palabraRetornar, palabraProcesada);
    return palabraRetornar;
}

int main() {
    char* palabra = "arbol";
    int letrasEncontradas[strlen(palabra)];
    // llenar letrasEncontradas de 0
    // 0 representa letra no encontrada
    // 1 representa letra encontrada
    for(int i=0; i < strlen(palabra); ++i) {
        letrasEncontradas[i] = 0;
    }

    // procedimiento de letra random
    char letra = 'a';

    // aqui se modifica letrasEncontradas
    // esto se puede llamar cada vez que los usuarios meten una letra, si verificarLetra retorna true
    encontrarLetra(palabra, letrasEncontradas, letra);

    // ver palabra descubierta hasta ahora
    cout << procesarPalabraParaImprimir(palabra, letrasEncontradas) << endl;

    // Y con esto ya puede seguir, digamos, hagamoslo de nuevo pero con 'b'
    letra = 'b';
    encontrarLetra(palabra, letrasEncontradas, letra);
    cout << procesarPalabraParaImprimir(palabra, letrasEncontradas) << endl;

    return 0;
}