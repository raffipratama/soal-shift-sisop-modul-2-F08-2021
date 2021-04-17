#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <time.h>

int main() {
  pid_t pid,sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
  
        pid_t child_id;
		int status;

        child_id = fork();

        if (child_id < 0) {
            exit(EXIT_FAILURE);
        }

        if (child_id == 0) {
            pid_t child_id2;
            int status_2;

            child_id2 = fork();
            
            if (child_id2 < 0) {
            exit(EXIT_FAILURE);
            }

            if (child_id2 ==0 ){
            char *argv[] = {"mkdir", "-p", "Musyik","Fylm","Pyoto" ,NULL};
            execv("/usr/bin/mkdir", argv);}

            else{
               while ((wait(&status_2)) > 0);
               pid_t child_id3;
               int status3;

               child_id3 = fork();

               if (child_id3 < 0) {
                exit(EXIT_FAILURE);
                }

                if (child_id3 ==0 ){
                    pid_t child_id4;
                	int status4;

                    child_id4=fork();
               	 
                	if(child_id4<0) {
                    exit(EXIT_FAILURE);
                    }
               	 
                	if(child_id4==0){
                    	pid_t child_id5;
                    	int status5;

                        child_id5=fork();

                    	if(child_id5<0) {
                        exit(EXIT_FAILURE);
                        }
                   	 
                    	if(child_id5==0){
                        	pid_t child_id6;
                        	int status6;

                            child_id6=fork();
                       	 
                        	if(child_id6<0) {
                            exit(EXIT_FAILURE);
                            }
                       	 
                        	if(child_id6==0){
                               	char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Foto_for_Stevany.zip", NULL};
                            	execv("/usr/bin/wget",argv);
                        	}
                        	else{
                            	while((wait(&status6)) > 0);
                            	char *argv[] = {"unzip","Foto_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
                            	execv("/usr/bin/unzip", argv);
                        	}
                    	}
                    	else{
                        	while((wait(&status5)) > 0);
                        	pid_t child_id7;
                        	int status7;

                            child_id7=fork();
                       	 
                        	if(child_id7<0) {
                            exit(EXIT_FAILURE);
                            }
                       	 
                        	if(child_id7 == 0){
                            	char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","Musik_for_Stevany.zip", NULL};
                            	execv("/usr/bin/wget", argv);
                        	}
                        	else{
                            	while((wait(&status7)) > 0);
                            	char *argv[] = {"unzip","Musik_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
                            	execv("/usr/bin/unzip", argv);
                        	}
                    	}
                	}
                	else{
                    	while((wait(&status4)) > 0);
                    	pid_t child_id8;
                    	int status8;

                        child_id8 = fork();

                    	if(child_id8<0) {
                        exit(EXIT_FAILURE);
                        }

                    	if(child_id8 == 0){
                        	char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","Film_for_Stevany.zip", NULL};
                           	execv("/usr/bin/wget", argv);
                    	}
                    	else{
                        	while((wait(&status8)) > 0);
                        	char *argv[] = {"unzip","Film_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
                        	execv("/usr/bin/unzip", argv);
                    	}
                	}
               	}
               	else{
                   	while((wait(&status3)) > 0);
                   	pid_t child_id9;
                   	int status9;
                  	
                    child_id9 = fork();
                   	
                    if(child_id9<0) {
                    exit(EXIT_FAILURE);
                    }

                   	if(child_id9==0){
                       	pid_t child_id10;
                       	int status10;

                        child_id10 = fork();
                      	 
                       	if(child_id10<0) {
                        exit(EXIT_FAILURE);
                         }

                    	if(child_id10==0){
                        	char *argv[] = {
								"find", 
								"/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/FOTO", 
								"-type",
								"f",
								"-exec",
								"mv",
								"{}",
								"/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/Pyoto",
								";", 
								NULL};
                        	execv("/usr/bin/find", argv);
                    	}
                    	else{
                        	while((wait(&status10)) > 0);
                        	char *argv[] = {
								"find", 
								"/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/FILM", 
								"-type",
								"f",
								"-exec",
								"mv",
								"{}",
								"/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/Fylm",
								";", 
								NULL};
                        	execv("/usr/bin/find", argv);
                    	}
                	}
                	else{
                    	while((wait(&status9)) > 0);
                    	char *argv[] = {
							"find",
							"/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/MUSIK",
							"-type",
							"f",
							"-exec",
							"mv",
							"{}",
							"//home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/Musyik",
							";", 
							NULL};
                    	execv("/usr/bin/find", argv);
                	}
            	}
        	}
         
    	}else{
			while((wait(&status)) > 0);
		}
	}
}

 
