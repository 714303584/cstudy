#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>
#include "md5.h"

#define MESSAGE ((const unsigned char *) "Arbitrary data to hash")
#define MESSAGE_LEN 22

#define CIPHERTEXT_LEN (crypto_secretbox_MACBYTES + MESSAGE_LEN)



int main()
{
    MD5_CTX md5;
    MD5Init(&md5);
    int i;
    unsigned char encrypt[] ="admin";//21232f297a57a5a743894a0e4a801fc3
    unsigned char decrypt[16];
    MD5Update(&md5,encrypt,strlen((char *)encrypt));
    MD5Final(&md5,decrypt);
    printf("加密前:%s\n加密后16位:",encrypt);
    for(i=4;i<12;i++)
    {
        printf("%02x",decrypt[i]);  //02x前需要加上 %
    }

    printf("\n加密前:%s\n加密后32位:",encrypt);
    for(i=0;i<16;i++)
    {
        printf("%02x",decrypt[i]);  //02x前需要加上 %
    }

    getchar();


    return 0;
}



void second()
{
        if (sodium_init() < 0) {
        /* panic! the library couldn't be initialized, it is not safe to use */
            printf("sodium_init()  error! \n");
            return -1;
        }else{
            printf("sodium_init() success!\n");
        }

        unsigned char *message = "Arbitrary data to hash";

        int message_len = 22;

        unsigned char hash[crypto_generichash_BYTES];

        crypto_generichash(hash, sizeof hash, message, message_len, NULL, 0);



}

void first()
{

    unsigned char key[crypto_secretbox_MACBYTES] = "xiaozhuzhu";
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    unsigned char ciphertext[CIPHERTEXT_LEN];

    crypto_secretbox_keygen(key);

    //randombytes_buf(nonce, sizeof nonce);

    crypto_secretbox_easy(ciphertext, MESSAGE, MESSAGE_LEN, nonce, key);

    unsigned char decrypted[1024];


    memset(decrypted, 0, sizeof decrypted);


    if(crypto_secretbox_open_easy(decrypted, ciphertext, CIPHERTEXT_LEN, nonce, key) != 0){


    }
    else
    {
        printf("message: %s \n" , decrypted);

    }

}
