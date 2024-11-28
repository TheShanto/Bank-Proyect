#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

// Funciones extra
void clearBuffer() {
    while (getchar() != '\n');
}

// Funcion para depositar dinero
void depositar(Client *client) {
    float cantidad;
    char confirmacion;

    do{
        printf("Su nombre es: %s %s\n", client->name, client->lastName);
        printf("Introduzca el monto a depositar: ");
        scanf("%f", &cantidad);

        if (cantidad > 0) {
            printf("Esta seguro que desea depositar $%.2f? (s/n): ", cantidad);
            scanf(" %c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if (confirmacion == 's') {
                client->balance += cantidad;
                printf("Deposito exitoso. Nuevo saldo: $%.2f\n\n", client->balance);
                break;
            } else {
                printf("Monto rechazado. Intente nuevamente.\n\n");
            }
        } else {
            printf("La cantidad debe ser positiva. Intente nuevamente.\n\n");
        }
    } while (1);
}

// Funcion para transferir dinero
void transferir(Client client[], int totalClients, Client *remitente) {
    float cantidad;
    char confirmacion;
    char telefonoDestinatario[15];
    char nombreDestinatario[50];
    char tarjetaDestinatario[17];

    do {
        printf("Su nombre es: %s %s\n", remitente->name, remitente->lastName);
        printf("Su saldo actual es: $%.2f\n\n", remitente->balance);

        printf("Ingrese el nombre del destinatario: ");
        getchar(); // Limpiar buffer
        fgets(nombreDestinatario, sizeof(nombreDestinatario), stdin);
        nombreDestinatario[strcspn(nombreDestinatario, "\n")] = 0;

        printf("Ingrese el numero de tarjeta del destinatario: ");
        scanf("%16s", tarjetaDestinatario);

        printf("Ingrese el numero de telefono del destinatario: ");
        scanf("%14s", telefonoDestinatario);

        printf("Ingrese la cantidad a transferir: ");
        scanf("%f", &cantidad);

        if (cantidad > 0 && remitente->balance >= cantidad) {
            printf("¿Esta seguro de transferir $%.2f a %s con tarjeta %s? (s/n): ", cantidad, nombreDestinatario, tarjetaDestinatario);
            scanf(" %c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if (confirmacion == 's') {
                // Buscar al destinatario por su telefono
                int i;
                int found = 0;
                for (i = 0; i < totalClients; i++) {
                    if (strcmp(client[i].phone, telefonoDestinatario) == 0) {
                        client[i].balance += cantidad;
                        remitente->balance -= cantidad;
                        printf("Transferencia exitosa. Nuevo saldo del remitente: $%.2f\n", remitente->balance);
                        printf("Nuevo saldo del destinatario: $%.2f\n\n", client[i].balance);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("El destinatario no fue encontrado. Operacion cancelada.\n\n");
                }
                break;
            } else {
                printf("Operacion cancelada. Intente nuevamente.\n\n");
            }
        } else {
            printf("Saldo insuficiente o monto invalido. Intente nuevamente.\n\n");
        }
    } while (1);
}

// Funcion para recargar tiempo aire
 void recargarTiempoAire(Client *client){
     float cantidad;
     char confirmacion;
     int opcionCompania;
     int opcionRecarga;
     char numeroRecarga[15];

     do{
         printf("Su nombre es: %s %s\n", client->name, client->lastName);
        printf("Seleccione la compania telefonica:\n1. AT&T\n2. Telcel\n3. Movistar\n");
        scanf("%d", &opcionCompania);

        if (opcionCompania < 1 || opcionCompania > 3) {
            printf("Opcion invalida. Intente nuevamente.\n\n");
            continue; 
        }

        printf("Ingrese el numero al que desea recargar: ");
        scanf("%14s", numeroRecarga);



        printf("Introduzca el monto a recargar: ");
        scanf("%f", &cantidad);

        if (cantidad > 0 && client->balance >= cantidad) {
            printf("�Esta seguro que desea recargar $%.2f al numero %s? (s/n): ", cantidad, numeroRecarga);
            scanf(" %c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if (confirmacion == 's') {
                client->balance -= cantidad;
                printf("Recarga exitosa. Nuevo saldo: $%.2f\n\n", client->balance);
                break;
            } else {
                printf("Operacion cancelada. Intente nuevamente.\n\n");
            }
        } else {
            printf("Saldo insuficiente o monto invalido. Intente nuevamente.\n\n");
        }
     } while (1);
 }

//cambiar nip
void cambiarNIP(Client *client) {
    char nuevoNIP[5];
    char confirmarNIP[5];
    char confirmacion;

    do{
        printf("Su NIP actual es: %s\n", client->nip);
        printf("Ingrese su nuevo NIP: ");
        scanf("%4s", nuevoNIP);

        printf("Confirme su nuevo NIP: ");
        scanf("%4s", confirmarNIP);

        if (strcmp(nuevoNIP, confirmarNIP) == 0 && strlen(nuevoNIP) == 4) {
            printf("¿Esta seguro de cambiar su NIP a %s? (s/n): ", nuevoNIP);
            scanf(" %c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if (confirmacion == 's') {
                strcpy(client->nip, nuevoNIP);
                printf("NIP cambiado exitosamente.\n\n");
                break;
            } else {
                printf("Cambio cancelado. Intente nuevamente.\n\n");
            }
        } else {
            printf("Los NIPs no coinciden o no tienen 4 digitos. Intente nuevamente.\n\n");
        }
    } while (1);
}


// Menu de Registro (Completo)
void Register(Client client[], int *totalClients) {
    int isValidPin = 0;
    int isValidCard = 0;
    int isValidPhone = 0;
    char nip[5], cardNumber[17], phone[11];

    if (*totalClients >= MAX_CLIENTS) {
        printf("No se pueden registrar mas clientes\n");
        return;
    }

    // Invocar al cliente
	Client newClient;
	clearBuffer(); // Elimina el buffer residual para evitar duplicados a usar fgets

    // Solicitar datos del cliente
    printf("Nombre(s): ");
    fgets(newClient.name, sizeof(newClient.name), stdin);
	newClient.name[strcspn(newClient.name, "\n")] = 0; // Elimina el buffer
    printf("Apellido(s): ");
    fgets(newClient.lastName, sizeof(newClient.lastName), stdin);
	newClient.lastName[strcspn(newClient.lastName, "\n")] = 0; // Eliminar el buffer

    // Validar Numero de Telefono
    while(!isValidPhone){
        printf("Telefono: ");
        scanf("%s", phone);

        if(strlen(phone) == 10){
            isValidPhone = 1;
        } else {
            printf("Numero de telefono incorrecto, Debe tener 10 digitos\n");
        }
    }

    // Guardar el telefono en el struct
    strcpy(newClient.phone, phone);

    // Validar Tarjeta
    while(!isValidCard) {
        printf("Numero de Tarjeta:");
        scanf("%s", cardNumber);

        if(strlen(cardNumber) == 16) {
            isValidCard = 1;
        } else {
            printf("EL numero de tarjeta es invalido, debe tener 16 digitos\n");
        }
    }

    // Copiar la tarjeta una vez se comprueba
    strcpy(newClient.cardNumber, cardNumber);

    // Validar NIP
    while (!isValidPin) {
        printf("Ingrese su NIP: ");
        scanf("%s", nip);

        if (strlen(nip) == 4) {
            isValidPin = 1;
        } else {
            printf("El NIP debe tener 4 digitos\n");
        }
    }

    // Copiar el NIP al cliente
    strcpy(newClient.nip, nip);

    // Establecer el balance inicial en cero
    newClient.balance = 0.0;

    // Agregar el cliente al arreglo
    client[*totalClients] = newClient;
    (*totalClients)++;

    // Comprobacion de datos
    system("cls");
    system("color f3");
    printf("\t\t\t Cliente registrado con exito con los siguientes datos\n");
    printf("\t\t\t =====================================================\n");
    printf("Nombre: %s\n", newClient.name);
    printf("Apellido: %s\n", newClient.lastName);
    printf("Telefono: %s\n", newClient.phone);
    printf("Numero de Tarjeta: %s\n", newClient.cardNumber);
    printf("NIP: %s\n", newClient.nip);
    printf("Balance: %.2f\n\n\n\n", newClient.balance);
}

// Menu de Inicio de Sesion (Completo)
void Login(Client client[], int totalClients) {
    // Variables para el inicio de sesion
    char phone[15];
    char nip[5];
    int i, found = 0;

    system("cls");
    system("color 70");
    printf("\t\t\t\t               Iniciar Sesion\n");
    printf("\t\t\t\t         =========================\n");
    // Solicitar Numero de Telefono y NIP
    printf("Numero de Telefono: ");
    scanf("%14s", phone);
    printf("NIP: ");
    scanf("%4s", nip);

    // Buscar el cliente
    for (i = 0; i < totalClients; i++) {
        if (strcmp(client[i].phone, phone) == 0 && strcmp(client[i].nip, nip) == 0) {
            // Valor para indicar que el cliente fue encontrado
            found = 1;

            // Mostrar el menu de opciones
            int opcion;   do {
            system("color e0"); // cambiar el color de pantalla
            printf("\t\t\t\t     ******Bienvenido %s %s******\n\n", client[i].name, client[i].lastName);
            printf("\t\t\t\t         1. Depositar Dinero\n\n");
            printf("\t\t\t\t         2. Verificar Saldo Actual\n\n");
            printf("\t\t\t\t         3. Transferir Dinero\n\n");
            printf("\t\t\t\t         4. Recargar Tiempo Aire\n\n");
            printf("\t\t\t\t         5. Cambiar NIP\n\n");
            printf("\t\t\t\t         6. Salir\n");
            //funciones completas
            // Menu de opciones
             scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                        system("cls");
                        system("color 71");
                        depositar(&client[i]);
                        break;

                    case 2:
                        system("cls");
                        system("color 67");
                        printf("Su saldo actual es: $%.2f\n\n", client[i].balance);
                        break;

                    case 3:
                        system("cls");
                        system("color f1");
                        transferir(client, totalClients, &client[i]);
                        break;

                    case 4:
                        system("cls");
                        system("color b0");
                        recargarTiempoAire(&client[i]);
                        break;

                    case 5:
                        system("cls");
                        system("color a1");
                        cambiarNIP(&client[i]);
                        break;

                    case 6:
                        system("cls");
                        system("color 90");
                         printf("Gracias por usar nuestro servicio.Hasta luego!\n\n");
                        break;

                    default:
                        printf("Opcion no valida\n");
                }
            } while (opcion != 6);
            break;
        }
    }
    if (!found) {
        printf("No se encontro el cliente\n");
    }
}

// Arranque del programa
main() {
    Client clients[MAX_CLIENTS];

    int totalClients = 0;
    int option;

    do {
        // Menu principal  
		system("color f3");
        printf("\t\t\t\t       Bienvenido, Por favor elija una opcion.\n\n");
        printf("                                               1. Registrar\n\n" );
        printf("                                               2. Iniciar Sesion\n\n");
        printf("                                               3. Salir\n");
        scanf("%d", &option);

        switch (option) {
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
    } while (option != 3);

    return 0;
}
