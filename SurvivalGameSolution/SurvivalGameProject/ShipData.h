#pragma once

#define SHIPTYPE_BATTLESHIP		0	//����
#define SHIPTYPE_CORVETT		1	//�ʰ���
#define SHIPTYPE_CRUISER		2	//������
#define SHIPTYPE_DESTROYER		3	//������
#define SHIPTYPE_FRIGATE		4	//ȣ����
#define SHIPTYPE_PATROLKILLER	5	//�����

#define SHIPZONE_NORMAL		0	//����
#define SHIPZONE_MINOR		1	//�ұԸ� ����
#define SHIPZONE_MIDDLE		2	//�߰� ����
#define SHIPZONE_SERIOUS	3	//��Ը� ����

typedef struct
{
	INT HP;				//ü��	
	INT ARMOR;			//�尩
	INT STATE;			//����
}ShipZone;

typedef struct
{
	INT xScale;			//x�� ũ��
	INT yScale;			//y�� ũ��
	INT ShipType;		//����
	INT ShipImg;		//�̹��� ��ȣ
	INT ShipSpeed;		//�� �ӵ�

	ShipZone Bow;		//����
	ShipZone Body;		//��ü
	ShipZone Stern;		//����
	ShipZone Bridge;	//�Ա�
	ShipZone Chimney;	//����
	ShipZone Hangar;	//�ݳ���
}ShipData;

#define SHIP_TEST_TEST_INDEX 0
#define SHIP_TEST_TEST_DATA {22,166,SHIPTYPE_CRUISER,1000,30,{1000,200,SHIPZONE_NORMAL},{2000,200,SHIPZONE_NORMAL},{1500,200,SHIPZONE_NORMAL},{500,50,SHIPZONE_NORMAL},{500,100,SHIPZONE_NORMAL},{500,25,SHIPZONE_NORMAL}}

extern ShipData ShipDataDir[128];