/*Propuesta de Ejercicio

-	Utilice una estructura para almacenar información de estudiantes (por ejemplo, nombre, edad, calificación).
-	Administre una lista de estudiantes, permitiendo agregar, listar y buscar estudiantes.
-	Guarde los datos en un archivo y pueda cargarlos nuevamente al iniciar el programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100

typedef struct {
    char nombre[50];
    int edad;
    float calificacion;
} Estudiante;

void agregarEstudiante(Estudiante estudiantes[], int *conteo) {
    if (*conteo >= MAX_ESTUDIANTES) {
        printf("Límite de estudiantes alcanzado.\n");
        return;
    }
    printf("Ingrese el nombre: ");
    scanf(" %[^\n]", estudiantes[*conteo].nombre);
    printf("Ingrese la edad: ");
    scanf("%d", &estudiantes[*conteo].edad);
    printf("Ingrese la calificacion: ");
    scanf("%f", &estudiantes[*conteo].calificacion);
    (*conteo)++;
    printf("Estudiante agregado con exito.\n");
}

void listarEstudiantes(Estudiante estudiantes[], int conteo) {
    printf("\nLista de Estudiantes:\n");
    for (int i = 0; i < conteo; i++) {
        printf("%d. Nombre: %s, Edad: %d, Calificacion: %.2f\n", 
               i + 1, estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].calificacion);
    }
}

void guardarEnArchivo(Estudiante estudiantes[], int conteo, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fwrite(estudiantes, sizeof(Estudiante), conteo, archivo);
    fclose(archivo);
    printf("Datos guardados en %s\n", nombreArchivo);
}

void cargarDesdeArchivo(Estudiante estudiantes[], int *conteo, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se encontro un archivo previo.\n");
        return;
    }
    *conteo = fread(estudiantes, sizeof(Estudiante), MAX_ESTUDIANTES, archivo);
    fclose(archivo);
    printf("Datos cargados desde %s\n", nombreArchivo);
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int conteo = 0;
    int opcion;

    cargarDesdeArchivo(estudiantes, &conteo, "estudiantes.dat");

    do {
        printf("\nMenu:\n");
        printf("1. Agregar Estudiante\n");
        printf("2. Listar Estudiantes\n");
        printf("3. Guardar y Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &conteo);
                break;
            case 2:
                listarEstudiantes(estudiantes, conteo);
                break;
            case 3:
                guardarEnArchivo(estudiantes, conteo, "estudiantes.dat");
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 3);

    return 0;
}


