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

    int main(){
    
    int cavalo = 0; // usado pra quando não se entende algum problema
        
    int i;
    int TamStr;
    char Str[30];
    char tres_primeiros[4];
    
    int tamanho_string(char string[]);
    char nome1[51];
    char nome2[51];
        
    float dinheiros_BR;
    float dinheiros_EUA;
    float dinheiros_EU;
    
    int x;
    int y;
    int z;
    int w;
    
    int A;
    int B;
    int C;
    
    int Valor_A;
    int Valor_B;
    int Valor_C;
    
    int idade;
    char resposta_sim_ou_nao[4];
    char nome_cidade[100];
    char nome[51];
    char char_inutil[1];

    printf("\n Eae champz, me digita seu nome: ");
    fgets(nome,51,stdin);                           //Solução que encontrei pra receber a variavel de string "nome" com nome compostos
    

    printf("\n Prazer em conhecer você, Sou Carlos, desenvolvedor desse programa.");
    printf("\n Poderia me informar quantos anos voce tem? Sr(a) %s",nome);
    scanf("%d", &idade);

    printf("\n Seu nome é %s e voce tem %d anos que novinho(a),e qual cidade voce mora? \n \n Por favor, por incompetencia do desenvolvedor desse programa o programa não consegue receber os espaços \n \n Então substitua-os por '_': underlines na hora de escrever esse_é_um_exemplo:",nome,idade);
    scanf ( "%s[^\n]", nome_cidade);                //Juro que tentei de tudo mas não consigo fazer receber nome composto, tentei até usar o fgets mas por algum motivo do alem ele não funciona..
    
    printf("\n Legal, eu tambem moro em %s rsrs ai.. quer me ajudar com a lição da faculdade?",nome_cidade);
    scanf("%s",resposta_sim_ou_nao);
    
        if (strcmp(resposta_sim_ou_nao, "sim") == 0){
    printf("\n Já que sua resposta foi %s vamos começar! Pra isso preciso que você digite pra mim qualquer numero de 1-100:",resposta_sim_ou_nao);
    int numero;
    scanf("%d", &numero);
    int numero_do_dobro = numero + numero;
    printf("\n Eu vou te dar o resultados sobre o numero que voce digitou, relacionado com minha tarefa");
    int numero_quadrado = numero * numero;
    
    printf("\n Escreva um programa que leia um número inteiro, calcule e exiba o resultado no dobro deste número: %d",numero_do_dobro);
    

        scanf("%c",char_inutil);
    
    printf("\n Escreva um programa que leia um número inteiro, calcule e exiba o resultado no quadrado deste número: %d",numero_quadrado);
    

        scanf("%c",char_inutil);
    
    if(idade >= 18){
        
        printf("\n Escreva um programa que leia a idade de uma pessoa e deverá ser exibido na tela, se esta pessoa é maior ou menor \n de idade (considerar 18 anos para maior idade)\n Ou seja se você estiver lendo isso eu sei que você e maior de idade");
        scanf("%c",char_inutil);
            
       cout << "\n  Escreva um programa que calcule e exiba o resultado da seguinte expressão matemática: \n \n A2 * 5 – C / (B – A % 4)" 
       << endl;

       cout << "\n Digite o Valor_A: " 
       << endl;

       cin >> Valor_A;

       cout << "\n Digite o Valor_B: " 
       << endl;

       cin >> Valor_B;

       cout << "\n Digite o Valor_C: " 
       << endl;

       cin >> Valor_C;

       double formula = ((pow(Valor_A, 2) * 5) - Valor_C) / (Valor_B - Valor_A + 4);

       cout << "\n O resultado e: " 
       << formula 
    << endl;
    
       printf("\n Escreva um programa que leia um valor em Reais (R$) \n Leia também a cotação do Dólar e Euro \n Realize o cálculo da conversão de moeda (de Reais para Dólares e de Reais para Euros) e exiba na tela o resultado \n \n Digite a quantidade em Reais:");
       scanf("%f",&dinheiros_BR);
       
       dinheiros_EUA = dinheiros_BR / 4.78;  //Valor do dia 24/3/2022
       dinheiros_EU  = dinheiros_BR / 5.27; //Valor do dia 24/3/2022
       
       printf("\n E o seu valor em dolar é: %f ",dinheiros_EUA);
       printf("\n E o seu valor em Euros é: %f ",dinheiros_EU);

       
       printf("\n Escreva um programa que leia o nome de duas pessoas e ao final exiba: O nome das duas pessoas com todos os caracteres maiúsculos ");
       printf("\n A quantidade de caracteres de cada nome apenas os três primeiros caracteres de cada nome");
       
       printf("\n Digite o primeiro nome: ");
       scanf("%s",nome);
       printf("\n Digite o segundo nome: ");
       scanf("%s",nome2);
       
       int num = tamanho_string(nome);
       
       printf("\n Aqui a quantidade de caracteres do %s é de: %i",nome ,num);
       
       int num2 = tamanho_string(nome2);
       
      printf("\n Aqui a quantidade de caracteres do %s é de: %i",nome2 ,num2);
      
      printf("\n Agora, vou mostrar os nomes digitados em maiúsculos:  \n");
      
    // divisorsinho **********************************************************
      
      TamStr = strlen(nome);
      
      for(i=0; i<TamStr; i++)
    {                            // Converte cada caracter de nome(1)
      nome[i] = tolower (nome[i]);  // para Minisculas
    }
       printf("\n %s <-- Miniscula",nome);
    
    // divisorsinho ********************************************************
    
    TamStr = strlen(nome2);
      
      for(i=0; i<TamStr; i++)
    {                            // Converte cada caracter de nome(2)
      nome2[i] = tolower (nome2[i]);  // para Minisculas
    }
       printf("\n %s <-- Miniscula",nome2);   
      
    // divisorsinho **********************************************************

      TamStr = strlen(nome);
      
      for(i=0; i<TamStr; i++)
    {                            // Converte cada caracter de nome(1)
      nome[i] = toupper (nome[i]);  // para maiusculas
    }
       printf("\n %s <-- Maiuscula",nome);

    // divisorsinho **********************************************************
       
       TamStr = strlen(nome2);
      
      for(i=0; i<TamStr; i++)
    {                              // Converte cada caracter de nome(2)
      nome2[i] = toupper (nome2[i]);  // para maiusculas
    }
       printf("\n %s <-- Maiuscula",nome2);
       
       
    // divisorsinho **********************************************************
    
       memcpy( tres_primeiros, &nome[0], 3);
       tres_primeiros[3] = '\0';
       
       printf("\n %s <--- 3 Letras Primeiro nome", tres_primeiros);
       
       memcpy( tres_primeiros, &nome2[0], 3);
       tres_primeiros[3] = '\0';
       
       printf("\n %s <--- 3 Letras Segundo nome",tres_primeiros);
       
    // divisorsinho **********************************************************
    
       printf("\n Escreva um programa que leia dois números inteiros, sendo armazenados respectivamente nas variáveis A e B.");
       printf("\n  O programa deverá inverter os valores entre as variáveis, de modo que o valor da variável A seja atribuído na variável B e vice-versa. Ao final exibir os valores de cada variável.");
       
       printf("\n Digite dois valores: ");
       scanf("%d%d", &A, &B);
       
       
       printf("a: %d\tb: %d\n", A, B);  
       
        A = A + B;
        B = A - B;
        A = A - B;
        
       printf("a: %d\tb: %d\n", A, B);
       
    // divisorsinho **********************************************************
    
       printf("\n  Escreva um programa que calcule a expressão lógica, sendo que o usuário deverá informar os valores (números inteiros) para as variáveis");
       printf("\n ((X >= Y) AND (Z <=X)) OR ((X == W) AND (Y == Z)) OR (NOT(X != W))");
       
       printf("\n Informe o valor de x: ");
       scanf("%d",&x);

       printf("\n Informe o valor de y: ");
       scanf("%d",&y);

       printf("\n Informe o valor de z: ");
       scanf("%d",&z);

       printf("\n Informe o valor de w ");
       scanf("%d",&w);
       
       
       
      if (((x >=y) && (z <= x)) || ((x == w) && (y == z)) || (!(x != w))){
         return 1;
      }
        else{
         return 0;
        }
      
      
        }
        else{
            printf("\n Ia te chamar pra beber cerveja");
            
        }
    }
        else{
            printf("\n Tudo bem, nem queria mesmo, vou pedir ajuda a outra pessoa");
            
        }
    
    return 0;
}

    int tamanho_string(char string[]){
        int Numcaracteres = 0;
        
        while(string[Numcaracteres] != '\0'){
            ++Numcaracteres;
        }
    return Numcaracteres;
}
