#include <iostream>
using namespace std;
//Definir fuera de la main
int const filas=4;
int const columnas=5;
void limpiarMatrices (bool disponibilidad[filas][columnas],int peso[filas][columnas]);
void ImprimirMatrizBooleana(bool matriz[filas][columnas]);
void coordenadasingreso (bool disponibilidad[filas][columnas],int cantidadcontenedores,int filasactuales,int columnasactuales,string marcas[filas][columnas],string puertoCarga[filas][columnas],int peso[filas][columnas],string tipoArticulo[filas][columnas],int tipoA,int tipoB,int tipoC);
void ImprimirMatricesString(string texto[filas][columnas]);
int ImprimirMatricesEnteras(int entero[filas][columnas]);
float PorcentajeOcupacion (bool disponibilidad[filas][columnas]);
int Valorecaudado (bool disponibilidad[filas][columnas]);
void Cantidadcontenedorespuertos(bool disponibilidad[filas][columnas]);
float Promediopeso (int peso[filas][columnas],bool disponibilidad[filas][columnas]);
int cantidadArticulosA (string tipoArticulo[filas][columnas],int cantidadA);
int cantidadArticulosB (string tipoArticulo[filas][columnas],int cantidadB);
int cantidadArticulosC (string tipoArticulo[filas][columnas],int cantidadC);
float pesoEnUnPuerto (string puertoCarga[filas][columnas],int peso[filas][columnas], string nombrePuerto,int cantidadPuertos);
void ReporteNC (int cantidadPuertos,string NombrePuertos[],int vectorcantidad[]);
void Listaeconomica (bool disponibilidad[filas][columnas],string marcas [filas][columnas]);
void Listapremium (bool disponibilidad[filas][columnas],string marcas [filas][columnas]);
int PagoEmpresa (string marcas [filas][columnas],bool disponibilidad[filas][columnas], string nombreEmpresa);
int filaMayorCarga (int peso[filas][columnas]);
int columnaMenorCarga (int peso[filas][columnas]);
string Nombremaspeso (int peso[filas][columnas],string marcas [filas][columnas]);
int Pesomasgrande (int peso[filas][columnas]);
string Nombremasliviano (int peso[filas][columnas],int contenedorconmenospeso,string marcas[filas][columnas]);
int Pesomasliviano (int peso[filas][columnas],int contenedorconmenospeso);
int main (){
    //Preguntar por la cantidad de puertos
    int cantidadPuertos = 0;
    cout<<"Digite la cantidad de puertos"<<endl;
    cin>>cantidadPuertos;
    
    //Preguntar por los nombres de la "n cantidad de puertos"
        string NombrePuertos[cantidadPuertos];
    
    //vector de cantidad de puertos 
        int vectorcantidad[cantidadPuertos];

    //Definir las matrices
    bool disponibilidad[filas][columnas];
    string marcas [filas][columnas];
    int peso[filas][columnas];
    string puertoCarga[filas][columnas];
    string tipoArticulo[filas][columnas];
    
    //limpiar las matrices 

    limpiarMatrices(disponibilidad,peso);
    
    /*lo hacemos por fuera de la main
    */  
    
    for(int repeticionesenpuerto=0;repeticionesenpuerto<cantidadPuertos;repeticionesenpuerto++){
        for(int i=0;i<cantidadPuertos;i++){
        cout<<"Cual es el nombre del puerto: "<<i<<endl;
            cin>>NombrePuertos[i];
        int cantidadcontenedores=0;
        cout<<"Ingrese la cantidad de contenedores que va a ingresar en el barco en el puerto "<<endl<<NombrePuertos[i] <<endl;
            cin>>cantidadcontenedores;
            vectorcantidad[i]=cantidadcontenedores;
        //Para imprimir las matrices de disponibilidad 
    cout<<"Matriz de disponibilidad"<<endl;
    ImprimirMatrizBooleana(disponibilidad);
    /*lo hacemos por fuera de la main
    */
    
     //preguntar por la cantidad de contenedores en cada puerto y sus cordenadas
    int repeticiones=0;
    int filasactuales=0;
    int columnasactuales=0;
    int tipoA=0;
    int tipoB=0;
    int tipoC=0;
    coordenadasingreso (disponibilidad,cantidadcontenedores,filasactuales,columnasactuales,marcas,puertoCarga,peso,tipoArticulo,tipoA,tipoB,tipoC);
    /*
    lo hacemos por fuera de la main
    */
    //Imprimir matriz disponibilidad actializado
     cout<<"Matriz de disponibilidad"<<endl;
    ImprimirMatrizBooleana(disponibilidad);
    //para imprimir las matrices de texto
    cout<<"Matriz de Marcas"<<endl;
    ImprimirMatricesString(marcas);
    cout<<"Matriz de puerto de carga"<<endl;
    ImprimirMatricesString(puertoCarga);
    cout<<"Matriz de tipo de articulo"<<endl;
    ImprimirMatricesString(tipoArticulo);
    /*lo hacemos por fuera de la main
    */
    
    //para imprimir las matrices enteras
    cout<<"Matriz de peso"<<endl;
    ImprimirMatricesEnteras(peso);
    /* lo hacemos por fuera de la main
    */  
    cout<<endl;
    //Porcentaje de ocupacion
    cout<<"El porcentaje de ocupacion es "<<PorcentajeOcupacion (disponibilidad)<<"%"<<endl;
    //El valor recaudado
    cout<<"El valor recaudado en el puerto actual es "<<Valorecaudado ( disponibilidad)<<"$"<<endl;
    
    }   

    //Todos los procedimientos y funciones
    
    //Cantidad total de contenedores ingresados
    Cantidadcontenedorespuertos(disponibilidad);
    //Promedio del peso de los contenedores     
    cout<<"El promedio del peso es "<<Promediopeso (peso,disponibilidad)<<endl;
    //Cantidad articulos segun la clase A
	int cantidadA=0;
	cantidadArticulosA (tipoArticulo,cantidadA);
	cout<<"La cantidad de contenedores tipo A es de: "<<cantidadArticulosA (tipoArticulo, cantidadA)<<endl;
	//Cantidad articulos segun la clase B
	int cantidadB=0;
	cout<<"La cantidad de contenedores tipo B es de: "<<cantidadArticulosB (tipoArticulo, cantidadB)<<endl;
	//Cantidad articulos segun la clase C
	int cantidadC=0;
	cout<<"La cantidad de contenedores tipo C es de: "<<cantidadArticulosC (tipoArticulo, cantidadC)<<endl;
    //Dado el puerto de origen
    string nombrePuerto;
	cout<<"Ingrese el nombre del puerto del cual desea conocer el promedio de peso ingresado en el mismo: "<<endl;
	cin>>nombrePuerto;
    cout<<"El promedio del peso del puerto dado es "<<pesoEnUnPuerto (puertoCarga,peso,nombrePuerto,cantidadPuertos)<<endl;
	//Reporte
    ReporteNC (cantidadPuertos,NombrePuertos,vectorcantidad);
    //Listado de marcas en zona economica
    cout<<"El listado de las marcas en zona economica es: "<<endl;
    Listaeconomica ( disponibilidad,marcas );
    //Listado de marcas en zona economica
    cout<<"El listado de las marcas en zona premium es: "<<endl;
    Listapremium (disponibilidad,marcas);
    //Valor a pagar de cada empresa
    string nombreEmpresa=" ";
    cout<<"Ingrese el nombre de la empresa que desea conocer el valor del pago: "<<endl;
    cin>>nombreEmpresa;
    cout<<"El valor a pagar por la empresa es "<<PagoEmpresa ( marcas,disponibilidad, nombreEmpresa)<<endl;
    //fila de mayor carga 
    cout<<"La fila de mayor carga es "<<filaMayorCarga (peso)<<endl;
    //columna de menor carga
    cout<<"La columna de menor carga es "<<columnaMenorCarga (peso)<<endl;
    //empresa y peso mas alto
    cout<<"La empresa con el contenedor mas pesado es "<<Nombremaspeso ( peso, marcas)<<endl;
    cout<<"Con un peso de "<<Pesomasgrande ( peso)<<endl;
    //empresa y peso mas liviano
    int contenedorconmenospeso=INT_MAX;
    cout<<"La empresa con el contenedor mas liviano es "<<Nombremasliviano (peso,contenedorconmenospeso, marcas)<<endl;
    cout<<"El peso mas liviano es "<<Pesomasliviano (peso,contenedorconmenospeso)<<endl;
    }
    return 0;
}

//Limpiamos las matrices con un procedimiento
void limpiarMatrices (bool disponibilidad[filas][columnas],int peso[filas][columnas]){
    //se recorre la matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            disponibilidad[i][j]=1;
            peso[i][j]=0;
        }
    }
}
//imprimimos las matrices booleanas con un procedimiento
void ImprimirMatrizBooleana(bool matriz[filas][columnas]){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
}
//Preguntar por el numero de contenedores ingresados en cada puerto y su coordenadas
void coordenadasingreso (bool disponibilidad[filas][columnas],int cantidadcontenedores,int filasactuales,int columnasactuales,string marcas[filas][columnas],string puertoCarga[filas][columnas],int peso[filas][columnas],string tipoArticulo[filas][columnas],int tipoA,int tipoB,int tipoC){
        for(int i=0;i<cantidadcontenedores;i++){
            cout<<"ingrese la fila donde quiere dejar su "<<i<<" contenedor"<<endl;
            cin>>filasactuales;
            cout<<"ingrese la columna donde quiere dejar su "<<i<<" contenedor"<<endl;
            cin>>columnasactuales;
            if(disponibilidad[filasactuales][columnasactuales]==0){
            while(disponibilidad[filasactuales][columnasactuales]==0){
            cout<<"Su posicion no es valida, por favor intentelo de nuevo"<<endl;
            cout<<"ingrese la fila donde quiere dejar su "<<i<<" contenedor"<<endl;
            cin>>filasactuales;
            cout<<"ingrese la columna donde quiere dejar su "<<i<<" contenedor"<<endl;
            cin>>columnasactuales;
            }
                } else{
            cout<<"Ingresado con exito"<<endl;
            disponibilidad[filasactuales][columnasactuales]=0;
            //preguntar por marca
            cout<<"Ingrese la marca de su "<<i<<" contenedor"<<endl;
            cin>>marcas[filasactuales][columnasactuales];
            //preguntar por peso 
            cout<<"Ingrese el peso en kg de su "<<i<<" contenedor"<<endl;
            cin>>peso[filasactuales][columnasactuales];
            //preguntar el puerto de orgigen 
            cout<<"Ingrese el puerto de origen del contenedor "<<endl;
            cin>>puertoCarga[filasactuales][columnasactuales];         
            //preguntar tipo de articulo
            cout<<"Ingrese el tipo de articulos que almacena su contenedor: "<<endl;
            cout<<"Tipo A: Alimentos"<<endl;
            cout<<"Tipo B: Dispositivos electronicos"<<endl;
            cout<<"Tipo C: Ropa y demas textiles"<<endl;
            cin>>tipoArticulo[filasactuales][columnasactuales];
            }
    }
}
//Porcentaje de ocupacion
float PorcentajeOcupacion (bool disponibilidad[filas][columnas]){
    int contadorcontenedores=0;
    float ocupacion=0.0;
      for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (disponibilidad[i][j]==0){
                contadorcontenedores=contadorcontenedores+1;
                
            }
        }
    }
    ocupacion=(contadorcontenedores*100)/(filas*columnas);
    return ocupacion;
}

int Valorecaudado (bool disponibilidad[filas][columnas]){
    int zonaEco=0;
    int zonaPre=0;
    int racudo=0;
      for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (disponibilidad[i][j]==0){
                if(i==0 || i==3 || j==0 || j==4 ){
                    zonaEco=zonaEco+1;
                }else{
                    zonaPre=zonaPre+1;
                }
                
            }
        }
    }
    racudo=(zonaEco*100)+(zonaPre*300);
    return racudo;
}

//imprimimos las matrices de texto con un procedimiento
void ImprimirMatricesString(string texto[filas][columnas]){
        for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<texto[i][j]<<"\t";
        }
        cout<<endl;
    }
}
//imprimimos las matrices de enteros con un procedimiento
int ImprimirMatricesEnteras(int entero[filas][columnas]){
        for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<entero[i][j]<<"\t";
        }
        cout<<endl;
    }
}
//Cantidad contenedores ingresados en los n puertos
void Cantidadcontenedorespuertos(bool disponibilidad[filas][columnas]){
    int contadorcontenedores=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (disponibilidad[i][j]==0){
                contadorcontenedores=contadorcontenedores+1;
                
            }
        }
}
cout<<"La cantidad de contenedores ingresados al barco es "<<contadorcontenedores<<endl;
}
//Promedio de peso que estan en una celda 
float Promediopeso (int peso[filas][columnas],bool disponibilidad[filas][columnas]){
    int contadorpeso=0;
    int acumuladorpeso=0;
    float promediopeso=0.0;
      for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (disponibilidad[i][j]==0){
                contadorpeso=contadorpeso+1;
                acumuladorpeso=acumuladorpeso+peso[i][j];
            }
        }
    }
    promediopeso=(acumuladorpeso)/(contadorpeso);
    return promediopeso;
}

//Cantidad articulos A
int cantidadArticulosA (string tipoArticulo[filas][columnas],int cantidadA){;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(tipoArticulo[i][j]=="A"){
				cantidadA=cantidadA+1;
			}
		}
	}
	return cantidadA;
}
//cantidad articulos B
int cantidadArticulosB (string tipoArticulo[filas][columnas],int cantidadB){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(tipoArticulo[i][j]=="B"){
				cantidadB=cantidadB+1;
			}
		}
	}
	return cantidadB;
}
//cantidad articulos C
int cantidadArticulosC (string tipoArticulo[filas][columnas],int cantidadC){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(tipoArticulo[i][j]=="C"){
				cantidadC=cantidadC+1;
			}
		}
	}
	return cantidadC;
}
//Dado el puerto de origen
float pesoEnUnPuerto (string puertoCarga[filas][columnas],int peso[filas][columnas], string nombrePuerto,int cantidadPuertos){
	int pesoDelPuerto=0;
	int contadorContenedores=0;
	float promedioContenedoresPuerto=0.0;
	for(int r=0;r<cantidadPuertos;r++){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(nombrePuerto==puertoCarga[i][j]){
					pesoDelPuerto=pesoDelPuerto+peso[i][j];
					contadorContenedores=contadorContenedores+1;
				}
			}
		}
	}
	promedioContenedoresPuerto=pesoDelPuerto/contadorContenedores;
	return promedioContenedoresPuerto;
}



//Reporte de nombre de puerto y cantidad de contenedores ingresados ordenados de mayor a menor
void ReporteNC (int cantidadPuertos,string NombrePuertos[],int vectorcantidad[]){
    for (int i=0;i<cantidadPuertos;i++){
        for(int j=0;j<cantidadPuertos;j++){
            if (vectorcantidad[i]>vectorcantidad[j]){
                int aux=vectorcantidad[i];
                string AUXNombrePuertos=NombrePuertos[i];
                vectorcantidad[i]=vectorcantidad[j];
                 NombrePuertos[i]= NombrePuertos[j];
                 vectorcantidad[j]=aux;
                 NombrePuertos[j]=AUXNombrePuertos;
            }
        }
    }
    cout<<"REPORTE"<<endl;
    for(int i=0;i<cantidadPuertos;i++){
        cout<<NombrePuertos[i]<<"-->"<<vectorcantidad[i]<<endl;
    }
}
//Listado de marcas que van en enconomica
void Listaeconomica (bool disponibilidad[filas][columnas],string marcas [filas][columnas]){
      for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (disponibilidad[i][j]==0){
                if(i==0 || i==3 || j==0 || j==4 ){
                cout<<marcas[i][j]<<"\t "<<endl;
                }   
            }
        }
    }
}

//Listado de marcas que van en premium 
void Listapremium (bool disponibilidad[filas][columnas],string marcas [filas][columnas]){
      for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (disponibilidad[i][j]==0){
                if(i==0 || i==3 || j==0 || j==4 ){
                }else {
                    cout<<marcas[i][j]<<"\t"<<endl;
                }
            }
        }
    }
}
//Pago por empresa

int PagoEmpresa (string marcas [filas][columnas],bool disponibilidad[filas][columnas],string nombreEmpresa){
    int contadoreco=0;
    int contadorpre=0;
    int pago=0;
	for (int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
          		if (disponibilidad[i][j]==0){
                if(nombreEmpresa==marcas[i][j]){
                   	if(i==0 || i==3 || j==0 || j==4 ){
                        contadoreco=contadoreco+1;
                    }else{
                        contadorpre=contadorpre+1;
                    }
                }
            }
        }
    }
    pago=(contadoreco*100)+(contadorpre*300);
    return pago;
} 


//Determinar fila con mayor carga
int filaMayorCarga (int peso[filas][columnas]){
    int numerosEnI=INT_MIN;
    int mayor=-1;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                if(peso[i][j]>numerosEnI){
                numerosEnI=peso[i][j];
                mayor=i;
            }
        }
    }
    return mayor;
}

//Determinar la columna con la menor carga
int columnaMenorCarga (int peso[filas][columnas]){
    int numerosEnJ=INT_MAX;
    int menor=-1;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                if(peso[i][j]<numerosEnJ){
                numerosEnJ=peso[i][j];
                menor=j;
            }
        }
    }
    return menor;
}

 //Nombre de contenedor con mas peso y menos peso
 string Nombremaspeso (int peso[filas][columnas],string marcas [filas][columnas]){
    string maspesado=" ";
    int maspeso=INT_MIN;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                if(peso[i][j]>maspeso){
                maspeso=peso[i][j];
                maspesado=marcas[i][j];
            }
    	}
    }
    return maspesado;
}

//Peso mas grande
int Pesomasgrande (int peso[filas][columnas]){
    int contenedorconmaspeso=INT_MIN;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                if(peso[i][j]>contenedorconmaspeso){
                contenedorconmaspeso=peso[i][j];
                
            }
        }
    }
    return contenedorconmaspeso;
}

//Nombre de peso mas liviano
string Nombremasliviano (int peso[filas][columnas],int contenedorconmenospeso,string marcas[filas][columnas]){
	string MarcaLiviano="";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                if(peso[i][j]<contenedorconmenospeso && peso[i][j]!=0 ){
                contenedorconmenospeso=peso[i][j];
                 MarcaLiviano=marcas[i][j];
           		}	
			}
        }
    return MarcaLiviano;
}

//Peso mas liviano
int Pesomasliviano (int peso[filas][columnas],int contenedorconmenospeso){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                if(peso[i][j]<contenedorconmenospeso && peso[i][j]!=0 ){
                contenedorconmenospeso=peso[i][j];
           		}	
			}
        }
    return contenedorconmenospeso;
}
