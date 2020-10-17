#include <iostream>
#include <math.h>

using namespace std;

bool Golpe(float *BalaOfensiva, float *CanionDefensivo, float *TiempoAire);


int main()
{
    float RangoBO=0.5; //BO= Bala Ofensiva
    float RangoBD=0.025; //BD = Bala Defensiva
    float RetrasoInfo=2; //Lo que demora en llegar la información
    float RetrasoComputador=0.5; //Lo que demora la cumputadora
    float VelocidadBO=30; // m/s
    float VelocidadBD=35; // m/s
    float SeparacionXCOCD=1000; // m
    float DistanciaX=0; // m ; la distancia que recorre en X la BD
    float DistanciaY=0; // m; la distancia que recorre en Y la BD
    float Tiempo=0; // m; tiempo que demorará la BD en tocar al enemigo
    float CanionO[2]{0,0}, CanionD[2]{38.6,22.8};//PosX, PosY
    float BalaO[5]{}, BalaD[5]{};//Velocidad, PosX, PosY, Angulo, Radio de explosion

    //Inicializacion de las variables del Ofensivo
    BalaO[0]=VelocidadBO;
    BalaO[1]=CanionO[0];
    BalaO[2]=CanionO[1];
    BalaO[3]=3.141592/4;
    BalaO[4]=RangoBO;
    //De las defensivas
    BalaD[0]=VelocidadBO;
    BalaD[1]=CanionD[0];
    BalaD[2]=CanionD[1];
    BalaD[4]=RangoBD;

    //Tiempo que demora la bala en chocar
    float TiempoVuelo=0;
    // Se debe calcular primero si la BalaO dará con el Cañon Defensivo
    if(Golpe(BalaO, CanionD, &TiempoVuelo))
    {
        cout << true<< endl;
    }
    return 0;
}

bool Golpe(float *BalaOfensiva, float *CanionDefensivo, float *TiempoAire)
{
    //Retornara true si la bala choca con el cañón, false de lo contrario
    float PosXCanion=CanionDefensivo[0];
    float PosYCanion=CanionDefensivo[1];
    float VelocidadBala=*BalaOfensiva++;
    float PosXBala=*BalaOfensiva++;
    float PosYBala=*BalaOfensiva++;
    float AnguloDisparo=*BalaOfensiva++;
    float RadioExplosion=*BalaOfensiva;

    //float DiferenciaPrevia=sqrt((PosXBala*PosXBala)+(PosYBala*PosYBala));

    //Se iterará entre 0 y 3 minutos (180 segundos)
    for(int Tiempo=0; Tiempo<10000; Tiempo++)
    {
        float i=float(Tiempo)/10;
        // Se calcula su posicion
        float PosXActual=PosXBala+VelocidadBala*cos(AnguloDisparo)*i;
        float PosYActual=PosYBala+VelocidadBala*sin(AnguloDisparo)*i-(4.9*i*i);
        // Se le agrega el radio
        PosXActual+=RadioExplosion;
        PosYActual+=RadioExplosion;
        float Diferencia=sqrt(((PosXActual-PosXCanion)*(PosXActual-PosXCanion))+((PosYActual-PosYCanion)*(PosYActual-PosYCanion)));
        /*if(Diferencia<DiferenciaPrevia)
        {
            return false;
        }*/
        if(Diferencia<RadioExplosion)
        {
            *TiempoAire=i;
            return true;
        }
        //DiferenciaPrevia=Diferencia;
    }
    return false;
}
