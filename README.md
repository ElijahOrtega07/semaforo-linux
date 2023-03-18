# Explicación del codigo.

* creamos un semáforo llamado "/mysem" con valor inicial 1. Luego, creamos un proceso hijo que espera al semáforo, entra en una sección crítica (simbolizada por una espera de 5 segundos) y luego libera el semáforo. El proceso padre hace lo mismo, pero en un orden diferente.

* Al ejecutar este programa en WSL, podemos ver que ambos procesos se sincronizan correctamente al entrar en la sección crítica alternativamente.

