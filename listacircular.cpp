#include <iostream>
#include <string>
using namespace std;

struct Pets{
    int id, edad, peso;
    string name, raza;
};
struct nodo{
    Pets dato;
    nodo *sig;
    nodo *back;
    
}*first, *last ;


int idPet;



void agregarnodo(void){
 
   nodo *nuevo = new nodo();
   Pets mascota;
   idPet++;
   mascota.id = idPet;
   cout <<"ID usuario: "<< mascota.id<< endl;
   cout <<"Favor ingrese el nombre del propetario: ";
   getline(cin,mascota.name);

   cout <<"Favor ingrese raza de la pet: ";
   getline(cin,mascota.raza);

   cout <<"Favor ingrese peso de la pet: ";
   cin>> mascota.peso; cin.ignore();

   cout <<"Favor ingrese edad de la pet: ";
   cin>> mascota.edad; cin.ignore();
 
   nuevo->dato = mascota;
   
   if (first == NULL){
     first = nuevo;
     last = nuevo;
     first->sig = first;
     first->back = last;

   }else{
    last->sig = nuevo;
    nuevo->back = last;
    nuevo->sig =first;
    last = nuevo;
    first->back = last;
   }
}

void mostrar(void){
        nodo *saltarin= new nodo();
        saltarin = first;
        bool found = false;
        int nodsearch = 0;
        cout <<"Ingrese el ID del usuario que quiere ver: ";
        cin >>  nodsearch;
        cout << endl;
        cin.ignore();

        if (first != NULL){
        do
        {  if (saltarin->dato.id ==nodsearch){
            cout <<"El id de la persona es: ("<<saltarin->dato.id<<")"<<endl;

            cout <<"Nombre del propetario: "<<saltarin->dato.name<<endl;

            cout <<"Raza de la pet es: "<<saltarin->dato.raza<<endl;

            cout <<"El peso de la pet es: "<<saltarin->dato.peso<<" libras" <<endl;

            cout <<"La edad de la pet es: " <<saltarin->dato.edad <<" anios"<<endl;

            found = true;
            }

            saltarin = saltarin->sig;

        } while (saltarin != first && found!= true);
        
        if(!found){
            cout <<"id no encontrado."<<endl;
            }
        }else{
            cout <<"La lista esta vacia. "<<endl;
        }

       
   } 

void eliminarpet(void)
{
	int id = 0;
	nodo *p = first;
	nodo *q = NULL;

	cout<<"Ingrese el ID que quiere eliminar : "; cin>>id;

    while ((p != NULL) && (p->dato.id != id))
	{
		q = p;
		p = p->sig;
	}
	if (p == NULL)
	{
		cout << "No hay persona con ese id" << endl;
		return;
	}
	if (first->dato.id == id)
	{
		first = first->sig;
		delete (p);
		cout<<"Se elimino el propetario en esta lista";
		return;
	}
	if (q == NULL)
		p = p->sig;
	else
		q->sig = p->sig;
	delete (p);
	cout<<"Se elimino el propetario en esta lista";
}

void eliminarnodo(){
    nodo* actual = new nodo();
	actual = first;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool found = false;
	int nodsearch = 0;
	cout << "Ingrese ID a borrar: ";
	cin >> nodsearch;
	if(first!=NULL){
		do{
			
			if(actual->dato.id == nodsearch){
				cout <<"Usuario con el ID [" << nodsearch << "] Encontrado"<<endl;
				
				if(actual==first){
					first = first->sig;
					last->sig = first;
                    delete actual;
				}else if(actual==last){
					anterior->sig = first;
					last = anterior;
                    delete actual;
				}else{
					anterior->sig = actual->sig;
                    delete actual;
				}
				
				cout << "Usuario removed";
				found = true;
			}
			anterior = actual;
			actual = actual->sig;
		}while(actual!=first && found != true);
		if(!found){
			cout << "Persona no encontrada";
		}
	}else{
		cout << "La lista de clientes esta vacia";
	}
}

int main(){
    int opcion = 0;
    do
    {
        cout << "Bienvenido a la veterinaria CBY"<<endl;
		cout << "1. Agregar un nuevo registro"<<endl;
		cout << "2. Buscar persona por su ID"<<endl;
		cout << "3. Borrar registro de la persona"<<endl;
        cout << "4. Salir"<<endl;
		cout << "Por favor eliga un numero valido: "<<endl;
        cin>> opcion; cin.ignore();

        switch (opcion)
        {
        case 1:
            agregarnodo();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            eliminarpet();
            break;
        case 4:
            opcion = 4;
            cout <<"See u again my favorite person :D" <<endl;
            break;
        default:
            cout <<"Ingrese un numero valido, thanks"<<endl;
            break;
        }
    } while (opcion !=4);

    return 0;
}