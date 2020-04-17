#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void *funtion1();
void *funtion2();
void *funtion3();
pthread_mutex_t First_mutex;
pthread_mutex_t Second_mutex;
pthread_mutex_t Third_mutex;
int main(){
pthread_mutex_init(&First_mutex,NULL);
pthread_mutex_init(&Second_mutex,NULL);
pthread_mutex_init(&Third_mutex,NULL);
pthread_t one,two,three;
pthread_create(&one,NULL,funtion1,NULL);
pthread_create(&two,NULL,funtion2,NULL);
pthread_create(&three,NULL,funtion3,NULL);
pthread_join(one,NULL);
pthread_join(two,NULL);
pthread_join(three,NULL);
printf("Threads joined:\n");
}
void *funtion1(){
pthread_mutex_lock(&First_mutex);
printf("Thread One acquired first_mutex\n");
sleep(1);
pthread_mutex_lock(&Second_mutex);
printf("Thread One acquired second_mutex\n");
sleep(1);
pthread_mutex_lock(&Third_mutex);
printf("Thread One acquired third_mutex\n");
pthread_mutex_unlock(&Third_mutex);
printf("Thread One released third_mutex\n");
pthread_mutex_unlock(&Second_mutex);
printf("Thread One released second_mutex\n");
pthread_mutex_unlock(&First_mutex);
printf("Thread One released first_mutex\n");
}
void *funtion2(){
pthread_mutex_lock(&Second_mutex);
printf("Thread Two acquired second_mutex\n");
sleep(1);
pthread_mutex_lock(&Third_mutex);
printf("Thread Two acquired third_mutex\n");
sleep(1);
pthread_mutex_lock(&First_mutex);
printf("Thread Two acquired first_mutex\n");
pthread_mutex_unlock(&First_mutex);
printf("Thread Two released first_mutex\n");
pthread_mutex_unlock(&Third_mutex);
printf("Thread Two released third_mutex\n");
pthread_mutex_unlock(&Second_mutex);
printf("Thread Two released second_mutex\n");
}
void *funtion3(){
pthread_mutex_lock(&Third_mutex);
printf("Thread Three acquired third_mutex\n");
sleep(1);
pthread_mutex_lock(&First_mutex);
printf("Thread Three acquired first_mutex\n");
sleep(1);
pthread_mutex_lock(&Second_mutex);
printf("Thread Three acquired second_mutex\n");
pthread_mutex_unlock(&Second_mutex);
printf("Thread Three released second_mutex\n");
pthread_mutex_unlock(&First_mutex);
printf("Thread Three released first_mutex\n");
pthread_mutex_unlock(&Third_mutex);
printf("Thread Three released third_mutex\n");
}

