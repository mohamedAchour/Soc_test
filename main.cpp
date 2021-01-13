#include <errno.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    clock_t t;
    t=clock();

    for(int i=0;i<1000;++i)
    {
        int fd = open("/sys/class/leds/fpga_led4/brightness", O_WRONLY);
        if (fd == -1) 
        {
            /*perror() affiche un message sur la sortie d'erreur standard,
            décrivant la dernière erreur rencontrée durant un appel système ou une fonction de bibliothèque.*/ 
            
            perror("Ne peut pas ouvrir le fichier /sys/class/leds/fpga_led4/brightness");
            exit(1); //EXIT_FAILURE
        }
        
        write(fd, "1",1); 

        close(fd);
    }    
    
    t=clock()-t;
    cout<<"Temps d'execution en cpp: ---"<<((float)t)/CLOCKS_PER_SEC<<" seconds ---\n"<<endl;

    return 0;
}