#include <iostream>
#include <math.h>

using namespace std;

bool Golpe(float *BalaOfensiva, float *CanionDefensivo);


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
    float CanionO[2]{0,0}, CanionD[2]{1000,20};//PosX, PosY
    float BalaO[5]{}, BalaD[5]{};//Velocidad, PosX, PosY, Angulo, Radio de explosion

    //Inicializacion de las variables del Ofensivo
    BalaO[0]=VelocidadBO;
    BalaO[1]=CanionO[0];
    BalaO[2]=CanionO[1];
    BalaO[3]=3.141592/4;
    BalaO[4]=RangoBO;
    //De las defensivas
    BalaO[0]=VelocidadBO;
    BalaO[1]=CanionD[0];
    BalaO[2]=CanionD[1];
    BalaO[4]=RangoBD;

    // Se debe calcular primero si la BalaO dará con el Cañon Defensivo
    if(Golpe(BalaO, CanionD))
    {
        cout << true<< endl;
    }
    return 0;
}

bool Golpe(float *BalaOfensiva, float *CanionDefensivo)
{
    //Retornara true si la bala choca con el cañón, false de lo contrario
    float PosXCanion=CanionDefensivo[0];
    float PosYCanion=CanionDefensivo[1];
    float VelocidadBala=BalaOfensiva[0];
    float PosXBala=BalaOfensiva[1];
    float PosYBala=BalaOfensiva[2];
    float AnguloDisparo=BalaOfensiva[3];
    float RadioExplosion=BalaOfensiva[4];
    //Se iterará entre 0 y 3 minutos (180 segundos)
    for(int Tiempo=0; Tiempo<1800; Tiempo++)
    {
        float i=Tiempo/10;
        // Se calcula su posicion
        float PosXActual=PosXBala+VelocidadBala*cos(AnguloDisparo)*i;
        float PosYActual=PosYBala+VelocidadBala*sin(AnguloDisparo)*i;
        // Se le agrega el radio
        PosXActual+=RadioExplosion;
        PosYActual+=RadioExplosion;
        if(abs(sqrt((PosXActual*PosXActual)+(PosYActual*PosYActual))-sqrt((PosXCanion*PosXCanion)+(PosYCanion*PosYCanion)))<RadioExplosion)
        {
            return true;
        }
    }
    return false;
}
