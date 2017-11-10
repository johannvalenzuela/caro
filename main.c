#include <stdio.h>
#include <string.h>

#define cant_conciertos 3;

struct ubicacion{
    char nombre[20];
    int cupos;
    float valor;
    int entradas_disponibles;
    float recaudacion;
    char codigo[11];
};

struct concierto{
    char nombre[20];
    char codigo[7];
    int cant_ubicaciones;
    struct ubicacion ubicaciones[3];
};

struct ubicacion *pubicacion;
struct concierto conciertos[4], *pconcierto;

void cargar_conciertos(){
    pconcierto = &conciertos[0];
    // Cargar Retro Concert
    strcpy(pconcierto->codigo,"RC-001");
    strcpy(pconcierto->nombre,"Guns N' Roses");
    pconcierto->cant_ubicaciones = 2;
    // Cargar Retro Concert - Ubicaciones
    pubicacion = &pconcierto->ubicaciones[0];
    strcpy(pubicacion->codigo,"RC-001-001");
    strcpy(pubicacion->nombre,"Cancha");
    pubicacion->valor = 35000.00;
    pubicacion->entradas_disponibles = 1200;
    pubicacion->cupos = 1200;
    pubicacion->recaudacion = 0.00;
    pubicacion++;
    strcpy(pubicacion->codigo,"RC-001-002");
    strcpy(pubicacion->nombre,"Golden VIP");
    pubicacion->valor = 70000.00;
    pubicacion->entradas_disponibles = 120;
    pubicacion->cupos = 120;
    pubicacion->recaudacion = 0.00;

    // Cargar Classic Concert
    pconcierto++;
    strcpy(pconcierto->codigo,"CC-001");
    strcpy(pconcierto->nombre,"Pink Floyd");
    pconcierto->cant_ubicaciones = 3;
    // Cargar Classic Concert - Ubicaciones
    pubicacion = &pconcierto->ubicaciones[0];
    strcpy(pubicacion->codigo,"CC-001-001");
    strcpy(pubicacion->nombre,"Platea");
    pubicacion->valor = 80000.00;
    pubicacion->entradas_disponibles = 1000;
    pubicacion->cupos = 1000;
    pubicacion->recaudacion = 0.00;
    pubicacion++;
    strcpy(pubicacion->codigo,"CC-001-002");
    strcpy(pubicacion->nombre,"Golden VIP");
    pubicacion->valor = 160000.00;
    pubicacion->entradas_disponibles = 100;
    pubicacion->cupos = 100;
    pubicacion->recaudacion = 0.00;
    pubicacion++;
    strcpy(pubicacion->codigo,"CC-001-003");
    strcpy(pubicacion->nombre,"Premium Site");
    pubicacion->valor = 320000.00;
    pubicacion->entradas_disponibles = 3;
    pubicacion->cupos = 3;
    pubicacion->recaudacion = 0.00;

    // Cargar New Concert
    pconcierto++;
    strcpy(pconcierto->codigo,"NC-001");
    strcpy(pconcierto->nombre,"Wisin y Yandel");
    pconcierto->cant_ubicaciones = 2;
    // Cargar New Concert - Ubicaciones
    pubicacion = &pconcierto->ubicaciones[0];
    strcpy(pubicacion->codigo,"NC-001-001");
    strcpy(pubicacion->nombre,"Cancha");
    pubicacion->valor = 15000.00;
    pubicacion->entradas_disponibles = 50000;
    pubicacion->cupos = 50000;
    pubicacion->recaudacion = 0.00;
    pubicacion++;
    strcpy(pubicacion->codigo,"NC-001-002");
    strcpy(pubicacion->nombre,"Cancha más Cerca");
    pubicacion->valor = 20000.00;
    pubicacion->entradas_disponibles = 5000;
    pubicacion->cupos = 5000;
    pubicacion->recaudacion = 0.00;
    mostrar_conciertos_ubicaciones();
}

// Muestra toda la información de los conciertos y todas sus ubicaciones
void mostrar_conciertos_ubicaciones(){
    int i,j;
    pconcierto = &conciertos[0];
    for(i=0; i < 3; i++){
        printf("====================================");
        printf("\nNombre: %s\n",pconcierto->nombre);
        printf("Codigo: %s\n",pconcierto->codigo);
        pubicacion = &pconcierto->ubicaciones[0];
        printf("Ubicaciones:\n");
        for(j=0; j < pconcierto->cant_ubicaciones ;j++){
            printf("\t Nombre: %s\n",pubicacion->nombre);
            printf("\t Código: %s\n",pubicacion->codigo);
            printf("\t Precio: %.2f\n",pubicacion->valor);
            printf("\t Entradas Disponibles: %d\n",pubicacion->entradas_disponibles);
            printf("\t Cupos de ubicación: %d\n",pubicacion->cupos);
            printf("\t Recaudación: %.2f\n\n",pubicacion->recaudacion);
            pubicacion++;
        }
        pconcierto++;
    }
}

// Muestra solamente la información de los conciertos
void mostrar_conciertos(){
    int i,j;
    pconcierto = &conciertos[0];
    for(i=0; i < 3; i++){
        printf("====================================");
        printf("\n%d)Nombre: %s\n",i+1,pconcierto->nombre);
        printf("\tCodigo: %s\n",pconcierto->codigo);
        pconcierto++;
    }
}

// Muestra la información de las ubicaciones de 1 concierto
void seleccionar_ubicacion_agregar_ticket(int posicion){
    int i,j;
    pconcierto = &conciertos[0];
    int opc_ubicacion;
    int cant_tickets;
    for(i=1; i <= 3; i++){
        if(i==posicion){            
            printf("====================================");
            printf("\nNombre: %s\n",pconcierto->nombre);
            printf("Codigo: %s\n",pconcierto->codigo);
            pubicacion = &pconcierto->ubicaciones[0];
            printf("Ubicaciones:\n");
            for(j=0; j < pconcierto->cant_ubicaciones ;j++){
                printf("%d\t Nombre: %s\n",j+1,pubicacion->nombre);
                printf("\t Código: %s\n",pubicacion->codigo);
                printf("\t Precio: %.2f\n",pubicacion->valor);
                printf("\t Entradas Disponibles: %d\n",pubicacion->entradas_disponibles);
                printf("\t Cupos de ubicación: %d\n",pubicacion->cupos);
                printf("\t Recaudación: %.2f\n\n",pubicacion->recaudacion);
                pubicacion++;
            }
            printf("%d) Volver.\n",pconcierto->cant_ubicaciones+1);
            printf("\n Ingrese el numero del ubicación que desea vender tickets, ó %d para salir.",pconcierto->cant_ubicaciones+1,pconcierto->codigo);
            scanf("%d",&opc_ubicacion);
            if(opc_ubicacion==pconcierto->cant_ubicaciones+1){
                return;
            } else if (opc_ubicacion < pconcierto->cant_ubicaciones+1) {
                pubicacion = &pconcierto->ubicaciones[0];
                for(j=0; j < pconcierto->cant_ubicaciones ;j++){
                    
                    if(j+1==opc_ubicacion){   
                        printf("\nUsted seleccionó:\n");
                        printf("%d\t Nombre: %s\n",j+1,pubicacion->nombre);
                        printf("\t Código: %s\n",pubicacion->codigo);
                        printf("\t Precio: %.2f\n",pubicacion->valor);
                        printf("\t Entradas Disponibles: %d\n",pubicacion->entradas_disponibles);
                        printf("\t Cupos de ubicación: %d\n",pubicacion->cupos);
                        printf("\t Recaudación: %.2f\n\n",pubicacion->recaudacion);
                        printf("\nAhora ingrese cantidad de tickets a vender: ");
                        scanf("%d",&cant_tickets);
                        // En caso de querer vender más de las entradas disponibles.
                        if(cant_tickets>pubicacion->entradas_disponibles || cant_tickets < 0){
                            mensaje_error();
                            return;
                        }else{
                            pubicacion->recaudacion += cant_tickets * pubicacion->valor;
                            pubicacion->entradas_disponibles = pubicacion->entradas_disponibles - cant_tickets;
                        }
                    }
                    pubicacion++;
                }                
            } else {
                mensaje_error();
                return;
            }
        }
        pconcierto++;
    }
}

// Muestra la información de las ubicaciones de 1 concierto para devolver
void seleccionar_ubicacion_devolver_ticket(int posicion){
    int i,j;
    pconcierto = &conciertos[0];
    int opc_ubicacion;
    int cant_tickets;
    for(i=1; i <= 3; i++){
        if(i==posicion){            
            printf("====================================");
            printf("\nNombre: %s\n",pconcierto->nombre);
            printf("Codigo: %s\n",pconcierto->codigo);
            pubicacion = &pconcierto->ubicaciones[0];
            printf("Ubicaciones:\n");
            for(j=0; j < pconcierto->cant_ubicaciones ;j++){
                printf("%d\t Nombre: %s\n",j+1,pubicacion->nombre);
                printf("\t Código: %s\n",pubicacion->codigo);
                printf("\t Precio: %.2f\n",pubicacion->valor);
                printf("\t Entradas Disponibles: %d\n",pubicacion->entradas_disponibles);
                printf("\t Cupos de ubicación: %d\n",pubicacion->cupos);
                printf("\t Recaudación: %.2f\n\n",pubicacion->recaudacion);
                pubicacion++;
            }
            printf("%d) Volver.\n",pconcierto->cant_ubicaciones+1);
            printf("\n Ingrese el numero del ubicación que desea devolver tickets, ó %d para salir.",pconcierto->cant_ubicaciones+1,pconcierto->codigo);
            scanf("%d",&opc_ubicacion);
            if(opc_ubicacion==pconcierto->cant_ubicaciones+1){
                return;
            } else if (opc_ubicacion < pconcierto->cant_ubicaciones+1) {
                pubicacion = &pconcierto->ubicaciones[0];
                for(j=0; j < pconcierto->cant_ubicaciones ;j++){
                    
                    if(j+1==opc_ubicacion){   
                        printf("\nUsted seleccionó:\n");
                        printf("%d\t Nombre: %s\n",j+1,pubicacion->nombre);
                        printf("\t Código: %s\n",pubicacion->codigo);
                        printf("\t Precio: %.2f\n",pubicacion->valor);
                        printf("\t Entradas Disponibles: %d\n",pubicacion->entradas_disponibles);
                        printf("\t Cupos de ubicación: %d\n",pubicacion->cupos);
                        printf("\t Recaudación: %.2f\n\n",pubicacion->recaudacion);
                        printf("\nAhora ingrese cantidad de tickets a DEVOLVER: ");
                        scanf("%d",&cant_tickets);
                        // En caso de querer DEVOLVER más de las entradas vendidas.
                        if(cant_tickets > (pubicacion->cupos - pubicacion->entradas_disponibles ) || cant_tickets < 0){
                            mensaje_error();
                            return;
                        }else{
                            pubicacion->recaudacion = pubicacion->recaudacion - (cant_tickets * pubicacion->valor)*0.9;
                            pubicacion->entradas_disponibles += cant_tickets;
                        }
                    }
                    pubicacion++;
                }                
            } else {
                mensaje_error();
                return;
            }
        }
        pconcierto++;
    }
}


void mostrar_menu(){
    printf("1) Venta de Tickets\n");
    printf("2) Devolución de Tickets\n");
    printf("3) Ventas por conciertos\n");
    printf("4) Ventas por localidad\n");
    printf("5) Salir\n");
};

void venta_tickets(){
    int opc = 0;
    while( opc != 4 ){
        mostrar_conciertos();
        printf("4) Volver al menú principal. \n");
        printf("\n Ingrese el numero del concierto que desea vender tickets, ó 4 para salir.");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                seleccionar_ubicacion_agregar_ticket(opc);
                break;
            case 2:
                seleccionar_ubicacion_agregar_ticket(opc);
                break;
            case 3:
                seleccionar_ubicacion_agregar_ticket(opc);
                break;
            case 4: 
                break;
            default:
                mensaje_error();
                break;
        }
    };
};

void devolucion_tickets() {
    int opc = 0;
    while( opc != 4 ){
        mostrar_conciertos();
        printf("4) Volver al menú principal. \n");
        printf("\n Ingrese el numero del concierto que desea devolver tickets, ó 4 para salir.");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                seleccionar_ubicacion_devolver_ticket(opc);
                break;
            case 2:
                seleccionar_ubicacion_devolver_ticket(opc);
                break;
            case 3:
                seleccionar_ubicacion_devolver_ticket(opc);
                break;
            case 4: 
                break;
            default:
                mensaje_error();
                break;
        }
    };
}

void ventas_x_conciertos() {}
void ventas_x_localidad() {}

void mensaje_error(){
    printf("\n\nERROR: Ingrese una opción válida.\n\n");
}

int main(){
    cargar_conciertos();
    int menu_opc = 0;
    while (menu_opc != 5){
        mostrar_menu();
        scanf("%d", &menu_opc);
        switch (menu_opc){
        case 1:
            venta_tickets();
            break;
        case 2:
            devolucion_tickets();
            break;
        case 3:
            ventas_x_conciertos();
            break;
        case 4:
            ventas_x_localidad();
            break;
        case 5:
            break;
        default:
            mensaje_error();
            break;
        }
    }
    return (0);
}