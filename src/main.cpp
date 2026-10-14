#include <Arduino.h>
// fora do arduino.h, para manipulação de strings
#include <string.h> // Biblioteca para manipulação de strings
#include <stdlib.h> // Biblioteca para manipulação de strings
void textoTipo();
void textoTipoString();

void setup()
{
    Serial.begin(9600);
    textoTipo();
    textoTipoString();
}

void loop()
{
}

void textoTipo()
{
    const char *cidade = "Sao paulo";
    const char outraCidade[] = "Sao caerano";
    Serial.println(cidade);
    Serial.println(outraCidade);

    /*descobrindo o tamanho das strings
     */
    int tamanhoTexto = strlen(cidade); // strlen() retorna o tamanho da string
    Serial.print("Tamanho da string: ");
    Serial.println(tamanhoTexto);
    int tamanhoOutraCidade = strlen(outraCidade); // strlen() retorna o tamanho da string
    Serial.print("Tamanho da outra string: ");
    Serial.println(tamanhoOutraCidade);

    // descobrindo o tamanho das strings com sizeof()
    int tamanhoTexto2 = sizeof(cidade); // sizeof() retorna o tamanho da string
    Serial.print("Tamanho da string com sizeof(): ");
    Serial.println(tamanhoTexto2);
    size_t tamanhoOutraCidade2 = sizeof(outraCidade); // sizeof() retorna o tamanho da string
    Serial.print("Tamanho da outra string com sizeof(): ");
    Serial.println(tamanhoOutraCidade2);

    // o caractere nulo '\0' é adicionado automaticamente ao final da string, então o tamanho real da string é o tamanho do array - 1
    char vertorTexto[8] = {'E', 'd', 'u', 'a', 'r', 'd', 'o', '\0'};
    Serial.println(vertorTexto);

    // ============================
    // *comparar texto
    // ============================ 
    const char* cidade1 = "porto alegre";
    const char* cidade2 = "porto alegre";
    if(strcmp(cidade1, cidade2) == 0) // strcmp() compara duas strings e retorna 0 se forem iguais
    {
        Serial.println("As strings são iguais");
    }
    else
    {
        Serial.println("As strings são diferentes");
    }
    // se a primeira palavra vem antes da segunda, strcmp() retorna um valor negativo, se a primeira palavra vem depois da segunda, strcmp() retorna um valor positivo

    // ============================
    // * texto editaval com char* e char[]
    // ============================

    char nomeDoAluno[8] = "Eduards";
    nomeDoAluno[6] = 'o'; // alterando o último caractere da string
    Serial.println(nomeDoAluno);

    // ============================
    // *Copiando outro texto para o vetor
    //! Aviso: o tamanho do vetor deve ser maior que o tamanho do texto a ser copiado, caso contrário, ocorrerá um estouro de memória
    // ============================

    strcpy(nomeDoAluno, "Tadeu"); // copiando o texto para o vetor
    Serial.println(nomeDoAluno);

    // ============================
    // *Concatenando textos
    // ============================

    char frase[20] = "Ola, ";
    strcat(frase, "Mundo cruel"); // concatenando o texto
    Serial.println(frase);

    // ============================
    // * Procururando um caractere em um texto
    // ============================

    char* posicaoLetra = strchr(frase, 'M'); // procurando a letra M na frase
    if(posicaoLetra != NULL) // se a letra foi encontrada
    {
        Serial.print("A letra M foi encontrada na posição: ");
        Serial.println(posicaoLetra); // imprimindo a posição da letra M
    }
    else
    {
        Serial.println("A letra M não foi encontrada");
    }
    
    // ============================
    // *convertendo um número para texto
    // ============================

    char idadeTexto[] = "39"; // [0x33, 0x39, 0x00] -> [3, 9, \0]
    int idade = atoi(idadeTexto); // atoi() converte uma string para um inteiro
    Serial.print("Idade: ");
    
    // buffer para armazenar o texto convertido
    char buffer[100];
    char* local = "sala de aula";
    float temperatura = 26.4;
    int unidade = 72;

    snprintf(buffer, sizeof(buffer), "A temperatura na %s é de %.1f graus e a unidade é %d", local, temperatura, unidade);
    Serial.println(buffer);

    // ==============================================================
    // * snprintf() monta um texto dentro de um buffer, com o tamanho máximo do buffer, e com os valores passados como parâmetros, evitando estouro de memória
    // * - enviar para MQTT
    // * - enviar para Serial
    // * - enviar para display
    // * - enviar para arquivo
    // ==============================================================
    // ==============================================================
    // * ESPECIFICADORES
    // * %s - string
    // * %d - inteiro
    // * %f - float
    // * %c - caractere
    // * %x - hexadecimal
    // * %p - ponteiro
    // * %u - unsigned int
    // * %ld - long int
    // * %lu - unsigned long int
    // * %lld - long long int
    // * %llu - unsigned long long int
    // * %e - notação científica
    // * %g - notação científica ou decimal, dependendo do valor
    // * %n - número de caracteres escritos até o momento
    // * %% - caractere %
    // * %m - mensagem de erro
    // * %a - hexadecimal de ponto flutuante
    // * %A - hexadecimal de ponto flutuante (maiúsculo)
    // * %F - ponto flutuante (decimal)
    // * %G - ponto flutuante (decimal ou notação científica, dependendo do valor)
    // * %C - caractere (Unicode)
    // * %S - string (Unicode)
    // * %Z - string (Unicode, terminada em nulo)
    // * %% - caractere %
    // ===============================================================
    // ==============================================================\
    // * Flags, largura e precisão
    // * %5d  -imprime com largura minima de 5, alinhado a direita
    // * %-2d -imprime com lagura minima de 2, alinhado a esquerda
    // * %04d -completa com zeros ex. 0022
    // * %.2f -imprime com 2 casas decimais
    // * %5.2f -imprime com largura minima de 5 e
    // * 2 casas decimais, alinhado a direita
    // * %-5.2f -imprime com largura minima de 5 e


}

void textoTipoString()
{
    String nome = "Eduardo";
    String curso = "Logica de programação";
    String mensagem = "ola";

    mensagem = mensagem + ", " + nome + "! Bem vindo ao curso de " + curso + ".";

    Serial.println(mensagem);

    //* tamanho da string'

    int tamanhoMensagem = mensagem.length();

    Serial.printf("tamanho da string em letra: %u", tamanhoMensagem);


    //* acessando caracteres em uma posicao especifica 

    char priimeiraLetra = mensagem.charAt(0);
    Serial.printf("\nA primeira letra da mensagem é: %c", priimeiraLetra);

    //* tambem e possivel acessar com colchetes.

    char ultimaLetra = mensagem.charAt(tamanhoMensagem - 1);
    Serial.printf("\nA última letra da mensagem é: %c", ultimaLetra);

    // * procurar um texto dentro de uma string

    int posicaoCurso = mensagem.indexOf(curso);
    Serial.printf("\nA posição do curso na mensagem é: %d", posicaoCurso);
    int inicioNomeDoCurso = posicaoCurso + 0; // e a posicao da palavra curso + 9 posição na frente
    String nomeDocurso =  mensagem.substring(inicioNomeDoCurso, inicioNomeDoCurso + tamanhoMensagem - 2);   
    Serial.printf("\nO nome do curso é: %s", nomeDocurso.c_str());
    
    // substituir um texto dentro de uma string
    mensagem.replace("ola", "Boa tarde! ");
    Serial.println(mensagem);

    // corvertendo tudo em maicusculo
    mensagem.toUpperCase();
    Serial.println(mensagem);
}