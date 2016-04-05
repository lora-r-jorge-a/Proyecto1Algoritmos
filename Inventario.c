/*Programa de ventas,compras en los departamentos*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct departamentos{//Estructura para guardar informacion de los articulos
	char  producto[30];
 	int precio;    
 	int cantidad;
};

//Funciones a usar en este programa
char elegirRegistro();
void venderProducto(char *b,char *a, int n,struct departamentos dept[n]);
void comprarProducto(char *b,char *a, int n,struct departamentos dept[n]);
void agregarProducto(char *a, int n,struct departamentos depa[n]);
struct departamentos leerArchivo(char *a,int n,struct departamentos depa[n]);
int leerElementos(char *a);
char elegirDepa();


 
int main(){
	char opcion;
	struct departamentos *aba,*ferre,*hig,*elec,*rop;
	do{
		int c,t=0,s=0,s2=0, i;
		FILE *fp;
		char arch,archivo[30],archivo2[30];
		printf("\n\n\t Elije una opcion: ");//Inicio de menu
		printf("\n\n\t a) Consultar inventario.");
		printf("\n\t b) Ingresar un producto.");
		printf("\n\t c) Compra de un producto. " );
		printf("\n\t d) Venta de un producto. ");
		printf("\n\t e) Consultar registro de Compra/venta.");
		printf("\n\n\t\t\tQ.-Salir");// fin de menu
		printf("\n\n\t\t\tSelecciona una opcion: ");
		printf("\n\n ");	
		fflush(stdin);
		opcion=getchar();
		switch(opcion){//Inicio de menu 
			case 'a': case 'A': //opcion consultar inventario
				printf("\n\n\t **Consultar inventario** ");
				arch=elegirDepa();//Inicio de menu para consultar inventario
				if(arch=='a' || arch=='A'){
					strcpy(archivo,"abarrotes.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			}
			  		else{		
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			printf("\n\n\tproductos en el departamento Abarrotes: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba[i].producto,aba[i].cantidad,aba[i].precio);
							}
			  			printf("\n");	
						}
					}//fin else y opcion abarrotes
				else if(arch=='b' || arch=='B'){
			  		strcpy(archivo,"Ferreteria.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			}	
			  		else{	
			  			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			printf("\n\n\tproductos en el departamento Ferreteria: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,ferre[i].producto,ferre[i].cantidad,ferre[i].precio);
							}
			  			printf("\n");	
						}
					}//fin else if y opcion ferreteria
				else if(arch=='c' || arch=='C'){
			  		strcpy(archivo,"Electronica.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			}
			  		else{	
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			printf("\n\n\tproductos en el departamento de Electronica: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,elec[i].producto,elec[i].cantidad,elec[i].precio);
							}
			  			printf("\n");	
						}
					}//fin else if y opcion electronica
				else if(arch=='d' || arch=='D'){
			  		strcpy(archivo,"Ropa.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			}
  			  		else{
			  			struct departamentos rop[c];	
		  	  			*rop=leerArchivo(archivo,c,rop);
			  			printf("\n\n\tproductos en el departamento de Ropa: %d",c);	
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,rop[i].producto,rop[i].cantidad,rop[i].precio);	
							}
	                  	printf("\n");	
						}
					}// fin else if y opcion ropa
				else if(arch=='e' || arch=='E'){
 			  		strcpy(archivo,"Higiene.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			}
			  		else{	
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			printf("\n\n\tproductos en el departamento de Higiene: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,hig[i].producto,hig[i].cantidad,hig[i].precio);
						}
			  			printf("\n");	
						}
					}//fin else if y opcion higiene

			  	fflush(stdin);
			  	getchar();
				break;//fin de la opcion consultar inventario
			

			case 'b' : case 'B': //Opcion agregar un producto
				printf("\n\n\t Elije un departamento: ");
				arch=elegirDepa();
		        if(arch=='a' || arch=='A'){//inicia menu para agregar un producto
					strcpy(archivo,"abarrotes.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos 
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
					  	agregarProducto(archivo,c,aba);
						}
			  		else{	
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			printf("\n\n\tproductos en el departamento Abarrotes: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba[i].producto,aba[i].cantidad,aba[i].precio);
							}
			  			agregarProducto(archivo,c,aba);		  
                        }
					}//fin if
		        else if(arch=='b' || arch=='B'){
			  		strcpy(archivo,"Ferreteria.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			agregarProducto(archivo,c,ferre);
			  			}
			  		else{		
			  			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			printf("\n\n\tproductos en el departamento Ferreteria: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,ferre[i].producto,ferre[i].cantidad,ferre[i].precio);
							}
			  			agregarProducto(archivo,c,ferre);
			            }
					}//fin else if
		        else if(arch=='c' || arch=='C'){	
			  		strcpy(archivo,"Electronica.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			agregarProducto(archivo,c,elec);
						}
			  		else{
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			printf("\n\n\tproductos en el departamento de Electronica: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,elec[i].producto,elec[i].cantidad,elec[i].precio);
							}
			  			agregarProducto(archivo,c,elec);
                    	}
					}//fin else if
		        else if(arch=='d' || arch=='D'){
			  		strcpy(archivo,"Ropa.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos ropa[c];	
		  	  			*ropa=leerArchivo(archivo,c,ropa);
			  			agregarProducto(archivo,c,ropa);
			  			}
			  		else{		
			  			struct departamentos ropa[c];	
		  	  			*ropa=leerArchivo(archivo,c,ropa);
			  			printf("\n\n\tproductos en el departamento de Ropa: %d",c);	
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,ropa[i].producto,ropa[i].cantidad,ropa[i].precio);
							}
			  			agregarProducto(archivo,c,ropa);
                    	}
					}//fin else if
		        else if(arch=='e' || arch=='E'){
 			  		strcpy(archivo,"Higiene.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			agregarProducto(archivo,c,hig);	
			  			}
			  		else{	
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			printf("\n\n\tproductos en el departamento de Higiene: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,hig[i].producto,hig[i].cantidad,hig[i].precio);
							}
			  			agregarProducto(archivo,c,hig);	
                    	}
					}//fin else if
			fflush(stdin);
			getchar();
			break;//fin de la opcion agregar un producto


		    case 'c' : case 'C': //opcion comprar un producto
				printf("\n\n\t Elije un departamento: ");
				arch=elegirDepa();//inicia menu
		        if(arch=='a' || arch=='A'){//opcion abarrotes
					strcpy(archivo,"abarrotes.txt");
			  		strcpy(archivo2,"comprasAbarrotes.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			comprarProducto(archivo2,archivo,c,aba);
			  			}
			  		else{
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			printf("\n\n\tproductos en el departamento Abarrotes: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba[i].producto,aba[i].cantidad,aba[i].precio);
							}
			  			comprarProducto(archivo2,archivo,c,aba);
						}
					}//fin if y fin de abarrotes
		        else if(arch=='b' || arch=='B'){//opcion ferreteria
					strcpy(archivo,"Ferreteria.txt");
		 	  		strcpy(archivo2,"comprasFerreteria.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			   			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			comprarProducto(archivo2,archivo,c,ferre);}
	                else{
			  			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			printf("\n\n\tproductos en el departamento Ferreteria: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,ferre[i].producto,ferre[i].cantidad,ferre[i].precio);
							}
			  			comprarProducto(archivo2,archivo,c,ferre);
			  	      }
					}//fin else if y ferreteria
		        else if(arch=='c' || arch=='C'){//opcion electronica	
			  		strcpy(archivo,"Electronica.txt");
		 	  		strcpy(archivo2,"comprasElectronica.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			comprarProducto(archivo2,archivo,c,elec);
						}
			  		else{
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			printf("\n\n\tproductos en el departamento de Electronica: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,elec[i].producto,elec[i].cantidad,elec[i].precio);
							}
			  			comprarProducto(archivo2,archivo,c,elec);
                    	}
					}//fin else if y de opcion electronica
		        else if(arch=='d' || arch=='D'){//opcion ropa
			  		strcpy(archivo,"Ropa.txt");
		 	  		strcpy(archivo2,"comprasRopa.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos ropa[c];	
		  	  			*ropa=leerArchivo(archivo,c,ropa);
			  			comprarProducto(archivo2,archivo,c,ropa);				
			  			}
                     else{	
			  			struct departamentos ropa[c];	
		  	  			*ropa=leerArchivo(archivo,c,ropa);
			  			printf("\n\n\tproductos en el departamento de Ropa: %d",c);	
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,ropa[i].producto,ropa[i].cantidad,ropa[i].precio);
							}
			  			comprarProducto(archivo2,archivo,c,ropa);
                        }
					}//fin else if y de ropa
		        else if(arch=='e' || arch=='E'){//opcion higiene
 			  		strcpy(archivo,"Higiene.txt");
		 	  		strcpy(archivo2,"comprasHigiene.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			comprarProducto(archivo2,archivo,c,hig);	
			  			}
			  		else{	
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			printf("\n\n\tproductos en el departamento de Higiene: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,hig[i].producto,hig[i].cantidad,hig[i].precio);
							}
			  			comprarProducto(archivo2,archivo,c,hig);	
                        }
					}//fin else if y de higiene
			fflush(stdin);
			getchar();
			break;//fin de opcion compras
			
			
			case 'd' : case 'D': //opcion Ventas
				printf("\n\n\t Elije un departamento: ");
				arch=elegirDepa();//inicia menu de ventas
		        if(arch=='a' || arch=='A'){
					strcpy(archivo,"abarrotes.txt");
			  		strcpy(archivo2,"VentasAbarrotes.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			venderProducto(archivo2,archivo,c,aba);				
						}
			  		else{		
			  			struct departamentos aba[c];	
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			printf("\n\n\tproductos en el departamento Abarrotes: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba[i].producto,aba[i].cantidad,aba[i].precio);
							}
			  			venderProducto(archivo2,archivo,c,aba);
						}
					}//fin if
		        if(arch=='b' || arch=='B'){
			  		strcpy(archivo,"Ferreteria.txt");
			  		strcpy(archivo2,"VentasFerreteria.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			venderProducto(archivo2,archivo,c,ferre);	
						}
			  		else{
			  			struct departamentos ferre[c];	
		  	  			*ferre=leerArchivo(archivo,c,ferre);
			  			printf("\n\n\tproductos en el departamento Ferreteria: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,ferre[i].producto,ferre[i].cantidad,ferre[i].precio);
							}
			  			venderProducto(archivo2,archivo,c,ferre);
						}
					}//fin else if
		        if(arch=='c' || arch=='C'){
			  		strcpy(archivo,"Electronica.txt");
			  		strcpy(archivo2,"VentasElectronica.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			venderProducto(archivo2,archivo,c,elec);
						}
	                else{	
			  			struct departamentos elec[c];	
		  	  			*elec=leerArchivo(archivo,c,elec);
			  			printf("\n\n\tproductos en el departamento Electronica: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,elec[i].producto,elec[i].cantidad,elec[i].precio);
							}
			  			venderProducto(archivo2,archivo,c,elec);
						}
					}//fin else if
		        if(arch=='d' || arch=='D'){
			  		strcpy(archivo,"Ropa.txt");
			  		strcpy(archivo2,"VentasRopa.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos rop[c];	
		  	  			*rop=leerArchivo(archivo,c,rop);
			  			venderProducto(archivo2,archivo,c,rop);
						}
			  		else{	
			  			struct departamentos rop[c];	
		  	  			*rop=leerArchivo(archivo,c,rop);
			  			printf("\n\n\tproductos en el departamento Ropa: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,rop[i].producto,rop[i].cantidad,rop[i].precio);
							}
			  			venderProducto(archivo2,archivo,c,rop);
						}
					}//fin else if
		        if(arch=='e' || arch=='E'){
			  		strcpy(archivo,"Higiene.txt");
			  		strcpy(archivo2,"VentasHigiene.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			venderProducto(archivo2,archivo,c,hig);          
			  			}	
			  		else{
			  			struct departamentos hig[c];	
		  	  			*hig=leerArchivo(archivo,c,hig);
			  			printf("\n\n\tproductos en el departamento Higiene: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,hig[i].producto,hig[i].cantidad,hig[i].precio);
							}
			  			venderProducto(archivo2,archivo,c,hig);
						}
					}//fin else if
			fflush(stdin);
			getchar();
			break;//fin de opcion ventas
	
	
			
			case'e':case'E'://opcion compras/ventas
				printf("\n\n\t **Consultar Operaciones** ");
				arch=elegirRegistro();
				if(arch=='a' || arch=='A'){
					strcpy(archivo,"comprasAbarrotes.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{	
			  			struct departamentos aba[c];
		  	  			*aba=leerArchivo(archivo,c,aba);
			  			printf("\n\n\tCompras en Abarrotes: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba[i].producto,aba[i].cantidad,aba[i].precio);
			  				t=aba[i].precio+t;
							}
			  			printf("\n\nTotal de Compras: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='b' || arch=='B'){
			  		strcpy(archivo,"VentasAbarrotes.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{	
			  			struct departamentos aba1[c];
		  	  			*aba1=leerArchivo(archivo,c,aba1);
			  			printf("\n\n\tVentas en Abarrotes: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba1[i].producto,aba1[i].cantidad,aba1[i].precio);
			  				t=aba1[i].precio+t;
							}
			  			printf("\n\nTotal de ventas: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
			  	if(arch=='c' || arch=='C'){
			  		strcpy(archivo,"comprasFerreteria.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{	
			  			struct departamentos aba2[c];
		  	  			*aba2=leerArchivo(archivo,c,aba2);
			  			printf("\n\n\tCompras en Ferreteria: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba2[i].producto,aba2[i].cantidad,aba2[i].precio);
			  				t=aba2[i].precio+t;
							}
			  			printf("\n\nTotal de Compras: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='d' || arch=='D'){
			  		strcpy(archivo,"VentasFerreteria.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{	
			  			struct departamentos aba4[c];
		  	  			*aba4=leerArchivo(archivo,c,aba4);
			  			printf("\n\n\tVentas en Ferreteria: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba4[i].producto,aba4[i].cantidad,aba4[i].precio);
			  				t=aba4[i].precio+t;
							}
			  			printf("\n\nTotal de Ventas: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='e' || arch=='E'){
			  		strcpy(archivo,"comprasElectronica.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{	
			  			struct departamentos aba5[c];
		  	  			*aba5=leerArchivo(archivo,c,aba5);
			  			printf("\n\n\tCompras en Electronica: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba5[i].producto,aba5[i].cantidad,aba5[i].precio);
			  				t=aba5[i].precio+t;
							}
			  			printf("\n\nTotal de compras: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='f' || arch=='F'){
			  		strcpy(archivo,"VentasElectronica.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba6[c];
		  	  			*aba6=leerArchivo(archivo,c,aba6);
			  			printf("\n\n\tVentas en Electronica: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba6[i].producto,aba6[i].cantidad,aba6[i].precio);
			  				t=aba6[i].precio+t;
							}
			  			printf("\n\nTotal de Ventas: $%d",t);
			  			printf("\n");	
						}
					}
	 		 	if(arch=='g' || arch=='G'){
			  		strcpy(archivo,"comprasRopa.txt");
			  		c=leerElementos(archivo);
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{	
			  			struct departamentos aba7[c];
		  	  			*aba7=leerArchivo(archivo,c,aba7);
			  			printf("\n\n\tCompras en Ropa: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba7[i].producto,aba7[i].cantidad,aba7[i].precio);
			  				t=aba7[i].precio+t;
							}
			  			printf("\n\nTotal de compras: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='h' || arch=='H'){
			  		strcpy(archivo,"VentasRopa.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
						c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba8[c];
		  	  			*aba8=leerArchivo(archivo,c,aba8);
			  			printf("\n\n\tVentas en Ropa: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba8[i].producto,aba8[i].cantidad,aba8[i].precio);
			  				t=aba8[i].precio+t;
						}
			  			printf("\n\nTotal de ventas: $%d",t);
			  			printf("\n");	
						}
					}
	 		 	if(arch=='i' || arch=='I'){
			  		strcpy(archivo,"comprasHigiene.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba9[c];
		  	  			*aba9=leerArchivo(archivo,c,aba9);
			  			printf("\n\n\tCompras en Higiene: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba9[i].producto,aba9[i].cantidad,aba9[i].precio);
			  				t=aba9[i].precio+t;
							}
			  			printf("\n\nTotal de compras: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='j' || arch=='J'){
			  		strcpy(archivo,"VentasHigiene.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba10[c];
		  	  			*aba10=leerArchivo(archivo,c,aba10);
			  			printf("\n\n\tVentas en Higiene: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba10[i].producto,aba10[i].cantidad,aba10[i].precio);
			  				t=aba10[i].precio+t;
							}
			  			printf("\n\nTotal de ventas: $%d",t);
			  			printf("\n");	
						}
					}
	 		 	if(arch=='k' || arch=='K'){
			  		strcpy(archivo,"compras totales.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba11[c];
		  	  			*aba11=leerArchivo(archivo,c,aba11);
			  			printf("\n\n\tCompras totales: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba11[i].producto,aba11[i].cantidad,aba11[i].precio);
			  				t=aba11[i].precio+t;
							}
			  			printf("\n\nTotal de compras: $%d",t);
			  			printf("\n");	
						}
					}//fin else if
				if(arch=='l' || arch=='L'){
			  		strcpy(archivo,"ventas totales.txt");
			  		c=leerElementos(archivo);	
			  		if(c==0){//si no hay productos
					  	c=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba12[c];
		  	  			*aba12=leerArchivo(archivo,c,aba12);
			  			printf("\n\n\tventas totales: %d",c);
			  			printf("\n\nProducto Cantidad Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.- %s   %d   $%d",i+1,aba12[i].producto,aba12[i].cantidad,aba12[i].precio);
			  				t=aba12[i].precio+t;
							}
			  			printf("\n\nTotal de ventas: $%d",t);
			  			printf("\n");	
		          		}
					}
				if(arch=='m' || arch=='M'){
			  		strcpy(archivo,"ventas totales.txt");	
 			  		strcpy(archivo2,"compras totales.txt");	
			  		c=leerElementos(archivo);
			  		t=leerElementos(archivo2);	
			  		if(c==0 || t==0){//si no hay productos
					  	c=1;
						t=1;
						printf("\n********************\n***No hay productos***\n*************************\n\n");
						}
			  		else{
			  			struct departamentos aba12[c];
			  			struct departamentos aba13[t];
		  	  			*aba12=leerArchivo(archivo,c,aba12);
			  			*aba13=leerArchivo(archivo2,t,aba13);
			  			printf("\n\n\tGanancia/perdida: %d",c);
			  			printf("\n\nProducto  Cantidad  Precio");	
 			  			for( i=0;i<c;i++){
			  				printf("\n%d.-%s     \t%d\t$%d",i+1,aba12[i].producto,aba12[i].cantidad,aba12[i].precio);
			  				s=aba12[i].precio+s;
							}
			  			for( i=0;i<t;i++){
			  				printf("\n%d.-%s     \t%d\t-$%d",i+1,aba13[i].producto,aba13[i].cantidad,aba13[i].precio);
			  				s2=-1*(aba13[i].precio-s2);
							}
			  			printf("\n\nCompras: $%d",s2);
			  			printf("\n\nVentas: $%d",s);
			  			printf("\n\nTotal: $%d",s+s2);
			  			printf("\n");	
						}
					}
			fflush(stdin);
			getchar();	
			break;//fin de opcion compras/ventas

			case 'q': case 'Q'://opcion salir
				printf("\n\n\t\t\t*************ADIOS************");
			 	fflush(stdin);
			  	getchar();
		        break;// fin de opcion salir
		        
		        
			default://para cualquier otra opcion
				printf("\n\n\t Opcion no valida.");
				break;

			}//fin switch, fin de menu
		}
	while(opcion!='q');
	printf("\n\n");
	return 0;
}//fin main




/*Funcion para leer el contenido del archivo*/
int leerElementos(char *a){  
    FILE *fp;
    char c;
    int n=0;	
    fp=fopen(a,"r+");
    if(fp==NULL){//se crea el archivo en caso de que no exista
		fp=fopen(a,"w+");
		printf("Se creo el archivo de %s",a);
		n=0;
		fclose(fp);
		return n;
     	}//fin if
    while((c=getc(fp))!=EOF){
    	if(c=='\n'){
        	n++;	
        	}//fin if
    	}//fin while
    fclose(fp);	
    return n;	
 }//fin de funcion para leer el contenido del archivo




/*Funcion para leer articulos desde un archivo y asignarlos a la estructura*/
struct departamentos leerArchivo(char *a,int n,struct departamentos depa[n]){
	 FILE *fp;
	 fp=fopen(a,"r+");
	 int i;
	 while(feof(fp)==0){
	 	for( i=0;i<n;i++){//se asignan los datos a la estructura de datos
	  		fscanf(fp,"%s %i %i",depa[i].producto,&depa[i].cantidad,&depa[i].precio);
        	}
    	}
	fclose(fp);
    return *depa;
}//fin de funcion para leer articulos desde un archivo y asignarlos a la estructura




/*Funcion para elegir el departamento*/
char elegirDepa(){  
	char op;
	printf("\nEn cual departamento desea hacer la operacion");
	printf("\n\na) Abarrotes\nb)Ferreteria\nc)Electronica\nd)Ropa\ne)Higiene\n\n"); 
	fflush(stdin);
	scanf("%s",&op);
  	return op; //regresa un valor tipo char para leerlo en el menu de la funcion main
}//fin funcion para elegir el departamento




/*Funcion para elegir compra o ventas por departamento o totales*/
char elegirRegistro(){
	char op;
	printf("\nCual registro deseas consultar");
	printf("\n\na)comprasAbarrotes\nb)ventasAbarrotes\n\nc)comprasFerreteria\nd)ventasFerreteria");
	printf("\n\ne)comprasElectronica\nf)ventasElectronica\n\ng)comprasRopa\nh)ventasRopa");
	printf("\n\ni)comprasHigiene\nj)ventasHigiene\n\nk)comprasTotales\n\nl)ventasTotales");  
	printf("\n\nm)Ganancia/perdida");
	printf("\n\n");
	fflush(stdin);
	scanf("%s",&op);
  	return op;

}//fin funcion para elegir compra o ventas por departamento o totales




/*Funcion para agregar producto*/
void agregarProducto(char *a, int n,struct departamentos dept[n]){ 
	FILE *fp;
	char nombre[30];
	int  cant,pr=0,m,cont=0,j,i;//cantidad, precio
	printf("\n\nIngrese el nombre del producto a agregar:\n");
	fflush(stdin);
	scanf("%s",nombre);
    for( i=0; i<n; i++){
    	if(strcmp(dept[i].producto,nombre)==0){	
			cont++;
			j=i;
			}//fin if
    	}//fin for
	if(cont>0){//se valida si ya existe un articulo que se quiere ingresar
		fp=fopen(a,"w+");
  		printf("\n\n***Este producto ya existe, ingrese los nuevos valores***");
		printf("\n\nValores actuales:\npoducto: %s cantidad: %d precio $%d",dept[j].producto,dept[j].cantidad,dept[j].precio);
		printf("\n\ningrese la cantidad a agregar del producto, o ponga el numero negativo si desea quitar\n");
		fflush(stdin);
		scanf("%d",&cant);
		dept[j].cantidad=dept[j].cantidad+cant;
		printf("\ningrese el precio del producto\n");
		fflush(stdin);
		scanf("%d",&pr);	
		dept[j].precio=pr;
		if(dept[j].cantidad<=0){
			for( i=j;i<n;i++){
				strcpy(dept[i].producto,dept[i+1].producto);
				dept[i].precio=dept[i+1].precio;
				dept[i].cantidad=dept[i+1].cantidad;
				}
			n--;
			}
		for( i=0; i<n;i++)
			fprintf(fp,"%s %i %i\n",dept[i].producto,dept[i].cantidad,dept[i].precio);
		fclose(fp);
		}//fin if
	
        else if(cont==0){
			 	fp=fopen(a,"a+");
            	strcpy(dept[0].producto,nombre);
				printf("\nIngrese la cantidad del producto agregado\n");
				fflush(stdin);
				scanf("%d",&dept[0].cantidad);
        		printf("\nIngrese el precio del producto:\n");
				fflush(stdin);
				scanf("%d",&dept[0].precio);
				fprintf(fp,"%s %i %i\n",dept[0].producto,dept[0].cantidad,dept[0].precio);
   				fclose(fp);
        	}//fin else
		printf("\n\t****Operacion exitosa*****\n\n");
		return;
}//fin funcion agregar producto



	
/*Funcion para comprar producto*/
void comprarProducto(char *b,char *a, int n,struct departamentos dept[n+1]){ 
	FILE *fp,*fp2,*fp3;
	char nombre[30];
	int  cant,pr=0,m,cont=0,j,i;//cantidad,precio
	printf("\nIngrese el nombre del producto a comprar\n");
	fflush(stdin);
	scanf("%s",nombre);
    for( i=0; i<n; i++){
	    if(strcmp(dept[i].producto,nombre)==0){	
			cont++;
			j=i;
			}//fin if	
        }//fin for
	if(cont>0){
		fp=fopen(a,"w+");
		fp2=fopen("compras totales.txt","a+");
		fp3=fopen(b,"a+");
       	printf("\n\n***Este producto ya existe, ingrese la cantidad que comprara***");
		printf("\n\nValores actuales:\n\npoducto: %s cantidad: %d precio $%d",dept[j].producto,dept[j].cantidad,dept[j].precio);
		printf("\n\ningrese la cantidad a comprar\n");
		fflush(stdin);
		scanf("%d",&cant);
		dept[j].cantidad=dept[j].cantidad+cant;
		printf("\ningrese el precio del producto\n");
		fflush(stdin);
		scanf("%d",&pr);
		pr=cant*dept[j].precio;
	    printf("\nTotal: %d \n",pr);	
		fprintf(fp2,"%s %i %i\n",dept[j].producto,cant,dept[j].precio);
		fprintf(fp3,"%s %i %i\n",dept[j].producto,cant,dept[j].precio);
		for( i=0; i<n;i++)
			fprintf(fp,"%s %i %i\n",dept[i].producto,dept[i].cantidad,dept[i].precio);
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		}//fin if
	
    else if(cont==0){
			fp=fopen(a,"a+");
			fp2=fopen("compras totales.txt","a+");
			fp3=fopen(b,"a+");
        	strcpy(dept[0].producto,nombre);
			printf("\ningrese la cantidad que comprara\n");
			fflush(stdin);
			scanf("%d",&dept[0].cantidad);
        	printf("\ningrese el precio del producto:\n");
			fflush(stdin);
			scanf("%d",&dept[0].precio);
			pr=dept[0].cantidad*dept[0].precio;
			printf("\nTotal: $%d \n",pr);
			fprintf(fp,"%s %i %i\n",dept[0].producto,dept[0].cantidad,dept[0].precio);
			fprintf(fp2,"%s %i %i\n",dept[0].producto,dept[0].cantidad,dept[0].precio);
			fprintf(fp3,"%s %i %i\n",dept[0].producto,dept[0].cantidad,dept[0].precio);
   			fclose(fp);
			fclose(fp2);
			fclose(fp3);
 			}//fin else
	printf("\n\t****Operacion exitosa*****\n\n");
	return;
}//fin funcion para comprar producto




/*Funcion para vender producto*/
void venderProducto(char *b,char *a, int n,struct departamentos dept[n]){ 
	FILE *fp,*fp2,*fp3;
	char nombre[30];
	int  cant,pr=0,m,cont=0,j,aux,aux2,i;//cantidad,precio
	printf("\n\nIngrese el nombre del producto a vender\n");
	fflush(stdin);
	scanf("%s",nombre);
    for( i=0; i<n; i++){
       	if(strcmp(dept[i].producto,nombre)==0){	
			cont++	;
			j=i;
			}//fin if
       	}//fin for
	if(cont>0){
		fp=fopen(a,"w+");
		fp2=fopen("ventas totales.txt","a+");
		fp3=fopen(b,"a+");
		printf("\n\nValores actuales:\n\npoducto: %s cantidad: %d precio %d",dept[j].producto,dept[j].cantidad,dept[j].precio);
		printf("\n\ningrese la cantidad a vender\n");
		fflush(stdin);
		scanf("%d",&cant);
		aux=dept[j].cantidad;
		aux2=dept[j].precio;
		dept[j].cantidad=dept[j].cantidad-cant;
		if(dept[j].cantidad==0){
			for( i=j;i<n;i++){
				strcpy(dept[i].producto,dept[i+1].producto);
				dept[i].precio=dept[i+1].precio;
				dept[i].cantidad=dept[i+1].cantidad;
				}//fin for
			n--;
			}//fin if
		else if(dept[j].cantidad<0){
			printf("\n*******No tienes suficientes productos****\n");
			dept[j].cantidad=aux;
			for( i=0; i<n;i++){
				fprintf(fp,"%s %i %i\n",dept[i].producto,dept[i].cantidad,dept[i].precio);
				}//fin for
			fclose(fp);
			fclose(fp2);
			fclose(fp3);
			return ;
			}
		pr=cant*aux2;
		printf("\nTotal: $%d \n",pr);
		printf("\n\n***Operacion exitosa***\n");
		fprintf(fp2,"%s %i %i\n",dept[j].producto,cant,dept[j].precio);
		fprintf(fp3,"%s %i %i\n",dept[j].producto,cant,dept[j].precio);
		for( i=0; i<n;i++){
			fprintf(fp,"%s %i %i\n",dept[i].producto,dept[i].cantidad,dept[i].precio);
			}//fin for
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		}//fin if
        else if(cont==0){
				fp=fopen(a,"w+");
				fp2=fopen("compras totales.txt","a+");
				fp3=fopen(b,"a+");
				printf("\n****No cuentas con este producto****\n");
				for( i=0; i<n;i++){
					fprintf(fp,"%s %i %i\n",dept[i].producto,dept[i].cantidad,dept[i].precio);
					}//fin for
				fclose(fp);
				fclose(fp2);
				fclose(fp3);
				}//fin else if
	return;
}//fin de funcion para vender producto







