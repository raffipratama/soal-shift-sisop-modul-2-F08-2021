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
char *argv1[] = {"mkdir", "-p", "Musyik","Fylm","Pyoto" ,NULL};
execv("/usr/bin/mkdir", argv1);}
```
Keterangan : 
- Pada proses child paling awal dilakukan dengan menggunakan execv untuk mengeksekusi sesuai dengan didalam argv yaitu membuat folder Fylm,Pyoto, dan Musyik

**b** untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link
dibawah juga :).


```
#Foto
char *argv2[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Foto_for_Stevany.zip", NULL};
execv("/usr/bin/wget",argv2);
```

```
#Film
char *argv6[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","Film_for_Stevany.zip", NULL};
execv("/usr/bin/wget", argv6);
```

```
#Musik
char *argv4[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","Musik_for_Stevany.zip", NULL};
execv("/usr/bin/wget", argv4);
```

Keterangan : 
-Pada tiap-tiap perintah menggunakan execv untuk mengeksekusi dengan isi dalam char * argv sesuai yang telah diberikan di soal untuk mendonwload konten berformat zip

**c** Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu
meng-extract-nya setelah didownload serta 
**d** memindahkannya ke dalam folder yang telah
dibuat (hanya file yang dimasukkan).

```
#Foto
char *argv3[] = {"unzip","-j","Foto_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/Pyoto", NULL};
execv("/usr/bin/unzip", argv3);;
```

```
#Film
char *argv7[] = {"unzip","-j","Film_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/Fylm", NULL};
execv("/usr/bin/unzip", argv7);
```

```
#Musik
char *argv5[] = {"unzip","-j","Musik_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1/Musyik", NULL};
execv("/usr/bin/unzip", argv5);
```
Keterangan :
- Pada 1c dan 1d dilakukan secara  bersamaan 
- untuk 1c meng-extract file.zip dilakukan dengan perintah unzip dimana menggunakan perintah execv pada /usr/bin/unzip
- untuk 1d file dalam zip ketika di-extract dapat langsung dipindahkan ke file diinginkan dengan menggunakan argumen "-j" setelah command unzip
- argumen "-d" digunakan untuk menaruh file ke direktori yang diinginkan untuk menaruh hasil extract

**e** Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum
waktu ulang tahun Stevany.

```
time_t currTm;
currTm = time(NULL);
struct tm currTime = *localtime(&currTm);

if( currTime.tm_sec==00 && currTime.tm_min==22 && currTime.tm_hour==16 && currTime.tm_mday==9 && currTime.tm_mon == 3){
}

```
Keterangan :
- Dengan menggunakan bantuan dari header time.h mengatur agar terdapat variabel yang berisikan informasi waktu di sistem
- Setelah itu untuk mengatur agar berjalan 6 jam sebelum Ulang Tahun stevany diatur dengan menggunakan percabangan dimana ketika info waktu yang ada di struct currTime sesuai yang diinginkan maka program akan dilaksanakan

**f** Setelah itu pada waktu ulang tahunnya Stevany, semua folder
akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya
menyisakan .zip)

```
#Dengan menggunakan perlanjutan dari percabangan sesuai pada 1e 

else if( currTime.tm_sec==00 && currTime.tm_min==22 && currTime.tm_hour==22 && currTime.tm_mday==9 && currTime.tm_mon == 3){
 ....
 char *argv8[]={"zip","-rm","Lopyu_Stevany.zip","Fylm","Musyik","Pyoto", NULL};
 execv("/usr/bin/zip",argv8);
 ....
}
```
Keterangan :
- Code akan berjalan ketika kondisi waktu sesuai dengan syarat percabangan yaitu pada 9 april pukul 22:22:00
- Zip file dilakukan dengan perintah zip pada execv dan menggunakan argumen "-r" akan dilakukan zip semua folder yang diinginkan beserta file isi didalamnya
- Argumen "-m" pada zip akan membuat folder dan file yang telah di zip akan dihapus oleh sistem setelah selesai menjadikannya dalam 1 file zip Lopyu_Stevany.zip

Kendala :
- mencari argumen/ command pada perintah eksekusi yang pas untuk hasil yang diinginkan
- terdapat kendala error saat melakukan perintah wget(donwload file) dimana request mendapat status forbidden 403 sehingga donwload file gagal. Terjadinya kendala donwload secara tidak menentu.
![WhatsApp Image 2021-04-24 at 18 43 08](https://user-images.githubusercontent.com/65032157/115995021-bb27ea00-a603-11eb-876b-a66905d868e3.jpeg)
 
 
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
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

**Daemon**
````
int main(int argc, char **argv){
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
}
````
Penjelasan : 
- Sebelum memulai, dibuat daemon terlebih dahulu untuk membuat parent id dan child id yang dibutuhkan untuk fork.

### 3A
**Soal :** Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].
````
while(1) {
		char foldername[100] = "/home/akmal/Akmal/";
        	char strtime[100];
        	time_t t = time(NULL);
        	struct tm *tm = localtime(&t);
        	strftime(strtime, sizeof(foldername), "%Y-%m-%d_%H:%M:%S", tm);
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
		sleep(40);
}
````
Penjelasan : 
- Membuat folder path yang akan dituju `char foldername[100] = "/home/akmal/Akmal/";`
- Membuat penamaan file menggunakan local time `struct tm *tm = localtime(&t);` dan mereturn string berbentuk tanggal `strftime(strtime, sizeof(foldername), "%Y-%m-%d_%H:%M:%S", tm);`
- Menyimpan string tanggal tersebut ke dalam foldername `strcat(foldername,strtime);`
- Melakukan fork untuk pid1 `pid_t pid1 = fork();` dan ketika pid1 == 0 melakukan fork untuk pid2 `pid_t pid2 = fork();`
- Membuat directory menggunakan penamaan foldername yang berisi string tanggal `char *arg1[]={"mkdir",foldername,NULL};`dan melakukan execv untuk menjalankannya `execv("/bin/mkdir", arg1);`dan hanya membuat directory setiap 40 detik `sleep(40);`

### 3B
**Soal :** Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.
````
else { // 3B. Mendownload 10 gambar
        			while((wait(&status2)) > 0);
				for(int i=0; i<10; i++) {
					pid_t pid3 = fork();
					if(pid3 == 0) {
						time_t t = time(NULL);
			                	struct tm *tp = localtime(&t);

			                        char filename[100];
	        		                strcpy(filename, foldername);
						strcat(filename,"/");
						
						char timefilename[100];
	                	             	strftime(timefilename, sizeof(timefilename), "%Y-%m-%d_%H:%M:%S", tp);
						strcat(filename, timefilename);

	                                	char link[100];
		                                sprintf(link,"https://picsum.photos/%d",(((int)t) % 1000) + 50);
        		          

						char *arg2[]={"wget","-qO",filename,link,NULL};
        	                		execv("/usr/bin/wget", arg2);
					}
					sleep(5);
				}
````
Penjelasan :
- ketika wait status > 0 maka akan melakukan perulangan dan melakukan fork untuk pid baru
- Membuat penamaan file menggunakan local time `struct tm *tp = localtime(&t);` dan mereturn string berbentuk tanggal `strftime(timefilename, sizeof(timefilename), "%Y-%m-%d_%H:%M:%S", tp);`
- Menyimpan string tanggal ke dalam filename `strcat(filename, timefilename);`
- Mengeprint gambar dari berupa link yang tersedia dan mengatur formatnya `sprintf(link,"https://picsum.photos/%d",(((int)t) % 1000) + 50);`
- Mendownload gambar yang ada menggunakan `char *arg2[]={"wget","-qO",filename,link,NULL};`dan menjalankannya `execv("/usr/bin/wget", arg2);`
- Karena ingin mendownload gambar setiap 5 detik `sleep(5);`

### 3C
**Soal :** Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

Fungsi Caesar Cipher 
````
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
````
Penjelasan :
- Untuk setiap huruf yang akan diinputkan akan dilakukan penjumlahan sesuai nilainya dan dijumlahkan dengan nilai shiftnya `word = word + shift;`
- Apabila nilai huruf melebihi nilai z maka akan direturn `word = word - 'Z' + 'A' - 1;` 
- Apabila telah selesai dienkripsi maka akan direturn hasil enkripsinya

````
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
````
Penjelasan : 
- Membuat status.txt `sprintf(status,"%s/status.txt",foldername);` 
- Melakukan hasil enkripsi pesan `caesarcipher(pesan,5);`
- Melakukan penulisan isi status.txt `fprintf(download,"%s",pesan);`
- Membuat pid4 dan dilakukan fork, kemudian membuat file zipname dengan menggunakan penamaan foldername `strcpy(zipname, foldername);`
- Melakukan proses zip `char *arg3[]={"zip","-j","-r","-m",zipname,foldername,NULL};` dan menjalankan prosesnya `execv("/usr/bin/zip",arg3);`
- Apabila wait status > 0 maka akan menghapus directory yang sebelumnya dibuat `char *arg4[]={"rm","-d",foldername,NULL};` dan menjalankannya `execv("/bin/rm",arg4);`

### 3D
**Soal :** Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.

````
	char killername[100];
	strcpy(killername, "/home/akmal/Akmal/killer.sh");
	FILE *killer = fopen(killername, "w");

	if(strcmp(argv[1], "-z") == 0) {
		fprintf(killer, "#!/bin/bash\nkillall -9 soal3\nrm %s", killername);
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
````
Penjelasan : 
- Membuat file killer.sh `strcpy(killername, "/home/akmal/Akmal/killer.sh");`
- Melakukan ceck argumen yang dimasukkan `if(strcmp(argv[1], "-z") == 0` atau `else if(strcmp(argv[1], "-x") == 0` jika tidak sama maka akan exit failure
- kemudian membuat fork dan membuat file killer.sh bisa dijalankan dalam bash `char *arg[]={"chmod","x",killername,NULL};` dan menjalankan program bash tersebut `execv("/bin/chmod", arg);`

### 3E
**Soal : ** Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dsdengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).
````
if(argc != 2 || (argv[1][1] != 'z' && argv[1][1] != 'x')) {
        printf("Mode hanya ada -z atau -x\n");
        exit(0);
        }
````
Penjelasan :
- Jika input yang diberikan bukan z atau x maka program tidak berjalan

Program killer -z
````
if(strcmp(argv[1], "-z") == 0) {
		fprintf(killer, "#!/bin/bash\nkillall -9 soal3\nrm %s", killername);
	}
````
Program killer -x 
````
else if(strcmp(argv[1], "-x") == 0) {
                fprintf(killer, "#!/bin/bash\nkill %d\nrm %s", getpid(), killername);
        }
````
Penjelasan : 
- Apabila program z dijalankan akan diprint dalam killer.sh `fprintf(killer, "#!/bin/bash\nkillall -9 soal3\nrm %s", killername);`
- Apabila program x dijalankan akan diprint dalam killer.sh `fprintf(killer, "#!/bin/bash\nkill %d\nrm %s", getpid(), killername);`

Kendala :
- Kesulitan ketika menemukan kesalahan kesalahan ketika program mendownload, akan tetapi hasil download ternyata tidak keluar
- Kesulitan ketika menemukan kesalahan directory tidak membuat directory setiap 40 detik
- Kesulitan ketika program killer dijalankan, namun killer masih belum berjalan
