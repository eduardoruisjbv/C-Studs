#include    <stdio.h>  // Biblioteca Sensorial do sistema, é aqui que identifica que voce está num teclado e num mouse ou celular com touchscreen e etc...
#include    <stdlib.h> // Biblioteca responsavel por alocação de memoria e processamento de dados armazenados
#include    <string.h> // Biblioteca de Textos
#include    <math.h>   // Bibliteca para soluções matematicas
#include    <iostream> // Biblioteca com Funcionamento parecido da junção de <stdio.h> e <stdlib.h> porem funciona com alocação de Buffers do sistema
#include    <cstdio>   // Biblioteca com mais moderna de <stdio.h>
#include    <ctype.h> // Biblioteca que permite a ultilização do Toupper
#include    <conio.h> // Biblioteca de manipulação de caracteres

//UNIVERSIDADE DE ENSINO SUPERIOR CIENCIA DE DADOS UNIFEOB
//ESSE CODIGO FOI ESCRITO POR CARLOS EDUARDO RUI PARA FINS ACADEMICOS
//CONTATO eduardoruisjbv@outlook.com / eduardoruisjbv@gmail.com
using namespace std;

unsigned int factorial(int a) {
         int r=1;
         for (int i=a;i>0;i--) r*=i;
         return r;
}

int main () {
    double a,b,r,memory=0;
    char op, choice[10];

    cout<<"+ pra adicionar, - pra subtrair, * pra multiplicar, / pra dividir, \
^ to power, ! to factorial\n\n";
    start: // começo

    cin>>a; // primeiro numero
    reused: //
    cin>>op; // OPERADOR
    // OQUE FAZER
    if (op=='!') r=factorial(a); 
    else {
         cin>>b;
         if (op=='+') r=a+b;
         if (op=='-') r=a-b;
         if (op=='*') r=a*b;
         if (op=='/') r=a/b;
         if (op=='^') r=pow(a,b);
         }
    // CONTE O RESULTADO
    cout<<"="<<r<<endl;

    // CRIANDO MEMORIA
    cout<<"\nDigite 'mi' pra inserir o numero na memoria, ou 'mc' pra apagar a memoria\n";
    cin>>choice;
    if (!strcmp(choice,"mi")) memory=r; // Insira a memoria
    else if (!strcmp(choice,"mc")) memory=0; // Limpe a memoria
    else cout<<"Comando desconhecido o programa vai continuar!\n"; // DEFAULT

    //Criando a Base para o LOOP!
    cout<<"\nDigite 'restart' pra voltar desde o inicio, \
'reuse' to use the result, \n'mr' to reuse the number \
in the memory, or 'quit' to quit: ";
    cin>>choice; // Diga ao programa oque fazer
    if (!strcmp(choice,"restart")) goto start; // VOLTANDO DO INICIO
    if (!strcmp(choice,"reuse")) { a=r; cout<<a; } // USE O RESULTADO
    if (!strcmp(choice,"reuse")) goto reused; // COMECE COM O RESULTADO
    if (!strcmp(choice,"quit")) goto end; // FECHE O PROGRAMA
    if (!strcmp(choice,"mr")) { a=memory; cout<<a; } // USE A MEMORIA
    if (!strcmp(choice,"mr")) goto reused; // COMECE COM A MEMORIA
    getchar();
    end: // Pra fechar o programa
    return 0;
}
