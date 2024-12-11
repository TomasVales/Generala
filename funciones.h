#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
void MostrarPuntuacionMaxima(int PuntuacionMaxima, string &Nombre){

    rlutil::locate(25, 5);
    cout<<"Puntuacion mas alta hasta el momento: "<<PuntuacionMaxima;
    rlutil::locate(25,6);
    cout<<"Nombre del jugador: "<<Nombre<<endl;
    system("pause");

}
void NombrePrimerJugador(string &Nombre){

    rlutil::locate(20, 3);
    cout<<" ---------------------------------"<<endl;
    rlutil::locate(20, 4);
    cout<<"|  Ingrese el Nombre del Jugador: |"<<endl;
    rlutil::locate(20, 5);
    cout<<"|                                 |"<<endl;
    rlutil::locate(20, 6);
    cout<<" ---------------------------------"<<endl;
    rlutil::locate(25, 5);
    cin>>Nombre;

}

void NombreDosJugadores(string &Nombre1, string &Nombre2){

     rlutil::locate(20, 3);
    cout<<" ----------------------------------------"<<endl;
    rlutil::locate(20, 4);
    cout<<"|  Ingrese el Nombre del Primer Jugador: |"<<endl;
    rlutil::locate(20, 5);
    cout<<"|                                        |"<<endl;
    rlutil::locate(20, 6);
    cout<<" -----------------------------------------"<<endl;
    rlutil::locate(25, 5);
    cin>>Nombre1;

    rlutil::cls();

    rlutil::locate(20, 3);
    cout<<" -----------------------------------------"<<endl;
    rlutil::locate(20, 4);
    cout<<"|  Ingrese el Nombre del Segundo Jugador: |"<<endl;
    rlutil::locate(20, 5);
    cout<<"|                                         |"<<endl;
    rlutil::locate(20, 6);
    cout<<" -----------------------------------------"<<endl;
    rlutil::locate(25, 5);
    cin>>Nombre2;

}

void SiguienteRonda(int Ronda, int PuntajeTotal){

        rlutil::locate(25, 2);
        cout << "Puntaje Total despues de la Ronda " << Ronda << ": " << PuntajeTotal << endl;

        if(PuntajeTotal<100){ //EVITAR QUE LE SALTE ESTE TEXTO AL YA LLEGAR A LOS 100 PUNTOS
        rlutil::locate(30, 3);
        cout << "Comenzando la siguiente ronda..."<<endl;
        }


        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        system("pause");
        system("cls");
    }

void FinPartida(int Ronda, string Nombre, int PuntajeTotal)
{

    rlutil::locate(25, 5);
    cout << "Felicidades " << Nombre << ", Lograste ganar el juego con la increible cantidad de " << Ronda << " rondas." << endl;
    rlutil::locate(42   , 6 );
    cout << "Puntos obtenidos: "<<PuntajeTotal<<endl;
    system("pause");



}

void FinPartidaEscalera(int Ronda, int PuntajeTotal, string Nombre){
     system("cls");

    rlutil::locate(25, 5);
    cout << "Felicidades " << Nombre << ", conseguiste realizar una escalera, ganaste con la cantidad de: " << Ronda << " rondas." << endl;
    rlutil::locate(42, 6 );
    cout << "Puntos obtenidos: "<<PuntajeTotal<<endl;
    system("pause");

}

void UnSoloJugador(int &PuntuacionMaxima, string &NombreMaximo){
    string Nombre;
    int Ronda = 1 , PuntajeTotal = 0;
    int VectorDados[6];
    bool Escalera;
    bool Sexteto;
    int ValorSexteto = 0;

    NombrePrimerJugador(Nombre);
    rlutil::cls();
    while (PuntajeTotal < 100) {

        rlutil::locate(25, 1);
        cout << "Turno de: " << Nombre << " | Ronda: " << Ronda << " | Puntaje Total: " << PuntajeTotal << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        int PuntajeMaxLanzamiento = 0;  // Puntaje de los lanzamientos de cada ronda

        for (int lanzamiento = 0; lanzamiento < 3; lanzamiento++) { //LANZAMIENTOS
            int PuntajeLanzamiento = 0;

            for (int tiro = 0; tiro < 6; tiro++) { //DADOS - 6 Tiros
                VectorDados[tiro] = rand() % 6 + 1;  // Genera el valor Aleatorio de los dados
                PuntajeLanzamiento += VectorDados[tiro];
                cout<<" " " " "" "" "" <<VectorDados[tiro];

            }



            Sexteto = Sexteto6(VectorDados, 6, ValorSexteto);
            if (Sexteto == true) {
                if (ValorSexteto == 6) {
                    cout<<"Conseguiste un Sexteto de 6, se reiniciaran tus puntos..."<<endl;
                    PuntajeTotal = 0;
                    system("pause");
                    break;
                }
            }

            cout << " Lanzamiento " << (lanzamiento + 1) << " de la Ronda " << (Ronda) << ": " << PuntajeLanzamiento << endl;

            if (PuntajeLanzamiento > PuntajeMaxLanzamiento) { //Puntaje lanzamiento mayor al maximo es igual maximo de los 3 lanzamientos
                PuntajeMaxLanzamiento = PuntajeLanzamiento;
            }
            system("pause");
Escalera = HayEscalera(VectorDados, 6);
           if(Escalera == true) {
            FinPartidaEscalera(Ronda, PuntajeTotal, Nombre);
                return; }

        }
        system("cls");
        PuntajeTotal += PuntajeMaxLanzamiento;

        if(PuntajeTotal > PuntuacionMaxima) {
            PuntuacionMaxima = PuntajeTotal;
            NombreMaximo = Nombre;
        }

        SiguienteRonda(Ronda, PuntajeTotal);
        Ronda++;

    }
        FinPartida(Ronda, Nombre,PuntajeTotal); //FIN PARTIDA

}

void ModoSimulado(){
 string Nombre;
    int Ronda = 1 , PuntajeTotal = 0;
    int VectorDados[6];
    bool Escalera;
    bool Sexteto;
    int ValorSexteto = 0;
    bool juego = true;


    NombrePrimerJugador(Nombre);
    rlutil::cls();
    while (juego) {


        rlutil::locate(45, 8);
        cout<<"Cargando Ronda Simulada..."<<endl;
        system("pause");
        system("cls");

        rlutil::locate(25, 1);
        cout << "Turno de: " << Nombre << " | Ronda: " << Ronda << " | Puntaje Total: " << PuntajeTotal << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        int PuntajeMaxLanzamiento = 0;  // Puntaje de los lanzamientos de cada ronda
            cout<<"Ingrese los valores del lanzamiento manualmente:"<<endl;
        for (int lanzamiento = 0; lanzamiento < 3; lanzamiento++) { //LANZAMIENTOS
            int PuntajeLanzamiento = 0;

            for (int tiro = 0; tiro < 6; tiro++) { //DADOS - 6 Tiros
                cin>>VectorDados[tiro]; // INGRESAR POR VECTOR CADA TIRADA MANUALMENTE
                if (VectorDados[tiro]<=6 && VectorDados[tiro] >= 1){ // Toma solamente los valores 1-6
                PuntajeLanzamiento += VectorDados[tiro];
                }else{
                system("pause");
                 cout<<"Numero invalido, reiniciando juego..."<<endl;
                 juego = false;
                 break;
                }

            }

           Escalera = HayEscalera(VectorDados, 6);
           if(Escalera) {
            FinPartidaEscalera(Ronda, PuntajeTotal, Nombre);
                return;
                }

            Sexteto = Sexteto6(VectorDados, 6, ValorSexteto);
            if (Sexteto) {
                if (ValorSexteto == 6) {
                    cout<<"Conseguiste un Sexteto de 6, se reiniciaran tus puntos..."<<endl;
                    PuntajeTotal = 0;
                    PuntajeLanzamiento = 0;
                    system("pause");
                    break;
                }
                else {
                    PuntajeLanzamiento = ValorSexteto * 10;
                }
            }

            cout << " Lanzamiento " << (lanzamiento + 1) << " de la Ronda " << (Ronda) << ": " << PuntajeLanzamiento << endl;

            if (PuntajeLanzamiento > PuntajeMaxLanzamiento) { //Puntaje lanzamiento mayor al maximo es igual maximo de los 3 lanzamientos

                if(ValorSexteto == 6) PuntajeTotal = 0;
                else{
                PuntajeMaxLanzamiento = PuntajeLanzamiento;
                }
            }
            system("pause");
        }
        system("cls");
        PuntajeTotal += PuntajeMaxLanzamiento;
        SiguienteRonda(Ronda, PuntajeTotal);
        Ronda++;
        if(PuntajeTotal >=100) juego = false;
    }

        FinPartida(Ronda, Nombre,PuntajeTotal); //FIN

}

void SiguienteRondaJugadorUno(int Ronda, int PuntajeTotalDos, int PuntajeTotalUno , string Nombre1, string Nombre2){

    rlutil::locate(25, 1);
                cout<<"---------------------------------------------------"<<endl;
                rlutil::locate(25, 2);
                cout<<"Turno del jugador: "<<Nombre2 <<endl;
                rlutil::locate(25, 3);
               cout << "Puntaje de " << Nombre2 << " : " << PuntajeTotalDos << endl;
                rlutil::locate(25, 4);
                cout << "Puntaje de " << Nombre1 << " : " << PuntajeTotalUno << endl;
                rlutil::locate(25, 5);
                cout<<"--------------------------------------------------"<<endl;




            system("pause");
            system("cls");
}

void SiguienteRondaJugadorDos(int Ronda, int PuntajeTotalDos, int PuntajeTotalUno , string Nombre1, string Nombre2){


                rlutil::locate(25, 1);
                cout<<"---------------------------------------------------"<<endl;
                rlutil::locate(25, 2);
                cout<<"Turno del jugador: "<<Nombre1 <<endl;
                rlutil::locate(25, 3);
               cout << "Puntaje de " << Nombre2 << " : " << PuntajeTotalDos << endl;
                rlutil::locate(25, 4);
                cout << "Puntaje de " << Nombre1 << " : " << PuntajeTotalUno << endl;
                rlutil::locate(25, 5);
                cout<<"--------------------------------------------------"<<endl;




            system("pause");
            system("cls");
    }


void DosJugadores(int &PuntuacionMaxima, string &NombreMaximo){
string Nombre1, Nombre2;
    int Ronda = 1, PuntajeTotalUno = 0, PuntajeTotalDos = 0;
    int VectorDados[6];
    bool Escalera;
    bool Sexteto;
    int ValorSexteto = 0;

    NombreDosJugadores(Nombre1, Nombre2);
    rlutil::cls();

    while ((PuntajeTotalUno <= 100) and (PuntajeTotalDos <= 100)) {

        // Turno del Jugador 1
        rlutil::locate(25, 1);
        cout << "Turno de: " << Nombre1 << " | Ronda: " << Ronda << " | Puntaje Total: " << PuntajeTotalUno << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        int PuntajeMaxLanzamiento1 = 0;

        for (int lanzamiento = 0; lanzamiento < 3; lanzamiento++) {
            int PuntajeLanzamiento1 = 0;

            for (int tiro = 0; tiro < 6; tiro++) {
                VectorDados[tiro] = rand() % 6 + 1;
                PuntajeLanzamiento1 += VectorDados[tiro];
                cout << " " << VectorDados[tiro];
            }

            Escalera = HayEscalera(VectorDados, 6);
            if (Escalera) {
                FinPartidaEscalera(Ronda, PuntajeTotalUno, Nombre1);
                return;
            }

            Sexteto = Sexteto6(VectorDados, 6, ValorSexteto);
            if (Sexteto) {
                if (ValorSexteto == 6) {
                    cout << "Conseguiste un Sexteto de 6, se reiniciaran tus puntos..." << endl;
                    PuntajeTotalUno = 0;
                    system("pause");
                    break;
                }
            }

            cout << " Lanzamiento " << (lanzamiento + 1) << " de la Ronda " << Ronda << ": " << PuntajeLanzamiento1 << endl;

            if (PuntajeLanzamiento1 > PuntajeMaxLanzamiento1) {
                PuntajeMaxLanzamiento1 = PuntajeLanzamiento1;
            }
            system("pause");
        }
        system("cls");
        PuntajeTotalUno += PuntajeMaxLanzamiento1;

        if (PuntajeTotalUno > PuntuacionMaxima) {
            PuntuacionMaxima = PuntajeTotalUno;
            NombreMaximo = Nombre1;
        }

        SiguienteRondaJugadorUno( Ronda,PuntajeTotalDos, PuntajeTotalUno ,Nombre1, Nombre2);

        // Turno del Jugador 2
        rlutil::locate(25, 1);
        cout << "Turno de: " << Nombre2 << " | Ronda: " << Ronda << " | Puntaje Total: " << PuntajeTotalDos << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        int PuntajeMaxLanzamiento2 = 0;

        for (int lanzamiento = 0; lanzamiento < 3; lanzamiento++) {
            int PuntajeLanzamiento2 = 0;

            for (int tiro = 0; tiro < 6; tiro++) {
                VectorDados[tiro] = rand() % 6 + 1;
                PuntajeLanzamiento2 += VectorDados[tiro];
                cout << " " << VectorDados[tiro];
            }

            Escalera = HayEscalera(VectorDados, 6);
            if (Escalera) {
                FinPartidaEscalera(Ronda, PuntajeTotalDos, Nombre2);
                return;
            }

            Sexteto = Sexteto6(VectorDados, 6, ValorSexteto);
            if (Sexteto) {
                if (ValorSexteto == 6) {
                    cout << "Conseguiste un Sexteto de 6, se reiniciaran tus puntos..." << endl;
                    PuntajeTotalDos = 0;
                    system("pause");
                    break;
                }
            }

            cout << " Lanzamiento " << (lanzamiento + 1) << " de la Ronda " << Ronda << ": " << PuntajeLanzamiento2 << endl;

            if (PuntajeLanzamiento2 > PuntajeMaxLanzamiento2) {
                PuntajeMaxLanzamiento2 = PuntajeLanzamiento2;
            }
            system("pause");
        }
        system("cls");
        PuntajeTotalDos += PuntajeMaxLanzamiento2;

        if (PuntajeTotalDos > PuntuacionMaxima) {
            PuntuacionMaxima = PuntajeTotalDos;
            NombreMaximo = Nombre2;
        }

        SiguienteRondaJugadorDos(Ronda, PuntajeTotalDos, PuntajeTotalUno , Nombre1, Nombre2);

        Ronda++;
    }

    if (PuntajeTotalUno >= 100) {
        FinPartida(Ronda, Nombre1, PuntajeTotalUno);
    } else {
        FinPartida(Ronda, Nombre2, PuntajeTotalDos);
    }
}




#endif // FUNCIONES_H_INCLUDED
