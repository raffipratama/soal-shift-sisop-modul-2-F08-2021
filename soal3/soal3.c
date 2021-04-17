#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>

char caesarcipher(char* msg, int shift)
{	
	int i;
	char word;
	for(int i = 0; msg [i] != '\0'; ++i)
	{
		word=msg[i];
		if (word >= 'A' && word <= 'Z') // untuk huruf Uppercase
		{
			word = word + shift;
			if (word > 'Z')
				{	
					word = word - 'Z' + 'A' - 1;
				}
			msg[i] = word;
		}
		else if (word >= 'a' && word <= 'z') // untuk huruf lowercase
		{
			word = word + shift;
			if (word > 'z')
				{	
					word = word - 'z' + 'a' - 1;
				}
			msg[i] = word;
		}
	}	
}


int main(int argc, char **argv) 
{
	if (argc != 2) {
	exit(EXIT_FAILURE);
  	}

	pid_t pid, sid;        // Variabel untuk menyimpan PID

	pid = fork();     // Menyimpan PID dari Child Process

	/* Keluar saat fork gagal
	* (nilai variabel pid < 0) */
	if (pid < 0) 
	{
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

	if ((chdir("/")) < 0) {
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	// 3E. Membuat mode Killer menggunakan bash
	char killername[100];
	strcpy(killername, "/home/akmal/Akmal/killer.sh");
	FILE *killer = fopen(killername, "w");

	if(strcmp(argv[1], "-z") == 0) {
		fprintf(killer, "#!/bin/bash\nkillall -9 soal2\nrm %s", killername);
	}
	else if(strcmp(argv[1], "-x") == 0) {
                fprintf(killer, "#!/bin/bash\nkill %d\nrm %s", getpid(), killername);
        }
	else {
		fclose(killer);
		exit(EXIT_FAILURE);
	}

	pid_t pidk = fork();
	if(pidk == 0) {
		char *arg[]={"chmod","x",killername,NULL};
		execv("/bin/chmod", arg);
	}
	fclose(killer);

	char pesan[120] = "Download Success";
	while(1) {
		char foldername[100] = "/home/akmal/Akmal/";
        	char strtime[100];
        	time_t t_folder = time(NULL);
        	struct tm *t = localtime(&t_folder);
        	strftime(strtime, sizeof(foldername)-1, "%Y-%m-%d_%H:%M:%S", t);
        	strcat(foldername,strtime);

		pid_t pid1 = fork();
        	int status1;
        	if(pid1 == 0) {
			pid_t pid2 = fork();
			int status2;
			if(pid2 == 0) {
				// 3A. membuat direktori file
                		char *arg1[]={"mkdir",foldername,NULL};
				execv("/bin/mkdir", arg1);
        		}
        		else { // 3B. Mendownload 10 gambar
        			while((wait(&status2)) > 0);
				for(int i=0; i<10; i++) {
					pid_t pid3 = fork();
					if(pid3 == 0) {
						time_t t_file = time(NULL);
			                	struct tm *tp = localtime(&t_file);

			                        char filename[100];
	        		                strcpy(filename, foldername);
						strcat(filename,"/");
						
						char timefilename[100];
	                	             	strftime(timefilename, sizeof(timefilename)-1, "%Y-%m-%d_%H:%M:%S", tp);
						strcat(filename, timefilename);

                	                	char stime[10];
	                        	        strftime(stime, sizeof(stime)-1, "%S", tp);
        	                        	int st = atoi(stime);
                	                	st = (st%1000)+50; // set size dan pixel

	                                	sprintf(stime, "%d", st);

	                                	char link[100];
		                                strcpy(link,"https://picsum.photos/");
        		                        strcat(link,stime);

						char *arg2[]={"wget","-O",filename,link,NULL};
        	                		execv("/usr/bin/wget", arg2);
					}
					sleep(5);
				}
				
				//3C. Membuat file status.txt
				char status[120];
				sprintf(status,"%s/status.txt",foldername);
				caesarcipher(pesan,5);
				FILE *download = fopen(status,"w");
				fprintf(download,"%s",pesan);
				fclose(download);
				//3C. Melakukan zip file
				pid_t pid4 = fork();
				int status4;
				if(pid4 == 0) {
					char zipname[120];
					strcpy(zipname, foldername);
					strcat(zipname,".zip");
					char *arg3[]={"zip","-j","-r","-m",zipname,foldername,NULL};
					execv("/usr/bin/zip",arg3);
				}
				// Menghapus folder
				else { 
					while((wait(&status4)) > 0);
					char *arg4[]={"rm","-d",foldername,NULL};
					execv("/bin/rm",arg4);
				}
			}
		}
                sleep(40);
	}
}