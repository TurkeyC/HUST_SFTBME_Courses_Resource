/*  输入一个仅有英文大写字母、逗号、句点和空格符组成的英文句子（字符数不超过80个）和正整数k（1<=k<=26）
	将其中的大写英文字母替换成字母表中该字母开始的第k个字母，其它字符保持不变.
	
	测试输入：
	ON A CLEAR DAY,YOU CAN SEE FOREVER
	9
	预期输出：
	VWI K MTZIL GIG,CWK VIA MMN ZWDMZM
*/

#include<stdio.h>

int main(){
	char sentence1[81]={0}, sentence2[81]={0}, ch=0;
	int k=0;
	scanf("%[^\n]",sentence1); //! 使 scanf 能够输入含有空格符的字符串
	scanf("%d",&k);

	// for(int i=0;sentence1[i]!='\0';i++){
	// 	ch=sentence1[i];
	// 	if(ch>='A' && ch<='Z'){
	// 		if(ch+(k-1)>'Z')  {ch=ch+(k-1)-26;}
	// 		else {ch=ch+(k-1);}
			
	// 		// ch=ch-'A'+k;
	// 		// ch=ch%26+'A';
	// 	}
	// 	printf("%c",ch);
	// }

	for(int i=0;sentence1[i]!='\0';i++){
		sentence2[i]=sentence1[i];
		if(sentence2[i]>='A' && sentence2[i]<='Z'){
			if(sentence2[i]+(k-1)>'Z')  {sentence2[i]=sentence2[i]+(k-1)-26;}
			else {sentence2[i]=sentence2[i]+(k-1);}
		}
		//printf("%c",sentence2[i]);
	}



	//然后再将上述转换过后的句子从左至右两两字符交换，若最后仅剩下单个字符则不换,并输出最后的句子
	for(int i=0;sentence2[i+1]!='\0';i+=2){
		
		ch=sentence2[i];
		sentence2[i]=sentence2[i+1];
		sentence2[i+1]=ch;
		if(sentence2[i+2] == '\0') break;
		//printf("%c",sentence2[i]);
		
	}
	printf("%s",sentence2);

	return 0;  
}