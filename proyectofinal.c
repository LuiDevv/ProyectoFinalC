#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int determinarGanador(int eleccion1, int eleccion2) {
    if (eleccion1 == eleccion2) {
        return 0;
    }
    if ((eleccion1 == 1 && eleccion2 == 3) ||
        (eleccion1 == 2 && eleccion2 == 1) ||
        (eleccion1 == 3 && eleccion2 == 2)) {
        return 1;
    }
    return 2;
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

int main()
{
    int opcion, jugador1, jugador2;
    int puntuacionJugador1 = 0, puntuacionJugador2 = 0;
    char jugarDeNuevo;
    srand(time(NULL));

    do
    {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            do
            {
                printf("Elige tu jugada (1. Piedra, 2. Papel, 3. Tijeras): ");
                scanf("%d", &jugador1);
                if (jugador1 < 1 || jugador1 > 3)
                {
                    printf("Eleccion invalida. Intentalo de nuevo.\n");
                    continue;
                }

                jugador2 = rand() % 3 + 1;
                printf("\nCPU eligio:\n%s\n", opcionToString(jugador2));

                int resultado = determinarGanador(jugador1, jugador2);
                if (resultado == 1)
                {
                    puntuacionJugador1++;
                    printf("Jugador 1 gana esta ronda.\n");
                }
                else if (resultado == 2)
                {
                    puntuacionJugador2++;
                    printf("CPU gana esta ronda.\n");
                }
                else
                {
                    printf("Es un empate.\n");
                }

                printf("\n--- Marcador ---\n");
                printf("Jugador 1: %d\n", puntuacionJugador1);
                printf("CPU: %d\n", puntuacionJugador2);

                printf("Quieres jugar de nuevo? (s/n): ");
                scanf(" %c", &jugarDeNuevo);
            } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');
            break;

        case 2:
            do
            {
                printf("Jugador 1, elige tu jugada (1. Piedra, 2. Papel, 3. Tijeras): ");
                scanf("%d", &jugador1);
                printf("Jugador 2, elige tu jugada (1. Piedra, 2. Papel, 3. Tijeras): ");
                scanf("%d", &jugador2);

                int resultado = determinarGanador(jugador1, jugador2);
                if (resultado == 1)
                {
                    puntuacionJugador1++;
                    printf("Jugador 1 gana esta ronda.\n");
                }
                else if (resultado == 2)
                {
                    puntuacionJugador2++;
                    printf("Jugador 2 gana esta ronda.\n");
                }
                else
                {
                    printf("Es un empate.\n");
                }

                printf("\n--- Marcador ---\n");
                printf("Jugador 1: %d\n", puntuacionJugador1);
                printf("Jugador 2: %d\n", puntuacionJugador2);

                printf("¿Quieres jugar de nuevo? (s/n): ");
                scanf(" %c", &jugarDeNuevo);
            } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');
            break;

        case 3:
            puntuacionJugador1 = 0;
            puntuacionJugador2 = 0;
            printf("\n--- Marcador reiniciado ---\n");
            printf("Jugador 1: %d\n", puntuacionJugador1);
            printf("Jugador 2: %d\n", puntuacionJugador2);
            break;

        case 4:
            printf("Gracias por jugar.\n");
            break;

        default:
            printf("Opcion invalida. Intentalo de nuevo.\n");
            break;
        }

        printf("\n");
    } while (opcion != 4);

    return 0;
}
