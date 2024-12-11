
#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

void Menu();
void UnSoloJugador(int &PuntuacionMaxima, string &NombreMaximo);
void ModoSimulado();
void MostrarPuntuacionMaxima(int PuntuacionMaxima, string &NombreMaximo);
void DosJugadores(int &PuntuacionMaxima, string &NombreMaximo);

void Menu(){

int PuntajeTotal;
int op;
int PuntuacionMaxima = 0;
string Nombre, Nombre1, Nombre2, NombreMaximo;

        rlutil::setColor(rlutil::RED);

    do{

        rlutil::cls();
        rlutil::locate(50, 1);
        cout<< R"(

    ________________________________________________________________
    |                                                              |
    |                                                              |
    |                ______                __                      |
    |               / ____/_____________ _/ /__  _________ _       |
    |              / __/ / ___/ ___/ __ `/ / _ \/ ___/ __ `/       |
    |             / /___(__  ) /__/ /_/ / /  __/ /  / /_/ /        |
    |            /_____/____/\___/\__,_/_/\___/_/   \__,_/         |
    |                                                              |
    |                                                              |
    |                                                              |
    |==============================================================|
    |                                                              |
    |  1. Un jugador                                               |
    |  2. Dos Jugadores                                            |
    |  3. Puntuacion mas alta                                      |
    |  4. Modo simulado                                            |
    |  0. Salir del juego                                          |
    |                                                              |
    |==============================================================|
    )"<<endl;

    cout<< "Elija una opcion: ";
    cin>>op;

    switch(op){

    case 1:
    rlutil::cls();
    UnSoloJugador(PuntuacionMaxima, NombreMaximo);
    break;

    case 2:
    rlutil::cls();
    DosJugadores(PuntuacionMaxima, NombreMaximo);
    break;

    case 3:
    rlutil::cls();
    MostrarPuntuacionMaxima(PuntuacionMaxima, NombreMaximo);
    break;

    case 4:
    rlutil::cls();
    ModoSimulado();
    break;


    default:

        cout<<"Opcion Incorrecta, Por favor, vuelva a ingresar una opcion."<<endl;
        system("Pause");

    case 0:

    rlutil::locate(25, 24);
    cout<<"Saliendo del juego..."<<endl;

    rlutil::locate(25, 25);
    cout<<"Espero que te haya gustado, un saludo! :)"<<endl;
    break;

    }

    } while(op != 0);

}

#endif // HEADERS_H_INCLUDED
