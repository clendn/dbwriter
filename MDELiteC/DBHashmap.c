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
//typedef char* string;
//
//typedef struct{
//    string name;
//    int size;
//    int tuples;
//    string metadata[MAX_TUPLES];
//    hashmap *map;    
//} table;
//
//    int get_number_of_tables(string a);   
//    table* readFile(string a);
//    void writeFile(string file);    
//    void navigate(table t[MAX_TABLES]);    
//    int readTableInput(table t[MAX_TABLES]);
//    void printTable(table t);
//    void printColumns(table t);
//    int writeTable(FILE *out);
//    int writeTuples(FILE*out, table current);    
//    string stripNewline(string str);
//    void joinTables(table t[MAX_TABLES]);
//    void printTableDefinition(table t);
//    string* getTuple(table t, string ID);
//
//int main(int argc, char* argv[]) {
//    table* t;
//    if(argv[1] != NULL){        
//        t = readFile(argv[1]);
//    }
//    int k = sizeof(t)-2;
//    printf("size: %d\n", k);
//    int i = 0;
////    for(; i < k; i++){
////        printf("%s\n", t[i].name);
////    }
////    string *tuple; 
////    tuple = __hmap_get(t[0].map, "classnode0");
////    for(i = 0; i < t[0].size; i++){
////        printf("%d %s\n", i, tuple[i]);
////    }
////    printf("\n");
//    return (1);
//}
//
//table* readFile(string a){
//    int num_tables; 
//    num_tables = get_number_of_tables(a);    
//    table t[num_tables];
//    FILE *inputFile;
//    string token;    
//    inputFile = fopen(a, "r");
//    string line = malloc(MAX_LINE_SIZE);
//    int buffer[1];
//    int top = -1;
//    string ID;    
//    //****end vars****
//    while(fgets(line, MAX_LINE_SIZE, inputFile) != NULL){        
//        //if not a tuple or table, skip line
//        token = strtok(line, "(,]).");
//        if(!strncmp(token, ":",1) || !strcmp(token, " ")){
//            while(token != NULL){
//                token = strtok(NULL, "(,]).");
//            }
//        }
//        int i = 0        
//        if(token != NULL){//add new tuple
//            if(top >= 0 && !strcmp(token, t[top].name)){
//                string tuple[MAX_TUPLES];
//                string tuple2[MAX_TUPLES];
//                i = 0;
//                t[top].tuples++;
//                token = strtok(NULL, "(,]).");                
//                ID = strdup(token);
//                for(;i <= t[top].size; i++){
//                    tuple[i] = strdup(token);//copy tuple into string[] buffer
//                    token = strtok(NULL, "(,]).");
//                }
//                
//                __hmap_add(t[top].map, ID, tuple);                   
//                string *a = __hmap_get(t[top].map, ID);
//                i=0;
//                for(;i < t[top].size; i++){
//                    printf("Afield %d: %s\n", i, a[i]);
//                }
//                
//                string *b = __hmap_get(t[top].map, "classnode0");
//                i = 0;
//                for(;i < t[top].size; i++){
//                    printf("Bfield %d: %s\n", i, b[i]);
//                }
//            }
//            //create new table by copying metadata from table declaration, 
//            //make map from ID to string[] tuple
//            else if(!strcmp(token, "table") || !strcmp(token, "%table")){                
//                top++;
//                t[top].name = strdup(strtok(NULL, "(,]). "));
//                t[top].map = mk_hmap(str_hash_fn, str_eq_fn, str_del_fn);
//                token = strtok(NULL, "(,]). ");
//                while(token != NULL){
//                    if(i == 0)
//                        t[top].metadata[i] = strdup(++token);
//                    else
//                        t[top].metadata[i] = strdup(token);
//                    token = strtok(NULL, "(,]). ");
//                    i++;
//                }
//                t[top].size = i-1;                
//            }
//        }
//    }
//    int j = 0;
//    for(j = 0; j < num_tables; j++){
//        printf("%d: %s\n", j, t[j].name);
//    }
//    
//    fclose(inputFile);
//    free(line); 
//    
//    return t;
//}
//
//int get_number_of_tables(string a){    
//    FILE *in = fopen(a, "r+");
//    string line = malloc(MAX_LINE_SIZE);
//    string counter;
//    int k = 0;
//    while(fgets(line, MAX_LINE_SIZE, in) != NULL){
//        counter = strtok(line, "(,]).");              
//        if(!strcmp(counter, "table") || !strcmp(counter, "%table")){
//            k++;
//        }        
//    }
//    fclose(in);
//    free(line);
//    return k;
//}
//
//string* getTuple(table t, string ID){
//    return __hmap_get(t.map, ID);
//}