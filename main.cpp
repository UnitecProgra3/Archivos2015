#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int tamano_formato = 14;

void ingresarValores()
{
    int cant;
    cout<<"Ingrese la cantidad de jugadores: ";
    cin>>cant;

    ofstream out("archivo");

    for(int i=0;i<cant;i++)
    {
        string nombre;
        int puntaje;
        cout<<"Ingrese el nombre: ";
        cin>>nombre;
        cout<<"Ingrese el puntaje: ";
        cin>>puntaje;

        out.write(nombre.c_str(),10);
        out.write((char*)&puntaje,4);
    }

    out.close();
}

void imprimirTodos()
{
    ifstream in("archivo");
    in.seekg(0,ios::end);
    int cant_registros = in.tellg()/tamano_formato;
    in.seekg(0,ios::beg);

    for(int i=0;i<cant_registros;i++)
    {
        char* nombre_ptr = new char[10];
        int puntaje;

        in.read(nombre_ptr,10);
        in.read((char*)&puntaje,4);

        string nombre = nombre_ptr;

        cout<<nombre<<endl;
        cout<<puntaje<<endl;

        delete nombre_ptr;
    }
}

void imprimirRegistro()
{
    ifstream in("archivo");
    in.seekg(0,ios::end);
    int cant_registros = in.tellg()/tamano_formato;
    in.seekg(0,ios::beg);

    int pos;
    cout<<"Ingrese la posicion a leer: "<<endl;
    cin>>pos;

    if(pos <= cant_registros && pos > 0)
    {
        in.seekg((pos-1)*tamano_formato);
        char* nombre_ptr = new char[10];
        int puntaje;
        in.read(nombre_ptr,10);
        in.read((char*)&puntaje,4);
        cout<<nombre_ptr<<endl;
        cout<<puntaje<<endl;
        delete nombre_ptr;
    }else
    {
        cout<<"Error: posicion invalida."<<endl;
    }
}

void agregarRegistro(string nombre, int puntaje)
{
    ofstream out("archivo",ios::app);
    out.write(nombre.c_str(),10);
    out.write((char*)&puntaje,4);
    out.close();
}

void editarRegistro(string nombre, int puntaje, int pos)
{
    ofstream out("archivo",ios::in);
    out.seekp((pos-1)*tamano_formato);
    out.write(nombre.c_str(),10);
    out.write((char*)&puntaje,4);
    out.close();
}

int main()
{
    //agregarRegistro("hola3", 40);
    editarRegistro("test",80,2);
    imprimirTodos();
    return 0;
}
