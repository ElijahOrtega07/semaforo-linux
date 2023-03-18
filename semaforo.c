 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <semaphore.h>
 #include <fcntl.h>

int main() {
  sem_t *sem;
  pid_t pid;

  // Creamos el semáforo
  sem = sem_open("/mysem", O_CREAT, 0644, 1);
  if (sem == SEM_FAILED) {
    perror("Error al crear el semáforo");
    exit(EXIT_FAILURE);
  }

  // Creamos un proceso hijo
  pid = fork();
  if (pid < 0) {
    perror("Error al crear el proceso hijo");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    // Proceso hijo
    printf("Proceso hijo esperando al semáforo...\n");
    sem_wait(sem);
    printf("Proceso hijo dentro de la sección crítica\n");
    sleep(5);
    sem_post(sem);
    printf("Proceso hijo ha liberado el semáforo\n");
    exit(EXIT_SUCCESS);
  } else {
    // Proceso padre
    printf("Proceso padre esperando al semáforo...\n");
    sem_wait(sem);
    printf("Proceso padre dentro de la sección crítica\n");
    sleep(5);
    sem_post(sem);
    printf("Proceso padre ha liberado el semáforo\n");
    exit(EXIT_SUCCESS);
  }
}
