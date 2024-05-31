#include "header.h"

bool ceklogin(string user, string pass){
	string temp="DuoLeveling";
	
	if(!strcmp(user, temp) && !strcmp(pass,strrev(temp))) return true;
	else return false;
}

void validasi(string captcha){
	int i, acak;
	char random_char;
	
	for (i = 0; i < 8; i++) {
		
		acak = rand()%(3-1+1)+1;
		
		if(acak == 1){
    		random_char = 'a' + rand() %26;
		}else if(acak == 2){
			random_char = 'A' + rand() %26;
		}else{
			random_char = '0' + rand() %10;
		}
		
    	sprintf(captcha + i, "%c", random_char);
	}
}

void roket(){
	int i;
	string temp;
	
	for(i=0; i<36 ; i++){
		system("cls");
		printf(
			"\t\t\t .--."
			"\n\t\t\t / /  `"  
			"\n\t\t\t+\t\t | |"
			"\n\t\t\t\t,\t   %c %c__,"
			"\n\t\t\t*\t\t+   %c--%c   *"
			"\n\t\t\t\t\t  +   /"
			"\n\t\t\t+\t\t    .%c  %c.   *"
			"\n\t\t\t\t  *\t   /======%c      +"	
			"\n\t\t\t\t\t  ;:.  _   ;"
			"\n\t\t\t\t\t  |:. (_)  |"
			"\n\t\t\t\t\t  |:.  _   |"
			"\n\t\t\t  +\t\t  |:. (_)  |\t\t*"
			"\n\t\t\t\t\t  ;:.      ;"
			"\n\t\t\t\t\t.' %c:.    / `."
			"\n\t\t\t\t       / .-%c%c:._.%c`-. %c"
			"\n\t\t\t\t       |/    /||%c    %c|"
			"\n\t\t\t\t    _..----.._"
			"\n\t\t\t\t_.-%c``\t\t\t``%c-._"
			"\n\t\t\t      -%c\t\t\t      %c-"
			"\n\t\t\t\t\t   Loading....\n\n", 92, 92, 39, 39, 39, 39, 92, 92, 39, 39, 39, 92, 92, 92, 39, 39, 39, 39,39
		);
		sprintf(temp + i ,"%s", ">");
		printf("\t\t\t    [%s", temp);
		if(i>1 && i <10){
			printf("\t\t\t\t ]");		
		}else if(i>=10 && i < 18){
			printf("\t\t\t ]");	
		}else if(i >=18 && i <26){
			printf("\t\t ]");	
		}else if(i >=26 && i <34){
			printf("\t ]");
		}else if(i >= 34 && i < 35){
		printf(" ]");
		}else if(i >=35){
			printf("]");
		}else{
			printf("\t\t\t\t\t ]");		
		}
		Sleep(100);
	}	
}

void showmenu(string user, int cek_tanggal, int cek_data, int D, int M, int Y, string id, string status_perbaikan){
	system("cls");
	system("color 09");
	printf(
		"\n\n        ---==[ BENGKEL ROKET GALAXY JAYA ]==---"
		"\n        Username : %s", user);
	if(cek_tanggal == 1){
		printf("\n        Tanggal  : %d-%d-%d", D, M, Y);
	}
	if(cek_data == 1){
		printf("\n        Perbaikan roket dengan ID %s %s", id, status_perbaikan);
	}	
	printf(
		"\n\n        [1] Isi Data"
		"\n        [2] Show Nota"
		"\n        [3] Mulai Perbaikan"
		"\n        [4] Isi Minyak"
		"\n        [5] Pembayaran"
		"\n        [6] Next Pelanggan"
		"\n        [ESC] Exit Program"
		"\n        >>> "
	);
}

void tipe_roket(string tipe){
	int acak;
	
	acak = rand()%(3-1+1)+1;
		
	if(acak == 1){
    	strcpy(tipe,"Superior");
	}else if(acak == 2){
		strcpy(tipe,"Standard");
	}else{
		strcpy(tipe,"Budgetan");
	}	
}

void jenis_kerusakan(string jenis){
	int acak;
	
	acak = rand()%(3-1+1)+1;
		
	if(acak == 1){
    	strcpy(jenis,"Struktural");
	}else if(acak == 2){
		strcpy(jenis,"Mesin");
	}else{
		strcpy(jenis,"Struktural dan Mesin");
	}
}

void tingkat_kerusakan(string tingkat){
	int acak;
	
	acak = rand()%(3-1+1)+1;
		
	if(acak == 1){
    	strcpy(tingkat,"Urgent");
	}else if(acak == 2){
		strcpy(tingkat,"Sedang");
	}else{
		strcpy(tingkat,"Ringan");
	}
}

void riwayat_pemakaian(int *pemakaian){
	*pemakaian = rand()%(150000-100000+1)+100000;
}

void kapasitas_minyak(int *kapasitas){
	*kapasitas = rand()%(9-5+1)+5;
}

void minyak_saatini(int *ini, int kapasitas){
	do{	
		*ini = rand()%(9-0+1)+0;
	}while(*ini >= kapasitas);
}

void keluhan_pelanggan(int pemakaian, int kapasitas, int ini, string tipe, string jenis, string tingkat){
	printf(
		"\n        ---==[ KELUHAN PELANGGAN ]==---"
		"\n        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"\n        Tipe Roket               : %s"
		"\n        Jenis Kerusakan          : %s"
		"\n        Tingkat Kerusakan        : %s"
		"\n        Riwayat Pemakaian Roket  : %d km"
		"\n        Kapasitas Minyak         : %d"
		"\n        Minyak saat ini          : %d"
		"\n        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"\n\n        ---==[ INPUT DATA PELANGGAN ]==---"
		"\n        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", tipe, jenis, tingkat, pemakaian, kapasitas, ini
	);
}

void input_data(string nama, string telp, string id, string tp, string jns, string tk, int riwayat, int kap, int count_nama, int count_telp, int count_id, int count_tipe, int count_jenis, int count_tingkat, int count_riwayat, int count_kapasitas){
	if(count_nama == 1){
		printf("\n        Nama Pelanggan           : %s", nama);
	}
	if(count_telp == 1){
		printf("\n        No Telp                  : %s", telp);	
	}
	if(count_id == 1){
		printf("\n        ID Roket                 : %s", id);	
	}
	if(count_tipe == 1){
		printf("\n        Tipe Roket Pelanggan     : %s", tp);		
	}
	if(count_jenis == 1){
		printf("\n        Jenis Kerusakan          : %s", jns);
	}
	if(count_tingkat == 1){
		printf("\n        Tingkat Kerusakan        : %s", tk);	
	}
	if(count_riwayat == 1){
		printf("\n        Riwayat Pemakaian Roket  : %d", riwayat);
	}
	if(count_kapasitas == 1){
		printf("\n        Kapasitas Minyak Roket   : %d", kap);	
	}
}

void semua_harga(string tipe, string jenis, string tingkat, int riwayat, int kapasitas, int ini, int *harga_tipe, int *harga_jns, int *kali_tingkat, int *kali_riwayat, int *pengisian, int *harga_pengisian, int *total_harga){
	int temp;
	if(!strcmpi(tipe,"Superior")){
		*harga_tipe = 30000000;
		*kali_riwayat = 2;
		
		if(!strcmpi(jenis,"Struktural") || !strcmpi(jenis,"Mesin")){
			*harga_jns = 20000000;
		}else{
			*harga_jns = 30000000;
		}
	}else if(!strcmpi(tipe,"Standard")){
		*harga_tipe = 20000000;
		
		if(riwayat > 110000){
			*kali_riwayat = 2;
		}else{
			*kali_riwayat = 1;
		}
		
		if(!strcmpi(jenis,"Struktural") || !strcmpi(jenis,"Mesin")){
			*harga_jns = 15000000;
		}else{
			*harga_jns = 28000000;
		}
	}else{
		*harga_tipe = 10000000;
		
		if(riwayat > 120000){
			*kali_riwayat = 2;
		}else{
			*kali_riwayat = 1;
		}
		
		if(!strcmpi(jenis,"Struktural") || !strcmpi(jenis,"Mesin")){
			*harga_jns = 10000000;
		}else{
			*harga_jns = 18000000;
		}
	}
	
	if(!strcmpi(tingkat,"Urgent")){
		*kali_tingkat = 3;
	}else if(!strcmpi(tingkat,"Sedang")){
		*kali_tingkat = 2;
	}else{
		*kali_tingkat = 1;
	}
	
	*pengisian = kapasitas - ini;
	
	*harga_pengisian = *pengisian * 1000 *1200;
	
	temp = (*harga_tipe + *harga_jns) * *kali_tingkat * *kali_riwayat;
	
	*total_harga = temp + *harga_pengisian;
}

void cetak_nota(string nama, string telp, string id, string tp, string jns, string tk, int harga_tipe, int harga_jns, int riwayat, int kali_tingkat, int kali_riwayat, int kapasitas, int minyak, int pengisian, int harga_pengisian, int total_harga){

	printf(
	        "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c  ---===[ NOTA PELANGGAN BENGKEL ROKET GALAXY JAYA ]===---  %c"
	        "\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
			218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191,
			179, 179, 
	        195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180
		);
	if(strlen(nama)<=8){
		printf("\n%c         ^         %c Nama Pelanggan : %s\t\t     %c", 179, 179, nama, 179);
	}else if(strlen(nama)>8 && strlen(nama)<=16){
		printf("\n%c         ^         %c Nama Pelanggan : %s\t     %c", 179, 179, nama, 179);
	}else if(strlen(nama)==17){
		printf("\n%c         ^         %c Nama Pelanggan : %s     %c", 179, 179, nama, 179);
	}else if(strlen(nama)==18){
		printf("\n%c         ^         %c Nama Pelanggan : %s    %c", 179, 179, nama, 179);
	}else if(strlen(nama)==19){
		printf("\n%c         ^         %c Nama Pelanggan : %s   %c", 179, 179, nama, 179);
	}else if(strlen(nama)==20){
		printf("\n%c         ^         %c Nama Pelanggan : %s  %c", 179, 179, nama, 179);
	}else if(strlen(nama)==21){
		printf("\n%c         ^         %c Nama Pelanggan : %s %c", 179, 179, nama, 179);
	}else{
		printf("\n%c         ^         %c Nama Pelanggan : %s%c", 179, 179, nama, 179);
	}
	
	printf(      
	        "\n%c        / %c        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c       /___%c       %c No Telp : %s  %c  ID Roket : %s %c"
	        "\n%c      |=   =|      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c      |  P  |      %c Tipe Roket : %s   %c Rp.%d  %c"
		    "\n%c      |  N  |      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	        179, 92, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 92, 179, telp, 179, id, 179,
			179, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 179, tp, 179, harga_tipe, 179,
			179, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180	
	);
	
	if(!strcmpi(jns,"Struktural")){
		printf("\n%c      |  C  |      %c Kode Kerusakan : S      %c Rp.%d  %c", 179, 179, 179, harga_jns, 179);
	}else if(!strcmpi(jns,"Mesin")){
		printf("\n%c      |  C  |      %c Kode Kerusakan : M      %c Rp.%d  %c", 179, 179, 179, harga_jns, 179);
	}else{
		printf("\n%c      |  C  |      %c Kode Kerusakan : SM     %c Rp.%d  %c", 179, 179, 179, harga_jns, 179);
	}
	
	printf(
	        "\n%c      |     |      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c      |  2  |      %c Tingkat : %s        %c      x%d      %c"
	        "\n%c      |  0  |      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c      |  2  |      %c Riwayat : %d km     %c      x%d      %c"
	        "\n%c      |  4  |      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c      |     |      %c Kapasitas Minyak : %d kl %c      -       %c"
	        "\n%c     /|##!##|%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c    / |##!##| %c    %c Minyak saat ini  : %d kl %c      -       %c",
	        179, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 179, tk, 179, kali_tingkat, 179,
			179, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 179, riwayat, 179, kali_riwayat, 179,
			179, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 179, kapasitas, 179, 179,
			179, 92, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 92, 179, minyak, 179, 179		
	);
	
	if(harga_pengisian < 10000000){
		printf(
			"\n%c   /  |##!##|  %c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c  |  / ^ | ^ %c  |  %c Pengisian %d kl minyak   %c Rp.%d   %c",
	        179, 92, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 92, 179, pengisian, 179, harga_pengisian, 179
		);
	}else{
		printf(
			"\n%c   /  |##!##|  %c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	        "\n%c  |  / ^ | ^ %c  |  %c Pengisian %d kl minyak   %c Rp.%d  %c",
	        179, 92, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
			179, 92, 179, pengisian, 179, harga_pengisian, 179
		);
	}
	
	if(total_harga < 100000000){
		printf(
		        "\n%c  | /  ( | )  %c |  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		        "\n%c  |/   ( | )   %c|  %c      Total Harga        %c Rp.%d  %c"
		        "\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
				179, 92, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
				179, 92, 179, 179, total_harga, 179,
		        192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217
		);	
	}else{
		printf(
		        "\n%c  | /  ( | )  %c |  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		        "\n%c  |/   ( | )   %c|  %c      Total Harga        %c Rp.%d %c"
		        "\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
				179, 92, 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180,
				179, 92, 179, 179, total_harga, 179,
		        192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217
		);		
	}
}

void isi_minyak(int max, int  fuel, int *out){
    char tm = 203, bm = 202, ver = 186, hor = 205, tl= 201, tr = 187, bl = 200, br = 188, c = 178, s = ' ';
    int i, j, x;
    system("color 07");
    system("cls");
    for(; fuel<= max; fuel++){
        printf("\033[H");
        for(j=0;j<6;j++){
            if(j == 0){
                for(i = 0; i<=max; i++){
                if(i==0){
                        printf("\n\tE\t");
                    }else if(i==max){
                        printf("F");
                    }else{
                        printf("%d\t", i);
                    }
                }
            }
            if(j == 1){
                for(i = 0; i<=max*8; i++){
                    if(i==0){
                        printf("\n\t%c", tl);
                    }else if(i==max*8){
                        printf("%c",tr);
                    }else if(i%8==0){
                        printf("%c", tm);
                    }else{
                        printf("%c", hor);
                    }
                }
            }
            if(j >= 2 && j <= 4){
                for(i = 0; i<=max*8; i++){
                if(i==0){
                        printf("\n\t%c", ver);
                    }else if(i==max*8){
                        printf("%c",ver);
                    }else if(i%8==0){
                        printf("%c", ver);
                    }else if(i<fuel*8 && i<2*8){
                        printf("\033[0;41m");
                        printf("%c", s);
                        printf("\033[0m");
                    }else if(i<fuel*8 && i>(max -1)*8){
                        printf("\033[0;42m");
                        printf("%c", s);
                        printf("\033[0m");
                    }else if(i<fuel*8){
                        printf("\033[0;43m");
                        printf("%c", s);
                        printf("\033[0m");
                    }else{
                        printf("%c", s);
                    }
                }
            }
            if(j == 5){
                for(i = 0; i<=max*8; i++){
                if(i==0){
                        printf("\n\t%c", bl);
                    }else if(i==max*8){
                        printf("%c",br);
                    }else if(i%8==0){
                        printf("%c", bm);
                    }else{
                        printf("%c", hor);
                    }
                }
            }
        }
    if(fuel != max){sleep(3);}
    }
    *out = max;
    printf("\n\n\t\tPengisian minyak selesai....");
}

void reset(int *cek_data, int *cek_perbaikan, int *lunas, string status_perbaikan){
    *cek_data = 0;
    *cek_perbaikan = 0;
	*lunas = 0;
	strcpy(status_perbaikan, "sedang berlangsung!");
}

void inkremen_tanggal(int D, int M, int Y, int *outD, int *outM, int *outY){
        D++;
        if(M == 2 && Y % 400 == 0 && D > 29){
            M++;
            D=1;
        }else if(M == 2 && D > 28 && Y % 400 != 0){
            M++;
            D=1;
        }else if((M>=8 && M<=12 && M%2!=0) && D > 30){
            M++;
            D=1;
        }else if((M%2==0 && M<8) && D > 30){
            M++;
            D=1;
        }else if(D > 31){
            M++;
            D=1;
        }
        if(M > 12){
            M = 1;
            Y++;
        }
        *outD = D;
        *outM = M;
        *outY = Y;
}
