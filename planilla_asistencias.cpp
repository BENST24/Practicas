#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void comprobarArchivo();
void menu();
void buscarAlumno();
void ingresarAlumno();
string estadoAsistencia(); 

int main()
{
    comprobarArchivo();

    menu();

    return 0;
}
void menu()
{
    int opcion = 0;

    do
    {
        cout << "\n\t\tOpciones de Planilla\n\n";
        cout << "1. Ingresar Alumno\n";
        cout << "2. Buscar Alumno\n";
        cout << "3. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                ingresarAlumno();
                break;
            case 2:
                buscarAlumno();
                break;
            case 3:
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        } 

    }while (opcion != 3);
   
}
void comprobarArchivo()
{
    ifstream testOpenArchivo("planilla.csv");
    bool ArchivoExists = testOpenArchivo.good();
    testOpenArchivo.close();

    ofstream csvArchivo;
    csvArchivo.open("planilla.csv", ofstream::app);//permite amodificar agregando sin borrar lo que ya estaba (app)
    if (!ArchivoExists)
    {
        //column titles
        csvArchivo << "DNI,"
                << "Nombre/s,"
                << "Apellido/s,"
                << "Carrera,"
                << "Materia,"
                << "Fecha,"
                << "Hora,"
                << "Estado_de_la_Asistencia\n";
    }
}
void ingresarAlumno()
{
    int dni, año;
    string nombre, apellido, carrera, materia, asistencia, fecha, hora;
    ofstream archivo;

    archivo.open("planilla.csv", ios::app);
    if (archivo.is_open())
    {

        cout << "Ingrese DNI: ";
        cin >> dni;
        cin.ignore();
        cout << "ingresa Nombre/s: ";
        getline(cin, nombre);
        cout << "Ingresa Apellido/s: ";
        getline(cin, apellido);
        cout << "Ingresa Carrera: ";
        getline(cin, carrera);
        cout << "Ingresa Materia: ";
        getline(cin, materia);
        cout << "Ingresa Fecha: ";
        getline(cin, fecha);
        cout << "Ingresa Hora: ";
        getline(cin, hora);
        asistencia = estadoAsistencia();

        archivo << dni << "," << nombre << "," << apellido << "," << carrera << "," << materia << "," << fecha << "," << hora << "," << asistencia << endl; 
  
    }
}
void buscarAlumno()
{
    ifstream archivo;
    string dni, materia, linea;

    cout << "Ingrese el DNI: ";
    cin >> dni;
    cin.ignore();
    cout << "Ingrese la Materia: ";
    getline(cin, materia);

    archivo.open("planilla.csv");

    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            // Verificar si la línea contiene el DNI y la Materia
            if (linea.find(dni) != string::npos &&
                linea.find(materia) != string::npos) 
            {
                cout << linea << endl;
            }
        }

        archivo.close();
    } 
    else 
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
string estadoAsistencia()
{
    int opcion = 0;
    string asistencia;

   
        cout << "Estado de la Asistencia\n";
        cout << "1. Presente\n";
        cout << "2. Ausente\n";
     do
    {

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                asistencia = "Presente";
                break;
            case 2:
                asistencia = "Ausente";
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        } 

    }while (opcion != 1 && opcion != 2);

    return asistencia;
}
