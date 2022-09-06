import java.io.*;

public class OSprocess
{
    /**
     *
     */
    public static void main(String[] args) throws IOException {
        if (args.length !=1) {
            System.err.println("usage: java OSProcess <command>"); // para testar usei o comando para abrir o notepad  //java OSprocess C:\\WINDOWS\\system32\\notepad.exe
            System.exit(0); // caso der erro cancelar a execucao do programa                                      //java OSprocess C:\\WINDOWS\\system32\\notepad.exe
        }

        // Criar o processo dos argumetos
        ProcessBuilder pb = new ProcessBuilder(args[0]);
        Process proc = pb.start();

        // obter o arquivo que voce deseja abrir 
        InputStream is = proc.getInputStream();
        InputStreamReader isr = new InputStreamReader(is);
        BufferedReader br = new BufferedReader(isr);

        // Ler o arquivo e fazer a execucao do arquivo 
        String line;
        while ( (line = br.readLine()) !=null)
            System.out.println(line);
        // fechar o processo
        br.close();
    }
}
