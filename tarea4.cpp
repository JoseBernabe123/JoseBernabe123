#include <iostream>
#include <string>
using namespace std;


struct Nombres{
    string descripcion;
    int id;
};

Nombres solicitarNombres(void){
    Nombres p;
    cout << "Ingrese su nombre: ";
    getline(cin, p.descripcion);
    cout << "Por favor ingrese su ID : ";
    cin >> p.id; cin.ignore();
    return p;
}

void mostrarNombres(Nombres p){
    cout << "Ingrese su nombre " << p.descripcion<< endl;
    cout << "Su ID personal es: "<< p.id <<"" << endl;
}

typedef Nombres T;
const T noValido = {"",0};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insertFront(T);
        void insertBack(T);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
        bool empty(void);
        void insertAfter(T dato, T datoRef);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarNombres(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarNombres(q->dato);
        q = q->ant;
    }
}



bool ListaDoble::empty(void){
    return pInicio == NULL;
}


void ListaDoble::insertAfter(T dato, T datoRef){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && (saltarin->dato).descripcion.compare(datoRef.descripcion) != 0){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL)
            saltarin->sig->ant = nuevo;
        saltarin->sig = nuevo;

    }
}


int menu(){
    int opcion = 0;
    cout << endl << "1) Por favor ingrese sus datos personales:." << endl;
    cout << "2) Mostrar Datos." << endl;
    cout << "3) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble suPedido;
    
    bool continuar = true;
    Nombres p;
    Nombres pref;
    do{
        switch(menu()){
            case 1:
                p = solicitarNombres();
                suPedido.insertFront(p);
                cout << "Se almacenaron sus datos :D" << endl;
                break;

            case 2: //Mostrar suPedido de fin a inicio
                suPedido.traversalReverseDirection();
                break;

            case 4: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}