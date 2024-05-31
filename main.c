#include "header.h"

int main(int argc, char *argv[]) {
	string user, pass, captcha, cap, tipe, jenis, tingkat, telp, nama, id, tp, jns, tk, cetak, nama_bayar, status_perbaikan = "sedang berlangsung!";
	int kesempatan = 1, cap_salah = 0, count_nama , count_telp , count_id , cek_data = 0 , cek_tanggal = 0, count_tingkat, count_tipe , count_jenis, cek_perbaikan = 0, lunas = 0, count_riwayat, count_kapasitas;
	int menu, pemakaian, kapasitas, ini, riwayat, kap, minyak, cekid, bayar, pelunasan;
	int harga_tipe, harga_jns, kali_tingkat, kali_riwayat, pengisian, harga_pengisian, total_harga;
	int D, M, Y, i, j;
	bool status;
	
	srand(time(NULL));
	do{
		system("cls");
		system("color 09");
		status = false;
		printf("\n        ---==[ LOGIN ]==---");
		printf("\n        Masukkan Username        : ");scanf("%s", &user);
		printf("        Masukkan Password        : ");scanf("%s", &pass);
		status = ceklogin(user, pass);
		
		if(!status){
			if(kesempatan < 3){
				printf("\n\t[!] Username dan Password masih salah [!]"); getch();
			}
			if(kesempatan == 3 || kesempatan == 4){
				printf("\n\t[!] Username dan Password masih salah [!]"); getch();
				printf("\n\t[!] Gagal login sebanyak %dx, silahkan tunggu beberapa detik untuk mencoba lagi [!]\n", kesempatan);
				sleep(kesempatan);
				kbhit();
    			while (kbhit()!=0) {
        			getch();
    			}
			}
			if(kesempatan == 5){
				printf("\n\t[!] Username dan Password masih salah [!]"); getch();
				system("color 4F");
				printf("\n        [!] Salah login sebanyak 5x, anda akan dikeluarkan secara paksa [!]\n"); getch();
				return 0;
			}
			kesempatan++;	
		}else{
			while(1){
				validasi(captcha);
				if(cap_salah == 1){
					system("cls");
					printf("\n        ---==[ LOGIN ]==---");
					printf("\n        Masukkan Username        : %s", user);
					printf("\n        Masukkan Password        : %s\n", pass);
				}
				printf("\n        CAPTCHA                  : %s", captcha);
				printf("\n        Silahkan Input CAPTCHA   : ");fflush(stdin);gets(cap);
				if(strcmp(cap,captcha)){
					cap_salah = 1;
					printf("\n        [!] CAPTCHA salah [!]");
				}else{
					kesempatan = 1;
					system("cls");
					roket();
					system("cls");	
					printf("\n        LOGIN BERHASIL, SELAMAT DATANG!\n\t");
					system("pause");
					break;
				}getch();	
			}
			
			do{
				showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
				menu = getche();
				
				switch(menu){
					
					case 49 :
                        if(cek_data == 1){
                	    	printf("\n\t\t[!] Sudah ada data pelanggan [!]");
                            break;
                		}
						count_nama = 0, count_telp = 0, count_id = 0, cek_data = 0, count_tingkat=0, count_tipe = 0, count_jenis = 0, count_riwayat=0, count_kapasitas=0;
						tipe_roket(tipe);
						jenis_kerusakan(jenis);
						tingkat_kerusakan(tingkat);
						riwayat_pemakaian(&pemakaian);
						kapasitas_minyak(&kapasitas);
						minyak_saatini(&ini, kapasitas);
						if(cek_tanggal == 0){
							while(1){
								system("cls");							
								showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
								printf("\n\n         Masukkan Tanggal Hari ini [D-M-Y]: ");scanf("%d-%d-%d", &D, &M, &Y);
								if(D < 1 || D > 31){
									printf("\n        [!] Tanggal tidak boleh kurang dari 1 atau lebih dari 31 [!]");
								}else if(M < 1 || M > 12){
									printf("\n        [!] Bulan tidak boleh kurang dari 1 atau lebih dari 12 [!]");
								}else if(Y < 1){
									printf("\n        [!] Tahun tidak boleh kurang dari 1 [!]");
								}else if((M == 2 && ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))) && D > 29){
									printf("\n        [!] Bulan 2 pada tahun %d hanya memiliki 29 hari [!]", Y);	
								}else if(M == 2 && D > 28){
									printf("\n        [!] Bulan 2 hanya memiliki 28 hari, karena bukan tahun kabisat [!]");
								}else if((M%2==0 && M<8) && D > 30){
									printf("\n        [!] Bulan %d hanya memiliki 30 hari [!]", M);
								}else if((M>=8 && M<=12 && M%2!=0) && D > 30){
										printf("\n        [!] Bulan %d hanya memiliki 30 hari [!]", M);
								}else if((Y==2024 && M==5 && D>=10 && D<=31) || (Y== 2024 && M==6 && D==1)){
									printf("\n        [!] Bengkel Roket sedang libur dari 10 may 2024 - 1 juni 2024, karena sedang mengikuti PNC 2024 [!]");
								}else{
									cek_tanggal = 1;
									break;
								}getch();
							}
						}
						
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							printf("\n        Nama Pelanggan           : ");fflush(stdin);gets(nama);
							if(strlen(nama)==0){
								printf("\n        [!] Inputan nama tidak boleh kosong! [!]");
							}else if(strlen(nama)==23){
								printf("\n        [!] Inputan nama tidak boleh lebih dari 22 karakter! [!]");
							}else{
								count_nama = 1;
								break;
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        No Telp                  : ");fflush(stdin);gets(telp);
							if(strlen(telp)==8){
								count_telp = 1;
								break;
							}else{
								printf("\n        [!] Inputan no telepon harus 8 digit! [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        ID Roket                 : ");fflush(stdin);gets(id);
							cekid = atoi(id);
							if(cekid!=0 && strlen(id)==4){
								count_id = 1;
								break;
							}else{
								printf("\n        [!] Inputan ID roket harus 4 digit dan diawali dengan angka! [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        Tipe Roket Pelanggan     : ");fflush(stdin);gets(tp);
							if(!strcmpi(tp, tipe)){
								count_tipe = 1; 
								break;
							}else{
								printf("\n        [!] Inputan Tipe Roket Pelanggan Tidak Sesuai [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        Jenis Kerusakan          : ");fflush(stdin);gets(jns);
							if(!strcmpi(jns, jenis)){
								count_jenis = 1; 
								break;
							}else{
								printf("\n        [!] Inputan Jenis Kerusakan Roket Pelanggan Tidak Sesuai [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        Tingkat Kerusakan        : ");fflush(stdin);gets(tk);
							if(!strcmpi(tk, tingkat)){
								count_tingkat = 1; 
								break;
							}else{
								printf("\n        [!] Inputan Tingkat Kerusakan Roket Pelanggan Tidak Sesuai [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        Riwayat Pemakaian Roket  : ");scanf("%d", &riwayat);
							if(riwayat == pemakaian){
								count_riwayat = 1;
								break;
							}else{
								printf("\n        [!] Inputan Riwayat Roket Pelanggan Tidak Sesuai [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							input_data(nama, telp, id, tp, jns, tk, riwayat, kap, count_nama, count_telp, count_id, count_tipe, count_jenis, count_tingkat, count_riwayat, count_kapasitas);
							printf("\n        Kapasitas Minyak Roket   : ");scanf("%d", &kap);
							if(kap == kapasitas){
								count_kapasitas = 1;
								break;
							}else{
								printf("\n        [!] Inputan Kapasitas Minyak Roket Pelanggan Tidak Sesuai [!]");
							}getch();
						}
						while(1){
							system("cls");
							keluhan_pelanggan(pemakaian, kapasitas, ini, tipe, jenis, tingkat);
							printf("\n        Nama Pelanggan           : %s", nama);
							printf("\n        No Telp                  : %s", telp);
							printf("\n        ID Roket                 : %s", id);
							printf("\n        Tipe Roket Pelanggan     : %s", tp);
							printf("\n        Jenis Kerusakan          : %s", jns);
							printf("\n        Tingkat Kerusakan        : %s", tk);
							printf("\n        Riwayat Pemakaian Roket  : %d", riwayat);
							printf("\n        Kapasitas Minyak Roket   : %d", kap);
							printf("\n        Minyak Roket saat ini    : ");scanf("%d", &minyak);
							if(minyak == ini){
								printf("        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
								break;
							}else{
								printf("\n        [!] Inputan Minyak Roket Pelanggan saat ini Tidak Sesuai [!]");
							}getch();
						}
						printf("\n        Cetak Nota? [Y/N] ");fflush(stdin);gets(cetak);
						if(!strcmpi(cetak,"Y")){
							system("cls");
							semua_harga(tipe, jenis, tingkat, riwayat, kapasitas, ini, &harga_tipe, &harga_jns, &kali_tingkat, &kali_riwayat, &pengisian, &harga_pengisian, &total_harga);
							cetak_nota(nama, telp, id, tp, jns, tk, harga_tipe, harga_jns, riwayat, kali_tingkat, kali_riwayat, kapasitas, minyak, pengisian, harga_pengisian, total_harga);
							cek_data = 1;
							while(1){
								system("cls");
								cetak_nota(nama, telp, id, tp, jns, tk, harga_tipe, harga_jns, riwayat, kali_tingkat, kali_riwayat, kapasitas, minyak, pengisian, harga_pengisian, total_harga);
								printf("\n\n        Pembayaran Deposit / Lunas ? ");fflush(stdin);gets(nama_bayar);
								if(!strcmpi(nama_bayar,"Deposit")){
									printf(
										"\n        Minimal Deposit adalah 50%% dari total harga"
										"\n        Silahkan masukkan nominal uang pelanggan : "
									);
									scanf("%d", &bayar);
									if(bayar == total_harga){
										printf("\n\n                 [+] Pembayaran Lunas [+]");
										lunas = 1;
										break;
									}else if(bayar > total_harga){
										bayar-= total_harga;
										printf("\n        Kembalian : %d", bayar);
										printf("\n                 [+] Pembayaran Lunas [+]");
										lunas = 1;
										break;
									}else if(bayar <= total_harga * 0.5){
										printf("\n                [!] Nominal uang yang dimasukkan tidak cukup! [!]");
									}else{
										pelunasan = total_harga - bayar;
										printf("\n                 [+] Berhasil melakukan deposit sebesar Rp.%d [+]\n                 Pelunasan sebesar Rp.%d dapat dilakukan setelah perbaikan selesai   ", bayar, pelunasan);
										break;
									}
								}else if(!strcmpi(nama_bayar,"Lunas")){
									printf("\n        Silahkan masukkan nominal uang pelanggan : ");scanf("%d", &bayar);
									if(bayar == total_harga){
										printf("\n\n                 [+] Pembayaran Lunas [+]");
										lunas = 1;
										break;
									}else if(bayar > total_harga){
										bayar-=total_harga;
										printf("\n        Kembalian : %d", bayar);
										printf("\n                 [+] Pembayaran Lunas [+]");
										lunas = 1;
										break;
									}else{
										printf("\n                [!] Nominal uang yang dimasukkan tidak cukup! [!]");
									}
								}getch();
							}
						}else{
							printf("\n        [!] Tidak jadi mencetak Nota, pengisian data dibatalkan! [!] ");
						}
					break;
					
					case 50 :
						if(cek_data == 0){
                	    	printf("\n\t\t[!] Belum ada data pelanggan [!]");
                		}else{
							printf("\n\n");
                			cetak_nota(nama, telp, id, tp, jns, tk, harga_tipe, harga_jns, riwayat, kali_tingkat, kali_riwayat, kapasitas, minyak, pengisian, harga_pengisian, total_harga);
						}
					break;

                    case 51 :
						if(cek_data == 0){
                	    	printf("\n\t\t[!] Belum ada data pelanggan [!]");
                		}else if(cek_perbaikan == 1){
                			strcpy(status_perbaikan,"sudah selesai!");
		                    printf("\n\t\t[!] Perbaikan sudah dilakukan! [!]");
		                }else if(strcmpi(tingkat, "ringan")==0){
		                	if((D>=10 && D<=30)&& M == 5 && Y == 2024){
		                		sleep(3);
	                            inkremen_tanggal( D,  M,  Y,  &D,  &M,  &Y);
	                            strcpy(status_perbaikan,"sudah selesai!");
	                            showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
	                            printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Ringan membutuhkan waktu sebanyak 1 hari");
	                            printf("\n\n\t\t[!] Masuk Tanggal Rangkaian Acara PNC 2024 [!]");
	                            printf("\n\t\t[!] Pekerjaan akan dilanjutkan kembali pada tanggal 2 Juni 2024 [!]");
	                            D = 2;
	                            M = 6;
	                            Y = 2024;
							}else{
								sleep(3);
	                            inkremen_tanggal( D,  M,  Y,  &D,  &M,  &Y);
	                            strcpy(status_perbaikan,"sudah selesai!");
	                            showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
	                            printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Ringan membutuhkan waktu sebanyak 1 hari");	
							}     
						}else if(strcmpi(tingkat, "sedang")==0){
                            printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Sedang membutuhkan waktu sebanyak 3 hari");
                            j = 2;
                            while(1){
                                if((D>=10 && D<=30)&& M == 5 && Y == 2024){
                                	j+=1;
                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Sedang membutuhkan waktu sebanyak 3 hari");
                                    printf("\n\n\t\t[!] Masuk Tanggal Rangkaian Acara PNC 2024 [!]");
                                    printf("\n\t\t[!] Pekerjaan akan dilanjutkan kembali pada tanggal 2 Juni 2024 [!]");
                                    sleep(3);
                                    D = 2;
                                    M = 6;
                                    Y = 2024;
                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Sedang membutuhkan waktu sebanyak 3 hari");
                                }else{
                                	if(j<=0){
                                		strcpy(status_perbaikan,"sudah selesai!");
                                		inkremen_tanggal( D,  M,  Y,  &D,  &M,  &Y);
                                    	showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
                                    	printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Sedang membutuhkan waktu sebanyak 3 hari");
                						break;
									}else{
	                                    inkremen_tanggal( D,  M,  Y,  &D,  &M,  &Y);
	                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
	                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Sedang membutuhkan waktu sebanyak 3 hari");
	                                    sleep(3);
	                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
	                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Sedang membutuhkan waktu sebanyak 3 hari");
										
									}
                                }
                                j--;
                            }
						}else if(strcmpi(tingkat, "urgent")==0){
                            printf("\n\tPerbaikan Roket dengan Tingkat Kerusakan Urgent membutuhkan waktu sebanyak 5 hari");
                            j = 4;
                            while(1){
                                if((D>=10 && D<=30) && M == 5 && Y == 2024){
                                	j+=1;
                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Urgent membutuhkan waktu sebanyak 5 hari");
                                    printf("\n\n\t\t[!] Masuk Tanggal Rangkaian Acara PNC 2024 [!]");
                                    printf("\n\t\t[!] Pekerjaan akan dilanjutkan kembali pada tanggal 2 Juni 2024 [!]");
                                    sleep(3);
                                    D = 2;
                                    M = 6;
                                    Y = 2024;
                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Urgent membutuhkan waktu sebanyak 5 hari");
                                }else{
                                	if(j<=0){
                                		strcpy(status_perbaikan,"sudah selesai!");
                                		inkremen_tanggal( D,  M,  Y,  &D,  &M,  &Y);
                                   		showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
                                    	printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Urgent membutuhkan waktu sebanyak 5 hari");
                                    	break;
									}else{
	                                    inkremen_tanggal( D,  M,  Y,  &D,  &M,  &Y);
	                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
	                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Urgent membutuhkan waktu sebanyak 5 hari");
	                                    sleep(3);
	                                    showmenu(user, cek_tanggal, cek_data, D, M, Y, id, status_perbaikan);
	                                    printf("\n\n\tPerbaikan Roket dengan Tingkat Kerusakan Urgent membutuhkan waktu sebanyak 5 hari");		
									}
                                }
                                j--;
                            }
						}
						cek_perbaikan = 1;
					break;
					
					case 52:
						if(cek_data == 0){
                	    	printf("\n\t\t[!] Belum ada data pelanggan [!]");
                		}else if(kapasitas == ini){
		                    printf("\n\t\t[!] Minyak Roket Sudah Full [!]");
		                }else if(kapasitas > ini){
		                    printf("\n\t\tMemulai Pengisian minyak..... [->]");
		                	sleep(2);
		                    isi_minyak(kapasitas, ini, &ini);
		                }
					break;
					
					case 53 :
						if(cek_data == 0){
							printf("\n\t\t[!] Belum ada data pelanggan [!]");
						}else if(cek_perbaikan == 0){
							printf("\n\t\t[!] Roket belum selesai di perbaiki [!]");
						}else if(lunas == 1){
							printf("\n                [!] Pembayaran Sudah Lunas :) [!]");
						}else{
							printf("\n        Jumlah Pelunasan adalah %d\n        Silahkan masukkan nominal uang pelanggan : ", pelunasan);scanf("%d", &bayar);
							if(bayar == pelunasan){
								printf("\n\n                 [+] Pembayaran Lunas [+]");
								lunas = 1;
							}else if(bayar > pelunasan){
								bayar-=pelunasan;
								printf("\n        Kembalian : %d", bayar);
								printf("\n                 [+] Pembayaran Lunas [+]");
								lunas = 1;
							}else{
								printf("\n                [!] Nominal uang yang dimasukkan tidak cukup! [!]");
							}
						}
					break;
                    case 54 :
						if(cek_data == 0){
                	    	printf("\n\t\t[!] Belum ada data pelanggan [!]");
                		}else if(cek_perbaikan == 0){
                	    	printf("\n\t\t[!] Roket belum selesai di perbaiki [!]");
                		}else if(lunas == 0){
                			printf("\n                [!] Silahkan lakukan pelunasan terlebih dahulu [!]");
						}else{
                            printf("\n\tData pelanggan %s akan dihapus", nama);
                            printf("\n\tTerima kasih pelanggan %s telah memercayai kami untuk memperbaiki roket anda!", nama);
                            printf("\n\tSemoga pelanggan %s puas dengan pelayanan BENGKEL ROKET GALAXY JAYA", nama);
                            reset(&cek_data, &cek_perbaikan, &lunas, status_perbaikan);
						}
					break;
					case 27 :
						if(lunas == 0){ 
							printf("\n                [!] Silahkan lakukan pelunasan terlebih dahulu [!]");
						}else{
							printf("\n         Keluar Program [<-]");
							return 0;
						}
					break;
					default :
						printf("\n        [!] Menu tidak tersedia [!]");
					break;
				}getch();
			}while(menu != 27);
		}
    
	}while(1);
	return 0;
}


