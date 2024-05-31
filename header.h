#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char string[100];

bool ceklogin(string user, string pass);
void validasi(string captha);
void roket();
void showmenu(string user, int cek_tanggal, int cek_data, int D, int M, int Y, string id, string status_perbaikan);
void tipe_roket(string tipe);
void jenis_kerusakan(string jenis);
void tingkat_kerusakan(string tingkat);
void riwayat_pemakaian(int *pemakaian);
void kapasitas_minyak(int *kapasitas);
void minyak_saatini(int *ini, int kapasitas);
void keluhan_pelanggan(int pemakaian, int kapasitas, int ini, string tipe, string jenis, string tingkat);
void input_data(string nama, string telp, string id, string tp, string jns, string tk, int riwayat, int kap, int count_nama, int count_telp, int count_id, int count_tipe, int count_jenis, int count_tingkat, int count_riwayat, int count_kapasitas);
void cetak_nota(string nama, string telp, string id, string tp, string jns, string tk, int harga_tipe, int harga_jns, int riwayat, int kali_tingkat, int kali_riwayat, int kapasitas, int minyak, int pengisian, int harga_pengisian, int total_harga);
void semua_harga(string tipe, string jenis, string tingkat, int riwayat, int kapasitas, int ini, int *harga_tipe, int *harga_jns, int *kali_tingkat, int *kali_riwayat, int *pengisian, int *harga_pengisian, int *total_harga);
void isi_minyak(int max, int  fuel, int *out);
void reset(int *cek_data, int *cek_perbaikan, int *lunas, string status_perbaikan);
void inkremen_tanggal(int D, int M, int Y, int *outD, int *outM, int *outY);

