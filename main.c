#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Estrcutura con los valores del cliente
struct Client{
    char name[25];
    char last_name[50];
    int phone_number;
    int card;
    int pin;
};

// Funcion del tipo estructura para crear cuentas
struct Client SignUpFunction(){

    // Invocar al objeto Client
    struct Client client;

    // Pedir la informacion del cliente
    printf("Bienvenido a la creacion de cuentas del banco, se le iran solicitando datos para la creacion de la cuenta\n");
    printf("Por favor ingrese su Nombre:\n");
    scanf("%s", &client.name);
    system("cls");
    printf("Ingrese sus apellidos:\n");
    scanf("%s", &client.last_name);
    system("cls");
    printf("Ingrese su numero de telefono:\n");
    scanf("%d", &client.phone_number);
    system("cls");
    printf("Ingrese 16 numeros para generar la tarjeta\n");
    scanf("%d", &client.card);
    system("cls");
    printf("Por ultimo ingrese un NIP de 4 digitos:\n");
    scanf("%d", &client.pin);

    return client;
}

// Menú principal 
void StartMenu(){

    // Variables del menu
    int option = 0;

    // Elementos del menu
    printf("Bienvenido al banco Ronpope\n");
    printf("Que desea hacer?\n");
    printf("1): Crear una cuenta\n");
    printf("2): Iniciar sesion\n");
    scanf("%d", &option);

    if(option == 1){
        // Invocar a la clase cliente
        struct Client client = SignUpFunction();

        // Mostrar los datos del cliente para verificar
        printf("\nRegistro completado!\n");
        printf("Nombre: %s %s\n", client.name, client.last_name);
        printf("Telefono: %d\n", client.phone_number);
        printf("Tarjeta: %d\n", client.card);
        printf("PIN: %d\n", client.pin);
    } else if(option == 2){
        LoggingMenu();
    } else {
        printf("Por favor ingrese una opcion valida");
    }
}

// Menú para cuando inicia sesión
int LoggingMenu(){

  
}



// Funcion para agregar dinero a la cuenta
int AddMoneyFunction(){
  
}

// Funcion para ver el dinero de la cuenta
int ViewMoneyFunction(){
  
}

// Funcion para transferir dinero
int TransferMoney(){
  
}

// Funcion para agregar saldo a un número de telefono
int AirTimeRecharge(){
  
}

// Funcion para cambiar el NIP
int NipChange(){
  
}

// Funcion para salir de la cuenta del usuario
int LogOutFunction(){
  
}

// Arranque del programa
main(){
  
    // Inicia el menu
    StartMenu();

      // Funciones por defecto
    getch();
    return 0;
}
