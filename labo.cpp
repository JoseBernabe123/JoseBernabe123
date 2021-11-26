#include <iostream>

#include <string.h>

#include <iomanip>

#define maxchar 20


using namespace std;

    
    struct nodo
{
    
     int edad;

   
    char apellido[maxchar];

       
    int telefono;

     char nombre[maxchar];
    
    int carnet;

    char correo[maxchar];

   

    struct nodo *sgte;

};

typedef struct nodo *PLista;



void menu(void);
void registrar(PLista &);

void eliminar(PLista &);

void mostrar(PLista );


int main(void)
{

    PLista lista = NULL;
    int opcion;


    do
    {
         menu();
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            registrar(lista);
            break;

        case 2:
            if (lista == NULL)
            {

                cout << "Ups, error no hay personas registradas\n";
            }
            else
            {

                mostrar(lista);
            }
            break;

        case 3:
            if (lista == NULL)
            {

                cout << "Ups, error no hay personas registradas\n";
            }
            else
            {

                eliminar(lista);
            }
            break;

        case 4:
            return 0;

        default:
            cout << "Holaaa, por favor ingrese una opcion que sea valida :D\n";
            break;
        }


        system("pause");

        system("cls");

    } while (opcion != 6);



    system("pause");

    return 0;
}


void menu(void)
{
    cout <<" Primer Labo :o"<<endl<<endl;

    cout <<"1. Aca ingresara los datos de la persona" << endl;

    cout <<"2. Aca se le mostrara las personas ya registradas" << endl;

    cout <<"3. Aca usted puede eliminar una persona :/" << endl;

    
    cout <<"4. Fin  " << endl;

    cout << "Holaa, por favor ingrese una opcion valida: ";
}

void mostrar(PLista q)
{

    int i = 1;

    while (q != NULL)
    {

        cout << "Datos personales [" << i << "] "<<endl;

        cout << "Nombre de la persona: " << q->nombre << endl;

        cout << "Apellido de la persona: " << q->apellido << endl;

        cout << "Edad de la persona: " << q->edad << endl;

        cout << "Carnet de la persona: "<< setfill('0')<<setw(8) << q->carnet << endl;

        cout << "Correo Electronico de la persona: " << q->correo << endl;

        cout << "Telefono de la persona : "<< setfill('0')<<setw(8) << q->telefono << endl;

        q = q->sgte;

        i++;
    }
}


void registrar(PLista &lista)
{
    PLista t, q = new (struct nodo);

    cout << "Registro de la people"<<endl;

    cin.ignore();

    cout << "Ingrese su primer nombre por favor:";
    cin.getline(q->nombre, maxchar);
    cin.ignore();


    cout << "Ingrese su apellido por favor:";
    cin.getline(q->apellido, maxchar);
    cin.ignore();


    cout << "Ingrese su edad por favor:";
    cin >> q->edad;
    cin.ignore();


    cout << "Ingrese su carnte por favor:";
    cin >> q->carnet;
    cin.ignore();


    cout << "Ingrese su correo electronico por favor:";
    cin.getline(q->correo, maxchar);
    cin.ignore();

    
    cout << "Ingrese su telefono por favor :";
    cin >> q->telefono;

    system("cls");


    q->sgte = NULL;


    if (lista == NULL)
    {

        lista = q;
    }
    else
    {
        t = lista;

    
        while (t->sgte != NULL)
        {

            t = t->sgte;
        }

        t->sgte = q;
    }
}



void eliminar(PLista &lista)
{

    string persoeli;

    PLista q, t;

    q = lista;

    cout << "Eliminar people"<<endl<<endl;


    cout << "Por favor escriba el nombre de la persona que quiere borrar:";


    cin >> persoeli;

    while (q != NULL)
    {

        if (q->nombre == persoeli)
        {

            if (q == lista)
                lista = lista->sgte;

            else
                t->sgte = q->sgte;

            delete (q);

            cout << "Se ha eliminado con exito :D\n";

            return;
        }
        else
        {

            t = q;
            q = q->sgte;
        }
    }
    if (q == NULL)
        cout << "Ups, este nombre no esta en el listado\n";
}