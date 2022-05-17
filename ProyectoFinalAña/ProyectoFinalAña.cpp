// ProyectoFinalAña.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int menu() {
    int opcion;
    system("CLS");
    cout << "Bienvenido al consulturio Don Sonrisas favor de escoger las siguientes opciones del menu!" << endl << endl;
    cout << "1. Agregar Cita" << endl;
    cout << "2. Buscar Cita" << endl;
    cout << "3. Modificar Cita" << endl;
    cout << "4. Ver citas" << endl;
    cout << "5. Eliminar citas " << endl;
    cout << "6. Salir " << endl;
    cin >> opcion;

    return opcion;
}

bool verifica(string numeroCita) {
    ifstream leer("Citas.txt", ios::in);
    string Nombre;
    string Apellido;
    int TipoConsulta;
    string HoraConsulta;
    int Numerodetratamiento;
    int OT = 0;
    string NumeroCita;  
    leer >> Nombre;
    while (!leer.eof()){
        leer >> Apellido;
        leer >> TipoConsulta;
        leer >> HoraConsulta;
        leer >> OT;
        leer >> NumeroCita;
        if (NumeroCita == numeroCita) {
            leer.close();
            return false;
        }
        leer >> Nombre;

    }

    leer.close();
    return true;
}
void agregar(ofstream &es) {
    system("CLS");
    string Nombre;
    string Apellido;
    int TipoConsulta;
    string HoraConsulta;
    int Numerodetratamiento;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, OT = 0;
    string NumeroCita;
    es.open("Citas.txt", ios::out | ios::app);
    cout << "Ingrese su nombre: ";
    cin >> Nombre;
    cout << "Ingrese su apellido: ";
    cin >> Apellido;
    
    
    cout << "AHORA LE PRESENTAMOS LOS DIVERSOS TRATAMIENTOS QUE TENEMOS!" << endl << endl;

    cout << "Tratamiento 1" << endl;
    cout << "Si usted tiene malestar o dolor este tratamiento trata de una consulta a sus dolencias" << endl;
    cout << "$900" << endl;

    cout << "Tratamiento 2" << endl;
    cout << "Este tratamiento consta de una reparacion total a su sistema de ortodoncia a un precio accesible y de bajo costo mas aparte asesoria profesional!" << endl;
    cout << "$400" << endl;

    cout << "Tratamiento 3" << endl;
    cout << "Este tratamiento consta de una limpieza dental profunda y blaqueamiento para momentos especiales!" << endl;
    cout << "$800" << endl;

    cout << "Porfavor ingrese cual es el que requiere usted: ";

    cin >> TipoConsulta;

    cout << "Ingrese la hora de su tratamient(En el formato de 24 hrs): ";
    cin >> HoraConsulta;

    cout << "cauntos tratamientos requiere?" << endl;
    cin >> NT;

    if (TipoConsulta == 1)
        OT = (NT * preciot1);
    else if (TipoConsulta == 2)
    {
        OT = (NT * preciot2);
    }
    else if (TipoConsulta == 3)
    {
        OT = (NT * preciot3);
    }

    cout << "el coste total de su tratamiento seria: $" << OT << endl;
    
    cout << "Ingrese su numero de cita (cualesquiera): " << endl;
    cin >> NumeroCita;
    if (verifica(NumeroCita))

    es  << Nombre << " " << Apellido << " " << TipoConsulta;
    es << " " << HoraConsulta << " " << OT << " " << NumeroCita << " " << endl;
    //es << "Nombre: " << Nombre << endl << "Apellido: " << Apellido << endl << "Numero de tratamiento: " << TipoConsulta << endl;
   // es << "Hora de la consulta: " << HoraConsulta << endl << "Costo Total: " << OT << endl << "Numero de cita: " << NumeroCita << endl;


    es.close();



}

void VerCitas(ifstream &Leer) {
    system("CLS");
    string Nombre;
    string Apellido;
    int TipoConsulta;
    string HoraConsulta;
    int Numerodetratamiento;
    int OT = 0;
    string NumeroCita;

    Leer.open("Citas.txt", ios::in);
    if (Leer.is_open())
    {
    cout << "<--------------CITAS VIGENTES------------------------>" << endl << endl;
    Leer >> Nombre;
    while (!Leer.eof()){
        Leer >> Apellido;
        Leer >> TipoConsulta;
        Leer >> HoraConsulta;
        Leer >> OT;
        Leer >> NumeroCita;
        cout << "Nombre: " << Nombre << endl;
        cout << "Apellido: " << Apellido << endl;
        cout << "Hora de consulta: " << HoraConsulta << endl;
        cout << "Precio Consulta: " << OT << endl;
        cout << "Numero de cita: " << NumeroCita << endl;
        cout << "<------------------------------------------------------>" << endl;
        Leer >> Nombre;
        }
    }else{
        cout << "error al abrir el archivo" << endl << endl;
    }
    Leer.close();
    system("pause");
}

void BuscarCita(ifstream &Leer) {
    system("CLS");
    Leer.open("Citas.txt", ios::in);
    ifstream lectura;
    string Nombre;
    string Apellido;
    int TipoConsulta;
    string HoraConsulta;
    int Numerodetratamiento;
    int OT = 0;
    string NumeroCita, NumeroCitaAux;
    bool encontrado = false;

    cout << "Ingrese el numero de cita: ";
    cin >> NumeroCitaAux;
    if(Leer.is_open()){
    Leer >> Nombre;
    while (!Leer.eof() && !encontrado){
        Leer >> Apellido;
        Leer >> TipoConsulta;
        Leer >> HoraConsulta;
        Leer >> OT;
        Leer >> NumeroCita;
        if (NumeroCita == NumeroCitaAux)
        {
            cout << "Nombre: " << Nombre << endl;
            cout << "Apellido: " << Apellido << endl;
            cout << "Hora consulta: " << HoraConsulta << endl;
            cout << "Precio Consulta: " << OT << endl;
            cout << "Numero de cita: " << NumeroCita << endl;
            cout << "<------------------------------------------------------>" << endl;
            encontrado = true;
        }
        Leer >> Nombre;
    }
        
    } else {
      cout << "Error al abrir el archivo" << endl << endl;
    }
    Leer.close();
    if (!encontrado)
    {
        cout << "No se a encontrado el registro" << endl;
        system("pause");
    }
    system("pause");



}

void CambiarNombre(ifstream &Lectura) {
    string Nombre;
    string Apellido;
    int TipoConsulta, TipoConsultaAux;
    string HoraConsulta;
    int Numerodetratamiento, NumerotratamientoAux;
    int OT = 0, OTAUX = 0;
    string NumeroCita, ApellidoAux, HoraConsultaAux, NumeroCitaAux, NombreAux;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, opcmod;
    Lectura.open("Citas.txt", ios::in);
    ofstream Aux("Auxiliar.txt", ios::out);
    if (Lectura.is_open())
    {
        cout << "Ingrese la cita a modificar: ";
        cin >> NumeroCitaAux;
        Lectura >> Nombre;
        while (!Lectura.eof())
        {
            Lectura >> Apellido;
            Lectura >> TipoConsulta;
            Lectura >> HoraConsulta;
            Lectura >> OT;
            Lectura >> NumeroCita;
            if (NumeroCita == NumeroCitaAux)
            {
                cout << "Nombre: ";
                cin >> NombreAux;
                Aux << NombreAux << " " << Apellido << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }else{
                Aux << Nombre << " " << Apellido << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }
            Lectura >> Nombre;
        }
        Lectura.close();
        Aux.close();
    }else{
        cout << "Error al abrir el arvhivo";
    }
    remove("Citas.txt");
    rename("Auxiliar.txt", "Citas.txt");

}

void CambiarApellido(ifstream& Lectura) {
    string Nombre;
    string Apellido;
    int TipoConsulta, TipoConsultaAux;
    string HoraConsulta;
    int Numerodetratamiento, NumerotratamientoAux;
    int OT = 0, OTAUX = 0;
    string NumeroCita, ApellidoAux, HoraConsultaAux, NumeroCitaAux, NombreAux;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, opcmod;
    Lectura.open("Citas.txt", ios::in);
    ofstream Aux("Auxiliar.txt", ios::out);
    if (Lectura.is_open())
    {
        cout << "Ingrese la cita a modificar: ";
        cin >> NumeroCitaAux;
        Lectura >> Nombre;
        while (!Lectura.eof())
        {
            Lectura >> Apellido;
            Lectura >> TipoConsulta;
            Lectura >> HoraConsulta;
            Lectura >> OT;
            Lectura >> NumeroCita;
            if (NumeroCita == NumeroCitaAux)
            {
                cout << "Apellido: ";
                cin >> ApellidoAux;
                Aux << Nombre << " " << ApellidoAux << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }
            else {
                Aux << Nombre << " " << Apellido << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }
            Lectura >> Nombre;
        }
        Lectura.close();
        Aux.close();
    }
    else {
        cout << "Error al abrir el arvhivo";
    }
    remove("Citas.txt");
    rename("Auxiliar.txt", "Citas.txt");

}

void CambiarHora(ifstream& Lectura) {
    string Nombre;
    string Apellido;
    int TipoConsulta, TipoConsultaAux;
    string HoraConsulta;
    int Numerodetratamiento, NumerotratamientoAux;
    int OT = 0, OTAUX = 0;
    string NumeroCita, ApellidoAux, HoraConsultaAux, NumeroCitaAux, NombreAux;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, opcmod, NTAUX = 0;
    Lectura.open("Citas.txt", ios::in);
    ofstream Aux("Auxiliar.txt", ios::out);
    if (Lectura.is_open())
    {
        cout << "Ingrese la cita a modificar: ";
        cin >> NumeroCitaAux;
        Lectura >> Nombre;
        while (!Lectura.eof())
        {
            Lectura >> Apellido;
            Lectura >> TipoConsulta;
            Lectura >> HoraConsulta;
            Lectura >> OT;
            Lectura >> NumeroCita;
            if (NumeroCita == NumeroCitaAux)
            {
                cout << "Hora: ";
                cin >> HoraConsultaAux;
                Aux << Nombre << " " << Apellido << " " << TipoConsulta << " " << HoraConsultaAux << " " << OT << " " << NumeroCita << "\n";
            }
            else {
                Aux << Nombre << " " << Apellido << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }
            Lectura >> Nombre;
        }
        Lectura.close();
        Aux.close();
    }
    else {
        cout << "Error al abrir el arvhivo";
    }
    remove("Citas.txt");
    rename("Auxiliar.txt", "Citas.txt");

}

void CambiarTratamiento(ifstream& Lectura) {
    string Nombre;
    string Apellido;
    int TipoConsulta, TipoConsultaAux;
    string HoraConsulta;
    int Numerodetratamiento, NumerotratamientoAux;
    int OT = 0, OTAUX = 0, NTAUX = 0;       
    string NumeroCita, ApellidoAux, HoraConsultaAux, NumeroCitaAux, NombreAux;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, opcmod;
    Lectura.open("Citas.txt", ios::in);
    ofstream Aux("Auxiliar.txt", ios::out);
    if (Lectura.is_open())
    {
        cout << "Ingrese la cita a modificar: ";
        cin >> NumeroCitaAux;
        Lectura >> Nombre;
        while (!Lectura.eof())
        {
            Lectura >> Apellido;
            Lectura >> TipoConsulta;
            Lectura >> HoraConsulta;
            Lectura >> OT;
            Lectura >> NumeroCita;
            if (NumeroCita == NumeroCitaAux)
            {
                cout << "AHORA LE PRESENTAMOS LOS DIVERSOS TRATAMIENTOS QUE TENEMOS!" << endl << endl;

                cout << "Tratamiento 1" << endl;
                cout << "Si usted tiene malestar o dolor este tratamiento trata de una consulta a sus dolencias" << endl;
                cout << "$900" << endl;

                cout << "Tratamiento 2" << endl;
                cout << "Este tratamiento consta de una reparacion total a su sistema de ortodoncia a un precio accesible y de bajo costo mas aparte asesoria profesional!" << endl;
                cout << "$400" << endl;

                cout << "Tratamiento 3" << endl;
                cout << "Este tratamiento consta de una limpieza dental profunda y blaqueamiento para momentos especiales!" << endl;
                cout << "$800" << endl;

                cout << "Porfavor ingrese cual es el que requiere usted: ";
                cin >> TipoConsultaAux;

                cout << "cauntos tratamientos requiere?" << endl;
                cin >> NT;

                if (TipoConsulta == 1)
                    OTAUX = (NT * preciot1);
                else if (TipoConsulta == 2)
                {
                    OTAUX = (NT * preciot2);
                }
                else if (TipoConsulta == 3)
                {
                    OTAUX = (NT * preciot3);
                }

                Aux << Nombre << " " << Apellido << " " << TipoConsultaAux << " " << HoraConsulta << " " << OTAUX << " " << NumeroCita << "\n";
            }
            else {
                Aux << Nombre << " " << Apellido << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }
            Lectura >> Nombre;
        }
        Lectura.close();
        Aux.close();
    }
    else {
        cout << "Error al abrir el arvhivo";
    }
    remove("Citas.txt");
    rename("Auxiliar.txt", "Citas.txt");

}

void ModificarRegistro(ifstream & Leer) {
    ifstream Lectura;
    string Nombre;
    string Apellido;
    int TipoConsulta, TipoConsultaAux;
    string HoraConsulta;
    int Numerodetratamiento, NumerotratamientoAux;
    int OT = 0, OTAUX = 0;
    string NumeroCita, ApellidoAux, HoraConsultaAux, NumeroCitaAux, NombreAux;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, opcmod;
    cout << "Cual es el dato que desea modificar?" << endl << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Apellido" << endl;
    cout << "3. TipoConsulta/Numero de tratamientos" << endl;
    cout << "4. Hora consulta" << endl;

    cin >> opcmod;

    switch (opcmod)
    {
    case 1:
        CambiarNombre(Lectura);
        break;
    case 2:
        CambiarApellido(Lectura); 
        break;
    case 3:
        CambiarTratamiento(Lectura);
        break;
    case 4:
        CambiarHora(Lectura);
        break;
    default:
        break;
    }



}

void eliminar(ifstream &Leer) {
    string Nombre;
    string Apellido;
    int TipoConsulta, TipoConsultaAux;
    string HoraConsulta;
    int Numerodetratamiento, NumerotratamientoAux;
    int OT = 0, OTAUX = 0;
    string NumeroCita, ApellidoAux, HoraConsultaAux, NumeroCitaAux, NombreAux;
    int preciot1 = 900, preciot2 = 400, preciot3 = 800, NT = 0, opcmod, NTAUX = 0;
    Leer.open("Citas.txt", ios::in);
    ofstream Aux("Auxiliar.txt", ios::out);
    if (Leer.is_open())
    {
        cout << "Ingrese la cita a eliminar: ";
        cin >> NumeroCitaAux;
        Leer >> Nombre;
        while (!Leer.eof())
        {
            Leer >> Apellido;
            Leer >> TipoConsulta;
            Leer >> HoraConsulta;
            Leer >> OT;
            Leer >> NumeroCita;
            if (NumeroCita == NumeroCitaAux)
            {
                cout << "ELIMINADO CORRECTAMENTE**";
                Sleep(1500);
            }
            else {
                Aux << Nombre << " " << Apellido << " " << TipoConsulta << " " << HoraConsulta << " " << OT << " " << NumeroCita << "\n";
            }
            Leer >> Nombre;
        }
        Leer.close();
        Aux.close();
    }
    else {
        cout << "Error al abrir el arvhivo";
    }
    remove("Citas.txt");
    rename("Auxiliar.txt", "Citas.txt");

}

int main()
{
    ofstream archivo;
    ifstream Leer;
    int opc;
    do
    {
        system("CLS");
        opc = menu();
        switch (opc){
        case 1:
            agregar(archivo);
            break;
        case 3:
            ModificarRegistro(Leer);
            break;
        case 4:
            VerCitas(Leer);
            break;
        case 2:
            BuscarCita(Leer);
            break;
        case 5:
            eliminar(Leer);
            break;
        default:
            break;
        }
    } while (opc != 6);
    return 0;
}

//ofstream escritura("Ola.txt", ios::out | ios::app);
//escritura << "Hola Mundo\n";

//es << "Nombre: " << Nombre << endl << "Apellido: " << Apellido << endl << "Numero de tratamiento: " << TipoConsulta << endl;
//es << "Hora de la consulta: " << HoraConsulta << endl << "Costo Total: " << OT << endl << "Numero de cita: " << NumeroCita << endl;

