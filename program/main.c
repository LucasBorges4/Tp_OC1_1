#include "montador.h"

int main(void){

    FILE *arq_Entrada; //Armazena o arquivo de entrada
    FILE *arq_Saida; //Armazena o arquivo de saida

    limpa_Arquivo(arq_Saida, "./stdin/binary.txt"); //Apaga o que está escrito no arquivo binary.txt

    tipo_saida(); //./stdin/assembly.asm -o ./stdin/binary.txt

    Type_I vetor_I[NUM_INSTRUCT_TYPE_I];
    Type_R vetor_R[NUM_INSTRUCT_TYPE_R];
    Type_S vetor_S[NUM_INSTRUCT_TYPE_S];
    Type_B vetor_B[NUM_INSTRUCT_TYPE_B];
    // Tipo I addi, andi, ori, lw, lb, lh, -> 6 
    // Tipo R add, sub, and, or, xor, sll e srl -> 7
    // Tipo S sw, sb e sh -> 3
    // Pseudo instruções li, mv, j, o binário gerado é o mesmo que numa lógica padrão;
    // Por exemplo -> MV tem o mesmo binario que add x19, x19, x0
    
      
    char instrucoes_I[NUM_INSTRUCT_TYPE_I][5] = {"addi","andi","ori","lw","lb","lh"}; //Instrucoes do tipo I
    char instrucoes_R[NUM_INSTRUCT_TYPE_R][4] = {"add", "sub", "and", "or", "xor", "sll", "srl"}; //Instrucoes do tipo R
    char instrucoes_S[NUM_INSTRUCT_TYPE_S][3] = {"sw", "sb", "sh"}; //Instrucoes do tipo S
    char instrucoes_B[NUM_INSTRUCT_TYPE_B][4] = {"beq", "bne", "blt", "bge"};
                                    
    int instrucoes_I_codes[NUM_INSTRUCT_TYPE_I][2] = {{0,10011},{111,10011},{110,10011},{10,11},{0,11},{1,11}}; //func3,opcode7
    int instrucoes_R_codes[NUM_INSTRUCT_TYPE_R][3] = {{0,0,110011},{100000,0,110011},{0,111,110011},{0,110,110011},{0,100,110011},{0,1,110011},{0,101,110011}}; //func7,func3,opcode
    int instrucoes_S_codes[NUM_INSTRUCT_TYPE_S][2] = {{10,100011},{0,100011},{1,100011}}; //func3,opcode7
    int instrucoes_B_codes[NUM_INSTRUCT_TYPE_B][2] = {{000,1100011}, {001, 1100011}, {100, 1100011}, {101, 1100011}}; //func3, opcode7
    
    char *p;
    int cont = 0;
    
    for(int x = 0; x < NUM_INSTRUCT_TYPE_I; x++){ //Loop for para adicionar func3 e opcode para cada instrucao do tipo I
        strcpy(vetor_I[x].nome_Instrucao,instrucoes_I[x]); //Passa o nome contido em instrucoes_I no indice x para a instrucao I no indice x
        vetor_I[x].funct_3 = instrucoes_I_codes[x][0]; //Passa o func3 contido em instrucoes_I_codes no indice {x,0} para a instrucao I no indice x
        vetor_I[x].opcode_7 = instrucoes_I_codes[x][1]; //Passa o opcode contido em instrucoes_I_codes no indice {x,1} para a instrucao I no indice x
    }
    
    for(int x = 0; x < NUM_INSTRUCT_TYPE_R; x++){ //Loop for para adicionar func7,func3 e opcode para cada instrucao do tipo R
        strcpy(vetor_R[x].nome_Instrucao,instrucoes_R[x]); //Passa o nome contido em instrucoes_R no indice x para a instrucao R no indice x
        vetor_R[x].funct_7 = instrucoes_R_codes[x][0]; //Passa o func7 contido em instrucoes_R_codes no indice {x,0} para a instrucao R no indice x
        vetor_R[x].funct_3 = instrucoes_R_codes[x][1]; //Passa o func3 contido em instrucoes_R_codes no indice {x,1} para a instrucao R no indice x
        vetor_R[x].opcode_7 = instrucoes_R_codes[x][2]; //Passa o opcode contido em instrucoes_R_codes no indice {x,2} para a instrucao R no indice x
    }
    for(int x = 0; x < NUM_INSTRUCT_TYPE_S; x++){ //Loop for para adicionar func3 e opcode para cada instrucao do tipo S
        strcpy(vetor_S[x].nome_Instrucao,instrucoes_S[x]); //Passa o nome contido em instrucoes_S no indice x para a instrucao S no indice x
        vetor_S[x].funct_3 = instrucoes_S_codes[x][0]; //Passa o func3 contido em instrucoes_S_codes no indice {x,0} para a instrucao S no indice x
        vetor_S[x].opcode_7 = instrucoes_S_codes[x][1];  //Passa o opcode contido em instrucoes_S_codes no indice {x,1} para a instrucao S no indice x
    }
    for(int x = 0; x < NUM_INSTRUCT_TYPE_B; x++){ //Loop for para adicionar func3 e opcode para cada instrucao do tipo B
        strcpy(vetor_B[x].nome_Instrucao,instrucoes_B[x]); //Passa o nome contido em instrucoes_B no indice x para a instrucao B no indice x
        vetor_B[x].funct_3 = instrucoes_B_codes[x][0]; //Passa o func3 contido em instrucoes_B_codes no indice {x,0} para a instrucao B no indice x
        vetor_B[x].opcode_7 = instrucoes_B_codes[x][1]; //Passa o opcode contido em instrucoes_B_codes no indice {x,1} para a instrucao B no indice x
    }
    
    char* endereco_entrada; //String para armazenar o endereco de entrada
    endereco_entrada = (char*) malloc(50*sizeof(char)); //Alocacao de 50 caracteres(limite)
    strcpy(endereco_entrada, "./stdin/assembly.asm"); //Atribuicao do endereco para a string
    abre_Arquivo(&arq_Entrada, &arq_Saida, endereco_entrada); 
    free(endereco_entrada); //Libera a string, visto que nao sera mais utilizada
   // decimal_to_Binary_neg("-2");
    char* str = "add";
    Type_I binary_I;
    Type_R binary_R;
    Type_S binary_S;
    Type_B binary_B;
    FILE *fp;
    fp = fopen("./stdin/binary.txt", "ra+");
    while (1){
        if (!le_Linha(arq_Entrada, vetor_I, vetor_R, vetor_S, vetor_B, &binary_I, &binary_R, &binary_S, &binary_B)) break;
        
    };
    
    fclose(arq_Entrada); //Fecha o arquivo de entrada, visto que nao vai ser mais utilizado
    
    return 0;
}