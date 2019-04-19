unsigned int ELFhash(char *str)
{
	unsigned int hash=0;
	unsigned int x=0;
	while(*str)
	{
		hash=(hash<<4)+*str;     //1
		if((x=hash & 0xf0000000)!=0)         //2
		{
			hash^=(x>>24);   //Ӱ��5-8λ������һ��   3
			hash&=~x;   //��ո���λ    4
		}
		str++;   //5
	}
	return (hash & 0x7fffffff);    //6
}
