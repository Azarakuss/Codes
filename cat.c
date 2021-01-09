/* Proje 3
 * , ">" operatörünü yaptı,
 * , Opsiyonlar ve opsiyonların koda entegresi,
 * , Kopyala ve sadeceOku fonskiyonu
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int row = 1;
int sadeceOku(FILE *f)/*sadece okuyup ekrana yazdıran fonk*/
{
	char c;
	while((c = fgetc(f)) != EOF)
	{
		printf("%c", c);
	}
	
	printf("\n");
	fclose(f);
	
	return 0;
}

int kopyala(FILE *f, FILE *f2)/*Bir dosyayı diğerinin içine kopyalayan fonk.*/
{
	char c; 
	while((c = fgetc(f)) != EOF)
	{ 
		fputc(c, f2);
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	int k = 0;	
	int p = 0;
	
	for(int i = 1; i<argc; i++)
	{	
				
		if((strcmp(argv[i], ">")) == 0)/*işareti gördüyse*/
		{
			k = 1;
			p = i;
		}
		
		
		if((strcmp(argv[1], "-h")) == 0)
		{
			k = 2;
		}
	}
				
			
	if(k == 0)
	{	
		if(strcmp(argv[1], "-n") == 0)/*satır satır numaralandırma*/
		{
			for(int i=2; i<argc; i++)
			{
				FILE *f = fopen(argv[i], "r+"); 
				if(f == NULL)
				{ 
					return 0; 
				} 
				char s[100][250]; 
		
				while (fgets (s[row], 250, f) != NULL && row < 100)
				{			
					printf("%d-",row);
					printf("%.250s", s[row]);
					row++;						
				}
				printf("\n");
																		
			}				
		}
		
		else if(strcmp(argv[1], "-b") == 0)/*boş satıları göz ardı ederek numaralandırma*/
		{
			for(int i=2; i<argc; i++)
			{ 
				FILE *f = fopen(argv[i], "r+"); 
				if(f == NULL)
				{ 
					return 0; 
				} 
				char s[100][250]; 
         
				while (fgets (s[row], 250, f) != NULL && row < 100)
				{
			
					if((strcmp(s[row], "\t") != 0) && (strcmp(s[row], "\n") != 0) && (strcmp(s[row], " ") != 0))
					{
						printf("%d-",row);
						printf("%.250s", s[row]);
						row++;
					}
				
					else
					{
						printf("%.250s", s[row]);
					}
			
				}
						
				printf("\n");
					
			}
		}				
		
		else
		{
			for(int z=1; z<argc; z++)
			{
									
				FILE *f;
			
				f = fopen(argv[z], "r+");
			
				if(f == NULL)
				{
					printf("Dosyada veri bulunamadi !");
			
					return 0;
				}
		
				sadeceOku(f);
			}		 	
		}	
	}	
	
	
	if(k == 1)
	{			
		if(p == 1)/*komut satırından metin alan*/
		{
						
			FILE *f = fopen(argv[2], "w");
		
			char e;
			while((e = fgetc(stdin)) != EOF)
			{										
				fputc(e, f);				
			}
				
	
			return 0;
		}
		
					
			
		else if((p == argc-1))/*doğru kullanım*/
		{
			printf("\">\" operatorunu bu sekilde kullanamazsiniz.\n");
			printf("cat file1.txt \">\" file2.txt seklinde veya cat file1.txt file2.txt \">\" file3.txt seklinde kullanabilirsiniz.");
			
			return 0;
		}
			
			
		else 
		{						
			if(strcmp(argv[1], "-n") == 0)
			{
				for(int i = 2; i<argc; i++)
				{
					FILE *f = fopen(argv[i], "r"); 
					FILE *f2= fopen(argv[argc-1],"w"); 
						
					if(f == NULL)
					{ 
						return 0; 
					}
					char s[100]; 
					while (fgets (s, 100, f) != NULL)
					{
						fprintf(f2,"%d-",row);
						fprintf(f2,"%.250s", s);
						row++;
					}
					fclose(f); 
					return 0; 

				}
			}
			
			else if(strcmp(argv[1], "-b") == 0)
			{
				for(int i = 2; i<argc; i++)
				{
					FILE *f = fopen(argv[i], "r"); 
					FILE *f2= fopen(argv[i+1],"w"); 
					if(f == NULL)
					{ 
						return 0; 
					}
					char s[100]; 
	
	
					while (fgets (s, 100, f) != NULL)
					{
		
						if((strcmp(s, "\t") != 0) && (strcmp(s, "\n") != 0) && (strcmp(s, " ") != 0))
						{
							fprintf(f2,"%d-",row);
							fprintf(f2,"%.250s", s);
							row++;
						}
						else
						{
							fprintf(f2,"%.250s", s);
						}
					}
					fclose(f); 
					return 0; 

				}
			}
			
			
			else
			{
				for(int d=1; d<p; d++)
				{
								
					FILE *f, *f2;
				
					f = fopen(argv[d], "r+");
					f2 = fopen(argv[p+1], "w+");
				
					kopyala(f, f2);
					
					return 0;
				}
			}
		}
	}
	
	
	if(k == 2)
	{
		if(argv[2] != NULL)
		{
			printf("-h opsiyonunu herhangi bir dosya ile kullanamazsiniz. \n"
				   "-h opsiyonu sadece cat programini nasil kullanacaginiz hakkinda bilgi verir.");
	    }
				
		else/*Nasıl kullanılır*/
		{
			printf("\n\ncat programi dosyalari acip okumanizi,\n\n"
				"cat file1.txt , veya cat file1.txt file2.txt gibi yaparak dosya icerigini okuyabilirsiniz. \n\n\n"
				"\">\" operatoru ile yonlendirme yapabilmenizi saglar.\n\n"
				"cat \">\" file1.txt gibi yazarak direk komut satirindan giris yapip (Control-Z) + Enter ile  girisinizi sonlandirirsaniz \n\n"
				"giris yaptiginiz verileri hedef dosyaya yazdirir."
				"cat file1.txt \">\" file2.txt gibi veya cat file1.txt file2.txt \">\" file3.txt gibi yazarak \">\" operatorunden "
				"once belirttiginiz dosyalari \">\" operatorunden sonraki dosyaya, eger boyle bir dosya varsa icini sifirlar "
				"ve o sekilde yazdirir, eger boyle bir dosya yoksa ayni isimde bir dosya olusturarak yazdirir.\n\n"
				"Ancak \">\" operatorunu en sonda kullanirsaniz bir hata mesaj alirsiniz ve ornek kullanim gosterilir.\n\n"
				"cat \">\" gibi veya cat file1.txt \">\" veya cat file1.txt file2.txt \">\" gibi yazarsaniz bir hata mesaji alirsiniz ve "
				"ornek kullanim gorursunuz.\n\n");
		}


		return 0;
	}
}
	
