#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *codice_thread(void*arg){
    //Il tipo di dati pid_t è un numero che rappresenta l'ID di un processo.
    pid_t pid;
    //il getpid() restituisce ID del processo attuale
    pid = getpid();
    //Il tipo di dati pthread_t è un numero che rappresenta l'ID di un thread.
    pthread_t tid;
    //il pthread_self() restituisce ID del thread attuale
    tid = pthread_self();
    printf("Sono il thread con %i del processo %i\n", tid, pid);
    
    return NULL;
}

int main(){
    pthread_t ptid;
    printf("Il pid del main e' %d\n", (int) getpid());
    /*
        Utilizzato per creare un nuovo thread, prende come primo parametro l'id del thread, NULL è il secondo argomento (che dovrebbe essere un qualche attributo, ma potremmo non usarlo), il terzo argomento è la funzione e l'ultimo argomento è quello che vogliamo passare al nuovo thread, in questo caso nulla.
     */
    
    pthread_create(&ptid, NULL, codice_thread, NULL);
    sleep(5);
    
    return 0;
}
