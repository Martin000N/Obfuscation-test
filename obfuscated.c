#include<stdio.h>
#include<math.h>
#include<windows.h>

char a[0x1];

int main (){int b=80;int c=300;float d=0;float e=0;float f=0;printf("\033[1;1H\033[2J");
int g=b*c+c;char h[g];float i=0b1;float j=0b0;float k=0x0;float l=0x1;float m=(c>>1)/
tan(45);float n=cos(0.09);float o=sin(0.09);char p[]="@$#1{[!;:.";char q[]=",........'";
while (1){if (GetAsyncKeyState (0x52)){k=k*n+l*(-o);l=l*n-k*(-o);i=i*n+j*(-o);j=j*n-i*(-o);}
else if (GetAsyncKeyState (0x57)){d+=k;e+=l;}else if (GetAsyncKeyState (0x53)){d-=k;e-=l;}
else if (GetAsyncKeyState (0x44)){d+=i;e+=j;}else if (GetAsyncKeyState(0x41)){d-=i;e-=j;}
else if (GetAsyncKeyState (0x54)){k=k*n+l*o;l=l*n-k*o;i=i*n+j*o;j=j*n-i*o;}int r=0;for 
(int s=b>>1; s>-b>>1;s--){for (int t=-c>>1; t<=c>>1; t++){if (t==c>>1){h[r] = '\n';
}else{float u=k*m+t*i;float v=s;float w=l*m+t*j;float x=sqrt(pow(u, 2)+pow(v, 2)+pow(w, 2));
float y=u/=x;float z=v/=x;float aa=w/=x;float ab=fmax(fabs(y), fmax(fabs(z), fabs(aa)));
for (int ac=0; ac<100; ac++){double ad=d+ac*ab*u;float ae=f+ac*ab*v;double af=e+ac*ab*w;if 
(ae<-0x5){int ag=round(ac/0xa);h[r]=q[ag];break;}else if (ae > 0xa){int ag=round(ac/0xa);
h[r]=q[ag];break;}else if (a[(int)ceil(ad)*(int)ceil(af)+(int)ceil(af)]!=0||a[(int)floor(ad)
*(int)floor(af)+(int)floor(af)]!=0){int ag=round(ac/0xa);h[r]=p[ag];break;}else if (ac ==99)
{h[r]=' ';}}}r++;}}puts(h);Sleep(30);printf ("\x1b[d");}return 0;}
