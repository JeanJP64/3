/* JEAN PERALTA
Propuesta de Ejercicio
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


////////////////////////////////////////////////5///5555

//AQUI COFRESIN
import java.util.Scanner;

public class CuentaBancaria {
    private double saldo;
    private double tasaInteresAnual;
    private int numeroTransacciones;

    public CuentaBancaria(double saldoInicial, double tasaInteresAnual) {
        this.saldo = saldoInicial;
        this.tasaInteresAnual = tasaInteresAnual;
        this.numeroTransacciones = 0;
    }

    public void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            numeroTransacciones++;
            System.out.println("Depósito exitoso.");
        } else {
            System.out.println("Cantidad inválida.");
        }
    }

    public void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            numeroTransacciones++;
            System.out.println("Retiro exitoso.");
        } else {
            System.out.println("Cantidad inválida o saldo insuficiente.");
        }
    }

    public void verSaldo() {
        System.out.printf("Saldo actual: $%.2f\n", saldo);
    }

    public int getNumeroTransacciones() {
        return numeroTransacciones;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el saldo inicial: ");
        double saldoInicial = scanner.nextDouble();
        System.out.print("Ingrese la tasa de interés anual (%): ");
        double tasaInteres = scanner.nextDouble();

        CuentaBancaria cuenta = new CuentaBancaria(saldoInicial, tasaInteres);

        int opcion;
        do {
            System.out.println("\n--- Menú ---");
            System.out.println("1. Depositar");
            System.out.println("2. Retirar");
            System.out.println("3. Ver saldo");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = scanner.nextInt();

            System.out.println("Número de transacciones: " + cuenta.getNumeroTransacciones());

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese cantidad a depositar: ");
                    double deposito = scanner.nextDouble();
                    cuenta.depositar(deposito);
                    break;
                case 2:
                    System.out.print("Ingrese cantidad a retirar: ");
                    double retiro = scanner.nextDouble();
                    cuenta.retirar(retiro);
                    break;
                case 3:
                    cuenta.verSaldo();
                    break;
                case 4:
                    System.out.println("Saliendo del programa. ¡Gracias!");
                    break;
                default:
                    System.out.println("Opción inválida.");
            }

        } while (opcion != 4);

        scanner.close();
    }
}




import java.util.Scanner;

public class CuentaBancaria {
    private double saldo;
    private double tasaInteresAnual;
    private int numeroTransacciones;

    public CuentaBancaria(double saldoInicial, double tasaInteresAnual) {
        this.saldo = saldoInicial;
        this.tasaInteresAnual = tasaInteresAnual;
        this.numeroTransacciones = 0;
    }

    public void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            numeroTransacciones++;
            System.out.println("Depósito exitoso.");
        } else {
            System.out.println("Cantidad inválida.");
        }
    }

    public void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            numeroTransacciones++;
            System.out.println("Retiro exitoso.");
        } else {
            System.out.println("Cantidad inválida o saldo insuficiente.");
        }
    }

    public void verSaldo() {
        System.out.printf("Saldo actual: $%.2f\n", saldo);
    }

    public int getNumeroTransacciones() {
        return numeroTransacciones;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el saldo inicial: ");
        double saldoInicial = scanner.nextDouble();
        System.out.print("Ingrese la tasa de interés anual (%): ");
        double tasaInteres = scanner.nextDouble();

        CuentaBancaria cuenta = new CuentaBancaria(saldoInicial, tasaInteres);

        int opcion;
        do {
            System.out.println("\n--- Menú ---");
            System.out.println("1. Depositar");
            System.out.println("2. Retirar");
            System.out.println("3. Ver saldo");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = scanner.nextInt();

            System.out.println("Número de transacciones: " + cuenta.getNumeroTransacciones());

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese cantidad a depositar: ");
                    double deposito = scanner.nextDouble();
                    cuenta.depositar(deposito);
                    break;
                case 2:
                    System.out.print("Ingrese cantidad a retirar: ");
                    double retiro = scanner.nextDouble();
                    cuenta.retirar(retiro);
                    break;
                case 3:
                    cuenta.verSaldo();
                    break;
                case 4:
                    System.out.println("Saliendo del programa. ¡Gracias!");
                    break;
                default:
                    System.out.println("Opción inválida.");
            }

        } while (opcion != 4);

        scanner.close();
    }
}

