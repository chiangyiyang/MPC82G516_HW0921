/********** 4_5B_Homework.C ****************************
*動作：每按一次按鍵，令LED有六種變化
*硬體：SW1-2,3(8*8 LDE Matrix, P0LED)ON, 按KEY1 
***********************************************/
#include "MPC82.H"   //暫存器及組態定義

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

uint8 code greenMan[8][8]= //設定八個八單位矩陣
{
{0x00,0x8b,0xef,0x3c,0x18,0xa0,0xc0,0x00}, //第一張動作 走路中
{0x00,0xdb,0x6f,0x3c,0x18,0x28,0xd0,0x00}, //第二張動作 走路中
{0x10,0x4b,0x5f,0x3c,0x28,0x48,0xd0,0x00}, //第三張動作 走路中
{0x53,0x4f,0x3c,0x18,0x28,0x48,0x90,0x00}, //第四張動作 走路中
{0x93,0x8f,0xfc,0x38,0x28,0x50,0xe0,0x00}, //第五張動作 走路中
{0x93,0xcf,0x3c,0x38,0x48,0xd0,0x20,0x00}, //第六張動作 走路中
{0x03,0x5f,0xbc,0x78,0xc8,0x30,0x00,0x00}, //第七張動作 走路中
{0x00,0x03,0x0f,0x7c,0x58,0xe0,0x00,0x00} //第八張動作 走路中
};

char flag = 0;    //設定變數 
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

//void dotXY( uint8 X, uint8 Y, uint8 t){
//	Scan = ~(0x80>>X);
//	Data = ~(0x01<<Y);

//	Delay_ms( t ); 
//	
//	//Scan = Data = 0xFF;	
//}

void dotLine( int8 X0, int8 Y0, int8 DX, int8 DY, int8 n, int8 t){
	int8 i;
	for(i=0; i<n; i++){
		Scan = ~(0x80>>(X0 + DX*i));
		Data = ~(0x01<<(Y0 + DY*i));
		Delay_ms( t ); 		
	}
}

void showGreenMan( int8 mode ){
	//Green Go :Top, Bottom, Right, Left = 0, 1, 2, 3
	int8 i, j, k, t;
	Scan = (mode & 1)? 0xFE: 0X7F;
	for(t = 0 ; t < 4; t++){
		for(j = 0 ; j < 8; j++){
			for(k = 0 ; k < 10; k++){
				for(i = 0 ; i < 8; i++){
					switch (mode)
					{
						case 0://Top
							Data = ~greenMan[j][i];
							break;

						case 1://Bottom
							Data = ~revers(greenMan[j][i]);
							break;

						case 2://Right
							Data = ~revers(getRotateImage(j, i));
							break;

						case 3://Left
							Data = ~getRotateImage(j, i);
							break;
					}
					Delay_ms(1);
					Data =  0xFF;
					if(mode & 1) { Scan = RL8(Scan); } else { Scan = RR8(Scan); }
				}
			}
		}
	}
}



void dotShow(){
	uint8	t = 10;	
	int8 i, j;
	
	switch (dsState)
   {
		case 0:
			dotLine(7, 0, -1, 0, 8, t);
			break;
		
		case 1:
			dotLine(0, 0, 0, 1, 8, t);
			break;
		
		case 2:
			dotLine(0, 7, 1, 0, 8, t);
			break;
		
		case 3:
			dotLine(7, 7, 0, -1, 8, t);
			break;
		
		case 4:
			dotLine(7, 0, -1, 1, 8, t);
			break;
		
		case 5:
			dotLine(0, 7, 1, 0, 8, t);
			break;
		
		case 6:
			dotLine(7, 7, -1, -1, 8, t);
			break;
		
		case 7:
			dotLine(0, 0, 1, 0, 8, t);
			break;
			
   	case 8:
			showGreenMan(1); //Bottom
   		break;
			
   	case 9:
			showGreenMan(2); //Right
   		break;
		
   	case 10:
			showGreenMan(0); //Top
   		break;

   	case 11:
			showGreenMan(3); //Left		
   		break;

		case 12:
			i = 0;
			j = 1;
			do{
				dotLine(7-i, 0+i, -1, 0, 8-i-i, t);
				dotLine(0+i, 0+i, 0, 1, 8-i-i, t);
				dotLine(0+i, 7-i, 1, 0, 8-i-i, t);
				dotLine(7-i, 7-i, 0, -1, 8-i-i, t);
				i += j;
				if( i>=4) j = -1;
			}while( i > -1);
			break;
   }
	
	dsState = dsState == 12 ?  0 : dsState + 1;
}


void play(){
	
	uint16 dly;
	uint32 count;
	
	count = 0;
	while(1){
		
		if( littleBee[ inxlittleBee ] > 0){
			dly =  Pitch_TAB[ littleBee[ inxlittleBee ] -1 ];
			count += dly;
			while( dly-- ); //改變延時
			SPEAK = !SPEAK;   //SPEAK反相,令喇叭發出聲音
			if(count > 300000) break;
		}else{
			dly =  Pitch_TAB[ 0 ];
			count += dly;
			while( dly-- ); //改變延時
			NOP();
			if(count > 300000) break;
		}
	}
	inxlittleBee = inxlittleBee >= 63 ? 0 : inxlittleBee + 1;
}


main() 
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1)       //重覆執行 
   {		     //若flag=0，直接跳到此處
     if(KEY1==0)      //若有按鍵，flag反相
	  {
        Delay_ms(1); //延時，防止機械彈跳	   
        flag++; if(flag>5) flag=0;   
	    while(KEY1==0); //若未放開鍵，空轉 
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
			Delay_ms(100); //延時    
			
   }
}
