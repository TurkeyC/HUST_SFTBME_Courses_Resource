#include <stdio.h>
unsigned short change(char ch, int shift )
{
	//����shiftλ��shift+1λ��ֵ
	unsigned short mask = 0x01;
	//return (((ch & (mask << shift)) << 1) | ((ch & (mask << (shift + 1))) >> 1));
	return (( (ch & 0x55) << 1 ) | ((ch & 0xaa) >> 1)) & 0x3F;
}



void printBinary(unsigned int num) {
    unsigned int mask = 1U << (sizeof(num) * 8 - 1); // �����λ��ʼ

    for (int i = 0; i < sizeof(num) * 8; ++i) {
        putchar((num & mask) ? '1' : '0'); // ��鵱ǰλ�Ƿ�Ϊ1
        num <<= 1; // ����������һλ��׼�������һλ
    }
}

int main() {
/*	char string[100] = {0};
	unsigned char data[4] = {0}; 
	scanf("%s", string);

	for(int i = 0; string[i] != '\0'; i++)
	{	data[4] = string[i];

		int data_len = sizeof(data) / sizeof(data[0]);
		
		printf("Original data: ");
		for (int i = 0; i < data_len; ++i) {
			printf("%02X ", data[i]);
		}
		printf("\n");
		
		// ��������
		for (int i = 0; i < data_len; ++i) {
			unsigned char byte = data[i];
			
			// ����0��2��4λ��1��3��5λ
			byte = ((byte & 0x01) << 4) | // 0->4
				((byte & 0x04) << 1) | // 2->1
				((byte & 0x10) >> 2) | // 4->2
				((byte & 0x40) >> 1) | // 6->5
				((byte & 0x02) << 3) | // 1->6
				((byte & 0x08) >> 0) | // 3->3
				((byte & 0x20) >> 3);  // 5->0
			
			// ��ȡ6��7λ��ֵ
			int shift = (byte & 0xC0) >> 6;
			
			// ��0~5λ����ѭ������
			byte = ((byte & 0xFC) << shift) | ((byte & 0x03) >> (8 - shift));
			
			// ���¼��ܺ������
			data[i] = byte;
		}
		
		printf("Encrypted data: ");
		for (int i = 0; i < data_len; ++i) {
			printf("%02X ", data[i]);
		}
		printf("\n");
	}
*/    


	//char string[100] = {0};
	//scanf("%s", string);

	unsigned char ch = 'b', ch50 = 0, ch05 = 0, ch76 = 0, ch76_bin = 0;
	printBinary(ch);
	printf("\n");
	change(ch, 1);
	ch50 = change(ch, 0) | change(ch, 2) | change(ch, 4);
	printBinary(ch50);
	printf("\n");


	ch76 = ch & 0xC0;
	ch76_bin = ch76 >> 6;
	printBinary(ch76_bin);
	printf("\n");

	ch05 = ((ch50 << (ch76_bin)) & 0x3F) | (ch50 >> (6 - ch76_bin)) | ch76;
	printBinary(ch05);
	printf("\n");
	printf("%c", ch05);


    return 0;
}