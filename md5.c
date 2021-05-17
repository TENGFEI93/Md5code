#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <wctype.h>
#include <math.h>

int main()
{
    int i, j, k, l, q, rr, r, z, u, length, length1, length2, M, in, inj, remainder, uu, yy;
    unsigned int midtemp = 0;
    unsigned int midValue = 0;
    unsigned int little_midtemp = 0;
    char one[10] = {'1'};
    char zeros[600] = "\0";
    char a[100000] = "\0";
    char temp0[10] = "\0";
    char temp1[100000] = "\0";
    unsigned int temp32[100000] = {0};
    char padding[10] = "\0";
    char padding1[100] = "\0";
    char appending[10000] = "\0";
    char appending0[10000] = "\0";
    char appending1[10000] = "\0";
    char zeropadding[10] = "\0";
    char midTemp[40] = "\0";
    char p[10] = "\0";
    unsigned int X[16] = {0};
    char space[10] = {'0','0','1','0','0','0','0','0'};
    unsigned int A = 0x67452301;
    unsigned int B = 0xefcdab89;
    unsigned int C = 0x98badcfe;
    unsigned int D = 0x10325476;
    unsigned int AA = 0;
    unsigned int BB = 0;
    unsigned int CC = 0;
    unsigned int DD = 0;
    unsigned int little_A = 0;
    unsigned int little_B = 0;
    unsigned int little_C = 0;
    unsigned int little_D = 0;
    char md5[40] = "\0";
    const unsigned int T[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
    unsigned int F_function(unsigned int x, unsigned int y, unsigned int z);
    unsigned int G_function(unsigned int x, unsigned int y, unsigned int z);
    unsigned int H_function(unsigned int x, unsigned int y, unsigned int z);
    unsigned int I_function(unsigned int x, unsigned int y, unsigned int z);
    unsigned int Cycle_LeftMove(unsigned int x, unsigned int y);
    unsigned int bintodec(char *array);
    char *dectohex(unsigned int n);
    unsigned int bswap_32(unsigned int x);


    printf("input string: \n");
    scanf("%[^\n]s", a);

    //将字符串转换为二进制
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ')
        {
            strncat(temp1, space, strlen(space));
        }else
        {
            itoa(a[i], temp0, 2);
            for (j = 0; j < (8-strlen(temp0)); j++)
            {
                padding[j] = '0';
            }
            strncpy(p, padding, strlen(padding));
            strncat(p, temp0, strlen(temp0));
            strncat(temp1, p, strlen(p));
            memset(p, '\0', sizeof(p));
            memset(temp0, '\0', sizeof(temp0));                       
            memset(padding, '\0', sizeof(padding));
        }
    }

    //将转换后二进制位数补为512的整数倍
    printf("%s\n", temp1);
    length = strlen(temp1);
    printf("%d\n", length);
    M = length%512;
    if (M < 448)
    {
        for (k = 0; k < (447-M); k++)
        {
            zeros[k] = '0';
        }
    }else if (M == 448)
    {
        for (l = 0; l < 511; l++)
        {
            zeros[l] = '0';
        }       
    }else
    {
        for (q = 0; q < (959-M); q++)
        {
            zeros[q] = '0';
        }
    }
    strncat(temp1, one, strlen(one));
    strncat(temp1, zeros, strlen(zeros));
    itoa(length, appending, 2);
    printf("%s\n", appending);
    remainder = (strlen(appending))%8;
    if (remainder == 0)
    {
        strncpy(appending0, appending, strlen(appending));
    }else
    {
        for (uu = 0; uu < (8 - remainder); uu++)
        {
            zeropadding[uu] = '0';
        }
        strncat(appending0, zeropadding, strlen(zeropadding));
        strncat(appending0, appending, strlen(appending));
    }
    //printf("%s\n", appending0);
    if(strlen(appending0)>=64)
    {
        for(rr = 0; rr < 64; rr++)
        {
            padding1[rr] = appending0[rr + length - 64];
        }
        strncpy(appending0, padding1, strlen(padding1));
    }else
    {
        for (r = 0; r < (64-strlen(appending0)); r++)
        {
            padding1[r] = '0';
        }
        strncat(appending1, padding1, strlen(padding1));
        strncat(appending1, appending0, strlen(appending0));
        for (yy = 0; yy < 64; yy++)
        {
            if (yy >=0 && yy < 8)
            {
                appending0[yy] = appending1[yy + 56];
            }
            else if (yy < 16)
            {
                appending0[yy] = appending1[yy + 40];
            }
            else if (yy < 24)
            {
                appending0[yy] = appending1[yy + 24];
            }
            else if (yy < 32)
            {
                appending0[yy] = appending1[yy + 8];
            }
            else if (yy < 40)
            {
                appending0[yy] = appending1[yy - 8];
            }
            else if (yy < 48)
            {
                appending0[yy] = appending1[yy - 24];
            }
            else if (yy < 56)
            {
                appending0[yy] = appending1[yy - 40];
            }
            else if (yy < 64)
            {
                appending0[yy] = appending1[yy - 56];
            }  
        }
    }
    printf("%s\n", appending0);
    //printf("%d\n", strlen(temp1));
    strncat(temp1, appending0, strlen(appending0));
    printf("%s\n", temp1);
    //printf("%d\n", strlen(temp1));
    length1 = strlen(temp1);
    for (in = 0; in < length1/32; in++)
    {
        for(inj = 0; inj < 32; inj++)
        {
            midTemp[inj] = temp1[in*32 + inj];
        }
        midtemp = bintodec(midTemp);
        little_midtemp = bswap_32(midtemp);
        printf("midtemp:%d\n", little_midtemp);
        temp32[in] = little_midtemp;
        memset(midTemp, '\0', sizeof(midTemp));
    }
    length2 = length1/32;
    for (z = 0; z < length2/16; z++)
    {
        for (u = 0; u < 16; u++)
        {
            X[u] = temp32[z*16+u];
        }
        AA = A;
        BB = B;
        CC = C;
        DD = D;
        midValue = A + F_function(B, C, D) + X[0] + T[0];
        A = B + Cycle_LeftMove(midValue, 7);
        midValue = D + F_function(A, B, C) + X[1] + T[1];
        D = A + Cycle_LeftMove(midValue, 12);
        midValue = C + F_function(D, A, B) + X[2] + T[2];
        C = D + Cycle_LeftMove(midValue, 17);
        midValue = B + F_function(C, D, A) + X[3] + T[3];
        B = C + Cycle_LeftMove(midValue, 22);
        midValue = A + F_function(B, C, D) + X[4] + T[4];
        A = B + Cycle_LeftMove(midValue, 7);
        midValue = D + F_function(A, B, C) + X[5] + T[5];
        D = A + Cycle_LeftMove(midValue, 12);
        midValue = C + F_function(D, A, B) + X[6] + T[6];
        C = D + Cycle_LeftMove(midValue, 17);
        midValue = B + F_function(C, D, A) + X[7] + T[7];
        B = C + Cycle_LeftMove(midValue, 22);
        midValue = A + F_function(B, C, D) + X[8] + T[8];
        A = B + Cycle_LeftMove(midValue, 7);
        midValue = D + F_function(A, B, C) + X[9] + T[9];
        D = A + Cycle_LeftMove(midValue, 12);
        midValue = C + F_function(D, A, B) + X[10] + T[10];
        C = D + Cycle_LeftMove(midValue, 17);
        midValue = B + F_function(C, D, A) + X[11] + T[11];
        B = C + Cycle_LeftMove(midValue, 22);
        midValue = A + F_function(B, C, D) + X[12] + T[12];
        A = B + Cycle_LeftMove(midValue, 7);
        midValue = D + F_function(A, B, C) + X[13] + T[13];
        D = A + Cycle_LeftMove(midValue, 12);
        midValue = C + F_function(D, A, B) + X[14] + T[14];
        C = D + Cycle_LeftMove(midValue, 17);
        midValue = B + F_function(C, D, A) + X[15] + T[15];
        B = C + Cycle_LeftMove(midValue, 22);
        
        midValue = A + G_function(B, C, D) + X[1] + T[16];
        A = B + Cycle_LeftMove(midValue, 5);
        midValue = D + G_function(A, B, C) + X[6] + T[17];
        D = A + Cycle_LeftMove(midValue, 9);
        midValue = C + G_function(D, A, B) + X[11] + T[18];
        C = D + Cycle_LeftMove(midValue, 14);
        midValue = B + G_function(C, D, A) + X[0] + T[19];
        B = C + Cycle_LeftMove(midValue, 20);
        midValue = A + G_function(B, C, D) + X[5] + T[20];
        A = B + Cycle_LeftMove(midValue, 5);
        midValue = D + G_function(A, B, C) + X[10] + T[21];
        D = A + Cycle_LeftMove(midValue, 9);
        midValue = C + G_function(D, A, B) + X[15] + T[22];
        C = D + Cycle_LeftMove(midValue, 14);
        midValue = B + G_function(C, D, A) + X[4] + T[23];
        B = C + Cycle_LeftMove(midValue, 20);
        midValue = A + G_function(B, C, D) + X[9] + T[24];
        A = B + Cycle_LeftMove(midValue, 5);
        midValue = D + G_function(A, B, C) + X[14] + T[25];
        D = A + Cycle_LeftMove(midValue, 9);
        midValue = C + G_function(D, A, B) + X[3] + T[26];
        C = D + Cycle_LeftMove(midValue, 14);
        midValue = B + G_function(C, D, A) + X[8] + T[27];
        B = C + Cycle_LeftMove(midValue, 20);
        midValue = A + G_function(B, C, D) + X[13] + T[28];
        A = B + Cycle_LeftMove(midValue, 5);
        midValue = D + G_function(A, B, C) + X[2] + T[29];
        D = A + Cycle_LeftMove(midValue, 9);
        midValue = C + G_function(D, A, B) + X[7] + T[30];
        C = D + Cycle_LeftMove(midValue, 14);
        midValue = B + G_function(C, D, A) + X[12] + T[31];
        B = C + Cycle_LeftMove(midValue, 20);

        midValue = A + H_function(B, C, D) + X[5] + T[32];
        A = B + Cycle_LeftMove(midValue, 4);
        midValue = D + H_function(A, B, C) + X[8] + T[33];
        D = A + Cycle_LeftMove(midValue, 11);
        midValue = C + H_function(D, A, B) + X[11] + T[34];
        C = D + Cycle_LeftMove(midValue, 16);
        midValue = B + H_function(C, D, A) + X[14] + T[35];
        B = C + Cycle_LeftMove(midValue, 23);
        midValue = A + H_function(B, C, D) + X[1] + T[36];
        A = B + Cycle_LeftMove(midValue, 4);
        midValue = D + H_function(A, B, C) + X[4] + T[37];
        D = A + Cycle_LeftMove(midValue, 11);
        midValue = C + H_function(D, A, B) + X[7] + T[38];
        C = D + Cycle_LeftMove(midValue, 16);
        midValue = B + H_function(C, D, A) + X[10] + T[39];
        B = C + Cycle_LeftMove(midValue, 23);
        midValue = A + H_function(B, C, D) + X[13] + T[40];
        A = B + Cycle_LeftMove(midValue, 4);
        midValue = D + H_function(A, B, C) + X[0] + T[41];
        D = A + Cycle_LeftMove(midValue, 11);
        midValue = C + H_function(D, A, B) + X[3] + T[42];
        C = D + Cycle_LeftMove(midValue, 16);
        midValue = B + H_function(C, D, A) + X[6] + T[43];
        B = C + Cycle_LeftMove(midValue, 23);
        midValue = A + H_function(B, C, D) + X[9] + T[44];
        A = B + Cycle_LeftMove(midValue, 4);
        midValue = D + H_function(A, B, C) + X[12] + T[45];
        D = A + Cycle_LeftMove(midValue, 11);
        midValue = C + H_function(D, A, B) + X[15] + T[46];
        C = D + Cycle_LeftMove(midValue, 16);
        midValue = B + H_function(C, D, A) + X[2] + T[47];
        B = C + Cycle_LeftMove(midValue, 23);

        midValue = A + I_function(B, C, D) + X[0] + T[48];
        A = B + Cycle_LeftMove(midValue, 6);
        midValue = D + I_function(A, B, C) + X[7] + T[49];
        D = A + Cycle_LeftMove(midValue, 10);
        midValue = C + I_function(D, A, B) + X[14] + T[50];
        C = D + Cycle_LeftMove(midValue, 15);
        midValue = B + I_function(C, D, A) + X[5] + T[51];
        B = C + Cycle_LeftMove(midValue, 21);
        midValue = A + I_function(B, C, D) + X[12] + T[52];
        A = B + Cycle_LeftMove(midValue, 6);
        midValue = D + I_function(A, B, C) + X[3] + T[53];
        D = A + Cycle_LeftMove(midValue, 10);
        midValue = C + I_function(D, A, B) + X[10] + T[54];
        C = D + Cycle_LeftMove(midValue, 15);
        midValue = B + I_function(C, D, A) + X[1] + T[55];
        B = C + Cycle_LeftMove(midValue, 21);
        midValue = A + I_function(B, C, D) + X[8] + T[56];
        A = B + Cycle_LeftMove(midValue, 6);
        midValue = D + I_function(A, B, C) + X[15] + T[57];
        D = A + Cycle_LeftMove(midValue, 10);
        midValue = C + I_function(D, A, B) + X[6] + T[58];
        C = D + Cycle_LeftMove(midValue, 15);
        midValue = B + I_function(C, D, A) + X[13] + T[59];
        B = C + Cycle_LeftMove(midValue, 21);
        midValue = A + I_function(B, C, D) + X[4] + T[60];
        A = B + Cycle_LeftMove(midValue, 6);
        midValue = D + I_function(A, B, C) + X[11] + T[61];
        D = A + Cycle_LeftMove(midValue, 10);
        midValue = C + I_function(D, A, B) + X[2] + T[62];
        C = D + Cycle_LeftMove(midValue, 15);
        midValue = B + I_function(C, D, A) + X[9] + T[63];
        B = C + Cycle_LeftMove(midValue, 21);

        A += AA;
        B += BB;
        C += CC;
        D += DD;
        memset(X, 0, sizeof(X));
    }
    little_A = bswap_32(A);
    little_B = bswap_32(B);
    little_C = bswap_32(C);
    little_D = bswap_32(D);
    strncat(md5, dectohex(little_A), 8);
    strncat(md5, dectohex(little_B), 8);
    strncat(md5, dectohex(little_C), 8);
    strncat(md5, dectohex(little_D), 8);
    printf("MD5 value\n%s\n", md5);
    system("pause");
    return 0;
}

unsigned int F_function(unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int temp;
    
    temp = (((x) & (y)) | ((~x) & (z)));
    return temp;
}

unsigned int G_function(unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int temp;
    
    temp = (((x) & (z)) | ((y) & (~z)));
    return temp;
}

unsigned int H_function(unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int temp;
    
    temp = ((x) ^ (y) ^ (z));
    return temp;
}

unsigned int I_function(unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int temp;
    
    temp = ((y) ^ ((x) | (~z)));
    return temp;
}

unsigned int Cycle_LeftMove(unsigned int temp, unsigned int n)
{
    unsigned int temp_cycleleft;

    temp_cycleleft = (((temp) << (n)) | ((temp) >> (32-(n))));
    return temp_cycleleft;
}

unsigned int bintodec(char *array)
{
    int kk;
    int LL;
    int TT;
    unsigned int num = 0;
    char tempv[2] = "\0"; 

    LL = strlen(array);
    for(kk = 0; kk < LL; kk++)
    {
        tempv[0] = array[kk];
        TT = strtol(tempv, NULL, 2);
        num += TT*pow(2, LL-kk-1);
        memset(tempv, '\0', sizeof(tempv));
    }
    return num;
}

char* dectohex(unsigned int n)
{
    static char hexstring[10];
    static char hexstring1[10];
    static char hexstring2[10];
    memset(hexstring, '\0', sizeof(hexstring));
    memset(hexstring1, '\0', sizeof(hexstring1));
    memset(hexstring2, '\0', sizeof(hexstring2));
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char padding[10] = "\0";
    unsigned int temp, j, length;
    int i = 0;
    int k = 0;

    while(n > 0)
    {
        temp = n%16;
        hexstring[i] = hex[temp];
        n = n/16;
        i++;
    }
    length = strlen(hexstring);
    for(j = 0; j < length; j++)
    {
        hexstring1[j] = hexstring[length - j - 1];
    }
    for (k = 0; k < (8 - strlen(hexstring1)); k++)
    {
        padding[k] = '0';
    }
    strncpy(hexstring2, padding, strlen(padding));
    strncat(hexstring2, hexstring1, strlen(hexstring1));

    return hexstring2; 
}

unsigned int bswap_32(unsigned int x)
{
    return (((unsigned int)(x) & 0xff000000) >> 24) | \
           (((unsigned int)(x) & 0x00ff0000) >> 8) | \
           (((unsigned int)(x) & 0x0000ff00) << 8) | \
           (((unsigned int)(x) & 0x000000ff) << 24) ;
}