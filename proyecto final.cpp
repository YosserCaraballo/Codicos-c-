#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <sstream>
#include <vector>
#include <string>

// ----------------------------------------
// Declaración adelantada para listas enlazadas
struct Nodo {
    double valor;
    Nodo* siguiente;
    Nodo(double valor) : valor(valor), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;
    int longitud;

public:
    ListaEnlazada() : cabeza(nullptr), longitud(0) {}
    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    void insertar(double valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente) actual = actual->siguiente;
            actual->siguiente = nuevo;
        }
        longitud++;
    }
    Nodo* obtenerNodo(int indice) const {
        Nodo* actual = cabeza;
        int contador = 0;
        while (actual && contador < indice) {
            actual = actual->siguiente;
            contador++;
        }
        return actual;
    }
    double obtener(int indice) const {
        Nodo* nodo = obtenerNodo(indice);
        return nodo ? nodo->valor : 0.0;
    }
    void modificar(int indice, double valor) {
        Nodo* nodo = obtenerNodo(indice);
        if (nodo) nodo->valor = valor;
    }
    int tamano() const { return longitud; }
};

// ----------------------------------------
// Clase SistemaEcuaciones
class SistemaEcuaciones {
private:
    ListaEnlazada* matriz;
    int numFilas, numColumnas;

public:
    SistemaEcuaciones(int filas, int columnas)
        : numFilas(filas), numColumnas(columnas) {
        matriz = new ListaEnlazada[filas];
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) matriz[i].insertar(0.0);
        }
    }
    ~SistemaEcuaciones() { delete[] matriz; }
    void ingresarValor(int fila, int columna, double valor) {
        matriz[fila].modificar(columna, valor);
    }
    void gaussJordan() {
        for (int pivote = 0; pivote < numFilas; ++pivote) {
            double valorPivote = matriz[pivote].obtener(pivote);
            if (valorPivote == 0.0) {
                for (int i = pivote + 1; i < numFilas; ++i) {
                    if (matriz[i].obtener(pivote) != 0.0) {
                        std::swap(matriz[pivote], matriz[i]);
                        valorPivote = matriz[pivote].obtener(pivote);
                        break;
                    }
                }
            }
            if (valorPivote != 0.0) {
                for (int col = 0; col < numColumnas; ++col) {
                    double nuevoValor = matriz[pivote].obtener(col) / valorPivote;
                    matriz[pivote].modificar(col, nuevoValor);
                }
            }
            for (int fila = 0; fila < numFilas; ++fila) {
                if (fila != pivote) {
                    double factor = matriz[fila].obtener(pivote);
                    for (int col = 0; col < numColumnas; ++col) {
                        double nuevoValor = matriz[fila].obtener(col) -
                                            factor * matriz[pivote].obtener(col);
                        matriz[fila].modificar(col, nuevoValor);
                    }
                }
            }
        }
    }
    double obtenerSolucion(int fila) const {
        return matriz[fila].obtener(numColumnas - 1);
    }
};

// ----------------------------------------
// Clase MainWindow
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_botonMatriz_clicked();
    void on_botonResolver_clicked();
    void on_botonVolver_clicked();

private:
    QTableWidget* tableWidget;
    QLabel* labelResultado;
    QPushButton* botonMatriz;
    QPushButton* botonResolver;
    QPushButton* botonVolver;
    std::vector<std::vector<double>> matrizDatos;
    void mostrarSoluciones(const std::vector<double>& soluciones);
};

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    auto* layout = new QVBoxLayout;
    auto* centralWidget = new QWidget;

    tableWidget = new QTableWidget(this);
    labelResultado = new QLabel(this);
    botonMatriz = new QPushButton("Configurar Matriz", this);
    botonResolver = new QPushButton("Resolver", this);
    botonVolver = new QPushButton("Volver", this);

    layout->addWidget(tableWidget);
    layout->addWidget(labelResultado);
    layout->addWidget(botonMatriz);
    layout->addWidget(botonResolver);
    layout->addWidget(botonVolver);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    botonResolver->hide();
    botonVolver->hide();
    labelResultado->hide();

    connect(botonMatriz, &QPushButton::clicked, this, &MainWindow::on_botonMatriz_clicked);
    connect(botonResolver, &QPushButton::clicked, this, &MainWindow::on_botonResolver_clicked);
    connect(botonVolver, &QPushButton::clicked, this, &MainWindow::on_botonVolver_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::on_botonMatriz_clicked() {
    tableWidget->setRowCount(3); // Ejemplo
    tableWidget->setColumnCount(4); // Ejemplo
    botonResolver->show();
    botonMatriz->hide();
}

void MainWindow::on_botonResolver_clicked() {
    matrizDatos.clear();
    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        std::vector<double> filaDatos;
        for (int j = 0; j < tableWidget->columnCount(); ++j) {
            QTableWidgetItem* item = tableWidget->item(i, j);
            filaDatos.push_back(item ? item->text().toDouble() : 0.0);
        }
        matrizDatos.push_back(filaDatos);
    }
    SistemaEcuaciones sistema(matrizDatos.size(), matrizDatos[0].size());
    for (size_t i = 0; i < matrizDatos.size(); ++i) {
        for (size_t j = 0; j < matrizDatos[i].size(); ++j) {
            sistema.ingresarValor(i, j, matrizDatos[i][j]);
        }
    }
    sistema.gaussJordan();
    std::vector<double> soluciones;
    for (size_t i = 0; i < matrizDatos.size(); ++i) {
        soluciones.push_back(sistema.obtenerSolucion(i));
    }
    mostrarSoluciones(soluciones);
}

void MainWindow::on_botonVolver_clicked() {
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    botonMatriz->show();
    botonResolver->hide();
    botonVolver->hide();
    labelResultado->hide();
}

void MainWindow::mostrarSoluciones(const std::vector<double>& soluciones) {
    std::ostringstream resultado;
    for (size_t i = 0; i < soluciones.size(); ++i) {
        resultado << "X" << i + 1 << " = " << soluciones[i] << "\n";
    }
    labelResultado->setText(QString::fromStdString(resultado.str()));
    labelResultado->show();
    botonVolver->show();
}

// ----------------------------------------
// main.cpp
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Sistema de Ecuaciones");
    mainWindow.show();
    return app.exec();
}
