#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //lib que tive que usar 
#include <stdlib.h>

int main(){

    pid_t pid;

// processo de criacao de processos

    pid = fork();


    if(pid < 0){ //criando processo 

        printf("Fork Failed"); //caso o processo de errado
        exit(-1);

    }
    else if(pid == 0){ //processo de criacao deu certo

        execlp("/home/nome.sh","ls" ,NULL); // diretorio a buscar 

    }
    else { // processo encontrando o diretorio e exercutando com sucesso
        wait(NULL); // aguardando 
        printf("child complete\n"); //print caso a execucao de certo!
        exit(0); // saindo 
    }

}

// para executar eu usei o kali linux, gcc main.c -o main.run -- ./main.run executou com sucesso
