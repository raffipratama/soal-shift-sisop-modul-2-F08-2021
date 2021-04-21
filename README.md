# soal-shift-sisop-modul-2-F08-2021 

## Anggota Kelompok :
Anggota | NRP
--------|-------------
M. Rayhan Raffi P. | 05111940000110
M. Akmal Joedhiawan | 05111940000125
Nur Moh. Ihsanuddien | 05111940000142

## Penjelasan NO 1
**a** Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama
folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg

```
char *argv[] = {"mkdir", "-p", "Musyik","Fylm","Pyoto" ,NULL};
execv("/usr/bin/mkdir", argv);}
```
Keterangan : 
- Pada proses child paling awal dilakukan dengan menggunakan execv untuk mengeksekusi sesuai dengan didalam argv yaitu membuat folder Fylm,Pyoto, dan Musyik

**b** untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link
dibawah juga :).


```
#Foto
	char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Foto_for_Stevany.zip", NULL};
  execv("/usr/bin/wget",argv);
```

```
#Film
char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","Film_for_Stevany.zip", NULL};
execv("/usr/bin/wget", argv);
```

```
#Musik
char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","Musik_for_Stevany.zip", NULL};
execv("/usr/bin/wget", argv);
```

Keterangan : 
-Pada tiap-tiap perintah menggunakan execv untuk mengeksekusi dengan isi dalam char * argv sesuai yang telah diberikan di soal untuk mendonwload konten berformat zip

**c**Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu
meng-extract-nya setelah didownload serta

```
#Foto
char *argv[] = {"unzip","Foto_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
execv("/usr/bin/unzip", argv);
```

```
#Film
char *argv[] = {"unzip","Film_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
execv("/usr/bin/unzip", argv);
```

```
#Musik
char *argv[] = {"unzip","Musik_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
execv("/usr/bin/unzip", argv);
```
Keterangan :
- Unzip dilakukan dengan menggunakan execv untuk mengeksekusi perintah dalam argv dimana unzip file (namafile).zip dan dilakukan di direktori yang dimasukkan 

## Penjelasan NO 2 
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

### 2a
**soal :** Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

fungsi execute :
```c
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
```

fungsi unzip :
```c
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
```

Penjelasan :
- Pertama fungsi unzip, dimana dijalankan `mkdir` dengan dengan tujuan `/home/raffi/modul2/petshop` (`execv`dijalankan pada fungsi execute).
- lalu file di unzip pada alamat asal `/home/raffi/Downloads/pets.zip` dengan pengecualian (`-x`) tidak mengunzip folder (`*/*`) kepada alamat `/home/raffi/modul2/petshop`.

### 2b
**soal :** Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam “/petshop/cat”, jenis peliharaan kura-kura akan disimpan dalam “/petshop/turtle”.
```c
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
```
Penjelasan :
- Pertama kita membuka directory `/home/raffi/modul2/petshop` lalu di cek isinya. 
- Diambil string pertama sebelum `;` dimana string tersebut merupakan jenis hewan yang akan dijadikan folder.
- Lalu jenis hewan tersebut dijadikan folder dengan menggunakan `mkdir`.

### 2c
**soal :** Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
Contoh: “/petshop/cat/joni.jpg”.
```c
//2c
//memindahkan ke folder
strcat(nama,".jpg");
strcat(base2,copy2);                   
char *copytofolder[]={"cp","-r", base2, base, NULL};
execute("/bin/cp",copytofolder);

//ganti nama
strcpy(base3,base);
strcat(base3,"/");
strcat(base3,copy2);
strcat(base,"/");
strcat(base,nama);
char *rename[]={"mv",base3,base,NULL};
execute("/bin/mv",rename);
```
Penjelasan :
- Pertama digabungkan string `nama` yang diambil dengan `.jpg`lalu base2 dibuat menjadi alamat tujuan.
- Dipindahkan file ke dalam folder menggunakan `cp`.
- Lalu diubah namanya menjadi `nama.jpg` pada proses rename menggunakan `mv`.

### 2c
**soal :** Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.

fungsi untuk memotong string `.jpg` dimana terletak di 4 character belakang :
```c
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
```
### 2d
**soal :** Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.

loop yang digunakan untuk memotong string saat bertemu char `_` dan `;`:
```c
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
```
Penjelasan :
- Loop pertama dipisahkan string hewan pertama dan kedua dengan pemisah char `_`.
- Loop kedua dipisahkan antar kata dengan pemisah char `;`.

### 2e
**Soal :*** Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.
```c
//2e sementara
char txtloc[100],txtpath[100];
strcpy(txtloc,base);
stpcpy(txtpath,txtloc);
			
/2e
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
```
penjelasan :
- String `txtpath` merupakan alamat keterangan.txt.
- String `isi` berisi konten yang akan dipush ke file keterangan. Dimana terdapat serangkaian proses strcat untuk menginputkan nama dan juga umur hewan.
- Lalu String `isi` dipush ke `txtpath` menggunakan `"a"` agar string yang lama tidak terhapus.

Lalu setelah serangkaian proses dijalankan hal yang terakhir dilakukan adalah menghapus file foto yang telah diproses :
```c
//menghapus file yang telah dipindah
                if(ep->d_type == DT_REG)
                {
                    char source[99]="/home/raffi/modul2/petshop/";
                    strcat(source,ep->d_name);
                    char *removefile[]={"rm","-rf",source,NULL};
                    execute("/bin/rm",removefile);
                }
```
## Penjelasan NO 3 

