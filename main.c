#include<conio.h>
#include<stdio.h>
#include<math.h>

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
    SignUpFunction();
  } else if(option == 2){
    LoggingMenu();
  } else {
    printf("Por favor ingrese una opcion valida");
  }
}

// Menú para cuando inicia sesión
int LoggingMenu(){
  
}

// Funcion para crear cuentas
int SignUpFunction(){
  
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
