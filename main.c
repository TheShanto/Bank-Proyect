#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

// Función para depositar dinero
void depositar(Client *client, float cantidad) {
    if (cantidad > 0) {
        client->balance += cantidad;
        printf("Deposito exitoso. Nuevo saldo: $%.2f\n\n", client->balance);
    } else {
        printf("Cantidad no valida para deposito.\n\n");
    }
}

// Función para transferir dinero
void transferir(Client client[], int totalClients, Client *remitente, float cantidad, const char *telefonoDestinatario) {
    if (cantidad > 0 && remitente->balance >= cantidad) {
        // Buscar destinatario
        int found = 0;
        for (int i = 0; i < totalClients; i++) {
            if (strcmp(client[i].phone, telefonoDestinatario) == 0) {
                client[i].balance += cantidad;
                remitente->balance -= cantidad;
                printf("Transferencia exitosa. Nuevo saldo del remitente: $%.2f\n", remitente->balance);
                printf("Nuevo saldo del destinatario: $%.2f\n", client[i].balance);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Numero de telefono del destinatario no encontrado.\n\n");
        }
    } else {
        printf("Cantidad no valida o saldo insuficiente para la transferencia.\n\n");
    }
}

// Función para recargar tiempo aire
 void recargarTiempoAire(Client *client, float cantidad)
  { if (cantidad > 0 && client->balance >= cantidad) {
   client->balance -= cantidad; printf("Recarga exitosa. Nuevo saldo: $%.2f\n\n", client->balance); 
   } else { printf("Cantidad no valida o saldo insuficiente para la recarga.\n\n"); } }

//cambiar nip
void cambiarNIP(Client *client) { char nuevoNIP[5];
 char confirmarNIP[5]; printf("Ingrese su nuevo NIP: "); 
 scanf("%4s", nuevoNIP); printf("Confirme su nuevo NIP: ");
  scanf("%4s", confirmarNIP);
   if (strcmp(nuevoNIP, confirmarNIP) == 0 && strlen(nuevoNIP) == 4) { 
   strcpy(client->nip, nuevoNIP); printf("NIP cambiado exitosamente.\n\n"); } 
   else { printf("Error: los NIPs no coinciden o no tienen 4 digitos.\n\n"); } }


// Menú de Registro (Completo)
void Register(Client client[], int *totalClients) {
    int isValidPin = 0;
    char nip[5];

    if (*totalClients >= MAX_CLIENTS) {
        printf("No se pueden registrar mas clientes\n");
        return;
    }

    Client newClient;
    // Solicitar datos del cliente
    printf("Nombre: ");
    scanf("%49s", newClient.name);
    printf("Apellido: ");
    scanf("%49s", newClient.lastName);
    printf("Telefono: ");
    scanf("%14s", newClient.phone);
    printf("Numero de Tarjeta: ");
    scanf("%16s", newClient.cardNumber);

    // Validar NIP
    while (!isValidPin) {
        printf("Ingrese su NIP: ");
        scanf("%4s", nip);

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

    // Comprobación de datos
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

// Menú de Inicio de Sesión (Completo)
void Login(Client client[], int totalClients) {
    // Variables para el inicio de sesión
    char phone[15];
    char nip[5];
    int i, found = 0;

    system("cls");
    system("color 70");
    printf("\t\t\t\t               Iniciar Sesion\n");
    printf("\t\t\t\t\         =========================\n");
    // Solicitar Número de Teléfono y NIP
    printf("Numero de Telefono: ");
    scanf("%14s", phone);
    printf("NIP: ");
    scanf("%4s", nip);

    // Buscar el cliente
    for (i = 0; i < totalClients; i++) {
        if (strcmp(client[i].phone, phone) == 0 && strcmp(client[i].nip, nip) == 0) {
            // Valor para indicar que el cliente fue encontrado
            found = 1;

            // Mostrar el menú de opciones
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
             scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                        system("cls");
                        system("color 71");
                        float cantidad;
                        printf("Introduce la cantidad a depositar: ");
                        scanf("%f", &cantidad);
                        depositar(&client[i], cantidad);
                        break;

                    case 2:
                        system("cls");
                        system("color 67");
                        printf("Su saldo actual es: $%.2f\n\n", client[i].balance);
                        break;

                    case 3:
                        system("cls");
                        system("color f1");
                        float cantidadTransferir;
                        char telefonoDestinatario[15];
                        printf("Introduce la cantidad a transferir: ");
                        scanf("%f", &cantidadTransferir);
                        printf("Introduce el numero de telefono del destinatario: ");
                        scanf("%14s", telefonoDestinatario);
                        transferir(client, totalClients, &client[i], cantidadTransferir, telefonoDestinatario);
                        break;

                    case 4:
                        system("cls");
                        system("color b0");
                        float cantidadRecarga;
                        printf("Introduce la cantidad a recargar: ");
                        scanf("%f", &cantidadRecarga);
                        recargarTiempoAire(&client[i], cantidadRecarga);
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
                        printf("Opción no válida\n");
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
int main() {
    Client clients[MAX_CLIENTS];
    int totalClients = 0;

    int option;

    do {
        // Menú principal  
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
