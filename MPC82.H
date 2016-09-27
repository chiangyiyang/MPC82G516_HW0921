/*-----------------------------------------------
MPC82G.H
-----------------------------------------------*/
//重新定義變數的型態名稱
typedef unsigned char   uint8;  // 無符號8-bit整數變數       
typedef signed   char  	int8;   // 有符號8-bit整數變數       
typedef unsigned int 	uint16; // 無符號16-bit整數變數      
typedef signed   int 	int16;  // 有符號16-bit整數變數      
typedef unsigned long  	uint32; // 無符號32-bit整數變數      
typedef signed   long  	int32;  // 有符號32-bit整數變數      
typedef float          	fp32;   // 單精度浮點數(32bit)

//重新定義Keil內部<intrins.h>函數
#include  <intrins.h>  //包括邏輯運算函數庫設定
#define RR8(x)  _cror_(x,1); //定義8-bit變數x右旋轉1-bit
#define RR16(x) _iror_(x,1); //定義16-bit變數x右旋轉1-bit
#define RR32(x) _lror_(x,1); //定義32-bit變數x右旋轉1-bit

#define RL8(x)  _crol_(x,1); //定義8-bit變數x左旋轉1-bit
#define RL16(x) _irol_(x,1); //定義16-bit變數x左旋轉1-bit
#define RL32(x) _lrol_(x,1); //定義32-bit變數x左旋轉1-bit

#define NOP() _nop_();  //定義空指令，延時一個機械週期時間
//----------------------------------------------
sfr  P0   = 0x80;  //P0輸出入埠暫存器
sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
sbit P0_4 = P0^4;
sbit P0_5 = P0^5;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;
//----------------------------------------------
sfr SP      = 0x81; //堆疊指標暫存器
sfr DPL     = 0x82; //資料指標低位元組暫存器
sfr DPH     = 0x83; //資料指標高位元組暫存器
//------------------------------------------------
sfr PCON    = 0x87;	 //功率控制暫存器
#define IDL    0x01  //1=進入idle省電模式
#define PD     0x02  //1=進入power down省電模式  
#define GF0    0x04  //通用存取位元
#define GF1    0x08  //通用存取位元
#define POF    0x10  //冷開機重置旗標，1=為冷開機所產生的重置(預定)
#define SMOD0  0x40  //1=設定UART1為增強型UART
#define SMOD   0x80  //1=UART1鮑率加倍
//------------------------------------------------
sfr TCON  = 0x88;	//Timer0-1控制暫存器
sbit IT0  = TCON^0;  	//INT0中斷信號選擇,1=負緣觸發輸入,0=低準位輸入 
sbit IE0  = TCON^1;	//INT0顯示旗標,1=INT0中斷成立
sbit IT1  = TCON^2;	//INT1中斷信號選擇,1=負緣觸發輸入,0=低準位輸入
sbit IE1  = TCON^3;	//INT1顯示旗標,1=INT1中斷成立
sbit TR0  = TCON^4;	//T0啟動位元,TR0=1令Timer0開始工作
sbit TF0  = TCON^5;	//T0溢位旗標,Timer0溢位時，令TF0=1
sbit TR1  = TCON^6;	//T1啟動位元,1=令Timer1開始工作
sbit TF1  = TCON^7;	//T1溢位旗標,Timer1溢位時，令TF1=1
//------------------------------------------------
sfr TMOD    = 0x89;	 //Timer0-1模式暫存器
#define T0_M0   0x01 //Timer0模式位元0
#define T0_M1   0x02 //Timer0模式位元1
#define T0_CT   0x04 //0=Timer0為內部計時，1=外部計數
#define T0_GATE 0x08 //1=Timer0由INT0腳(P32)啟動
#define T1_M0   0x10 //Timer1模式位元0
#define T1_M1   0x20 //Timer1模式位元1
#define T1_CT   0x40 //0=Timer1為內部計時，1=外部計數
#define T1_GATE 0x80 //1=Timer1由INT1腳(P33)啟動
//------------------------------------------------
sfr TL0 = 0x8A;	 //Timer0計時/計數低位元組暫存器
sfr TL1 = 0x8B;	 //Timer1計時/計數低位元組暫存器
sfr TH0 = 0x8C;	 //Timer0計時/計數高位元組暫存器
sfr TH1 = 0x8D;	 //Timer1計時/計數高位元組暫存器
//------------------------------------------------
sfr P1    = 0x90;  //P1輸出入埠暫存器
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

sbit T2   = P1^0;  //Timer2外部計數輸入腳(P10)
sbit T2EX = P1^1;  //Timer2外部重新載入/捕捉觸發輸入腳(P11)
//------------------------------------------------
sfr SCON  = 0x98; //UART串列埠控制暫存器
sbit RI   = SCON^0; //UART接收旗標，接收完成時，RI=1
sbit TI   = SCON^1; //UART發射旗標，發射完成時，TI=1
sbit RB8  = SCON^2; //UART模式2、3中，存放接收到的第9bit 
sbit TB8  = SCON^3; //UART模式2、3中，發射資料的第9bit
sbit REN  = SCON^4; //UART接收致能，REN=1允許接收串列資料
sbit SM2  = SCON^5; //UART工作模式設定
sbit SM1  = SCON^6;
sbit SM0  = SCON^7;

sbit FE   = SCON^7; //資料框錯誤(Frame Error)偵測(MPC82 Only)
//------------------------------------------------
sfr SBUF    = 0x99; //UART串列緩衝暫存器
//------------------------------------------------
sfr P2    = 0xA0;  //P2輸出入埠暫存器
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;
sbit P2_5 = P2^5;
sbit P2_6 = P2^6;
sbit P2_7 = P2^7;
//------------------------------------------------
sfr IE    = 0xA8;  //中斷致能暫存器
sbit EX0  = IE^0;  //1=致能INT0中斷
sbit ET0  = IE^1;  //1=致能Timer0中斷
sbit EX1  = IE^2;  //1=致能INT1中斷
sbit ET1  = IE^3;  //1=致能Timer1中斷
sbit ES   = IE^4;  //1=致能UART中斷
sbit ET2  = IE^5;  //1=致能Timer2中斷
sbit EA   = IE^7;  //0=禁能所有中斷
//------------------------------------------------
sfr P3    = 0xB0;  //P3輸出入埠暫存器
sbit P3_0 = P3^0;
sbit P3_1 = P3^1;
sbit P3_2 = P3^2;
sbit P3_3 = P3^3;
sbit P3_4 = P3^4;
sbit P3_5 = P3^5;
sbit P3_6 = P3^6;
sbit P3_7 = P3^7;

sbit RXD0 = P3^0;   //UART串列接收輸入腳(P30)
sbit TXD0 = P3^1;   //UART串列發射輸出腳(P31)
sbit INT0 = P3^2;   //外部中斷INT0輸入腳(P32)
sbit INT1 = P3^3;   //外部中斷INT1輸入腳(P33)
sbit T0   = P3^4;   //Timer0外部計數輸入腳(P34)
sbit T1   = P3^5;   //Timer1外部計數輸入腳(P35)
sbit WR   = P3^6;   //外部資料記憶體寫入控制腳(P36)
sbit RD   = P3^7;   //外部資料記憶體讀取控制腳(P37)

//------------------------------------------------
sfr  IP   = 0xB8; //中斷優先暫存器
sbit PX0  = IP^0; //1=INT0中斷優先
sbit PT0  = IP^1; //1=Timer0中斷優先
sbit PX1  = IP^2; //1=INT1中斷優先
sbit PT1  = IP^3; //1=Timer1中斷優先
sbit PS   = IP^4; //1=UART中斷優先
sbit PT2  = IP^5; //1=Timer2中斷優先

/* Timer2*暫存器 */
sfr T2MOD   = 0xC9; //Timer2 模式暫存器(僅MPC82G516)
#define DCEN    0x01  //1=Timer2下數計數致能
#define T2CKOE  0x02  //1=Timer2時脈輸出致能

sfr T2CON = 0xC8;   //Timer2控制暫存器
sbit CP_RL2= T2CON^0;  //0=重新載入(Reload),1=捕捉(Capture )
sbit C_T2 =  T2CON^1;   //0=計時(Timer),1=計數(Counter)
sbit TR2  =  T2CON^2;   //1=開始計時
sbit EXEN2=  T2CON^3;  	//1=致能T2EX腳輸入負緣觸發
sbit TCLK =  T2CON^4;   //0=串列埠發射時脈使用Timer1，1=使用Timer2
sbit RCLK =  T2CON^5;   //0=串列埠接收時脈使用Timer1，1=使用Timer2 
sbit EXF2 =  T2CON^6;   //T2EX腳輸入旗標
sbit TF2  =  T2CON^7;   //Timer2溢位旗標

sfr16  RCAP2  = 0xCA; //Timer2重新載入/捕捉暫存器
sfr RCAP2L  = 0xCA;   //Timer2重新載入/捕捉暫存器低位元組
sfr RCAP2H  = 0xCB;   //Timer2重新載入/捕捉暫存器高位元組

sfr16 T2R   = 0xCC;   //Timer2計時/計數暫存器
sfr TL2     = 0xCC;   //Timer2計時/計數暫存器低位元組
sfr TH2     = 0xCD;   //Timer2計時/計數暫存器高位元組

//------------------------------------------------
sfr PSW   = 0xD0;  	//程式狀態字元暫存器
sbit P    = PSW^0;	//同位元旗標，0=偶同位元，1=奇同位元
sbit OV   = PSW^2;	//溢位旗標，1=有溢位
sbit RS0  = PSW^3;	//暫存器庫選擇
sbit RS1  = PSW^4;	//暫存器庫選擇
sbit F0   = PSW^5;	//通用讀寫位元
sbit AC   = PSW^6;  //半進位旗標，1=有半進位或有半借位
sbit CY   = PSW^7;  //進位旗標，1=有進位或有借位
//----------------------------------------------
sfr ACC   = 0xE0;	//累積器
sfr B     = 0xF0;	//累積器
/*------------------------------------------------
中斷向量位址 = (中斷向量編號 * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR	  0  //INT0外部中斷，中斷向量位址0x03
#define TF0_VECTOR	  1  //Timer0溢位中斷，中斷向量位址0x0B
#define IE1_VECTOR	  2  //INT1外部中斷，中斷向量位址0x13
#define TF1_VECTOR	  3  //Timer1溢位中斷，中斷向量位址0x1B
#define UART_VECTOR   4  //UART1傳輸中斷，中斷向量位址0x23
#define TF2_VECTOR	  5  //Timer2溢位中斷，中斷向量位址0x2B
#define EX2_VECTOR	  5  //Timer2外部中斷，中斷向量位址0x2B
#define IE2_VECTOR    6  //INT2外部中斷，中斷向量位址0x33
#define IE3_VECTOR    7  //INT3外部中斷，中斷向量位址0x3B	
#define SPI_VECTOR    8  //SPI中斷，中斷向量位址0x43
#define ADC_VECTOR    9  //ADC中斷，中斷向量位址0x4B
#define PCA_VECTOR    10 //PCA中斷，中斷向量位址0x53
#define LVI_VECTOR    11 //低電源電壓中斷，中斷向量位址0x5B
#define UART2_VECTOR  12 //UART2傳輸中斷，中斷向量位址0x63
#define KBI_VECTOR    13 //Keypad中斷，中斷向量位址0x6B	

//*******MPC82特殊暫功能存器****************************
/*接腳模式暫存器*/
sfr P1M0 = 0x91;//P1接腳模式
sfr P1M1 = 0x92;//00=標準雙向輸出，01=推挽式輸出，10=僅輸入，11=開洩極輸出

sfr P0M0 = 0x93;//P0接腳模式
sfr P0M1 = 0x94;//00=標準雙向輸出，01=推挽式輸出，10=僅輸入，11=開洩極輸出

sfr P2M0 = 0x95;//P2接腳模式
sfr P2M1 = 0x96;//00=標準雙向輸出，01=推挽式輸出，10=僅輸入，11=開洩極輸出

sfr P3M0 = 0xB1;//P3接腳模式
sfr P3M1 = 0xB2;//00=標準雙向輸出，01=推挽式輸出，10=僅輸入，11=開洩極輸出

sfr P4M0 = 0xB3;//P4接腳模式 
sfr P4M1 = 0xB4;//00=標準雙向輸出，01=推挽式輸出，10=僅輸入，11=開洩極輸出

sfr EVRCR = 0x97;    //檢測電源提供狀態
#define  OPF   0x01  //1=當VDD腳輸入電壓低於3.7V時
#define  CPF   0x02  //1=當V3O腳輸出電壓低於2.4V時
#define  EOPFI 0x04  //1=致能當VDD腳輸入電壓低於3.7V時產生中斷
#define  ECPFI 0x08  //1=致能當V3O腳輸出電壓低於2.4V時產生中斷

sfr STRETCH = 0x8F;   //外部記憶體控制腳ALE及R/W時脈設定(MPC82G516 Only)

/*輔助暫存器*/
sfr AUXR = 0x8E;   //輔助暫存器
#define     EXTRAM 0x02   //1=禁能ERAM，0=致能內部ERAM位址0x000~0FFF
#define     P35ALE  0x10  //1=P35為ALE腳，0=P35為IO腳
#define     P41ALE  0x20  //1=P41為ALE腳，0=P41為IO腳
#define     ADRJ    0x40  //1=數位資料ADCH向右移，0=數位資料ADCH向左移
#define     URTS    0x80  //1=致能S2BRT提供UART1速率時脈

sfr AUXR1   = 0xA2;       //輔助暫存器(MPC82G516 Only)
#define     DPS     0x01  //使用的DPTR，0=DPTR0，1=DPTR1 
#define     GF2     0x08  //通用位元旗標 
#define     P4S2    0x10  //1=P4.2及P4.3為UART2，0=P1.2及P1.3為UART2
#define     P4SPI   0x20  //1=P4.7-4.3為SPI，0=P1.7-4為SPI 
#define     P4PCA   0x40  //1=P4為PCA，0=P1為PCA 
#define     P4KB    0x80  //1=P4為 keypad，0=P2為 keypad

sfr AUXIE   = 0xAD; //輔助中斷致能暫存器
#define ESPI  0x01  //SPI中斷致能
#define EADC  0x02  //ADC中斷致能
#define EPCA  0x04  //PCA中斷致能
#define EBD   0x08  //電源偵測中斷致能
#define ES2   0x10  //UART2中斷致能
#define EKBI  0x20  //按鍵中斷致能

sfr AUXIP   = 0xAE; //優先輔助暫存器
#define PSPI  0x01  // SPI中斷優先
#define PADC  0x02  // ADC中斷優先
#define PPCA  0x04  // PCA中斷優先
#define PBD   0x08  // 電源偵測中斷優先
#define PS2   0x10  // UART2中斷優先
#define PKB   0x20  // 按鍵中斷優先

sfr AUXIPH  = 0xAF; //高優先輔助暫存器
#define PSPIH 0x01  //SPI中斷高優先
#define PADCH 0x02  //ADC中斷高優先
#define PPCAH 0x04  //PCA中斷高優先
#define PBDH  0x08  //電源偵測中斷高優先
#define PS2H  0x10  //UART2中斷高優先
#define PKBH  0x20  //Keypad中斷高優先，1=高優先 

sfr AUXR2   = 0xA6;   //輔助暫存器(MPC82G516 Only)
#define T0CKOE  0x01  //1=致能T0溢位時由P34腳反相輸出 
#define S2CKOE  0x02  //1=致能UART2速率時脈由P35腳輸出 
#define S2TX12  0x04  //1=UART2時脈為系統頻率，0=UART2時脈為系統頻率/12  
#define S2SMOD  0x08  //1=UART2速率加倍 
#define S2TR    0x10  //1=UART2啟動位元
#define URM0X6  0x20  //1=系統頻率/2，0=UART mode0時脈為系統頻率/12
#define T1X12   0x40  //1=T1時脈為系統頻率，0=T1時脈為系統頻率/12
#define T0X12   0x80  //1=T0時脈為系統頻率，0=T0時脈為系統頻率/12

/* UART2暫存器 */
sfr S2BUF   = 0x9A;   //(MPC82G516 Only)
sfr S2BRT   = 0xBA;   //(MPC82G516 Only)

sfr S2CON   = 0xAA;   //(MPC82G516 Only)
#define S2RI    0x01  //UART2接收旗標，接收完成時，RI=1
#define S2TI    0x02  //UART2發射旗標，發射完成時，TI=1
#define S2RB8   0x04  //UART2模式2、3中，存放接收到的第9bit 
#define S2TB8   0x08  //UART2模式2、3中，發射資料的第9bit
#define S2REN   0x10  //UART2接收致能，REN=1允許接收串列資料
#define S2SM2   0x20  //UART2工作模式設定
#define S2SM1   0x40 
#define S2SM0   0x80


sfr SADDR   = 0xA9;		  //Slave Address

sfr SVAR    = 0xCE;       //(MPC82G516 Only)
sfr SBK     = 0xCF;       //(MPC82G516 Only)
sfr SADEN   = 0xB9;

sfr PCON2   = 0xC7;		
#define SCKD1   0  //SCKD3-0=系統除頻控制位元
#define SCKD2   1
#define SCKD4   2
#define SCKD8   3
#define SCKD16  4
#define SCKD32  5
#define SCKD64  6
#define SCKD128 7

/* Keypad暫存器*/
sfr KBPATN  = 0xD5;       //(MPC82G516 Only)
sfr KBMASK  = 0xD7;       //(MPC82G516 Only)

sfr KBCON   = 0xD6;       //(MPC82G516 Only)
#define KBIF  0x01       //鍵中斷Keypad中斷旗標
#define PATNS  0x02       //Keypad有比較功能

sbit KBI0   = P2^0;
sbit KBI1   = P2^1;
sbit KBI2   = P2^2;
sbit KBI3   = P2^3;
sbit KBI4   = P2^4;
sbit KBI5   = P2^5;
sbit KBI6   = P2^6;
sbit KBI7   = P2^7;

/* WDT暫存器  */
sfr TSTWD   = 0xA7;   //WDT測試(MPC82G516 Only)

sfr WDTCR   = 0xE1;	 //WDT控制
#define PS2_0 0x01  //Fosc預除倍數，000=Fosc/2, 001=Fosc/4, 010=Fosc/8,  011=Fosc/16,
                    //        100=Fosc/32,101=Fosc/64,110=Fosc/128,111=Fosc/256
#define WIDL  0x08  //1=在Idle模式WDT仍計數，0=在Idle模式WDT停止計數
#define CLRW  0x10  //1=清除WDT計數器為0
#define ENW   0x20  //1=致能WDT計數
#define WRF   0x80	//1=WDT溢位重置(reset)旗標

/* ADC暫存器  */
sfr ADCTL   = 0xC5;      // ADC控制暫存器
#define ADCON 0x80  // ADC電源，1=將電源送入ADC工作，0=停止ADC工作
#define ADCI  0x10  // ADC中斷旗標，1=ADC轉換完成
#define ADCS  0x08  // ADC啟動，1=啟動ADC開始轉換 

sfr ADCL    = 0xBE;   // ADC數位資料低位元組 
sfr ADCH    = 0xC6;   // ADC數位資料高位元組 

/*  SPI 暫存器 */
	  
sfr SPSTAT = 0x84;    //SPI狀態暫存器
#define WCOL  0x40    //SPI寫入碰撞旗標,0=SPI發射資料緩衝器是空的 
#define SPIF  0x80    //SPI中斷旗標

sfr SPCTL  = 0x85;    //SPI控制暫存器							
#define SPR  0x01     //Fosc預除倍數(SPR1-0)
                      //0=Fosc/4,1=Fosc/16,2=Fosc/64,3=Fosc/128                     
#define CPHA  0x04    //SPI時脈相位選擇
#define CPOL  0x08    //SPI時脈極性選擇,1=SPICLK is high when Idle
#define MSTR  0x10    //Master/Slave模式選擇
#define DORD  0x20    //SPI資料位元順序,1=bit0先傳輸, 0=bit7先傳輸,
#define SPEN  0x40    //1=SPI致能
#define SSIG  0x80    //1=忽略SS腳晶片選擇 
  
sfr SPDAT  = 0x86; 
/* ISP及IAP暫存器*/ 
sfr IFD     = 0xE2;    // ISP/IAP的Flash資料
sfr IFADRH  = 0xE3;    // ISP/IAP的flash高位址
sfr IFADRL  = 0xE4;    // ISP/IAP的flash低位址

sfr IFMT    = 0xE5;    // ISP/IAP操作模式
#define  READ    0x01  // 01=讀取
#define  WRITE   0x02  // 10=寫入
#define  ERASE   0x03  // 11=清除

sfr SCMD = 0xE6;    // ISP/IAP順序命令

sfr ISPCR = 0xE7;   // ISP/IAP控制
#define  IAPEN     0x80   //1=致能IAP/ISP功能
#define  CFAIL     0x10   //0=IAP/ISP命令完成，1=IAP/ISP命令失敗
#define  Fosc_11M  0x03   //寫入時脈

/* PCA 暫存器*/ 
sfr CCON  = 0xD8;	  //PCA計數組態暫存器
sbit CCF0 = CCON^0;	  //1=PCA模組0中斷旗標
sbit CCF1 = CCON^1;	  //1=PCA模組1中斷旗標
sbit CCF2 = CCON^2;	  //1=PCA模組2中斷旗標
sbit CCF3 = CCON^3;	  //1=PCA模組3中斷旗標
sbit CCF4 = CCON^4;	  //1=PCA模組4中斷旗標
sbit CCF5 = CCON^5;	  //1=PCA模組5中斷旗標
sbit CR   = CCON^6;	  //1=啟動PCA計數
sbit CF   = CCON^7;	  //1=PCA計數溢位

sfr CMOD    = 0xD9;	  //PCA計數模式控制暫存器
#define  ECF    0x01  //1=致能PCA計數溢位產生中斷
#define  CPS0   0x02  //選擇PCA的時脈來源
#define  CPS1   0x04  //00=Fosc/12(預定)，01=Fosc/2，10=Timer0溢位，11=ECI(P34)腳
#define  CIDL   0x80  //0=在IDLE時，PCA不計數(預定)，1=在IDLE時，PCA繼續計數

sfr CCAPM0  = 0xDA;	  //比較/捕捉模組暫存器
sfr CCAPM1  = 0xDB;
sfr CCAPM2  = 0xDC;
sfr CCAPM3  = 0xDD;
sfr CCAPM4  = 0xDE;
sfr CCAPM5  = 0xDF;
#define  ECCF   0x01  //1=致能有匹配或捕捉(CCFn=1)時產生中斷
#define  PWM    0x02  //1=致能由CEXn腳輸出PWM波形
#define  TOG    0x04  //1=設定PAC計數溢位及符合模組動作時，令CEXn腳反相輸出
#define  MAT    0x08  //1=設定PAC計數溢位及符合模組動作時，令CCON內的位元CCFn=1
#define  CAPN   0x10  //1=設定捕捉器在CEXn腳輸入負緣時，捕捉PCA計數
#define  CAPP   0x20  //1=設定捕捉器在CEXn腳輸入正緣時，捕捉PCA計數
#define  ECOM   0x40  //1=致能比較器功能，0=禁能比較器功能(預定)

sfr CL    = 0xE9;   //PCA計數器低位元組
sfr CH    = 0xF9;    //PCA計數器高位元組
	  
sfr CCAP0L = 0xEA;	 //比較/捕捉暫存器低元組
sfr CCAP1L = 0xEB;
sfr CCAP2L = 0xEC;
sfr CCAP3L = 0xED;
sfr CCAP4L = 0xEE;
sfr CCAP5L = 0xEF;

sfr CCAP0H  = 0xFA;	 //比較/捕捉暫存器高元組
sfr CCAP1H  = 0xFB;
sfr CCAP2H  = 0xFC;
sfr CCAP3H  = 0xFD;
sfr CCAP4H  = 0xFE;
sfr CCAP5H  = 0xFF;

sfr PCAPWM0 = 0xF2;	 //CEX0的PWM暫存器
sfr PCAPWM1 = 0xF3; 	 //CEX1的PWM暫存器
sfr PCAPWM2 = 0xF4; 	 //CEX2的PWM暫存器
sfr PCAPWM3 = 0xF5; 	 //CEX3的PWM暫存器
sfr PCAPWM4 = 0xF6; 	 //CEX4的PWM暫存器
sfr PCAPWM5 = 0xF7; 	 //CEX5的PWM暫存器

#define  ECAPL   0x01  //PWM脈波(Duty Cycle)時間CAPnL延長的bit-9
#define  ECAPH   0x02  //PWM脈波(Duty Cycle)載入CAPnH延長的bit-9

/*  P1特殊功能暫存器 (90H) */
sbit AIN0   = P1^0;
sbit AIN1   = P1^1;
sbit ECI    = P1^1;
sbit AIN2   = P1^2;
sbit CEX0   = P1^2;
sbit AIN3   = P1^3;
sbit CEX1   = P1^3;
sbit AIN4   = P1^4;
sbit SS    = P1^4;
sbit AIN5   = P1^5;
sbit MOSI   = P1^5;
sbit AIN6   = P1^6;
sbit MISO   = P1^6;
sbit AIN7   = P1^7;
sbit SPICLK   = P1^7;

/* P3特殊功能暫存器 (B0H) */
sbit S2CK0 = P3^5;
sbit TOCK0 = P3^4;

//----- P4輸出入埠暫存器---------- (MPC82G516 Only)
sfr P4      = 0xE8;
sbit P4_0   = P4^0;
sbit P4_1   = P4^1;
sbit P4_2   = P4^2;
sbit P4_3   = P4^3;
sbit P4_4   = P4^4;
sbit P4_5   = P4^5;
sbit P4_6   = P4^6;
sbit P4_7   = P4^7;	       

sfr XICON   = 0xC0;    //(MPC82G516 Only)
sbit IT2   = XICON^0;	//INT2中斷腳輸入選擇
sbit IE2   = XICON^1;	//INT2中斷旗標
sbit EX2   = XICON^2;	//致能INT2中斷
sbit PX2   = XICON^3;	//INT2中斷優先
sbit IT3   = XICON^4;	//INT3中斷腳輸入選擇
sbit IE3   = XICON^5;	//INT3中斷旗標
sbit EX3   = XICON^6;	//致能INT3中斷
sbit PX3   = XICON^7;	//INT3中斷優先

sfr IPH     = 0xB7;	//高中斷優先暫存器
#define PX0H  0x01  // INT0外部中斷高優先
#define PT0H  0x02  // TTimer0計時中斷高優先
#define PX1H  0x04  // INT1外部中斷高優先
#define PT1H  0x08  // Timer1計時中斷高優先
#define PSH   0x10  // UART串列傳輸中斷高優先
#define PT2H  0x20  // Timer2計時中斷高優先
#define PX2H  0x40  // INT2外部中斷高優先
#define PX3H  0x80  // INT3外部中斷高優先

/*******************************************
*實習板接腳宣告
*********************************************/
sfr    LED=0x80; //P0為LED輸出
sfr    LED0=0x80;//P0為LED輸出
sfr    LED1=0x90;//P1為LED輸出

//喇叭接腳
sbit   SPEAK=P1^0;  //P10喇叭輸出
sbit   SPK=P1^0;    //P10喇叭輸出
sbit   SPK1=P1^2;   //P12喇叭輸出

//步進馬達接腳
sfr    STEP=0x90; //步進馬達由P14-7輸出

//點矩陣LED及七段顯示器接腳
sfr    Data=0x80; //P0資料BUS輸出
sfr    Scan=0xE8; //P4點矩陣LED掃描輸出

sfr    SEG7=0xE8; //P4七段顯示器選擇
sbit   S3=P4^3;	 //P43七段顯示器千位數選擇
sbit   S2=P4^2;	 //P42七段顯示器百位數選擇
sbit   S1=P4^1;	 //P41七段顯示器十位數選擇
sbit   S0=P4^0;	 //P40七段顯示器個位數選擇

//文字型及繪圖型LCD接腳
sbit   RS=P4^0;  //文字型LCD指令/資料控制,RS=0指令，RS=1資料
sbit   D_I=P4^0; //繪圖型LCD指令/資料控制,D_I=0指令，D_I=1資料
sbit   RW=P4^1;  //文字型及繪圖型LCD讀取/寫入控制,RW=0寫入，RW=1讀取
sbit   EN=P4^2;  //文字型及繪圖型LCD致能輸出,EN=0禁能LCD，EN=1致能LCD
sbit   CS1=P4^3; //CS1=1，繪圖型LCD左半部選擇
sbit   CS2=P4^4; //CS2=1，繪圖型LCD右半部選擇
sbit   RST=P4^5; //RST=0，繪圖型LCD重置信號

//按鍵接腳
sbit   KEY1=P3^2;  //P32(INT0)按鍵開關輸入
sbit   KEY2=P3^3;  //P33(INT1)按鍵開關輸入
sbit   KEY3=P4^3;  //P43(INT2)按鍵開關輸入
sbit   KEY4=P4^2;  //P42(INT3)按鍵開關輸入

//矩陣式按鍵開關接腳
sfr   ROW =0xA0;	//P2按鍵掃描接腳
sbit   COL0=P2^0;	//P20-3為按鍵輸入接腳
sbit   COL1=P2^1;
sbit   COL2=P2^2;
sbit   COL3=P2^3;

sbit   ROW0=P2^4;	//P24-7為掃描輸出接腳
sbit   ROW1=P2^5;
sbit   ROW2=P2^6;
sbit   ROW3=P2^7;

//EEPROM 93C46 接腳
sbit   CS=P1^4;	  //93C46晶片選擇
sbit   DI=P1^5;   //93C46串列資料輸入
sbit   DO=P1^6;   //93C46串列資料輸出
sbit   SK=P1^7;   //93C46同步時脈

/*******************************************
*函數名稱: Delay_ms
*功能描述: 延時以1mS為單位，石英晶體為22.1184MHz
*********************************************/
void Delay_ms(unsigned int dly) 
{  
  unsigned int dly1; //內循環變數
  while(dly--)         // 外循環，遞減至0
   {dly1=950;  while(dly1--);} //內循環，延時1ms
}
//********宣告函數********************************** 
extern void Delay_ms(unsigned int dly);//以mS為單位延時
void Delay_10us(unsigned int dly);//以10uS為單位延時

extern void UART_init(unsigned int BPS);  //UART啟始程式
extern void OutputHex(unsigned char Uart_Data);	// 將十六進制碼轉換為字元，由UART發射出去
extern void Output(unsigned char d);// 將字元，由UART發射出去

void LCD_init(void);   	//LCD的啟始程式 
void LCD_Data(unsigned char Data); 	//傳送資料到LCD
void LCD_Cmd(unsigned char Cmd); 	//傳送命令到LCD
void LCD_Cmd_Init(unsigned char Cmd); //啟始傳送命令到LCD
void LCD_wait(void);   //LCD等待忙碌旗標BF
void LCD_clear(void);  //LCD清除畫面

 //宣告EEPROM 93C46函數
extern void Clock(void);           //送入串列EEPROM時脈信號
extern void SEND(bit flag);       //送入EEPROM串列1-bit位址或資料
extern void SEND8(unsigned char Addr);      //送入8-bit位址或資料
extern unsigned int  READ_16(unsigned char Addr); //讀取16-bit資料
extern unsigned char READ_8(unsigned char Addr);  //讀取8-bit資料
extern void WRITE_16(unsigned char Addr,unsigned int ch);//寫入16-bit資料
extern void WRITE_8(unsigned char Addr,unsigned char ch);//寫入8-bit資料
extern void EWEN(void);            //EEPROM寫入及清除致能
extern void EWDS(void);            //EEPROM寫入及清除禁能
extern void ERAL(void);           //EEPROM清除全部記憶體