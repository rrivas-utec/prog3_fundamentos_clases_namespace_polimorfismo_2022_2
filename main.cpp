#include <iostream>
using namespace std;

// Tema constructores y destructores
namespace privado {
    class punto_t {
        int x = 0;  // Inicializacion dentro de la class (in class)
        int y = 0;
    public:
        friend ostream& operator<<(ostream& os, const privado::punto_t& pto); // la clase punto le da acceso al operador <<
        friend ostream& operator<<(ostream& os, const privado::punto_t*& pto);
        friend privado::punto_t operator++(const privado::punto_t& pto); // Le da acceso al operador sobrecargado ++
    };
}

namespace publico {
    struct punto_t {
        int x = 0;  // Inicializacion dentro de la class (in class)
        int y = 0;
    };
}

/*
    Los operadores se pueden clasificar en 2 tipos
    1. Operadores Binarios
        + --> int + int
              float + float
              string + string
              int + float = float
        * --> int * int = int
        / -->   int / int
                float / int
        << -->  int << int shift binario a = 00001001 = 9, b = 00000001 = 1, c = a << b; c = 00010010
           -->  ostream << int ==> resultado ostream
                ostream << float ==> resultado ostream
                ostream << string ==> resultado ostream
                ostream << OBJETO  ==> resultado ostream


    2. Operadores Unarios
        * -->   *ptr;
        & -->
        ++ -->
*/
ostream& operator<<(ostream& os, const privado::punto_t& pto) {
    os << "(" << pto.x << "," << pto.y << ")";
    return os;
}

ostream& operator<<(ostream& os, const privado::punto_t*& pto) {
    os << "(" << pto->x << "," << pto->y << ")";
    return os;
}

privado::punto_t operator++(const privado::punto_t& pto) {    // referencia constante y por que es util
    auto result = pto;
    result.x++;
    result.y++;
    return result;
}

/*
 * Conclusion:
   1. Toda las clase tienen constructores sinteticos
   2. Todo atributo debe ser iniciado
   3. Struct tiene por defecto los atributos y metodos publicos, por tanto puede implementar el constructor copia
        utilizando sus atributos ordenadamente entre {}
*/

/*
 * Regla para implementar constructores:
 *  Se implementa constructores cuando se tiene acceso a la memoria dinamica o se usa puntero
 */

int main() {

    punto_t p1 = {10, 20}; // Es un caso especial para struct es un constructor copia {10, 20}
    punto_t p2; // Constructor por defecto
    punto_t p3 = p1; // constructor copia
    p2 = p3; // operador asignacion copia

    int a = 10;
    int b;
    int c = a;
    b = a;

    cout << p1.x << "," << p1.y << endl;
    cout << p2.x << "," << p2.y << endl;
    cout << p1 << endl;
    return 0;
}
