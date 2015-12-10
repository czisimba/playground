//
//  main.c
//  multi_thread_test
//
//  Created by nichola on 15/12/8.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

static int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_spinlock_t spinlock;
void* func(void *param) {
    clock_t start, finish;
    double duration;
    
    pthread_mutex_lock(&mutex);
    start = clock();
    for (int i = 0; i < 500000000; ++i) {
        ++count;
    }
    finish = clock();
    pthread_mutex_unlock(&mutex);
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("cost time :%f\n", duration);
    
    return NULL;
}
void* func1(void *param) {
    clock_t start, finish;
    double duration;
    start = clock();
    for (int i = 0; i < 500000000; ++i) {
        ++count;
    }
    finish = clock();
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("cost time :%f\n", duration);
    
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t thread1,thread2;
    pthread_create(&thread1, 0, func1, 0);
    pthread_create(&thread2, 0, func1, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    
    return 0;
}
