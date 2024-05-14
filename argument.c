#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void* function1()
{
puts ("первая функция запустилась") ;
sleep(5);
puts("Первая функция завершилась");
return NULL;
}
void* function2() {
puts("Вторая функция запустилась");
sleep(3);
puts("Вторая функция завершилась");
return NULL;
}
void error(char *msg){
fprintf(stderr, "&s: %s\n", msg, strerror(errno));
exit (1);
}
int main(){
       	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, function1, NULL);
	pthread_create(&t2, NULL, function2, NULL);
	if (pthread_create(&t2, NULL, function2, NULL) == -1)
		error("НЕ МОГУ СОЗДАТЬ ПОТОК t2");
	if (pthread_create(&t1, NULL, function1, NULL) == -1)
		error("НЕ МОГУ СОЗДАТЬ ПОТОК t1") ;
	void* result; 
	pthread_join(t1, &result);
	pthread_join(t2, &result);
	if (pthread_join(t1, &result) ==-1)
		error("Can't join thread t1");
	if (pthread_join(t2, &result) == -1)
		error("Can't join thread t2");
	return 0;
}
