//ANGEL EMANUEL MENDOZA REYES 
//22110083
//GRUPO 2 O
//PROGRAMACION ORIENTADA A OBJETOS
//PARCIAL 2
//LUIS MANUEL MORALES MEDINA
//TRABAJO MIERCOLES   Parte 2 
#include<iostream> 
#include<string>
#include <sstream>// SE INCLUYE UNA LIBRERIA
using namespace std;
class Date{ // CREAMOS LA CLASE DATE
// ATRIBUTOS DE LA CLASE DATE
private:   
int Year;
	int Month;
		int Day;
			int diagonal;
			string dateinstring;
//METODOS DE LA CLASE DATE
public:
//METODOS DE LA CLASE DATE CON SUS PARAMETROS
Date(int year,int month,int day,int Diagonal){
	year=Year;
		month=month;   
			day=Day;
				Diagonal=diagonal;
}
void Menu_Cadena(){
    char Fecha [10], aux; // DECLARAMOS UNA VARIABLE DE TIPO CHAR LLAMADA FECHA Y TAMBIEN AUX
    Day=0;
    Month=0;  //LES ASIGNAMOS VALORES A LAS VARIABLES QUE TENGAN UN VALOR DE CERO
    Year=0;
    diagonal=0;    
    cout<<"INGRESE LA FECHA"<<endl;
    gets(Fecha); //SE INGRESA LA CADENA DE CARACTERES Y SE LEE LA CADENA DE CARACTERES QUE INGRESE EL USUARIO
    // SE REVISA CADA CARACTER HASTA QUE SE ACABE LA LINEA 
    //SE INICIA UN CICLO FOR 
    for(int i=0;Fecha[i]!=NULL;i++){   
        aux=Fecha[i]-'0';
        //SE CUENTAN LAS DIAGONALES
        if(Fecha[i]=='/'){
            diagonal++;
        }
        if(Fecha[i]!='/'){
        	//INICIAMOS UN SWITCH PARA LAS VARIABLES DE DAY, MONTH, YEAR
        	
            switch (diagonal){
        case 0:
        Day=(Day*10)+aux;
            break;
        case 1:
        Month=(Month*10)+aux;//SE MULTIPLICAN POR 10 ANTES DE SUMAR LO INTRODUCIDO PARA RECORRER EL DIGITO CADA VEZ QUE SE LEA 
            break;
        case 2:
        Year=(Year*10)+aux;
            break;
        
        default:
            break;
        }
        }
        

    }
} 
bool validar_fecha(){
    if(Month>12 or Day>31 or Month<=0 or Day<=0 or diagonal>2 or Month%2==0 and Day>30 and Month != 2){ //SE VAN A VALIDAR TODAS LAS CONDICIONES QUE 
                                                                                                        //TENEMOS EN LOS DIAS Y MESES A TRAVEZ DE UN 
                                                                                                        //IF
        cout<<"LA FECHA ES INVALIDA"<<endl;
        return false;
    }else{
         //VALIDAR LA VARIABLE YEAR PARA SABER SI EL AÑO ES BISIESTO A TRAVEZ DE LAS CONDICIONES QUE TIENE EL IF PARA EL YEAR
          if(Year%4==0 and Year%100!=0){
            cout<<"EL ANIO ES BISIESTO"<<endl;
            //CONDICION DEL MES DE FEBRERO 
            if(Month==2 and Day>28){
                 cout<<"LA FECHA NO ES VALIDA"<<endl;
                 
                 return false;
                 //CONDICION DEL MES DE FEBRERO 
            }else if(Day>28 and Month==2 ){
                cout<<"LA FECHA NO ES VALIDA";
                return false;
            }
            
        } //SI NO HAY NINGUN PROBLEMA CON LA FECHA NOS VA A REGRESAR UN VALOR TRUE BOOLEANO
         cout<<"LA FECHA ES VALIDA \n LA FECHA ES :\n"<<Day<<"/"<<Month<<"/"<<Year<<endl;
    return true;
    }
}     //FUNCION OPERATOR CONST CHAR*
	 operator const char*(){
	 	ostringstream formattedDate;
	 	formattedDate<<Day<<"/"<<Month<<"/"<<Year<<endl;
	 	dateinstring = formattedDate.str();
	 	return dateinstring.c_str();
	 }
};

int main(){
    int month,year,day,diagonal; //DECLARAMOS VARIABLES PARA VERIFICAR SI LA FECHA ES VALIDA
    
    bool verificar; //DECLARAMOS UNA VARIABLE BOOLENA PARA VERIFICAR LA FECHA

    Date fecha=Date(month,year,day,diagonal);//SE CREA EL OBJETO fecha QUE ESTE ES IGUAL A DATE CON SUS PARAMETRO QUE INCLUYE LAS VARIABLES
    
    while (verificar==false){//REVISAMOS SI LA FECHA ES VALIDA 
                             //SI LO ES SE ROMPE EL WHILE Y SE ACABA EL PROGRAMA 
        fecha.Menu_Cadena(); //LLAMAMOS AL METODO DE MENU_CADENA PARA EJECUTAR TODO LO DEL CONSTRUCTOR
      
       verificar=fecha.validar_fecha();//VERIFICAR ES IGUAL AL OBJETO QUE LLAMA AL METODO DE VALIDAR_FECHA CON SU CONSTRUCTOR.
    }    
    cout<<"validacion de la fecha operator const char*()"<<fecha<<endl;
return 0;

}
