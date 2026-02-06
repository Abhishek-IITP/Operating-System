#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void taskA(){
  for(int i =0;i<10;++i){
    sleep(1);
    printf("TaskA: %d\n",i);
    fflush(stdout);
  }
}

void taskB(){
  for(int i =0;i<10;++i){
    sleep(1);
    printf("TaskA: %d\n",i);
    fflush(stdout);
  }
}

int main(){

  thread t1(taskA); //task is divided into thread
  thread t2(taskB);

  //apply the waiting condition , jb tk t1 t2 complete ni ho jate mera main process wait krega
  t1.join();
  t2.join();
  return 0;
}
