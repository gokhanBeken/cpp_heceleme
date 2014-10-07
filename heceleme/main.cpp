#include <iostream>
#include <string>

//deðiþkenler:
std::string kelime = "mustafa gokhan beken";
std::string kelime_yedek = kelime;
std::string hece = "";
int ilkSesliHarf=0; //ilk sesli harfin pozisyonu
char birSonrakiHarfSesliMi=0; //1 sesli,0 sessiz
char ikiSonrakiHarfSesliMi=0; //1 sesli,0 sessiz
char ucSonrakiHarfSesliMi=0; //1 sesli,0 sessiz
char sesliHarfler[11]="AaEeIiOoUu";

//fonksiyonlar:
void Hecele(void);
char sesliSessiz(char harf);
int IlkSesliHarfiBul(std::string str);

using namespace std;

int main ()
{
	while(kelime_yedek.length()>0){
	
		Hecele();
		
		cout << hece;	
		if(kelime_yedek.length()>1)cout << "-";	
	}
	cout <<  endl;	
  	return 0;
}

void Hecele(void)
{
	ilkSesliHarf=IlkSesliHarfiBul(kelime_yedek);	
	
	birSonrakiHarfSesliMi=sesliSessiz(kelime_yedek[ilkSesliHarf+1]);
	
	if(birSonrakiHarfSesliMi){
		//sesli harfin saðýndan heceyi bol:
		hece=kelime_yedek.substr (0,ilkSesliHarf+1);
		kelime_yedek.erase (0,ilkSesliHarf+1);
		return;
		//cout << "debug : 1 " << kelime_yedek<< endl;
	}
	else{
		//iki sonraki harfi kontrol et, sesli mi sessiz mi:
		ikiSonrakiHarfSesliMi=sesliSessiz(kelime_yedek[ilkSesliHarf+2]);
		if(ikiSonrakiHarfSesliMi){ //iki sonraki harf sesli
			hece=kelime_yedek.substr (0,ilkSesliHarf+1);
			kelime_yedek.erase (0,ilkSesliHarf+1);
			
			//cout << "debug : 2 " << kelime_yedek << endl;
			return;
		}
		else{//iki sonraki harf sessiz
			hece=kelime_yedek.substr (0,ilkSesliHarf+2);
			kelime_yedek.erase (0,ilkSesliHarf+2);
			//cout << "debug : 3 " << kelime_yedek << endl;
			return;
		}
	}	
}	

int IlkSesliHarfiBul(std::string str)
{
	int i=0;
	for(i=0;i<str.length();i++){
		if(sesliSessiz(str[i]))break;
	}
	  
	return(i);
}


char sesliSessiz(char harf)
{
   char i=0;
   while(i<11){
      if(harf==sesliHarfler[i])return(1);
      i++;
   }
   return(0);
}
