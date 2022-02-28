#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// MUCÝT YAZILIM- Sadýk ÞAHÝN 

char kelimeler[][5]= {"AHMET", "HASAN", "MESUT", "EKMEK", "SIFIR", "TARIK", "FATMA", "ARMUT", "LEYLA", "BEYZA"  } ; 
char kelime[5],  tahmin[5], tablo[6][5], bilinenHarfler[5] = {'-','-','-','-','-'} ;  
static int indis, index; 
void kelimeUret() 
{
	srand (time(0)) ; 
	indis= rand() %10; 
	int i=0; 
	while( i<5 )
	{
	 kelime[i] = kelimeler[indis][i];
	 i++; 
	}
	index=0;  
 } 
 
 void yesil() 
 {
 	HANDLE renk = GetStdHandle(STD_OUTPUT_HANDLE ) ; 
	SetConsoleTextAttribute( renk, FOREGROUND_GREEN ) ; 
 }
  void normal () 
 {
 	HANDLE renk = GetStdHandle(STD_OUTPUT_HANDLE ) ; 
	SetConsoleTextAttribute( renk, FOREGROUND_INTENSITY );   
 }
  
int tabloDoldur() 
{	
	int sonuc=1;
	int i ; 
	for( i=0; i<5; i++  ) 
	{
				
		if( kelime[i] != tahmin[i] ) 
		{ 		
			sonuc=0;
			bilinenHarfler[i]='-';  	
		} 
		else
		bilinenHarfler[i]= tahmin[i]; 
		
		tablo[index][i]= tahmin[i]; 		
	}
	index++; 	

		
	return sonuc; 
}
void  tabloYazdir () 
{
		int i,j; 
	printf("\n\n\t\t\t   WORDLE TR \n\n") ; 
	
	for ( i =0; i<6; i++   ) 
	{
		printf("\t\t") ; 
		for(j=0; j<5; j++ )
		{
			if( i==index -1 )
			{
				if( kelime[j] == tahmin[j] ) 
				{
				printf(" [ " ) ; 
				yesil(); 			
				printf("%c", tablo[i][j] ) ; 
				normal(); 			
				printf(" ] ") ; 	
				}
				else		
			printf(" [ %c ] ", tablo[i][j] ) ; 
								
			}
			else		
			printf(" [ %c ] ", tablo[i][j] ) ; 
			normal(); 
		}
		printf("\n\n") ;   
	 } 
	 
	yesil(); 
	normal(); 
		

}


int main( ) 
{
	
	int sayac=0, n, sonuc; 
	kelimeUret() ; 
	tabloYazdir() ;
	while( sayac < 6  ) 
	{
		printf("\n%d. Tahmininiz : ", sayac+1 ) ; scanf(" %[^\n]s", tahmin ) ; 
		strupr(tahmin) ; 
		n= strlen(tahmin); 
		if(n!=5) 
		{
			printf("Tahmininiz 5 harflik anlamli kelimeler olmali ! \n") ; 
			continue ; 
		}		
		
		sonuc= tabloDoldur(); 
		tabloYazdir();
		
		if( sonuc==1 )
		break; 		 
		sayac++; 
	}
	
	if( sonuc ==1)
	{
		
		printf("\nTebrikler Bildiniz. \n") ; 
		printf("Gunun Kelimesi     : " ); 
		yesil(); 
		printf("%s", kelime ) ;
		normal(); 
		
		
	}
	else 
	{
		printf("\nMalesef Bilemediniz ! \n") ; 
		printf("Gunun Kelimesi      : " ); 
		yesil(); 
		printf("%s", kelime ) ;
		normal(); 		
	}
	
	return 0; 
}



