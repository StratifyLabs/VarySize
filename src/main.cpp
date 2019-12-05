#include <cstdio>
#include <mcu/types.h>

extern const u8 some_data[DATA_SIZE];

int main(int argc, char * argv[]){

	u32 sum = 0;
	for(u32 i=0; i < sizeof(some_data)/sizeof(u8); i++){
		sum += some_data[i];
	}

	printf("Data size is %d %ld\n", sizeof(some_data), sum);

	return 0;
}

const u8 some_data[DATA_SIZE] = {
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 1, 2, 3, 4, 5, 6, 7,
};
