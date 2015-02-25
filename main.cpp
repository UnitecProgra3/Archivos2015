#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
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

        out.write((char*)nombre.c_str(),10);
        out.write((char*)&puntaje,4);
    }

    out.close();

    ifstream in("archivo");

    for(int i=0;i<cant;i++)
    {
        char* nombre = new char[10];
        int puntaje;

        in.read(nombre,10);
        in.read((char*)&puntaje,4);

        string test = nombre;

        cout<<nombre<<endl;
        cout<<puntaje<<endl;
        cout<<nombre<<endl;

        delete nombre;
    }

    return 0;
}
