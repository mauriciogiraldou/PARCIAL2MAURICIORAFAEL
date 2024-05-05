#include <iostream>
#include <string>
using namespace std;
class Estacion {
private:
    string* nombre;
    string tiempo;
public:
    Estacion(const string&);
    ~Estacion();
    void setNombre(const string&);
    void getEstacion() const;
    // Sobrecarga del operador de igualdad
    bool operator==(const Estacion& otraEstacion) const {
        // Comparar los nombres de las estaciones
        return *nombre == *(otraEstacion.nombre);
    }
    // Sobrecarga del operador de asignación
    Estacion& operator=(const Estacion& otraEstacion) {
        if (this != &otraEstacion) { // Evitar la auto-asignación
            // Asignar el nombre y el tiempo de otraEstacion a esta estación
            *nombre = *(otraEstacion.nombre);
            tiempo = otraEstacion.tiempo;
        }
        return *this;
    }


};
Estacion::Estacion(const string& _nombre) : nombre(new string(_nombre)) {}

Estacion::~Estacion() {
    delete nombre;
}

void Estacion::setNombre(const string& nuevoNombre) {
    *nombre = nuevoNombre;
}

void Estacion::getEstacion() const {
    if (nombre != nullptr) {
        cout << *nombre;
    } else {
        cout << "El nombre de la estación no está inicializado";
    }
}

class EstacionMatriz {
private:
    Estacion*** matriz;
    int filas;
    int columnas;
public:
    EstacionMatriz(int filas, int columnas);
    ~EstacionMatriz();
    Estacion* getEstacion(int fila, int columna) const;
    void setEstacion(int fila, int columna, Estacion* estacion);
    void redimensionar(int nuevaFilas, int columnas);
    void borrarEstacion(int fila, int columna);
    int obtenerFilas() const { return filas; }
    // Método para obtener el número de columnas
    int obtenerColumnas() const { return columnas; }
};

EstacionMatriz::EstacionMatriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    matriz = new Estacion**[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new Estacion*[columnas];
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = nullptr;
        }
    }
}

EstacionMatriz::~EstacionMatriz() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            delete matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

Estacion* EstacionMatriz::getEstacion(int fila, int columna) const {
    return matriz[fila][columna];
}
void EstacionMatriz::setEstacion(int fila, int columna, Estacion* estacion) {
    // Verificar si la posición está dentro de los límites de la matriz
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        // Verificar si ya hay un objeto en la posición especificada
        if (matriz[fila][columna] != nullptr) {
            // Si ya hay una estación en esta posición, mostrar un mensaje de error
            cout << "Ya hay una estación en esta posición. No se puede agregar una nueva estación aquí." << endl;
        } else {
            // Asignar la nueva estación a la posición especificada
            matriz[fila][columna] = estacion;
        }
    } else {
        // Redimensionar solo las columnas de la matriz para tener espacio adicional y asignar la nueva estación
        cout << "Posición fuera de los límites de la matriz. Redimensionando las columnas de la matriz..." << endl;
        redimensionar(filas, max(columna + 1, columnas));
        matriz[fila][columna] = estacion;
    }
}
void EstacionMatriz::redimensionar(int nuevaFilas, int nuevasColumnas) {
    Estacion*** nuevaMatriz = new Estacion**[nuevaFilas];
    for (int i = 0; i < nuevaFilas; ++i) {
        nuevaMatriz[i] = new Estacion*[nuevasColumnas]; // Utilizar nuevasColumnas en lugar de columnas
        for (int j = 0; j < nuevasColumnas; ++j) { // Utilizar nuevasColumnas
            nuevaMatriz[i][j] = nullptr;
        }
    }

    // Copiar las estaciones de la matriz anterior a la nueva matriz
    int filasCopiadas = min(nuevaFilas, filas);
    int columnasCopiadas = min(nuevasColumnas, columnas); // Utilizar nuevasColumnas
    for (int i = 0; i < filasCopiadas; ++i) {
        for (int j = 0; j < columnasCopiadas; ++j) { // Utilizar columnasCopiadas
            nuevaMatriz[i][j] = matriz[i][j];
        }
    }

    // Liberar memoria de la matriz anterior
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    // Actualizar la matriz con la nueva matriz
    matriz = nuevaMatriz;
    filas = nuevaFilas;
    columnas = nuevasColumnas; // Actualizar el número de columnas
}

void EstacionMatriz::borrarEstacion(int fila, int columna) {
    // Verificar si la posición está dentro de los límites de la matriz
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        // Liberar memoria de la estación en esa posición
        delete matriz[fila][columna];
        matriz[fila][columna] = nullptr;
    } else {
        cout << "Posición fuera de los límites de la matriz" << endl;
    }
}
EstacionMatriz inicializarmatriz(int n){
    EstacionMatriz sistemametro(n,n);
    return sistemametro;
}
void crearestacion(EstacionMatriz& sistemametro, int fila, int columna, const string& nombreEstacion) {
    int filas = sistemametro.obtenerFilas();
    int columnas = sistemametro.obtenerColumnas();
    // Verificar si la posición está dentro de los límites de la matriz
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        // Crear una nueva estación con el nombre proporcionado
        Estacion* nuevaEstacion = new Estacion(nombreEstacion);
        // Asignar la nueva estación a la posición especificada en la matriz
        sistemametro.setEstacion(fila, columna, nuevaEstacion);
    } else {
        cout << "Posición fuera de los límites de la matriz. Redimensionando la matriz..." << endl;
        // Determinar las nuevas dimensiones de la matriz
        int nuevaFilas = max(fila + 1, filas);
        int nuevasColumnas = max(columna + 1, columnas);
        // Redimensionar la matriz
        sistemametro.redimensionar(nuevaFilas, nuevasColumnas);
        // Crear una nueva estación con el nombre proporcionado
        Estacion* nuevaEstacion = new Estacion(nombreEstacion);
        // Asignar la nueva estación a la posición especificada en la matriz
        sistemametro.setEstacion(fila, columna, nuevaEstacion);
    }
}

int main() {
    //crear linea ¿cuantas lineas desea crear? r=2
    //EstacionMatriz matriz(2, 2); // Matriz de 3x3
    int n=2;
    EstacionMatriz sistemametro=inicializarmatriz(n);
    crearestacion(sistemametro,12,12,"genesis");
    Estacion* obtenida = sistemametro.getEstacion(12,12);
    obtenida->getEstacion();
    crearestacion(sistemametro,10,10,"Arboletes");
    Estacion* obtenida2 = sistemametro.getEstacion(10,10);
    obtenida2->getEstacion();
    crearestacion(sistemametro,3,3,"san joa");
    Estacion* obtenida3 = sistemametro.getEstacion(3,3);
    obtenida3->getEstacion();

    return 0;
}
