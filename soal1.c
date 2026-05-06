/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Fayyadh Ramadhan (13224077)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membuat Data Antrian Pasien dan Durasi Tunggunya menggunakan Queue, lalu mencetak Urutan Pasien dan Durasi Tunggu Seluruh Pasien.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAKS 100

typedef struct Pasien{
    char ID[50];
    int durasi;
} Pasien;

typedef struct Queue{
    Pasien data[MAKS];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue *q)
{
    return (q->front == q->rear - 1);
}

bool isFull(Queue *q)
{
    return (q->rear == MAKS);
}

void enqueue(Queue *q, char tempID[], int tempDurasi)
{
    if (isFull(q))
    {
        // printf("Queue Penuh!\n");
        return;
    }

    strcpy(q->data[q->rear].ID, tempID);
    q->data[q->rear].durasi = tempDurasi;
    q->rear++;
}

void hitungDurasi(Queue q, int N)
{
    int total=0, i, j, tempTotal=0;

    for(i=0;i<N-1;i++)
    {
        tempTotal += q.data[i].durasi;
        total += tempTotal;   
    }

    printf("\nWAIT %d", total);
}

void urutanPasien(Queue q, int N)
{
    printf("\nORDER");
    for(int i=0;i<N;i++)
    {
        printf(" %s", q.data[i].ID);
    }
}

int main()
{
    int N, i, tempDurasi;
    char tempID[50];
    Queue q;
    initializeQueue(&q);

    scanf("%d", &N);
    for(i=0;i<N;i++)
    {
        scanf(" %s %d", &tempID, &tempDurasi);
        enqueue(&q, tempID, tempDurasi);
        // printf("%s testest", q.data[i].ID);
    }

    // printf("%s %s %s\n",q.data[0].ID, q.data[1].ID, q.data[2].ID);

    urutanPasien(q, N);
    hitungDurasi(q, N);

    return 0;
}

// printf("%d %d %d %d", q.data[0].ID, q.data[0].durasi, q.data[1].ID, q.data[1].durasi);

// int main()
// {
//     int N, i;

//     scanf("%d", &N);

//     Queue pasien[N];

//     for(i=0;i<N;i++)
//     {
//         scanf(" %d %d", &pasien[i].ID, &pasien[i].durasi);
//     }



//     return 0;
// }

// Referensi
// https://www.geeksforgeeks.org/c/queue-in-c/
// https://www.geeksforgeeks.org/c/strings-in-c/
// https://www.geeksforgeeks.org/c/strcpy-in-c/