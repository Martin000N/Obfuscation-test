#include<stdio.h>
#include<math.h>
#include<windows.h>

char mapa[0x1];

int main (){

	int y_res=80;
	int x_res=300;
	float pozicija_x=0;
	float pozicija_z=0;
	float pozicija_y=0;

	printf ("\033[1;1H\033[2J");

	int st_pikslov=y_res*x_res+x_res;
	char slika[st_pikslov];
	float stranski_vektor_x=1;
	float stranski_vektor_z=0;
	float sprednji_vektor_x=0;
	float sprednji_vektor_z=1;

	float oddaljenost_od_igralca=(x_res/2)/tan(45);
	float kosinus=cos(0.09);
	float sinus=sin(0.09);

	char barve_sten[]="@$#1{[!;:.";
	char barve_stropa[]=",........'";

	while (1){
		if (GetAsyncKeyState (0x52)){
			sprednji_vektor_x=sprednji_vektor_x*kosinus+sprednji_vektor_z*(-sinus);
			sprednji_vektor_z=sprednji_vektor_z*kosinus-sprednji_vektor_x*(-sinus);
			stranski_vektor_x=stranski_vektor_x*kosinus+stranski_vektor_z*(-sinus);
			stranski_vektor_z=stranski_vektor_z*kosinus-stranski_vektor_x*(-sinus);
		}
		else if (GetAsyncKeyState (0x57)){
			pozicija_x+=sprednji_vektor_x;
			pozicija_z+=sprednji_vektor_z;
		}
		else if (GetAsyncKeyState (0x53)){
		pozicija_x-=sprednji_vektor_x;
		pozicija_z-=sprednji_vektor_z;
		}
		else if (GetAsyncKeyState (0x44)){
		pozicija_x+=stranski_vektor_x;
		pozicija_z+=stranski_vektor_z;
		}
		else if (GetAsyncKeyState (0x41)){
		pozicija_x-=stranski_vektor_x;
		pozicija_z-=stranski_vektor_z;
		}
		else if (GetAsyncKeyState (0x54)){
		sprednji_vektor_x = sprednji_vektor_x * kosinus + sprednji_vektor_z * sinus;
		sprednji_vektor_z = sprednji_vektor_z * kosinus - sprednji_vektor_x * sinus;
		stranski_vektor_x = stranski_vektor_x * kosinus + stranski_vektor_z * sinus;
		stranski_vektor_z = stranski_vektor_z * kosinus - stranski_vektor_x * sinus;
		}

		int indeks_piksla=0;
		for (int y_piksla=y_res/2; y_piksla>-y_res/2; y_piksla--){
			for (int x_piksla=-x_res/2; x_piksla<=x_res/2; x_piksla++){
				if (x_piksla==x_res/2){
					slika[indeks_piksla] = '\n';
				}

				else{
					float x_pregledanega_piksla=sprednji_vektor_x*oddaljenost_od_igralca+x_piksla*stranski_vektor_x;
					float y_pregledanega_piksla=y_piksla;
					float z_pregledanega_piksla=sprednji_vektor_z*oddaljenost_od_igralca+x_piksla*stranski_vektor_z;

					float oddaljenost_piksla=sqrt(pow(x_pregledanega_piksla, 2)+pow(y_pregledanega_piksla, 2)+pow(z_pregledanega_piksla, 2));

					float sprememba_x=x_pregledanega_piksla/=oddaljenost_piksla;
					float sprememba_y=y_pregledanega_piksla/=oddaljenost_piksla;
					float sprememba_z=z_pregledanega_piksla/=oddaljenost_piksla;

					float korak=fmax(fabs(sprememba_x), fmax(fabs(sprememba_y), fabs(sprememba_z)));

					for (int stevilka_koraka=0; stevilka_koraka<100; stevilka_koraka++){
						double V =pozicija_x+stevilka_koraka*korak*x_pregledanega_piksla;
						float W =pozicija_y+stevilka_koraka*korak*y_pregledanega_piksla;
						double X =pozicija_z+stevilka_koraka*korak*z_pregledanega_piksla;
						
						if (W < -0x5){
							int indeks_barve=round(stevilka_koraka/10);
							slika[indeks_piksla]=barve_stropa[indeks_barve];
							break;
						}
						else if (W > 10){
							int indeks_barve=round(stevilka_koraka/10);
							slika[indeks_piksla]=barve_stropa[indeks_barve];
							break;
						}
						else if (mapa[(int)ceil(V)*(int)ceil(X)+(int)ceil(X)]!=0||mapa[(int)floor(V)*(int)floor(X)+(int)floor(X)]!=0){
							int indeks_barve=round(stevilka_koraka/10);
							slika[indeks_piksla]=barve_sten[indeks_barve];
							break;
						}
						else if (stevilka_koraka ==99){
							slika[indeks_piksla]=' ';
						}
					}
				}
				
				indeks_piksla++;
			}
		}
		
		puts(slika);

		printf("\nLokacija v spominu: 0x%p\n", (pozicija_x*pozicija_z+pozicija_z));
		Sleep(30);
		printf ("\x1b[d");

	}

  return 0;
}
