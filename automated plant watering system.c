#include<reg51.h>
#define dis_port P2    
sbit rs = P3^2;  
sbit rw = P3^3; 
sbit e =  P3^4;  
sbit s=P1^0;
sbit r=P1^1;
void gpio_int()
{
s=0xFF;
r=0x00;

}
void delay(unsigned int time)  
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void cmd(unsigned char command)  
{
    dis_port = command;
    rs= 0;
    rw=0;
    e=1;
    delay(1);
    e=0;
}

void ldata(unsigned char disp_data)  
{
    dis_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    delay(1);
    e=0;
}

 void lcd_init()    
{		 
    cmd(0x38);  
    delay(10);
    cmd(0x06); 
    delay(10);    
			 
	 cmd(0x01);  
    delay(10);
	cmd(0x0F);  
    delay(10);
   
    cmd(0x81);  
    delay(10);

}
void dis()
{   unsigned char a[30]="  Starting "; 
    int l=0;
    lcd_init();
    while(a[l] != '\0') 
    {
        ldata(a[l]);
        l++;
        delay(1);
    }
}
void dis1()
{   unsigned char a[18]=" Low water";    
    int l=0;
    lcd_init();
    while(a[l] != '\0') 
    {
        ldata(a[l]);
        l++;
        delay(25);
    }
}
void dis2()
{   unsigned char a[18]="Water Enough ";    
    int l=0;
    lcd_init();
    while(a[l] != '\0') 
    {
        ldata(a[l]);
        l++;
        delay(25);
    }


}
void dis3()
{   unsigned char a[15]="Water Required";    
    int l=0;
    lcd_init();
    while(a[l] != '\0') 
    {
        ldata(a[l]);
        l++;
        delay(25);
    }
}
void dis4()
{   unsigned char a[19]="No Water Needed";   
    int l=0;
    lcd_init();
    while(a[l] != '\0') 
    {
        ldata(a[l]);
        l++;
        delay(25);
    }
}
void main()
{		gpio_int();
   		 dis();	 
		 while(1)
		 {
		 if(s==1)
		 { 
		  r=1;
		 dis1() ;
		
		 delay(10);
			 dis3();	


		 }
		 else if (s==0)	 {
		 r=0;
		 dis2();
		 
			delay(10);
								
				 dis4();	
		 }

		 }
}
