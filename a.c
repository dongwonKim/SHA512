#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdlib.h>

#ifndef HASH_WORD
#define HASH_WORD	8U
#endif

static uint64_t H[HASH_WORD];
static uint8_t *M;

void init_hash(void);
void read_file(char *path);

int main(int argc,char *argv[]){

	init_hash();
	read_file(argv[0]);

	return 0;
}

uint64_t Ch(uint64_t x,uint64_t y,uint64_t z){
	_asm {
			// push ebp
			// mov ebp,esp
			// mov esp, ebp
			// pop ebp
			// ret
	}

/*
 asm("commands"
     : output
     : input
     : registers);*/

	return x;
}
//uint64_t Maj(uint64_t x,uint64_t y,uint64_t z){
//	return (x & y) ^ (x ^ z) & (y ^ z);
//}

//Sn : right rotation by n bits  ROR
//Rn : right shift by n bits SHR

//uint64_t sum0(uint64_t x){
//	return Sn(x,28) ^ Sn(x,34) ^ Sn(x,39);
//}
//uint64_t sum1(uint64_t x){
//	return Sn(x,14) ^ Sn(x,18) ^ Sn(x,41);
//}
//uint64_t sigma0(uint64_t x){
//	return Sn(x,1) ^ Sn(x,8) ^ Rn(x,7);
//}
//uint64_t sigma1(uint64_t x){
//	return Sn(x,19) ^ Sn(x,61) ^ Rn(x,6);
//}

void read_file(char *path){
	FILE *in;
	int64_t len;
	int i;

	if((in = fopen(path,"rb")) == NULL){
		return;
	}
	else{

		//	    M = (uint8_t*)malloc(sizeof(uint8_t)*len);
		//	    fread(M, sizeof(char), sizeof(char)*len, in);

		fclose(in);
		free(M);


	}
}

void init_hash(void){
	H[0] = 0x6A09E667F3BCC908;
	H[1] = 0xBB67AE8584CAA73B;
	H[2] = 0x3C6EF372FE94F82B;
	H[3] = 0xA54FF53A5F1D36F1;
	H[4] = 0x510E527FADE682D1;
	H[5] = 0x9B05688C2B3E6C1F;
	H[6] = 0x1F83D9ABFB41BD6B;
	H[7] = 0x5BE0CD19137E2179;
}


/*
 int xor(int x,int y,int z){
00B913B0  push        ebp
00B913B1  mov         ebp,esp
00B913B3  sub         esp,0C0h
00B913B9  push        ebx
00B913BA  push        esi
00B913BB  push        edi
00B913BC  lea         edi,[ebp-0C0h]
00B913C2  mov         ecx,30h
00B913C7  mov         eax,0CCCCCCCCh
00B913CC  rep stos    dword ptr es:[edi]
   return (x & y) ^ (~x ^ z);
00B913CE  mov         eax,dword ptr [x]
00B913D1  and         eax,dword ptr [y]
00B913D4  mov         ecx,dword ptr [x]
00B913D7  not         ecx
00B913D9  xor         ecx,dword ptr [z]
00B913DC  xor         eax,ecx
}
00B913DE  pop         edi
00B913DF  pop         esi
00B913E0  pop         ebx
00B913E1  mov         esp,ebp
00B913E3  pop         ebp
00B913E4  ret
 */

/*int xor(int x,int y,int z){
00A813B0  push        ebp
00A813B1  mov         ebp,esp
00A813B3  sub         esp,0C0h
00A813B9  push        ebx
00A813BA  push        esi
00A813BB  push        edi
00A813BC  lea         edi,[ebp-0C0h]
00A813C2  mov         ecx,30h
00A813C7  mov         eax,0CCCCCCCCh
00A813CC  rep stos    dword ptr es:[edi]
   return (x & y) ^ (x & z) ^ (y & z);
00A813CE  mov         eax,dword ptr [x]
00A813D1  and         eax,dword ptr [y]
00A813D4  mov         ecx,dword ptr [x]
00A813D7  and         ecx,dword ptr [z]
00A813DA  xor         eax,ecx
00A813DC  mov         edx,dword ptr [y]
00A813DF  and         edx,dword ptr [z]
00A813E2  xor         eax,edx
}
00A813E4  pop         edi
00A813E5  pop         esi
00A813E6  pop         ebx
00A813E7  mov         esp,ebp
00A813E9  pop         ebp
00A813EA  ret*/

