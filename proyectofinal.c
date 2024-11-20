#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* determinarGanador(int eleccion1, int eleccion2) {
    if (eleccion1 == eleccion2) {
        return "Empate";
    }
    if ((eleccion1 == 1 && eleccion2 == 3) ||
        (eleccion1 == 2 && eleccion2 == 1) ||
        (eleccion1 == 3 && eleccion2 == 2)) {
        return "Jugador 1 gana";
    }
    return "Jugador 2 gana";
}

const char* opcionToString(int opcion) {
    switch (opcion) {
        case 1: return "Piedra";
        case 2: return "Papel";
        case 3: return "Tijeras";
        default: return "Invalido";
    }
}

void mostrarASCII(const char* archivo) {
    FILE* file = fopen(archivo, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo: %s\n", archivo);
        return;
    }
    char linea[128];
    while (fgets(linea, sizeof(linea), file)) {
        printf("%s", linea);
    }
    fclose(file);
}

void mostrarMenu() {
    printf("\n");
    mostrarASCII("menu.txt");
    printf("\nElige una opcion: ");
}

int main() {
    int opcion, jugador1, jugador2;
    char jugarDeNuevo;
    srand(time(NULL));

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                do {
                    printf("Elige tu jugada (1. Piedra, 2. Papel, 3. Tijeras): ");
                    scanf("%d", &jugador1);
                    if (jugador1 < 1 || jugador1 > 3) {
                        printf("Eleccion invalida. Intentalo de nuevo.\n");
                        continue;
                    }

                    if (jugador1 == 1) mostrarASCII("piedra.txt");
                    else if (jugador1 == 2) mostrarASCII("papel.txt");
                    else if (jugador1 == 3) mostrarASCII("tijeras.txt");

                    jugador2 = rand() % 3 + 1;
                    printf("\nCPU eligio:\n");
                    if (jugador2 == 1) mostrarASCII("piedra.txt");
                    else if (jugador2 == 2) mostrarASCII("papel.txt");
                    else if (jugador2 == 3) mostrarASCII("tijeras.txt");

                    printf("\n%s\n", determinarGanador(jugador1, jugador2));

                    printf("Quieres jugar de nuevo? (s/n): ");
                    scanf(" %c", &jugarDeNuevo);
                } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');
                break;

            case 2:
                do {
                    printf("Jugador 1, elige tu jugada (1. Piedra, 2. Papel, 3. Tijeras): ");
                    scanf("%d", &jugador1);
                    if (jugador1 < 1 || jugador1 > 3) {
                        printf("Eleccion invalida. Intentalo de nuevo.\n");
                        continue;
                    }
                    printf("Jugador 2, elige tu jugada (1. Piedra, 2. Papel, 3. Tijeras): ");
                    scanf("%d", &jugador2);
                    if (jugador2 < 1 || jugador2 > 3) {
                        printf("Eleccion invalida. Intentalo de nuevo.\n");
                        continue;
                    }

                    printf("\nJugador 1 eligio:\n");
                    if (jugador1 == 1) mostrarASCII("piedra.txt");
                    else if (jugador1 == 2) mostrarASCII("papel.txt");
                    else if (jugador1 == 3) mostrarASCII("tijeras.txt");

                    printf("\nJugador 2 eligio:\n");
                    if (jugador2 == 1) mostrarASCII("piedra.txt");
                    else if (jugador2 == 2) mostrarASCII("papel.txt");
                    else if (jugador2 == 3) mostrarASCII("tijeras.txt");

                    printf("\n%s\n", determinarGanador(jugador1, jugador2));

                    printf("¿Quieres jugar de nuevo? (s/n): ");
                    scanf(" %c", &jugarDeNuevo);
                } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');
                break;

            case 3:
                printf("Gracias por jugar.\n");
                break;

            default:
                printf("Opcion invalida. Intentalo de nuevo.\n");
                break;
        }

        printf("\n");
    } while (opcion != 3);

    return 0;
}
