/*  ����һ������Ӣ�Ĵ�д��ĸ�����š����Ϳո����ɵ�Ӣ�ľ��ӣ��ַ���������80������������k��1<=k<=26��
	�����еĴ�дӢ����ĸ�滻����ĸ���и���ĸ��ʼ�ĵ�k����ĸ�������ַ����ֲ���.
	
	�������룺
	ON A CLEAR DAY,YOU CAN SEE FOREVER
	9
	Ԥ�������
	VWI K MTZIL GIG,CWK VIA MMN ZWDMZM
*/

#include<stdio.h>

int main(){
	char sentence1[81]={0}, sentence2[81]={0}, ch=0;
	int k=0;
	scanf("%[^\n]",sentence1); //! ʹ scanf �ܹ����뺬�пո�����ַ���
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



	//Ȼ���ٽ�����ת������ľ��Ӵ������������ַ�������������ʣ�µ����ַ��򲻻�,��������ľ���
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