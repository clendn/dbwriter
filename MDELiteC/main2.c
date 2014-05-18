///* 
// * File:   main.c
// * Author: froogynamHD
// *
// * Created on May 14, 2014, 2:15 PM
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "DBWriter.h"
//
///*
// * 
// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DBWriter.h"
#include "hashmap.h"

typedef char* string;

int main(int argc, char** argv) {
    string test[4];
    test[0] = strdup("one");
    test[1] = strdup("two");
    test[2] = strdup("three");
    test[3] = strdup("four");
    hashmap *PeterFroggy; 
    PeterFroggy = mk_hmap(str_hash_fn, str_eq_fn, str_del_fn);
    __hmap_add(PeterFroggy,"id1",test);
    string *test2;
    test2 = __hmap_get(PeterFroggy, "id1");
    int i = 0;
    while(i < 4){
        printf("%s\n", test2[i]);        
        i++;        
    }
    
    test[0] = strdup("five");
    test[1] = strdup("six");
    test[2] = strdup("sevem");
    test[3] = strdup("maeight");
    __hmap_add(PeterFroggy,"id2",test);
    
    test2 = __hmap_get(PeterFroggy, "id2");
    i = 0;
    while(i < 4){
        printf("%s\n", test2[i]);        
        i++;        
    }
    test2 = __hmap_get(PeterFroggy, "id1");
    i = 0;
    while(i < 4){
        printf("%s\n", test2[i]);        
        i++;        
    }

    
    return (1);
}

