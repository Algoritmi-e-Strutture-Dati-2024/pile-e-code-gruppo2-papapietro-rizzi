#include <iostream>
#include <stdexcept>

/*creazione della classe Pila*/
template <typename T>
class Pila {
  private:
    ListaPuntatori<T> lista; /*usare la classe ListaPuntatori*/

  public:
    /*aggiungere un elemento alla pila*/
    void push(T elem) {
        lista.inslista(elem, 1); /*Inserisce l'elemento nella prima posizione, in cima alla lista*/
    }

    /* Rimuovere e restituire l'elemento in cima alla pila*/
    T pop() {
        T topElem = lista.leggilista(1); /*Legge l'elemento in cima*/
        lista.canclista(1);              /*Rimuove l'elemento in cima*/
        return topElem;
    }

    /*Restituire l'elemento in cima alla pila senza rimuoverlo*/
    T top() const {
        return lista.leggilista(1); /*Legge l'elemento in cima, nella prima posizione*/
    }

    /*Verificare se la pila vuota*/
    bool isEmpty() const {
        return lista.listavuota(); 
    }

    /*Restituire il numero di elementi nella pila*/
    int size() const {
        return lista.lunghezza();}
};

int main() {
    Pila<int> pila;

    try {
        pila.push(4);
        pila.push(8);
        pila.push(12);

        std::cout << "Elemento in prima posizione: " << pila.top() << std::endl; // 12
        std::cout << "Dimensione della pila: " << pila.size() << std::endl; // 3

        std::cout << "Rimuovo un elemento: " << pila.pop() << std::endl; // 12
        std::cout << "Rimuovo un altro: " << pila.pop() << std::endl; // 8

        std::cout << "Elemento in prima posizione: " << pila.top() << std::endl; // 4
        std::cout << "Dimensione della pila: " << pila.size() << std::endl; // 1

        pila.pop(); /*Rimuove l'ultimo elemento*/
    }

    return 0;
}

