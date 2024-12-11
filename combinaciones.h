#ifndef COMBINACIONES_H_INCLUDED
#define COMBINACIONES_H_INCLUDED
void ordenarVector(int v[], int tam ){
    int i,j; //for

    int posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

bool HayEscalera(int vectorDado[], int tiro){

    ordenarVector(vectorDado, 6);
    bool Escalera = false;
    int Numero = 0;

    for(int x=0; x<6; x++){
        Numero++;
        if (vectorDado[x]==Numero)Escalera = true;
        if (vectorDado[x]!=Numero){
            Escalera = false;
            break;
        }


    }
    if (Escalera == true )return true;
    if (Escalera == false) return false;

}

bool Sexteto6(int vectorDado[], int tiro, int &ValorSexteto) {

    for (int i = 0; i < tiro; i++) {
        if (vectorDado[0] != vectorDado[i]) {
            return false;
        }
    }
    ValorSexteto = vectorDado[0]; // Actualiza ValorSexteto con el valor del sexteto
    return true;

}


#endif // COMBINACIONES_H_INCLUDED
