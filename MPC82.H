/*-----------------------------------------------
MPC82G.H
-----------------------------------------------*/
//���s�w�q�ܼƪ����A�W��
typedef unsigned char   uint8;  // �L�Ÿ�8-bit����ܼ�       
typedef signed   char  	int8;   // ���Ÿ�8-bit����ܼ�       
typedef unsigned int 	uint16; // �L�Ÿ�16-bit����ܼ�      
typedef signed   int 	int16;  // ���Ÿ�16-bit����ܼ�      
typedef unsigned long  	uint32; // �L�Ÿ�32-bit����ܼ�      
typedef signed   long  	int32;  // ���Ÿ�32-bit����ܼ�      
typedef float          	fp32;   // ���ׯB�I��(32bit)

//���s�w�qKeil����<intrins.h>���
#include  <intrins.h>  //�]�A�޿�B���Ʈw�]�w
#define RR8(x)  _cror_(x,1); //�w�q8-bit�ܼ�x�k����1-bit
#define RR16(x) _iror_(x,1); //�w�q16-bit�ܼ�x�k����1-bit
#define RR32(x) _lror_(x,1); //�w�q32-bit�ܼ�x�k����1-bit

#define RL8(x)  _crol_(x,1); //�w�q8-bit�ܼ�x������1-bit
#define RL16(x) _irol_(x,1); //�w�q16-bit�ܼ�x������1-bit
#define RL32(x) _lrol_(x,1); //�w�q32-bit�ܼ�x������1-bit

#define NOP() _nop_();  //�w�q�ū��O�A���ɤ@�Ӿ���g���ɶ�
//----------------------------------------------
sfr  P0   = 0x80;  //P0��X�J��Ȧs��
sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
sbit P0_4 = P0^4;
sbit P0_5 = P0^5;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;
//----------------------------------------------
sfr SP      = 0x81; //���|���мȦs��
sfr DPL     = 0x82; //��ƫ��ЧC�줸�ռȦs��
sfr DPH     = 0x83; //��ƫ��а��줸�ռȦs��
//------------------------------------------------
sfr PCON    = 0x87;	 //�\�v����Ȧs��
#define IDL    0x01  //1=�i�Jidle�ٹq�Ҧ�
#define PD     0x02  //1=�i�Jpower down�ٹq�Ҧ�  
#define GF0    0x04  //�q�Φs���줸
#define GF1    0x08  //�q�Φs���줸
#define POF    0x10  //�N�}�����m�X�СA1=���N�}���Ҳ��ͪ����m(�w�w)
#define SMOD0  0x40  //1=�]�wUART1���W�j��UART
#define SMOD   0x80  //1=UART1�j�v�[��
//------------------------------------------------
sfr TCON  = 0x88;	//Timer0-1����Ȧs��
sbit IT0  = TCON^0;  	//INT0���_�H�����,1=�t�tĲ�o��J,0=�C�Ǧ��J 
sbit IE0  = TCON^1;	//INT0��ܺX��,1=INT0���_����
sbit IT1  = TCON^2;	//INT1���_�H�����,1=�t�tĲ�o��J,0=�C�Ǧ��J
sbit IE1  = TCON^3;	//INT1��ܺX��,1=INT1���_����
sbit TR0  = TCON^4;	//T0�Ұʦ줸,TR0=1�OTimer0�}�l�u�@
sbit TF0  = TCON^5;	//T0����X��,Timer0����ɡA�OTF0=1
sbit TR1  = TCON^6;	//T1�Ұʦ줸,1=�OTimer1�}�l�u�@
sbit TF1  = TCON^7;	//T1����X��,Timer1����ɡA�OTF1=1
//------------------------------------------------
sfr TMOD    = 0x89;	 //Timer0-1�Ҧ��Ȧs��
#define T0_M0   0x01 //Timer0�Ҧ��줸0
#define T0_M1   0x02 //Timer0�Ҧ��줸1
#define T0_CT   0x04 //0=Timer0�������p�ɡA1=�~���p��
#define T0_GATE 0x08 //1=Timer0��INT0�}(P32)�Ұ�
#define T1_M0   0x10 //Timer1�Ҧ��줸0
#define T1_M1   0x20 //Timer1�Ҧ��줸1
#define T1_CT   0x40 //0=Timer1�������p�ɡA1=�~���p��
#define T1_GATE 0x80 //1=Timer1��INT1�}(P33)�Ұ�
//------------------------------------------------
sfr TL0 = 0x8A;	 //Timer0�p��/�p�ƧC�줸�ռȦs��
sfr TL1 = 0x8B;	 //Timer1�p��/�p�ƧC�줸�ռȦs��
sfr TH0 = 0x8C;	 //Timer0�p��/�p�ư��줸�ռȦs��
sfr TH1 = 0x8D;	 //Timer1�p��/�p�ư��줸�ռȦs��
//------------------------------------------------
sfr P1    = 0x90;  //P1��X�J��Ȧs��
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

sbit T2   = P1^0;  //Timer2�~���p�ƿ�J�}(P10)
sbit T2EX = P1^1;  //Timer2�~�����s���J/����Ĳ�o��J�}(P11)
//------------------------------------------------
sfr SCON  = 0x98; //UART��C�𱱨�Ȧs��
sbit RI   = SCON^0; //UART�����X�СA���������ɡARI=1
sbit TI   = SCON^1; //UART�o�g�X�СA�o�g�����ɡATI=1
sbit RB8  = SCON^2; //UART�Ҧ�2�B3���A�s�񱵦��쪺��9bit 
sbit TB8  = SCON^3; //UART�Ҧ�2�B3���A�o�g��ƪ���9bit
sbit REN  = SCON^4; //UART�����P��AREN=1���\������C���
sbit SM2  = SCON^5; //UART�u�@�Ҧ��]�w
sbit SM1  = SCON^6;
sbit SM0  = SCON^7;

sbit FE   = SCON^7; //��Ʈؿ��~(Frame Error)����(MPC82 Only)
//------------------------------------------------
sfr SBUF    = 0x99; //UART��C�w�ļȦs��
//------------------------------------------------
sfr P2    = 0xA0;  //P2��X�J��Ȧs��
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;
sbit P2_5 = P2^5;
sbit P2_6 = P2^6;
sbit P2_7 = P2^7;
//------------------------------------------------
sfr IE    = 0xA8;  //���_�P��Ȧs��
sbit EX0  = IE^0;  //1=�P��INT0���_
sbit ET0  = IE^1;  //1=�P��Timer0���_
sbit EX1  = IE^2;  //1=�P��INT1���_
sbit ET1  = IE^3;  //1=�P��Timer1���_
sbit ES   = IE^4;  //1=�P��UART���_
sbit ET2  = IE^5;  //1=�P��Timer2���_
sbit EA   = IE^7;  //0=�T��Ҧ����_
//------------------------------------------------
sfr P3    = 0xB0;  //P3��X�J��Ȧs��
sbit P3_0 = P3^0;
sbit P3_1 = P3^1;
sbit P3_2 = P3^2;
sbit P3_3 = P3^3;
sbit P3_4 = P3^4;
sbit P3_5 = P3^5;
sbit P3_6 = P3^6;
sbit P3_7 = P3^7;

sbit RXD0 = P3^0;   //UART��C������J�}(P30)
sbit TXD0 = P3^1;   //UART��C�o�g��X�}(P31)
sbit INT0 = P3^2;   //�~�����_INT0��J�}(P32)
sbit INT1 = P3^3;   //�~�����_INT1��J�}(P33)
sbit T0   = P3^4;   //Timer0�~���p�ƿ�J�}(P34)
sbit T1   = P3^5;   //Timer1�~���p�ƿ�J�}(P35)
sbit WR   = P3^6;   //�~����ưO����g�J����}(P36)
sbit RD   = P3^7;   //�~����ưO����Ū������}(P37)

//------------------------------------------------
sfr  IP   = 0xB8; //���_�u���Ȧs��
sbit PX0  = IP^0; //1=INT0���_�u��
sbit PT0  = IP^1; //1=Timer0���_�u��
sbit PX1  = IP^2; //1=INT1���_�u��
sbit PT1  = IP^3; //1=Timer1���_�u��
sbit PS   = IP^4; //1=UART���_�u��
sbit PT2  = IP^5; //1=Timer2���_�u��

/* Timer2*�Ȧs�� */
sfr T2MOD   = 0xC9; //Timer2 �Ҧ��Ȧs��(��MPC82G516)
#define DCEN    0x01  //1=Timer2�U�ƭp�ƭP��
#define T2CKOE  0x02  //1=Timer2�ɯ߿�X�P��

sfr T2CON = 0xC8;   //Timer2����Ȧs��
sbit CP_RL2= T2CON^0;  //0=���s���J(Reload),1=����(Capture )
sbit C_T2 =  T2CON^1;   //0=�p��(Timer),1=�p��(Counter)
sbit TR2  =  T2CON^2;   //1=�}�l�p��
sbit EXEN2=  T2CON^3;  	//1=�P��T2EX�}��J�t�tĲ�o
sbit TCLK =  T2CON^4;   //0=��C��o�g�ɯߨϥ�Timer1�A1=�ϥ�Timer2
sbit RCLK =  T2CON^5;   //0=��C�𱵦��ɯߨϥ�Timer1�A1=�ϥ�Timer2 
sbit EXF2 =  T2CON^6;   //T2EX�}��J�X��
sbit TF2  =  T2CON^7;   //Timer2����X��

sfr16  RCAP2  = 0xCA; //Timer2���s���J/�����Ȧs��
sfr RCAP2L  = 0xCA;   //Timer2���s���J/�����Ȧs���C�줸��
sfr RCAP2H  = 0xCB;   //Timer2���s���J/�����Ȧs�����줸��

sfr16 T2R   = 0xCC;   //Timer2�p��/�p�ƼȦs��
sfr TL2     = 0xCC;   //Timer2�p��/�p�ƼȦs���C�줸��
sfr TH2     = 0xCD;   //Timer2�p��/�p�ƼȦs�����줸��

//------------------------------------------------
sfr PSW   = 0xD0;  	//�{�����A�r���Ȧs��
sbit P    = PSW^0;	//�P�줸�X�СA0=���P�줸�A1=�_�P�줸
sbit OV   = PSW^2;	//����X�СA1=������
sbit RS0  = PSW^3;	//�Ȧs���w���
sbit RS1  = PSW^4;	//�Ȧs���w���
sbit F0   = PSW^5;	//�q��Ū�g�줸
sbit AC   = PSW^6;  //�b�i��X�СA1=���b�i��Φ��b�ɦ�
sbit CY   = PSW^7;  //�i��X�СA1=���i��Φ��ɦ�
//----------------------------------------------
sfr ACC   = 0xE0;	//�ֿn��
sfr B     = 0xF0;	//�ֿn��
/*------------------------------------------------
���_�V�q��} = (���_�V�q�s�� * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR	  0  //INT0�~�����_�A���_�V�q��}0x03
#define TF0_VECTOR	  1  //Timer0���줤�_�A���_�V�q��}0x0B
#define IE1_VECTOR	  2  //INT1�~�����_�A���_�V�q��}0x13
#define TF1_VECTOR	  3  //Timer1���줤�_�A���_�V�q��}0x1B
#define UART_VECTOR   4  //UART1�ǿ餤�_�A���_�V�q��}0x23
#define TF2_VECTOR	  5  //Timer2���줤�_�A���_�V�q��}0x2B
#define EX2_VECTOR	  5  //Timer2�~�����_�A���_�V�q��}0x2B
#define IE2_VECTOR    6  //INT2�~�����_�A���_�V�q��}0x33
#define IE3_VECTOR    7  //INT3�~�����_�A���_�V�q��}0x3B	
#define SPI_VECTOR    8  //SPI���_�A���_�V�q��}0x43
#define ADC_VECTOR    9  //ADC���_�A���_�V�q��}0x4B
#define PCA_VECTOR    10 //PCA���_�A���_�V�q��}0x53
#define LVI_VECTOR    11 //�C�q���q�����_�A���_�V�q��}0x5B
#define UART2_VECTOR  12 //UART2�ǿ餤�_�A���_�V�q��}0x63
#define KBI_VECTOR    13 //Keypad���_�A���_�V�q��}0x6B	

//*******MPC82�S���ȥ\��s��****************************
/*���}�Ҧ��Ȧs��*/
sfr P1M0 = 0x91;//P1���}�Ҧ�
sfr P1M1 = 0x92;//00=�з����V��X�A01=��������X�A10=�ȿ�J�A11=�}������X

sfr P0M0 = 0x93;//P0���}�Ҧ�
sfr P0M1 = 0x94;//00=�з����V��X�A01=��������X�A10=�ȿ�J�A11=�}������X

sfr P2M0 = 0x95;//P2���}�Ҧ�
sfr P2M1 = 0x96;//00=�з����V��X�A01=��������X�A10=�ȿ�J�A11=�}������X

sfr P3M0 = 0xB1;//P3���}�Ҧ�
sfr P3M1 = 0xB2;//00=�з����V��X�A01=��������X�A10=�ȿ�J�A11=�}������X

sfr P4M0 = 0xB3;//P4���}�Ҧ� 
sfr P4M1 = 0xB4;//00=�з����V��X�A01=��������X�A10=�ȿ�J�A11=�}������X

sfr EVRCR = 0x97;    //�˴��q�����Ѫ��A
#define  OPF   0x01  //1=��VDD�}��J�q���C��3.7V��
#define  CPF   0x02  //1=��V3O�}��X�q���C��2.4V��
#define  EOPFI 0x04  //1=�P���VDD�}��J�q���C��3.7V�ɲ��ͤ��_
#define  ECPFI 0x08  //1=�P���V3O�}��X�q���C��2.4V�ɲ��ͤ��_

sfr STRETCH = 0x8F;   //�~���O���鱱��}ALE��R/W�ɯ߳]�w(MPC82G516 Only)

/*���U�Ȧs��*/
sfr AUXR = 0x8E;   //���U�Ȧs��
#define     EXTRAM 0x02   //1=�T��ERAM�A0=�P�ऺ��ERAM��}0x000~0FFF
#define     P35ALE  0x10  //1=P35��ALE�}�A0=P35��IO�}
#define     P41ALE  0x20  //1=P41��ALE�}�A0=P41��IO�}
#define     ADRJ    0x40  //1=�Ʀ���ADCH�V�k���A0=�Ʀ���ADCH�V����
#define     URTS    0x80  //1=�P��S2BRT����UART1�t�v�ɯ�

sfr AUXR1   = 0xA2;       //���U�Ȧs��(MPC82G516 Only)
#define     DPS     0x01  //�ϥΪ�DPTR�A0=DPTR0�A1=DPTR1 
#define     GF2     0x08  //�q�Φ줸�X�� 
#define     P4S2    0x10  //1=P4.2��P4.3��UART2�A0=P1.2��P1.3��UART2
#define     P4SPI   0x20  //1=P4.7-4.3��SPI�A0=P1.7-4��SPI 
#define     P4PCA   0x40  //1=P4��PCA�A0=P1��PCA 
#define     P4KB    0x80  //1=P4�� keypad�A0=P2�� keypad

sfr AUXIE   = 0xAD; //���U���_�P��Ȧs��
#define ESPI  0x01  //SPI���_�P��
#define EADC  0x02  //ADC���_�P��
#define EPCA  0x04  //PCA���_�P��
#define EBD   0x08  //�q���������_�P��
#define ES2   0x10  //UART2���_�P��
#define EKBI  0x20  //���䤤�_�P��

sfr AUXIP   = 0xAE; //�u�����U�Ȧs��
#define PSPI  0x01  // SPI���_�u��
#define PADC  0x02  // ADC���_�u��
#define PPCA  0x04  // PCA���_�u��
#define PBD   0x08  // �q���������_�u��
#define PS2   0x10  // UART2���_�u��
#define PKB   0x20  // ���䤤�_�u��

sfr AUXIPH  = 0xAF; //���u�����U�Ȧs��
#define PSPIH 0x01  //SPI���_���u��
#define PADCH 0x02  //ADC���_���u��
#define PPCAH 0x04  //PCA���_���u��
#define PBDH  0x08  //�q���������_���u��
#define PS2H  0x10  //UART2���_���u��
#define PKBH  0x20  //Keypad���_���u���A1=���u�� 

sfr AUXR2   = 0xA6;   //���U�Ȧs��(MPC82G516 Only)
#define T0CKOE  0x01  //1=�P��T0����ɥ�P34�}�Ϭۿ�X 
#define S2CKOE  0x02  //1=�P��UART2�t�v�ɯߥ�P35�}��X 
#define S2TX12  0x04  //1=UART2�ɯ߬��t���W�v�A0=UART2�ɯ߬��t���W�v/12  
#define S2SMOD  0x08  //1=UART2�t�v�[�� 
#define S2TR    0x10  //1=UART2�Ұʦ줸
#define URM0X6  0x20  //1=�t���W�v/2�A0=UART mode0�ɯ߬��t���W�v/12
#define T1X12   0x40  //1=T1�ɯ߬��t���W�v�A0=T1�ɯ߬��t���W�v/12
#define T0X12   0x80  //1=T0�ɯ߬��t���W�v�A0=T0�ɯ߬��t���W�v/12

/* UART2�Ȧs�� */
sfr S2BUF   = 0x9A;   //(MPC82G516 Only)
sfr S2BRT   = 0xBA;   //(MPC82G516 Only)

sfr S2CON   = 0xAA;   //(MPC82G516 Only)
#define S2RI    0x01  //UART2�����X�СA���������ɡARI=1
#define S2TI    0x02  //UART2�o�g�X�СA�o�g�����ɡATI=1
#define S2RB8   0x04  //UART2�Ҧ�2�B3���A�s�񱵦��쪺��9bit 
#define S2TB8   0x08  //UART2�Ҧ�2�B3���A�o�g��ƪ���9bit
#define S2REN   0x10  //UART2�����P��AREN=1���\������C���
#define S2SM2   0x20  //UART2�u�@�Ҧ��]�w
#define S2SM1   0x40 
#define S2SM0   0x80


sfr SADDR   = 0xA9;		  //Slave Address

sfr SVAR    = 0xCE;       //(MPC82G516 Only)
sfr SBK     = 0xCF;       //(MPC82G516 Only)
sfr SADEN   = 0xB9;

sfr PCON2   = 0xC7;		
#define SCKD1   0  //SCKD3-0=�t�ΰ��W����줸
#define SCKD2   1
#define SCKD4   2
#define SCKD8   3
#define SCKD16  4
#define SCKD32  5
#define SCKD64  6
#define SCKD128 7

/* Keypad�Ȧs��*/
sfr KBPATN  = 0xD5;       //(MPC82G516 Only)
sfr KBMASK  = 0xD7;       //(MPC82G516 Only)

sfr KBCON   = 0xD6;       //(MPC82G516 Only)
#define KBIF  0x01       //�䤤�_Keypad���_�X��
#define PATNS  0x02       //Keypad������\��

sbit KBI0   = P2^0;
sbit KBI1   = P2^1;
sbit KBI2   = P2^2;
sbit KBI3   = P2^3;
sbit KBI4   = P2^4;
sbit KBI5   = P2^5;
sbit KBI6   = P2^6;
sbit KBI7   = P2^7;

/* WDT�Ȧs��  */
sfr TSTWD   = 0xA7;   //WDT����(MPC82G516 Only)

sfr WDTCR   = 0xE1;	 //WDT����
#define PS2_0 0x01  //Fosc�w�����ơA000=Fosc/2, 001=Fosc/4, 010=Fosc/8,  011=Fosc/16,
                    //        100=Fosc/32,101=Fosc/64,110=Fosc/128,111=Fosc/256
#define WIDL  0x08  //1=�bIdle�Ҧ�WDT���p�ơA0=�bIdle�Ҧ�WDT����p��
#define CLRW  0x10  //1=�M��WDT�p�ƾ���0
#define ENW   0x20  //1=�P��WDT�p��
#define WRF   0x80	//1=WDT���쭫�m(reset)�X��

/* ADC�Ȧs��  */
sfr ADCTL   = 0xC5;      // ADC����Ȧs��
#define ADCON 0x80  // ADC�q���A1=�N�q���e�JADC�u�@�A0=����ADC�u�@
#define ADCI  0x10  // ADC���_�X�СA1=ADC�ഫ����
#define ADCS  0x08  // ADC�ҰʡA1=�Ұ�ADC�}�l�ഫ 

sfr ADCL    = 0xBE;   // ADC�Ʀ��ƧC�줸�� 
sfr ADCH    = 0xC6;   // ADC�Ʀ��ư��줸�� 

/*  SPI �Ȧs�� */
	  
sfr SPSTAT = 0x84;    //SPI���A�Ȧs��
#define WCOL  0x40    //SPI�g�J�I���X��,0=SPI�o�g��ƽw�ľ��O�Ū� 
#define SPIF  0x80    //SPI���_�X��

sfr SPCTL  = 0x85;    //SPI����Ȧs��							
#define SPR  0x01     //Fosc�w������(SPR1-0)
                      //0=Fosc/4,1=Fosc/16,2=Fosc/64,3=Fosc/128                     
#define CPHA  0x04    //SPI�ɯ߬ۦ���
#define CPOL  0x08    //SPI�ɯ߷��ʿ��,1=SPICLK is high when Idle
#define MSTR  0x10    //Master/Slave�Ҧ����
#define DORD  0x20    //SPI��Ʀ줸����,1=bit0���ǿ�, 0=bit7���ǿ�,
#define SPEN  0x40    //1=SPI�P��
#define SSIG  0x80    //1=����SS�}������� 
  
sfr SPDAT  = 0x86; 
/* ISP��IAP�Ȧs��*/ 
sfr IFD     = 0xE2;    // ISP/IAP��Flash���
sfr IFADRH  = 0xE3;    // ISP/IAP��flash����}
sfr IFADRL  = 0xE4;    // ISP/IAP��flash�C��}

sfr IFMT    = 0xE5;    // ISP/IAP�ާ@�Ҧ�
#define  READ    0x01  // 01=Ū��
#define  WRITE   0x02  // 10=�g�J
#define  ERASE   0x03  // 11=�M��

sfr SCMD = 0xE6;    // ISP/IAP���ǩR�O

sfr ISPCR = 0xE7;   // ISP/IAP����
#define  IAPEN     0x80   //1=�P��IAP/ISP�\��
#define  CFAIL     0x10   //0=IAP/ISP�R�O�����A1=IAP/ISP�R�O����
#define  Fosc_11M  0x03   //�g�J�ɯ�

/* PCA �Ȧs��*/ 
sfr CCON  = 0xD8;	  //PCA�p�ƲպA�Ȧs��
sbit CCF0 = CCON^0;	  //1=PCA�Ҳ�0���_�X��
sbit CCF1 = CCON^1;	  //1=PCA�Ҳ�1���_�X��
sbit CCF2 = CCON^2;	  //1=PCA�Ҳ�2���_�X��
sbit CCF3 = CCON^3;	  //1=PCA�Ҳ�3���_�X��
sbit CCF4 = CCON^4;	  //1=PCA�Ҳ�4���_�X��
sbit CCF5 = CCON^5;	  //1=PCA�Ҳ�5���_�X��
sbit CR   = CCON^6;	  //1=�Ұ�PCA�p��
sbit CF   = CCON^7;	  //1=PCA�p�Ʒ���

sfr CMOD    = 0xD9;	  //PCA�p�ƼҦ�����Ȧs��
#define  ECF    0x01  //1=�P��PCA�p�Ʒ��첣�ͤ��_
#define  CPS0   0x02  //���PCA���ɯߨӷ�
#define  CPS1   0x04  //00=Fosc/12(�w�w)�A01=Fosc/2�A10=Timer0����A11=ECI(P34)�}
#define  CIDL   0x80  //0=�bIDLE�ɡAPCA���p��(�w�w)�A1=�bIDLE�ɡAPCA�~��p��

sfr CCAPM0  = 0xDA;	  //���/�����ҲռȦs��
sfr CCAPM1  = 0xDB;
sfr CCAPM2  = 0xDC;
sfr CCAPM3  = 0xDD;
sfr CCAPM4  = 0xDE;
sfr CCAPM5  = 0xDF;
#define  ECCF   0x01  //1=�P�঳�ǰt�ή���(CCFn=1)�ɲ��ͤ��_
#define  PWM    0x02  //1=�P���CEXn�}��XPWM�i��
#define  TOG    0x04  //1=�]�wPAC�p�Ʒ���βŦX�Ҳհʧ@�ɡA�OCEXn�}�Ϭۿ�X
#define  MAT    0x08  //1=�]�wPAC�p�Ʒ���βŦX�Ҳհʧ@�ɡA�OCCON�����줸CCFn=1
#define  CAPN   0x10  //1=�]�w�������bCEXn�}��J�t�t�ɡA����PCA�p��
#define  CAPP   0x20  //1=�]�w�������bCEXn�}��J���t�ɡA����PCA�p��
#define  ECOM   0x40  //1=�P�������\��A0=�T�������\��(�w�w)

sfr CL    = 0xE9;   //PCA�p�ƾ��C�줸��
sfr CH    = 0xF9;    //PCA�p�ƾ����줸��
	  
sfr CCAP0L = 0xEA;	 //���/�����Ȧs���C����
sfr CCAP1L = 0xEB;
sfr CCAP2L = 0xEC;
sfr CCAP3L = 0xED;
sfr CCAP4L = 0xEE;
sfr CCAP5L = 0xEF;

sfr CCAP0H  = 0xFA;	 //���/�����Ȧs��������
sfr CCAP1H  = 0xFB;
sfr CCAP2H  = 0xFC;
sfr CCAP3H  = 0xFD;
sfr CCAP4H  = 0xFE;
sfr CCAP5H  = 0xFF;

sfr PCAPWM0 = 0xF2;	 //CEX0��PWM�Ȧs��
sfr PCAPWM1 = 0xF3; 	 //CEX1��PWM�Ȧs��
sfr PCAPWM2 = 0xF4; 	 //CEX2��PWM�Ȧs��
sfr PCAPWM3 = 0xF5; 	 //CEX3��PWM�Ȧs��
sfr PCAPWM4 = 0xF6; 	 //CEX4��PWM�Ȧs��
sfr PCAPWM5 = 0xF7; 	 //CEX5��PWM�Ȧs��

#define  ECAPL   0x01  //PWM�ߪi(Duty Cycle)�ɶ�CAPnL������bit-9
#define  ECAPH   0x02  //PWM�ߪi(Duty Cycle)���JCAPnH������bit-9

/*  P1�S���\��Ȧs�� (90H) */
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

/* P3�S���\��Ȧs�� (B0H) */
sbit S2CK0 = P3^5;
sbit TOCK0 = P3^4;

//----- P4��X�J��Ȧs��---------- (MPC82G516 Only)
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
sbit IT2   = XICON^0;	//INT2���_�}��J���
sbit IE2   = XICON^1;	//INT2���_�X��
sbit EX2   = XICON^2;	//�P��INT2���_
sbit PX2   = XICON^3;	//INT2���_�u��
sbit IT3   = XICON^4;	//INT3���_�}��J���
sbit IE3   = XICON^5;	//INT3���_�X��
sbit EX3   = XICON^6;	//�P��INT3���_
sbit PX3   = XICON^7;	//INT3���_�u��

sfr IPH     = 0xB7;	//�����_�u���Ȧs��
#define PX0H  0x01  // INT0�~�����_���u��
#define PT0H  0x02  // TTimer0�p�ɤ��_���u��
#define PX1H  0x04  // INT1�~�����_���u��
#define PT1H  0x08  // Timer1�p�ɤ��_���u��
#define PSH   0x10  // UART��C�ǿ餤�_���u��
#define PT2H  0x20  // Timer2�p�ɤ��_���u��
#define PX2H  0x40  // INT2�~�����_���u��
#define PX3H  0x80  // INT3�~�����_���u��

/*******************************************
*��ߪO���}�ŧi
*********************************************/
sfr    LED=0x80; //P0��LED��X
sfr    LED0=0x80;//P0��LED��X
sfr    LED1=0x90;//P1��LED��X

//��z���}
sbit   SPEAK=P1^0;  //P10��z��X
sbit   SPK=P1^0;    //P10��z��X
sbit   SPK1=P1^2;   //P12��z��X

//�B�i���F���}
sfr    STEP=0x90; //�B�i���F��P14-7��X

//�I�x�}LED�ΤC�q��ܾ����}
sfr    Data=0x80; //P0���BUS��X
sfr    Scan=0xE8; //P4�I�x�}LED���y��X

sfr    SEG7=0xE8; //P4�C�q��ܾ����
sbit   S3=P4^3;	 //P43�C�q��ܾ��d��ƿ��
sbit   S2=P4^2;	 //P42�C�q��ܾ��ʦ�ƿ��
sbit   S1=P4^1;	 //P41�C�q��ܾ��Q��ƿ��
sbit   S0=P4^0;	 //P40�C�q��ܾ��Ӧ�ƿ��

//��r����ø�ϫ�LCD���}
sbit   RS=P4^0;  //��r��LCD���O/��Ʊ���,RS=0���O�ARS=1���
sbit   D_I=P4^0; //ø�ϫ�LCD���O/��Ʊ���,D_I=0���O�AD_I=1���
sbit   RW=P4^1;  //��r����ø�ϫ�LCDŪ��/�g�J����,RW=0�g�J�ARW=1Ū��
sbit   EN=P4^2;  //��r����ø�ϫ�LCD�P���X,EN=0�T��LCD�AEN=1�P��LCD
sbit   CS1=P4^3; //CS1=1�Aø�ϫ�LCD���b�����
sbit   CS2=P4^4; //CS2=1�Aø�ϫ�LCD�k�b�����
sbit   RST=P4^5; //RST=0�Aø�ϫ�LCD���m�H��

//���䱵�}
sbit   KEY1=P3^2;  //P32(INT0)����}����J
sbit   KEY2=P3^3;  //P33(INT1)����}����J
sbit   KEY3=P4^3;  //P43(INT2)����}����J
sbit   KEY4=P4^2;  //P42(INT3)����}����J

//�x�}������}�����}
sfr   ROW =0xA0;	//P2���䱽�y���}
sbit   COL0=P2^0;	//P20-3�������J���}
sbit   COL1=P2^1;
sbit   COL2=P2^2;
sbit   COL3=P2^3;

sbit   ROW0=P2^4;	//P24-7�����y��X���}
sbit   ROW1=P2^5;
sbit   ROW2=P2^6;
sbit   ROW3=P2^7;

//EEPROM 93C46 ���}
sbit   CS=P1^4;	  //93C46�������
sbit   DI=P1^5;   //93C46��C��ƿ�J
sbit   DO=P1^6;   //93C46��C��ƿ�X
sbit   SK=P1^7;   //93C46�P�B�ɯ�

/*******************************************
*��ƦW��: Delay_ms
*�\��y�z: ���ɥH1mS�����A�ۭ^���鬰22.1184MHz
*********************************************/
void Delay_ms(unsigned int dly) 
{  
  unsigned int dly1; //���`���ܼ�
  while(dly--)         // �~�`���A�����0
   {dly1=950;  while(dly1--);} //���`���A����1ms
}
//********�ŧi���********************************** 
extern void Delay_ms(unsigned int dly);//�HmS����쩵��
void Delay_10us(unsigned int dly);//�H10uS����쩵��

extern void UART_init(unsigned int BPS);  //UART�ҩl�{��
extern void OutputHex(unsigned char Uart_Data);	// �N�Q���i��X�ഫ���r���A��UART�o�g�X�h
extern void Output(unsigned char d);// �N�r���A��UART�o�g�X�h

void LCD_init(void);   	//LCD���ҩl�{�� 
void LCD_Data(unsigned char Data); 	//�ǰe��ƨ�LCD
void LCD_Cmd(unsigned char Cmd); 	//�ǰe�R�O��LCD
void LCD_Cmd_Init(unsigned char Cmd); //�ҩl�ǰe�R�O��LCD
void LCD_wait(void);   //LCD���ݦ��L�X��BF
void LCD_clear(void);  //LCD�M���e��

 //�ŧiEEPROM 93C46���
extern void Clock(void);           //�e�J��CEEPROM�ɯ߫H��
extern void SEND(bit flag);       //�e�JEEPROM��C1-bit��}�θ��
extern void SEND8(unsigned char Addr);      //�e�J8-bit��}�θ��
extern unsigned int  READ_16(unsigned char Addr); //Ū��16-bit���
extern unsigned char READ_8(unsigned char Addr);  //Ū��8-bit���
extern void WRITE_16(unsigned char Addr,unsigned int ch);//�g�J16-bit���
extern void WRITE_8(unsigned char Addr,unsigned char ch);//�g�J8-bit���
extern void EWEN(void);            //EEPROM�g�J�βM���P��
extern void EWDS(void);            //EEPROM�g�J�βM���T��
extern void ERAL(void);           //EEPROM�M�������O����