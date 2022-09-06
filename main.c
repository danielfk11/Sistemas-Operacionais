#include <stdio.h>
#include <windows.h>
int main(VOID)
{
STARTUPINFO si ;
PROCESS_INFORMATION pi;

	// local para alocar memoria
	ZeroMemory (&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory (&pi, sizeof(pi));

	// criar processo
	if (!CreateProcess(NULL, // criacao de comando
		"C: \\WINDOWS\\system32\\notepad.exe", // comando a ser executado
		NULL, // nao herdar processos 
		NULL, // nao herdar processos
		FALSE, // desabilitar heranca
		0, // nao criar flags
		NULL, // nao usar blocos de criacao
		NULL, // usar diretorios existentes
		&si,
		&pi))
	{
		fprintf(stderr, "Create Process Failed"); //print caso a execucao der erro
		return -1; //return erro
	}
	
    // executando e informando que o processo de execucao deu certo
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");

	// fechando processos de memoria
	CloseHandles(pi.hProcess);
	CloseHandles(pi.hThread);
}
