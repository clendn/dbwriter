///*
// * File:   main.c
// * Author: froogynamHD
// *
// * Created on May 7, 2014, 3:22 PM
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "hashmap.h"
//#include "DBWriter.h"
//
//void joinTables(table t[MAX_TABLES]);
//void printTableDefinition(table t);
//
///*
// *
// */
////int main(int argc, char* argv[]) {
////    if(argv[1] != NULL){
////        if(!strcmp(argv[1], "-r")){
////            readFile(argv[2]);
////        }
////        else if(!strcmp(argv[1], "-w")){
////            writeFile(argv[2]);
////        }
////        else { printf("Use the command -r <input file> to read a database.\n            or -w <output file> to write to prolog db.\n");
////        }
////    }
////    else { printf("Use the command -r <input file> to read a database.\n            or -w <output file> to write to prolog db.\n");
////    }
////    return (EXIT_SUCCESS);
////}
//
//void readFile(string a){
//    table t[MAX_TABLES];
//    FILE *inputFile;
//    string token;
//    inputFile = fopen(a, "r");
//    string line = malloc(MAX_LINE_SIZE);
//    int buffer[1];
//    int top = -1;
//    //***end vars***
//    while(fgets(line, MAX_LINE_SIZE, inputFile) != NULL){
//        //if not a tuple or table, skip line
//        token = strtok(line, "(,]).");
//        if(!strncmp(token, ":",1) || !strcmp(token, " ")){
//            while(token != NULL){
//                token = strtok(NULL, "(,]).");
//            }
//        }
//        int i = 0;
//        if(token != NULL){//add new tuple
//            if(top >= 0 && !strcmp(token, t[top].name)){
//                i = 0;
//                t[top].tuples++;
//                token = strtok(NULL, "(,]).");
//                for(;i <= t[top].size; i++){
//                    t[top].cols[t[top].tuples][i] = strdup(token);
//                    token = strtok(NULL, "(,]).");
//                }
//
//            }
//            else if(!strcmp(token, "table") || !strcmp(token, "%table")){  //create new table
//                top++;
//                t[top].name = strdup(strtok(NULL, "(,]). "));
//                token = strtok(NULL, "(,]). ");
//                while(token != NULL){
//                    if(i == 0)
//                        t[top].cols[0][i] = strdup(++token);
//                    else
//                        t[top].cols[0][i] = strdup(token);
//                    token = strtok(NULL, "(,]). ");
//                    i++;
//                }
//                t[top].size = i-1;
//                
//            }
//        }
//    }
//    printf("Search: 1 | Print table: 2 ");
//    scanf("%d", buffer);
//    if(buffer[0] == 1){
//        joinTables(t);
//    }  
//    else if(buffer[0] == 2){
//        navigate(t);
//    }        
//
//    fclose(inputFile);
//    free(line);
//    
//}
//
//void navigate(table t[MAX_TABLES]){    
//    int buffer[1];
//    int tableNum = readTableInput(t);
//  
//    printTable(t[tableNum]);
//    printf("Choose different table? (1 for yes/0 for no)\n");
//    scanf("%d", buffer);
//    printf("\n");
//    if(buffer[0]){
//        navigate(t);
//    }    
//}
//
//int readTableInput(table t[MAX_TABLES]){
//    int i = 0;
//    int buffer[1];
//    
//    while(t[i].name != NULL){
//        printf("<%20s: %2d>\n",t[i].name, i);
//        i++;
//    }    
//    scanf("%d", buffer);
//    int tableNum = buffer[0];
//    while((tableNum < 0) || (tableNum > i-1)){
//        printf("invalid table number: \n");
//        tableNum = readTableInput(t);
//    }     
//    return buffer[0];
//}
//
//void joinTables(table t[MAX_TABLES]){
//    int buffer[1];
//    char str[100];
//    string query;
//    string joinID;
//    printf("Search which table?\n");    
//    table currentTable = t[readTableInput(t)];
//    printTableDefinition(currentTable);
//    printf("\n Which column?\n");
//    printColumns(currentTable);
//    scanf("%d", buffer);
//    int column = buffer[0];   
//    printf("%s: ", currentTable.cols[0][column]);
//    fgets(str, 256, stdin);
//    fgets(str, 256, stdin);
//    query = stripNewline(strdup(str));
//    
//    int i = 0;
//    printf("-------------\n");
//    while(currentTable.cols[i][column] != NULL){          
//        if(!strcmp(query, currentTable.cols[i][column])){
//            int j = 0;
//            for(; j < currentTable.size; j++){
//                printf("%s: %s\n", currentTable.cols[0][j], currentTable.cols[i][j]);
//            }  
//            break;
//        }
//        i++;
//    } 
//    joinID = strdup(currentTable.cols[i][0]);
//    printf("--------------\n");
//    printf("Join on which table?\n");
//    int joinRow = readTableInput(t);
//    table joinTable = t[joinRow];
//    
//    i = 1;
//    printf("%s\n", joinID);
//    while(joinTable.cols[i][0] != NULL){        
//        if(!strcmp(joinID, joinTable.cols[i][0])){
//            int j = 0;
//            printf("-------------\n");
//            for(; j < joinTable.size; j++){
//                    printf("%s: %s\n", joinTable.cols[0][j], joinTable.cols[i][j]);
//            }            
//        }
//        i++;
//    }
//    exit(1);
//}
//
//
//void printTable(table t){
//    printTableDefinition(t);
//    printf(")\n");
//    int i = 0;
//    if(t.tuples <=0){
//        printf("No Tuples (empty set)\n");
//    }
//    else{
//        for(i = 1; i <= t.tuples; i++){
//            printf("       %s(%s", t.cols[i][0], t.cols[i][1]);
//            int j = 2;
//            for(;j <= t.size; j++){
//                printf(", %s",t.cols[i][j]);
//            }
//        printf(")\n");
//        }
//    }    
//}
//
//void printColumns(table t){
//    int i = 0;
//    for(;i < t.size; i++){
//        printf("<%10s: %2d>\n",t.cols[0][i], i);
//    }
//}
//
//void printTableDefinition(table t){
//    printf("\nTable: %s(%s", t.name, t.cols[0][0]);
//    int i = 1;
//    for(;i < t.size; i++){
//        printf(", %s",t.cols[0][i]);
//    }
//}
//
//void writeFile(string output){
//    FILE *out;
//    char UserIn[100];
//    out = fopen(output, "w+");
//    int buffer[1];
//    int flag = 0;
//    
//    printf(":-style_check(-discontiguous).? <1 for yes> <0 for no>\n");
//    scanf("%d", buffer);
//    if(buffer[0]){
//        fprintf(out, "%s",":-style_check(-discontiguous).\n\n");
//    }
//    printf("type t for new table\n     q to quit\n");
//    fgets(UserIn, 100, stdin);//get rid of newline character
//    fgets(UserIn, 100, stdin);
//    if(!strncmp(UserIn, "t", 1)){
//        flag = writeTable(out);
//        while(flag){
//            fprintf(out, "\n");
//            fgets(UserIn, 100, stdin);
//            flag = writeTable(out);
//        }
//        fclose(out);
//    }
//    else if(!strncmp(UserIn, "q", 1)){
//        fclose(out);
//    }
//    else {
//        printf("Invalid entry.\n");
//        exit(-1);
//    }
//}
//    
//int writeTable(FILE *out){
//    char str[100];
//    int buffer[1];
//    table current;
//    int tuplets = 0;
//    //get table name------
//    printf("Name of new table: <:q to quit>\n");
//    fgets(str, 100, stdin);
//    if(!strcmp(stripNewline(strdup(str)), ":q")){
//        return 0;
//    }
//    current.name = stripNewline(strdup(str));
//    //get table size------
//    printf("How many fields? (1 - %d) ", MAX_TABLES);
//    scanf("%d", buffer);
//    if(buffer[0] < 1 || buffer[0] > MAX_TABLES){
//        printf("Invalid number of fields.\n");
//        exit(-1);
//    }
//    current.size = buffer[0];
//    //get field names-----
//    int i = 1;
//    fgets(str, 256, stdin);
//    current.cols[0][i] = stripNewline(strdup(str));
//    for(;i <= current.size; i++){
//        printf("Field %d: ", i);
//        fgets(str, 256, stdin);
//        current.cols[0][i] = stripNewline(strdup(str));
//    }
//    i = 1;
//    fprintf(out, "table(%s,[%s", current.name, current.cols[0][i]);
//    i++;
//    for(;i <= current.size; i++){
//        fprintf(out, ",%s", current.cols[0][i]);
//    }
//    fprintf(out, "]).\n");
//    
//    int flag = writeTuples(out, current);
//    while(flag){
//        tuplets++;
//        flag = writeTuples(out, current);
//    }
//    if(tuplets == 0){
//        fprintf(out, ":- dynamic umlfInterface/%d\n", current.size);
//    }
//    return 1;         
//}
//
//int writeTuples(FILE *out, table current){
//    int buffer[1];
//    char str[100];
//    printf("New tuple? <1 for yes, 0 for no> ");
//    scanf("%d", buffer);
//    if(!buffer[0]){
//        return buffer[0];
//    }
//    int i = 1;
//    printf("%s: ", current.cols[0][i]);
//    fgets(str, 256, stdin);
//    fgets(str, 256, stdin);
//    fprintf(out, "%s(%s", current.name, stripNewline(strdup(str)));
//    i++;
//    for(;i <= current.size; i++){
//        printf("%s: ", current.cols[0][i]);
//        fgets(str, 256, stdin);
//        fprintf(out, ",%s", stripNewline(strdup(str)));
//    }
//    fprintf(out, ").\n");
//    return buffer[0];
//}
//
//string stripNewline(string str){
//    if(str[strlen(str)-1] == '\n')
//        str[strlen(str)-1] = '\0';
//    return str;
//}
//
//
//
//
