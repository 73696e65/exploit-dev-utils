#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

char sc[]= "your shellcode here";

int main(){
        void * a = mmap(0, 4096, PROT_EXEC |PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
        printf("allocated executable memory at: %p\n", a);
        ((void (*)(void)) memcpy(a, sc, sizeof(sc)))();
}
