#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CLIENTS 100

// Estructura de Cliente (Completo)
typedef struct {
	char name[50];
	char lastName[50];
	char phone[15];
	char cardNumber[17];
	char nip[5];
	float balance;
} Client;

// Menu de Registro (Completo)
void Register(Client client[], int *totalClients){

	int isValidPin = 0;
	int i;
	char nip[5];

	if(*totalClients >= MAX_CLIENTS){
		printf("No se pueden registrar mas clientes\n");
		return;
	}

	Client newClient;
	// Solicitar datos del cliente
	printf("Nombre:");
	scanf("%49s", newClient.name);
	printf("Apellido: ");
	scanf("%49s", newClient.lastName);
	printf("Telefono: ");
	scanf("%14s", newClient.phone);
	printf("Numero de Tarjeta: ");
	scanf("%16s", newClient.cardNumber);

	// Validar NIP
	while(!isValidPin){
		printf("Ingrese su NIP: ");
		scanf("%s", &nip);

		for(i = 0; i < 1; i++){
			if(strlen(nip) == 4) {
				isValidPin = 1;
				break;
			} else{
				printf("El NIP debe tener 4 digitos\n");
				break;
			}
		}
	}

	// Copiar el NIP al cliente
	strcpy(newClient.nip, nip);

	// Establecer el balance inicial en cero
	newClient.balance = 0.0;

	// Agregar el cliente al arreglo
	client[*totalClients] = newClient;
	*totalClients += 1;

	// Comprobacion de datos
	system("cls"); system ("color D0");
	printf("\t\t\t\Cliente registrado con exito con los siguientes datos\n");
	printf("Nombre: %s\n", newClient.name);
	printf("Apellido: %s\n", newClient.lastName);
	printf("Telefono: %s\n", newClient.phone);
	printf("Numero de Tarjeta: %s\n", newClient.cardNumber);
	printf("NIP: %s\n", newClient.nip);
	printf("Balance: %.2f\n\n\n\n", newClient.balance);
}

// Menu de Inicio de Sesion (Incompleto)
void Login(Client client[], int	totalClients){

	// Variables para el inicio de sesion
	char phone[15];
	char nip[5];
	int i, found;

	system("cls");  system ("color 70");
	printf("Iniciar Sesion\n");
	// Solicitar Numero de Telefono y NIP
	printf("Numero de Telefono: ");
	scanf("%16s", &phone);
	printf("NIP: ");
	scanf("%4s", &nip);

	// Buscar el cliente
	for(i = 0; i < totalClients; i++){
		if(strcmp(client[i].phone, phone) == 0 && strcmp(client[i].nip, nip) == 0){
			// Valor para indicar que el cliente fue encontrado
			found = 1;

			// Mostrar el menu de opciones 
		
			char opcion;
			system("color b0"); //cabiar el color de pantalla
			printf("\t\t\t\t\Bienvenido %s %s\n", client[i].name, client[i].lastName);
			printf("\t\t\t\t\ 1.Depositar Dinero\n");
			printf("\t\t\t\t\ 2.Verificar Saldo Actual\n");
			printf("\t\t\t\t\ 3.Transferir Dinero\n");
			printf("\t\t\t\t\ 4.Recargar Tiempo Aire\n");
			printf("\t\t\t\t\ 5.Cambiar NIP\n");
			printf("\t\t\t\t\ 6.Salir\n");

			// Seleccionar una opcion
	scanf("%d",&opcion);
    switch(opcion)
	 {
	// Falta implementar las opciones
		   case 1: system("cls"); system ("color 20"); 
		void depositar(int* cuenta_saldo, int cantidad) {
         if (cantidad > 0) {
         cuenta_saldo += cantidad;
        printf("Depósito exitoso. Nuevo saldo: $%d\n", *cuenta_saldo);} 
		else {
        printf("Cantidad no válida para depósito.\n");
    }
} 

			break; 
							
	 case 2:  system("cls"); system ("color 67");
	 
	// Verificar saldo
							break;
							
		case 3:  system("cls"); system ("color 01");
		  	
								// Transferir dinero 
						
							break;
		case 4:  case 'd': system("cls"); system ("color 10");
						// Recargar tiempo aire
							break;
		case 5:  system("cls"); system ("color 01");
		  	
							// Cambiar NIP
						
							break;
		case 6: system("cls"); system ("color 10");
						// Salir
							break;				
				default:
				printf("Opcion no valida\n");
			}
			break;
		} 
	}
	printf("No se encontro el cliente\n");
}

// Arranque del programa
main(){
	Client clients[MAX_CLIENTS];
	int totalClients = 0;

	int option;

	do {
		// Menu principal
		printf("1. Registrar\n");
		printf("2. Iniciar Sesion\n");
		printf("3. Salir\n");
		scanf("%d", &option);

		switch(option){
			case 1:
				Register(clients, &totalClients);
				break;
			case 2:
				Login(clients, totalClients);
				break;
			case 3:
				break;
			default:
				printf("Opcion no valida\n");
		}
	} while(option != 3);

	return 0;
}
