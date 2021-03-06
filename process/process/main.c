//
//  main.c
//  process
//
//  Created by kuang junlin on 2019/3/27.
//  Copyright © 2019 kuang junlin. All rights reserved.
//
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    /**
     输出线程的标识符，然后退出。
     **/
    
    printf("Hello World.Greetings from thread %d0",tid);
    pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
    /**
        主程序创建10个线程，然后退出。
     **/
    pthread_t threads[NUMBER_OF_THREADS];
    int status,i;
    
    for (i = 0; i< NUMBER_OF_THREADS; i++) {
        printf("Main here. Creating thread %d0 \n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
        
        if (status != 0) {
            printf("Oops.pthread_create returned error code %d0 \n", status);
            exit(-1);
        }
    }
    exit(NULL);
}
