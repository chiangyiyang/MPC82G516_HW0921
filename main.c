/********** 4_5B_Homework.C ****************************
*�ʧ@�G�C���@������A�OLED�������ܤ�
*�w��GSW1-3(P0LED)ON, ��KEY1 
***********************************************/
#include "MPC82.H"   //�Ȧs���βպA�w�q

#define fSYS	2211840
uint16 code Pitch_TAB[] = {			      					//Pitch Control Table
			fSYS/(523*2*4),fSYS/(587*2*4),fSYS/(659*2*4),
			fSYS/(698*2*4),fSYS/(785*2*4),fSYS/(880*2*4),
			fSYS/(998*2*4),fSYS/(523*4*4)};

const uint8 littleBee[] = {
	5,3,3,0,4,2,2,0,
	1,2,3,4,5,5,5,0,
	5,3,3,0,4,2,2,0,
	1,3,5,5,3,0,0,0,
	2,2,2,2,2,3,4,0,
	3,3,3,3,3,4,5,0,
	5,3,3,0,4,2,2,0,
	1,3,5,5,1,0,0,0
};

uint8 code greenMan[8][8]= //�]�w�K�ӤK���x�}
{
{0x00,0x8b,0xef,0x3c,0x18,0xa0,0xc0,0x00}, //�Ĥ@�i�ʧ@ ������
{0x00,0xdb,0x6f,0x3c,0x18,0x28,0xd0,0x00}, //�ĤG�i�ʧ@ ������
{0x10,0x4b,0x5f,0x3c,0x28,0x48,0xd0,0x00}, //�ĤT�i�ʧ@ ������
{0x53,0x4f,0x3c,0x18,0x28,0x48,0x90,0x00}, //�ĥ|�i�ʧ@ ������
{0x93,0x8f,0xfc,0x38,0x28,0x50,0xe0,0x00}, //�Ĥ��i�ʧ@ ������
{0x93,0xcf,0x3c,0x38,0x48,0xd0,0x20,0x00}, //�Ĥ��i�ʧ@ ������
{0x03,0x5f,0xbc,0x78,0xc8,0x30,0x00,0x00}, //�ĤC�i�ʧ@ ������
{0x00,0x03,0x0f,0x7c,0x58,0xe0,0x00,0x00} //�ĤK�i�ʧ@ ������
};

char flag = 0;    //�]�w�ܼ� 
uint8 dsState = 0;
uint8 inxlittleBee = 0;

uint8 revers( uint8 org ){
	return ((org & 0x01) << 7 ) | ((org & 0x02) << 5) | ((org & 0x04) << 3) | ((org & 0x08) << 1)
		 | ((org & 0x10) >> 1) | ((org & 0x20) >> 3) | ((org & 0x40) >> 5) | ((org & 0x80) >> 7);
}

uint8 getRotateImage(uint8 i, uint8 j){
	return ((greenMan[i][0] >> j) & 0x01)
			| ((greenMan[i][1] >> j) & 0x01) << 1
			| ((greenMan[i][2] >> j) & 0x01) << 2
			| ((greenMan[i][3] >> j) & 0x01) << 3
			| ((greenMan[i][4] >> j) & 0x01) << 4
			| ((greenMan[i][5] >> j) & 0x01) << 5
			| ((greenMan[i][6] >> j) & 0x01) << 6
			| ((greenMan[i][7] >> j) & 0x01) << 7;
}

void dotShow(){
	uint8	t = 10;	
	uint8 i, j, k;
	
	switch (dsState)
   {
   	case 0:
			//X = 7>0 , Y = 0
			Scan = 0xFE;
			Data = 0xFE;
			do{
				Scan = RL8( Scan );
				Delay_ms( t  ); 
			}while( Scan != 0x7F );				
   		break;
		
   	case 1:
			//X = 0, Y = 0>7
			Scan = 0x7F;
			Data = 0xFE;
			do{
				Data = RL8( Data );
				Delay_ms( t  );
			}while( Data != 0x7F );			
   		break;

   	case 2:
			//X = 0>7, Y = 7
			Scan = 0x7F;
			Data = 0x7F;
			do{
				Scan = RR8( Scan );
				Delay_ms( t  ); 
			}while( Scan != 0xFE );				
   		break;

   	case 3:
			// X = 7, Y = 7>0
			Scan = 0xFE;
			Data = 0x7F;
			do{
				Data = RR8( Data );
				Delay_ms( t  ); 
			}while( Data != 0xFE );					
   		break;

   	case 4:
			//X = 7>0, Y = 0>7
			Scan = 0xFE;
			Data = 0xFE;
			do{
				Data = RL8( Data );
				Scan = RL8( Scan );
				Delay_ms( t  ); 
			}while( Data != 0x7F );			
   		break;

   	case 5:
			//X = 0>7, Y = 7
			Scan = 0x7F;
			Data = 0x7F;
			do{
				Scan = RR8( Scan );
				Delay_ms( t  ); 
			}while( Scan != 0xFE );				
   		break;

   	case 6:
			//X = 7>0, Y = 7>0
			Scan = 0xFE;
			Data = 0x7F;
			do{
				Data = RR8( Data );
				Scan = RL8( Scan );
				Delay_ms( t  ); 
			}while( Data != 0xFE );			
   		break;

   	case 7:
			//X = 0>7, Y = 0
			Scan = 0x7F;
			Data = 0xFE;
			do{
				Scan = RR8( Scan );
				Delay_ms( t  );
			}while( Scan != 0xFE );			
   		break;
			
   	case 8:
			//Green Go :Buttom
			Scan = 0xFE;

			for(t = 0 ; t < 4; t++){
				for(j = 0 ; j < 8; j++){
					for(k = 0 ; k < 10; k++){
						for(i = 0 ; i < 8; i++){
							Data = ~revers(greenMan[j][i]);
							Delay_ms(1);
							Data =  0xFF;
							Scan=RL8(Scan); //�����ˤU�@��
						}
					}
				}
			}
   		break;
			
   	case 9:
			//Green Go :Right
			Scan = 0x7F;
			for(t = 0 ; t < 4; t++){
				for(j = 0 ; j < 8; j++){
					for(k = 0 ; k < 10; k++){
						for(i = 0 ; i < 8; i++){
							Data = ~revers(getRotateImage(j, i));
							Delay_ms(1);
							Data =  0xFF;
							Scan=RR8(Scan); //�����ˤU�@��
						}
					}
				}
			}
   		break;
		
   	case 10:
			//Green Go :Top
			Scan = 0x7F;

			for(t = 0 ; t < 4; t++){
				for(j = 0 ; j < 8; j++){
					for(k = 0 ; k < 10; k++){
						for(i = 0 ; i < 8; i++){
							Data = ~greenMan[j][i];
							Delay_ms(1);
							Data =  0xFF;
							Scan=RR8(Scan); //�����ˤU�@��
						}
					}
				}
			}			
   		break;

   	case 11:
			//Green Go :Left
			Scan = 0xFE;
			for(t = 0 ; t < 4; t++){
				for(j = 0 ; j < 8; j++){
					for(k = 0 ; k < 10; k++){
						for(i = 0 ; i < 8; i++){
							Data = ~getRotateImage(j, i);
							Delay_ms(1);
							Data =  0xFF;
							Scan=RL8(Scan); //�����ˤU�@��
						}
					}
				}
			}
   		break;
   }
	
	dsState = dsState == 11 ?  0 : dsState + 1;
}


void play(){
	
	uint16 dly;
	uint32 count;
	
	count = 0;
	while(1){
		
		if( littleBee[ inxlittleBee ] > 0){
		
							dly =  Pitch_TAB[ littleBee[ inxlittleBee ] -1 ];
							count += dly;
							while( dly-- ); //���ܩ���
							SPEAK = !SPEAK;   //SPEAK�Ϭ�,�O��z�o�X�n��
							if(count > 300000) break;
		}else{
							dly =  Pitch_TAB[ 0 ];
							count += dly;
							while( dly-- ); //���ܩ���
							NOP();
							if(count > 300000) break;
		}
	}
	inxlittleBee = inxlittleBee >= 63 ? 0 : inxlittleBee + 1;
}


main() 
{
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  while(1)       //���а��� 
   {		     //�Yflag=0�A�������즹�B
     if(KEY1==0)      //�Y������Aflag�Ϭ�
	  {
        Delay_ms(1); //���ɡA�������u��	   
        flag++; if(flag>5) flag=0;   
	    while(KEY1==0); //�Y����}��A���� 
	  }

	switch (flag)
      {
				case 0:
					LED--;
					break;
				
				case 1:
					LED++;
					break;      
				
				case 2:
					LED=0;
					break;
				
				case 3:
					LED=0xFF;
					break;
				
				case 4:
					dotShow();
					break;
				
				case 5:
					Scan = 0xFF;
					play();
					break;
				
				default:
					break;
      }
			Delay_ms(100); //����    
			
   }
}
