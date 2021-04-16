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
#include <dirent.h>

char* potong (char* s){
    int n;
    int i;
    char* new;
    for (i = 0; s[i] != '\0'; i++);
    // lenght of the new string
    n = i - 4 + 1;
    if (n < 1)
        return NULL;
    new = (char*) malloc (n * sizeof(char));
    for (i = 0; i < n - 1; i++)
        new[i] = s[i];
    new[i] = '\0';
    return new;
}

void execute(char perintah[],char *argv[])
{
    pid_t child_id;
    int status;

    child_id=fork();

    if(child_id==0)
    {
        execv(perintah, argv);
    }

    else
    {
        while ((wait(&status))>0);
    }
}

void unzip()
{
    pid_t child_id;
    child_id = fork();
    int status;
    char asal[100] = "/home/raffi/Downloads/pets.zip";
    char tujuan[100] = "/home/raffi/modul2/petshop";

    if(child_id<0)
    {
       exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti 
    }

    if (child_id==0)
    {
        char *argv[] = {"mkdir","-p",tujuan,NULL};
        execute("/bin/mkdir", argv);
    }

    else {
        while ((wait(&status))>0);
        char *argv2[] = {"unzip","-q",asal,"-x","*/*","-d",tujuan,NULL};
        //-x berfungsi untuk exclude dimana */* untuk file folder. Sehingga folder tidak ter zip.
        execute("/bin/unzip", argv2); 
    }
}

void mkfolderhewan()
{
    pid_t child_id;
    child_id = fork();
    int status;
    if(child_id<0)
    {
       exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti 
    }

    if (child_id==0)
    {
    DIR *dp;
    char path[100] = "/home/raffi/modul2/petshop";
    dp = opendir(path);
        if (dp != NULL)
        {
            struct dirent *ep;
            while((ep = readdir(dp))!= NULL)
            {   
                if(ep->d_type == DT_REG)
                {
                    int i;
                    char *temp1,*temp2,*temp3,*temp4;
                    char *namafile=ep->d_name;
                    char *namabaru=potong(namafile);
                    char copy1[100], copy2[100], copy3[100];
                    char base2[100], base3[100];
                    char hewan[100], nama[100], umur[100];
                    for(temp1=strtok_r(namabaru,"_",&temp3);\
                        temp1!=NULL; temp1=strtok_r(NULL,"_",&temp3))
                    {
                        i=0;
                        char base[100]="/home/raffi/modul2/petshop/";
                        
                        strcpy(copy1, ep->d_name);
                        strcpy(base2, base);
                        strcpy(base3, base);
                        strcpy(copy2, ep->d_name);
                        strcpy(copy3, ep->d_name);
                        for(temp2=strtok_r(temp1,";",&temp4);\
                        temp2!=NULL; temp2=strtok_r(NULL,";",&temp4))
                            {
                                if(i==0)
                                strcpy(hewan,temp2);
                                if(i==1)
                                strcpy(nama,temp2);
                                if(i==2)
                                strcpy(umur,temp2);
                                i=i+1;
                            }
                        

                        //2b
                        strcat(base,hewan);
                        char *argmk[]={"mkdir","-p",base,NULL};
                        execute("/bin/mkdir",argmk);
                        
                        //2e sementara
                        char txtloc[100],txtpath[100];
                        strcpy(txtloc,base);
                        stpcpy(txtpath,txtloc);

                        char namaditxt[100], isi[100];
                        strcpy(namaditxt,nama);

                        //2c
                        //memindahkan ke folder
                        strcat(nama,".jpg");
                        strcat(base2,copy2);
                        
                        char *copytofolder[]={"cp","-r", base2, base, NULL};
                        execute("/bin/cp",copytofolder);

                        //merubah nama
                        strcpy(base3,base);
                        strcat(base3,"/");
                        strcat(base3,copy2);
                        strcat(base,"/");
                        strcat(base,nama);
                        char *rename[]={"mv",base3,base,NULL};
                        execute("/bin/mv",rename);
                        
                        //2e
                        strcat(txtpath,"/keterangan.txt");
                        strcpy(isi,"nama : ");
                        strcat(isi,namaditxt);
                        strcat(isi,"\n");
                        strcat(isi,"umur : ");
                        strcat(isi,umur);
                        strcat(isi,"tahun\n\n");
                        FILE *fptr=fopen(txtpath,"a");
                        fputs(isi,fptr);
                        fclose(fptr);
                    }
                }
                //menghapus file yang telah dipindah
                if(ep->d_type == DT_REG)
                {
                    char source[99]="/home/raffi/modul2/petshop/";
                    strcat(source,ep->d_name);
                    char *removefile[]={"rm","-rf",source,NULL};
                    execute("/bin/rm",removefile);
                }
            }
        }
    (void) closedir (dp);
    }
    else {
        while ((wait(&status))>0);
    }
}

int main()
{
    pid_t child_id;
    int status;
    child_id=fork();

    if(child_id<0)
    {
        exit(EXIT_FAILURE);//kl gagal membuat proses baru, program akan berhenti
    }

    if(child_id == 0)
    {
        unzip();
        mkfolderhewan();
    }

    else{
        //ini ortu
       while ((wait(&status))>0);
       
    }
    
    
    return 0;
}
