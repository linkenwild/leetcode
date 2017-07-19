/*
* 557. Reverse Words in a String III
* note: 不完美解法，当输入字符数过多时，不能通过
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 倒序输出一个单词
char* reverseAWord(char *s)
{
	int length=0;
	int i=0;
	//static char temp[10];
	char *temp = (char *)malloc(200*sizeof(char));

	//while(*s++)length++; //注意：这种方式来获取字符串长度，会改变s指针位置
	length = strlen(s);
	printf("length:%d\n",length);
    //printf("raw Str: %s\n",s);

	for(i; i<length; i++)
	{
		temp[i] = s[length-i-1];
		printf("temp[%d] = %c\n",i,temp[i]);
	}
	temp[i] = '\0';

	printf("ret str : %s \n",temp);
	return temp;
}
#if 1
// 将句子分解成单词
char* reverseWords(char* s) {

    int index = 1,i=0,j=0,y;
    static int x = 0;
    int idx,count=0;//count表示句子中空格的个数
    int space[10] = {0};
    static char tempStr1[10],tempStr2[10];
    static char resStr[100];
    char *strPtr = s;
    char *resStrPtr = resStr;
    char *tempStr2Ptr = tempStr2;

    printf("raw str = %s\n",s);

    //找到空格并记录在数组中
    while(*s++ != '\0')
    {
        index++;
        if(*s == ' ')
        {
            space[++i] = index;
            count++;
            printf("get value\n");
        }
    }
    space[++count] = strlen(strPtr)+1;

    #if 0
    //for test
    for(j = 0; j<10; j++)
   // while(space[j+1] != 0)
    {
    //    j++;
        printf("space[%d] = %d\n",j,space[j]);
    }
    #endif

    //根据空格分解单词
    i = 0;
    j = 0;
    //count+=1;// 加一表示单词数量
    //while(space[i+1] != 0)
    while(count--)
    {
        printf("count-- = %d\n",count);
        //分解成单词
        for(j=0; j<(space[i+1]-space[i]-1); j++)
        {
            idx = j+space[i];
            //printf("s[%d] = %c\n",idx,strPtr[idx]);
            tempStr1[j] = strPtr[idx];
            printf("tempStr1[%d] = %c\n",j,tempStr1[j]);
        }
        tempStr1[j] = '\0';
        i++;
        printf("tempStr1 = %s\n",tempStr1);

        //逆序一个单词
        tempStr2Ptr = reverseAWord(tempStr1);
        //strcat(resStr,tempStr2);
        //strcat(resStr,' ');

        for(x,y=0; y<strlen(tempStr2Ptr); x++,y++)
        {
            resStr[x] = tempStr2Ptr[y];
        }
        if(count != 0)
            resStr[x++] = ' ';

    }
    printf("resStr = %s\n",resStr);
	return resStr;
}
#endif
int main()
{
	char rawStr[] = "let's take LeetCode contest";
	//char rawStr[] = "hello";
	char aWord[] = "let's";
	char *ptr;

	//char resStr[50] = {0},*ptr;
	//ptr = resStr;

	//ptr = reverseAWord(aWord);
	ptr = reverseWords(rawStr);

	printf("raw str len=%d, str len=%d\n",strlen(rawStr),strlen(ptr));
	printf("ptr:%s\n",ptr);

	return 0;
}
