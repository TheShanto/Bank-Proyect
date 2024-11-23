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
        printf("Depósito exitoso. Nuevo saldo: $%.2f\n", client->balance);
    } else {
        printf("Cantidad no válida para depósito.\n");
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
            printf("Número de teléfono del destinatario no encontrado.\n");
        }
    } else {
        printf("Cantidad no válida o saldo insuficiente para la transferencia.\n");
    }
}

// Menú de Registro (Completo)
void Register(Client client[], int *totalClients) {
    int isValidPin = 0;
    char nip[5];

    if (*totalClients >= MAX_CLIENTS) {
        printf("No se pueden registrar más clientes\n");
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
    system("color e0");
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
            int opcion;
            system("color b0"); // cambiar el color de pantalla
            printf("\t\t\t\t******Bienvenido %s %s\n******", client[i].name, client[i].lastName);
            printf("\t\t\t\t1. Depositar Dinero\n");
            printf("\t\t\t\t2. Verificar Saldo Actual\n");
            printf("\t\t\t\t3. Transferir Dinero\n");
            printf("\t\t\t\t4. Recargar Tiempo Aire\n");
            printf("\t\t\t\t5. Cambiar NIP\n");
            printf("\t\t\t\t6. Salir\n");

            // Seleccionar una opción
            scanf("%d", &opcion);
            switch (opcion) {
                case 1:
                    system("cls");
                    system("color 20");
                    float cantidad;
                    printf("Introduce la cantidad a depositar: ");
                    scanf("%f", &cantidad);
                    depositar(&client[i], cantidad);
                    break;

                case 2:
                    system("cls");
                    system("color 67");
                    printf("Su saldo actual es: $%.2f\n", client[i].balance);
                    break;

                case 3:
                    system("cls");
                    system("color 01");
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
                    system("color 10");
                    // Recargar tiempo aire
                    break;

                case 5:
                    system("cls");
                    system("color 01");
                    // Cambiar NIP
                    break;

                case 6:
                    system("cls");
                    system("color 10");
                    // Salir
                    break;

                default:
                    printf("Opción no valida\n");
            }
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
        printf("\t\t\t\tBienvenido,Que desea hacer?\n");
        printf("1. Registrar\n");
        printf("2. Iniciar Sesion\n");
        printf("3. Salir\n");
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
