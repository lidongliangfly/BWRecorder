/** @file t9input.c
 * @brief brief description
 * @author <gao zhengdong, zhengdgao@163.com>
 * @date 2014��4��16������10:01:06
 * @version V1.0
 * @note
 * detailed description
 */

#if 0
//#include "sys.h"
//#include "usart.h"
//#include "pymb.h"
//#include "string.h"

//ƴ�����뷨
pyinput t9=
{
	get_pymb,
	0,
};

//����ֵ:0xff,��ʾ��ȫƥ��.
//	  ����,ƥ����ַ���
u8 str_match(u8*str1,u8*str2)
{
	u8 i=0;
	while(1)
	{
		if(*str1!=*str2)break;	   //����ƥ��
		if(*str1=='\0') {i=0XFF;break;}	   //��ȫƥ��
		i++;
		str1++;
		str2++;
	}
	return i;	   //�����ַ������
}

//��ȡƥ���ƴ�����
//*strin,������ַ���,����:"726"
//**matchlist,�����ƥ���.
//����ֵ:0,��ʾû����ȫƥ���ƴ��.
//       ����,��ȫƥ���ƴ������.
u8 get_matched_pymb(u8 *strin,py_index **matchlist)
{
	py_index *bestmatch;	   //���ƥ��
	u16 pyindex_len;
	u16 i;
	u8 temp,mcnt=0,bmcnt=0;
	bestmatch=(py_index*)&py_index3[0];//Ĭ��Ϊa��ƥ��
	pyindex_len=sizeof(py_index3)/sizeof(py_index3[0]);//�õ�py�������Ĵ�С.
	for(i=0;i<pyindex_len;i++)
	{
		temp=str_match(strin,(u8*)py_index3[i].py_input);
		if(temp)
		{
			if(temp==0XFF)matchlist[mcnt++]=(py_index*)&py_index3[i];
			else if(temp>bmcnt)	   //�����ƥ��
			{
				bmcnt=temp;
				bestmatch=(py_index*)&py_index3[i];	   //��õ�ƥ��.
			}
		}
	}
	if(mcnt==0)matchlist[0]=bestmatch;
	return mcnt;	   //����ƥ��ĸ���
}

//�õ�ƴ�����.
//str:�����ַ���
//����ֵ:ƥ�����.
u8 get_pymb(u8* str)
{
	return get_matched_pymb(str,t9.pymb);
}

void test_py(u8 *inputstr)
{
	u8 t=0;
	u8 i=0;
	t=t9.getpymb(inputstr);
	if(t==0)
	{
		printf("\r\n��������Ϊ:%s\r\n",inputstr);
		printf("����ƥ����:%s,%s\r\n",t9.pymb[0]->py,t9.pymb[0]->pymb);
	}
	else
	{
		printf("\r\n��������Ϊ:%s\r\n",inputstr);
		printf("��ȫƥ��Ľ��:\r\n");
		for(i=0;i<t;i++)
		{
			printf("%s,%s\r\n",t9.pymb[i]->py,t9.pymb[i]->pymb);
		}
	}
}
�������ֿ�:
#ifndef	__PY_MB_h__
#define	__PY_MB_h__
#include "pyinput.h"

//�������б�
const u8 PY_mb_space []= {""};
const u8 PY_mb_a []= {"������߹﹅����H����"};
const u8 PY_mb_ai []= {"�������������������������������������������"};
const u8 PY_mb_an []= {"�����������������ϰ����������������"};
const u8 PY_mb_ang []= {"�������a"};
const u8 PY_mb_ao []= {"�������������°ð���������������������������"};
const u8 PY_mb_ba []= {"�˰ͰְΰŰưǰȰɰʰ̰ϰаѰҰӰ԰���������������"};
const u8 PY_mb_bai []= {"�װذٰڰ۰ܰݰ޲�����"};
const u8 PY_mb_ban []= {"���߰������������������������"};
const u8 PY_mb_bang []= {"���������������������"};
const u8 PY_mb_bao []= {"�����������������������������������������������������"};
const u8 PY_mb_bei []= {"���������������������������������������������������������"};;
const u8 PY_mb_ben []= {"���������������"};
const u8 PY_mb_beng []= {"�������±ñı�ܡ���"};
const u8 PY_mb_bi []= {"�ƱǱȱɱʱ˱̱ͱαϱбѱұӱԱ�ذ�ֱױرٱڱ۱ܱ�������������ݩ��޵�������������������������������������������"};
const u8 PY_mb_bian []= {"�߱�����ޱ��������������������������������"};
const u8 PY_mb_biao []= {"������������������������"};
const u8 PY_mb_bie []= {"�������"};
const u8 PY_mb_bin []= {"������������������������������"};
const u8 PY_mb_bing []= {"������������������������������"};
const u8 PY_mb_bo []= {"�ذٰ�����������������������������������������������ެ�������������������"};
const u8 PY_mb_bu []= {"��������������������������߲�����������"};
const u8 PY_mb_ca []= {"������"};
const u8 PY_mb_cai []= {"�ŲƲǲ²òĲȲɲʲ˲�"};
const u8 PY_mb_can []= {"�ͲβϲвѲҲ����������"};
const u8 PY_mb_cang []= {"�Բղֲײ���"};
const u8 PY_mb_cao []= {"�ݲٲڲ۲�ܳ�������"};
const u8 PY_mb_ce []= {"����޲���"};
const u8 PY_mb_cen []= {"����"};
const u8 PY_mb_ceng []= {"�������"};
const u8 PY_mb_cha []= {"�������������ɲ���������������������"};
const u8 PY_mb_chai []= {"�����٭�������"};
const u8 PY_mb_chan []= {"���������������������������������������������"};
const u8 PY_mb_chang []= {"�������������������������������������������������"};
const u8 PY_mb_chao []= {"�������������������½�������"};
const u8 PY_mb_che []= {"������������������"};
const u8 PY_mb_chen []= {"���������������³óĳ����������������"};
const u8 PY_mb_cheng []= {"�ųƳǳȳɳʳ˳̳ͳγϳгѳҳ�ʢة�����������������������"};
const u8 PY_mb_chi []= {"�Գճֳ׳سٳڳ۳ܳݳ޳߳������߳������ܯ����������������������������"};
const u8 PY_mb_chong []= {"����������������������"};
const u8 PY_mb_chou []= {"��������������ٱ������"};
const u8 PY_mb_chu []= {"����������������������������������ءۻ�������������������"};
const u8 PY_mb_chuai []= {"����������"};
const u8 PY_mb_chuan []= {"������������������������"};
const u8 PY_mb_chuang[]= {"����������������"};
const u8 PY_mb_chui []= {"��������������"};
const u8 PY_mb_chun []= {"��������������ݻ����"};
const u8 PY_mb_chuo []= {"������������"};
const u8 PY_mb_ci []= {"�˴̴ʹ��Ų�ôĴŴƴǴȴɴ���������������"};
const u8 PY_mb_cong []= {"�ӴԴϴдѴ������������"};
const u8 PY_mb_cou []= {"������"};
const u8 PY_mb_cu []= {"�ִ״ش��������������"};
const u8 PY_mb_cuan []= {"�ڴ۴�����ߥ����"};
const u8 PY_mb_cui []= {"�ݴ޴ߴ����������������"};
const u8 PY_mb_cun []= {"��������"};
const u8 PY_mb_cuo []= {"��������������������������"};
const u8 PY_mb_da []= {"���������������������������"};
const u8 PY_mb_dai []= {"���������������������������ܤ߰߾��������"};
const u8 PY_mb_dan []= {"��������������������������������ʯ��������������������"};
const u8 PY_mb_dang []= {"�����������������������"};
const u8 PY_mb_dao []= {"��������������������������߶���������"};
const u8 PY_mb_de []= {"�µõĵ��"};
const u8 PY_mb_dei []= {"��"};
const u8 PY_mb_deng []= {"�εŵƵǵȵɵʵ������������"};
const u8 PY_mb_di []= {"�ĵֵ׵صٵڵ۵ܵݵ̵͵εϵеѵҵӵԵյ���ص��ڮ��ۡ��ݶ��������������������"};
const u8 PY_mb_dia []= {"��"};
const u8 PY_mb_dian []= {"�����������ߵ����������������������"};
const u8 PY_mb_diao []= {"���������������������"};
const u8 PY_mb_die []= {"����������������ܦ�����������"};
const u8 PY_mb_ding []= {"������������������������������������"};
const u8 PY_mb_diu []= {"����"};
const u8 PY_mb_dong []= {"��������������������������������"};
const u8 PY_mb_dou []= {"����������������������"};
const u8 PY_mb_du []= {"�Ƕȶɶ������������¶öĶŶƶ�ܶ�������������"};
const u8 PY_mb_duan []= {"�˶̶Ͷζ϶������"};
const u8 PY_mb_dui []= {"�ѶҶӶ�������"};
const u8 PY_mb_dun []= {"�ܶնֶ׶ضٶڶ۶���������������"};
const u8 PY_mb_duo []= {"���ȶ޶߶�����������������������"};
const u8 PY_mb_e []= {"�������������������Ŷج������ݭ��������������������"};
const u8 PY_mb_ei []= {"��"};
const u8 PY_mb_en []= {"������"};
const u8 PY_mb_er []= {"�������������������������"};
const u8 PY_mb_fa []= {"��������������������"};
const u8 PY_mb_fan []= {"����������������������������������ެ����������"};
const u8 PY_mb_fang []= {"���������������·÷ķ�������������"};
const u8 PY_mb_fei []= {"�ƷǷȷɷʷ˷̷ͷηϷз�����������������������������������"};
const u8 PY_mb_fen []= {"�ַҷܷݷ޷߷�ӷԷշ׷طٷڷ��������������"};
const u8 PY_mb_feng []= {"�����������������ٺۺ��������"};
const u8 PY_mb_fo []= {"��"};
const u8 PY_mb_fou []= {"���"};
const u8 PY_mb_fu []= {"���𸵸�����������������������������������������������������������������������������������������ۮܽ������ݳ����߻����������������������������������������������"};
const u8 PY_mb_ga []= {"���¼п�٤���������"};
const u8 PY_mb_gai []= {"�øĸŸƸǸȽ�ؤ���������"};
const u8 PY_mb_gan []= {"�ɸʸ˸̸͸θϸиѸҸ�������ߦ����������������"};
const u8 PY_mb_gang []= {"�Ըոָ׸ظٸڸ۸ܿ������"};
const u8 PY_mb_gao []= {"��޸߸�ݸ�����غھ۬޻��������"};
const u8 PY_mb_ge []= {"�����Ǹ�����������������������Ͽ�ت������ܪ��������������"};
const u8 PY_mb_gei []= {"��"};
const u8 PY_mb_gen []= {"����بݢ����"};
const u8 PY_mb_geng []= {"�����������������������"};
const u8 PY_mb_gong []= {"���������������������������������������"};
const u8 PY_mb_gou []= {"������������������ڸ��������������������"};
const u8 PY_mb_gu []= {"�ù����¹��������ĹŹƹǹȹɹʹ˹̹ͼ���ڬ��������������������������������������"};
const u8 PY_mb_gua []= {"�ιϹйѹҹ���ڴ�������"};
const u8 PY_mb_guai []= {"�Թչ���"};
const u8 PY_mb_guan []= {"�عٹڹ۹ܹݹ޹߹������ݸ������������"};
const u8 PY_mb_guang []= {"������������"};
const u8 PY_mb_gui []= {"�������������������Ȳ���������������������"};
const u8 PY_mb_gun []= {"�������������"};
const u8 PY_mb_guo []= {"������������������������������������"};
const u8 PY_mb_ha []= {"������"};
const u8 PY_mb_hai []= {"���Ⱥ�������������������"};
const u8 PY_mb_han []= {"��������������������������������������������������������"};
const u8 PY_mb_hang []= {"�к��������������"};
const u8 PY_mb_hao []= {"�ºúĺ������尸亾��������޶�������"};
const u8 PY_mb_he []= {"�ǺȺɺʺ˺̺ͺκϺӺкѺҺԺպغֺ���ڭ�������������������"};
const u8 PY_mb_hei []= {"�ں�"};
const u8 PY_mb_hen []= {"�ۺܺݺ�"};
const u8 PY_mb_heng []= {"�ߺ����޿����"};
const u8 PY_mb_hong []= {"��������������ڧݦޮް����"};
const u8 PY_mb_hou []= {"���������ܩ��������������"};
const u8 PY_mb_hu []= {"���������˺��������������������������������������������������������������������������"};
const u8 PY_mb_hua []= {"��������������������������"};
const u8 PY_mb_huai []= {"������������"};
const u8 PY_mb_huan []= {"�����������������������»���佻�ۨۼ����ߧ���������������"};
const u8 PY_mb_huang []= {"�λĻŻƻǻȻɻʻ˻̻ͻϻл��������������������"};
const u8 PY_mb_hui []= {"��ػٻڻһӻԻջֻ׻ۻܻݻ޻߻����������ڶ����ޥ���������������������"};
const u8 PY_mb_hun []= {"�������ڻ��������"};
const u8 PY_mb_huo []= {"�ͻ���������������޽߫������������"};
const u8 PY_mb_ji []= {"�ƼǸ��������������������������������������ȼɼʼ����������������������������������������������¼üļż˼̼ͽ���ϵآؽ����٥����ܸ����ݽ��ު��ߴ������������������������������������������������������������"};
const u8 PY_mb_jia []= {"�ҼӼμмѼԼռּ׼ؼټڼۼܼݼ޼�����٤ۣ���������������������������������"};
const u8 PY_mb_jian []= {"�������򽡼��߼�����������������������������������������������������������������������������������������������������"};
const u8 PY_mb_jiang []= {"���罩����������������������ǿ����������������"};
const u8 PY_mb_jiao []= {"�нϾ���У�������������������������½ýĽŽƽȽɽʽ˽̽ͽν�ٮ��ܴ����������������������"};
const u8 PY_mb_jie []= {"������ҽܽӽԽ���ݽ޽սֽ׽ؽٽڽ۽߽�������ڦڵ�������������������������"};
const u8 PY_mb_jin []= {"�������������������������������������ݣ������������������������"};
const u8 PY_mb_jing []= {"������������������������������������������������������������ݼ������������������"};
const u8 PY_mb_jiong []= {"����������"};
const u8 PY_mb_jiu []= {"�ž;Ⱦ��������¾þľƾɾʾ˾̾ξ�����������������"};
const u8 PY_mb_ju []= {"�޾߾���峵���ӾԾվ־׾ؾپھ۾ܾݾ���ϾоѾ���ڪ��������������������������������������������"};
const u8 PY_mb_juan []= {"���������Ȧ۲�������������"};
const u8 PY_mb_jue []= {"���������Ǿ����ž������������ܥާ���������������������"};
const u8 PY_mb_jun []= {"��������������������������������"};
const u8 PY_mb_ka []= {"��������������"};
const u8 PY_mb_kai []= {"�������������������������"};
const u8 PY_mb_kan []= {"������������٩�����ݨ�ۼ��"};
const u8 PY_mb_kang []= {"��������������������"};
const u8 PY_mb_kao []= {"����������������"};
const u8 PY_mb_ke []= {"�ɿʿ˿ƿ̿Ϳ�྿����¿ÿĿſǿ���������������������������������"};
const u8 PY_mb_ken []= {"�Ͽпѿ���"};
const u8 PY_mb_keng []= {"�ӿ������"};
const u8 PY_mb_kong []= {"�տֿ׿�������"};
const u8 PY_mb_kou []= {"�ٿڿۿ���ޢߵ����"};
const u8 PY_mb_ku []= {"�ݿ޿߿���������ܥ�"};
const u8 PY_mb_kua []= {"������٨�"};
const u8 PY_mb_kuai []= {"��������ۦ������"};
const u8 PY_mb_kuan []= {"������"};
const u8 PY_mb_kuang []= {"�����������ڲڿ������������"};
const u8 PY_mb_kui []= {"����������������������ظ���������������������������"};
const u8 PY_mb_kun []= {"��������������������"};
const u8 PY_mb_kuo []= {"����������"};
const u8 PY_mb_la []= {"�������������������������"};
const u8 PY_mb_lai []= {"���������������������"};
const u8 PY_mb_lan []= {"����������������������������������������"};
const u8 PY_mb_lang []= {"������������������������ݹ"};
const u8 PY_mb_lao []= {"�������������������������������������"};
const u8 PY_mb_le []= {"��������߷����"};
const u8 PY_mb_lei []= {"��������������������������ڳ������������"};
const u8 PY_mb_leng []= {"������ܨ�"};
const u8 PY_mb_li []= {"��������������������������������������������������������������������تٳٵ۪����ݰ��޼߿�����������������������������������������������������������"};
const u8 PY_mb_lia []= {"��"};
const u8 PY_mb_lian []= {"������������������������������������������������"};
const u8 PY_mb_liang []= {"������������������������ܮݹ�����"};
const u8 PY_mb_liao []= {"��������������������������ޤ������������"};
const u8 PY_mb_lie []= {"�������������������������"};
const u8 PY_mb_lin []= {"�����������������������������������������������"};
const u8 PY_mb_ling []= {"��������������������������������۹��������������������"};
const u8 PY_mb_liu []= {"����������������������µ½����������������"};
const u8 PY_mb_lo []= {"��"};
const u8 PY_mb_long []= {"��Ū��������¡¢£¤���������������"};
const u8 PY_mb_lou []= {"¥¦§¨©ª¶�����������������"};
const u8 PY_mb_lu []= {"��«¬­®¯°±²³´µ¶·¸¹º»¼½¾����ߣ������������������������������������"};
const u8 PY_mb_lv []= {"��������������������������¿�������������"};
const u8 PY_mb_luan []= {"������������"};
const u8 PY_mb_lue []= {"�����"};
const u8 PY_mb_lun []= {"����������������"};
const u8 PY_mb_luo []= {"���޸����������������������������������������������������"};
const u8 PY_mb_m []= {"߼"};
const u8 PY_mb_ma []= {"������������������ĦĨ��������"};
const u8 PY_mb_mai []= {"������������������áܬ��������������"};
const u8 PY_mb_man []= {"����������á������"};
const u8 PY_mb_mang []= {"âãäåæç��������"};
const u8 PY_mb_mao []= {"èéêëì��îïðñòó��í������������������"};
const u8 PY_mb_me []= {"ô"};
const u8 PY_mb_mei []= {"ÿ����õö��������÷øùúûüýþ��ݮ�����������"};
const u8 PY_mb_men []= {"��������������"};
const u8 PY_mb_meng []= {"��������������������ޫ��������������"};
const u8 PY_mb_mi []= {"����������������������������������ڢ������������������������"};
const u8 PY_mb_mian []= {"�����������������������������"};
const u8 PY_mb_miao []= {"�������������������������������"};
const u8 PY_mb_mie []= {"����ؿ�����"};
const u8 PY_mb_min []= {"�������������������������������"};
const u8 PY_mb_ming []= {"������������ڤ���������"};
const u8 PY_mb_miu []= {"����"};
const u8 PY_mb_mo []= {"��û��ġĢģĤĥĦħĨĩĪīĬĭĮįİ���������������������������"};
const u8 PY_mb_mou []= {"ıĲĳٰ����������"};
const u8 PY_mb_mu []= {"ľĿ��ģĲĴĵĶķĸĹĺĻļĽ���������������"};
const u8 PY_mb_na []= {"����������������������"};
const u8 PY_mb_nai []= {"����������ؾ٦ܵ����"};
const u8 PY_mb_nan []= {"����������������"};
const u8 PY_mb_nang []= {"������߭��"};
const u8 PY_mb_nao []= {"����������ث������������"};
const u8 PY_mb_ne []= {"����ګ"};
const u8 PY_mb_nei []= {"����"};
const u8 PY_mb_nen []= {"����"};
const u8 PY_mb_neng []= {"��"};
const u8 PY_mb_ng []= {"��"};
const u8 PY_mb_ni []= {"������������������������٣������������������"};
const u8 PY_mb_nian []= {"��������������إ���������"};
const u8 PY_mb_niang []= {"����"};
const u8 PY_mb_niao []= {"������������"};
const u8 PY_mb_nie []= {"�������������������ؿ�����"};
const u8 PY_mb_nin []= {"��"};
const u8 PY_mb_ning []= {"��������šŢ�������"};
const u8 PY_mb_niu []= {"ţŤťŦ�������"};
const u8 PY_mb_nong []= {"ŧŨũŪٯ��"};
const u8 PY_mb_nou []= {"��"};
const u8 PY_mb_nu []= {"ūŬŭ��������"};
const u8 PY_mb_nuan []= {"ů"};
const u8 PY_mb_nue []= {"űŰ"};
const u8 PY_mb_nuo []= {"��ŲųŴŵ�������"};
const u8 PY_mb_nv []= {"Ů������"};
const u8 PY_mb_o []= {"Ŷ���"};
const u8 PY_mb_ou []= {"ŷŸŹźŻżŽ��ک�����"};
const u8 PY_mb_pa []= {"�ǰ�žſ��������������"};
const u8 PY_mb_pai []= {"��������������ٽ����"};
const u8 PY_mb_pan []= {"�������������������������������������"};
const u8 PY_mb_pang []= {"����������������������"};
const u8 PY_mb_pao []= {"������������������������"};
const u8 PY_mb_pei []= {"�����������������������������"};
const u8 PY_mb_pen []= {"������"};
const u8 PY_mb_peng []= {"������������������������������ܡ���"};
const u8 PY_mb_pi []= {"�ٷ�����������������ơƢƣƤƥƦƧاƨƩ�����������ۯ����ܱ��ߨ�����������������������"};
const u8 PY_mb_pian []= {"���ƪƫƬƭ��������������"};
const u8 PY_mb_piao []= {"ƮƯưƱ����������������"};
const u8 PY_mb_pie []= {"ƲƳد���"};
const u8 PY_mb_pin []= {"ƴƵƶƷƸ�������"};
const u8 PY_mb_ping []= {"��ƹƺƻƼƽƾƿ����ٷ�����"};
const u8 PY_mb_po []= {"��������������������������۶�����������"};
const u8 PY_mb_pou []= {"������"};
const u8 PY_mb_pu []= {"�ձ������������������������������������������������"};
const u8 PY_mb_qi []= {"����������������������������������������������������������������������������������ؽ������������ٹ��ܻ��������������ޭ����������������������"};
const u8 PY_mb_qia []= {"����ǡǢ������"};
const u8 PY_mb_qian []= {"ǣǤǥǦǧǨǩǪǫǬǭǮǯǰǱǲǳǴǵǶǷǸ��ٻ����ܷ����ݡ�������������������������"};
const u8 PY_mb_qiang []= {"ǹǺǻǼǽǾǿ�������������������������"};
const u8 PY_mb_qiao []= {"��������������������������������ȸڽ��������������������"};
const u8 PY_mb_qie []= {"����������٤�����ۧ������"};
const u8 PY_mb_qin []= {"��������������������������������������������"};
const u8 PY_mb_qing []= {"���������������������������������������������������"};
const u8 PY_mb_qiong []= {"�����������������"};
const u8 PY_mb_qiu []= {"�������������������ٴ������������������������"};
const u8 PY_mb_qu []= {"����������������ȡȢȣȤȥ������ڰ۾����ޡ޾����������������������"};
const u8 PY_mb_quan []= {"ȦȧȨȩȪȫȬȭȮȯȰڹ�����������������"};
const u8 PY_mb_que []= {"ȱȲȳȴȵȶȷȸ������"};
const u8 PY_mb_qui []= {"��"};
const u8 PY_mb_qun []= {"ȹȺ����"};
const u8 PY_mb_ran []= {"ȻȼȽȾ������"};
const u8 PY_mb_rang []= {"ȿ�����������"};
const u8 PY_mb_rao []= {"�����������"};
const u8 PY_mb_re []= {"������"};
const u8 PY_mb_ren []= {"�����������������������������������"};
const u8 PY_mb_reng []= {"����"};
const u8 PY_mb_ri []= {"��"};
const u8 PY_mb_rong []= {"������������������������������"};
const u8 PY_mb_rou []= {"������������"};
const u8 PY_mb_ru []= {"���������������������������޸�������"};
const u8 PY_mb_ruan []= {"������"};
const u8 PY_mb_rui []= {"�����������ި�"};
const u8 PY_mb_run []= {"����"};
const u8 PY_mb_ruo []= {"����ټ��"};
const u8 PY_mb_sa []= {"������ئ�����"};
const u8 PY_mb_sai []= {"����������"};
const u8 PY_mb_san []= {"����ɡɢ�����"};
const u8 PY_mb_sang []= {"ɣɤɥ�����"};
const u8 PY_mb_sao []= {"ɦɧɨɩ����ܣ����"};
const u8 PY_mb_se []= {"��ɪɫɬ����"};
const u8 PY_mb_sen []= {"ɭ"};
const u8 PY_mb_seng []= {"ɮ"};
const u8 PY_mb_sha []= {"ɯɰɱɲɳɴɵɶɷɼ��������������"};
const u8 PY_mb_shai []= {"ɫɸɹ"};
const u8 PY_mb_shan []= {"����ɺɻɼɽɾɿ��������������������դڨ�����������۷���������������������"};
const u8 PY_mb_shang []= {"�������������������������"};
const u8 PY_mb_shao []= {"������������������������ۿ�����������"};
const u8 PY_mb_she []= {"�����������������������������������������"};
const u8 PY_mb_shei []= {"˭"};
const u8 PY_mb_shen []= {"����������������������������������ʲڷ��ݷ�������������"};
const u8 PY_mb_sheng []= {"��������������ʡʢʣʤʥ����������"};
const u8 PY_mb_shi []= {"���³�ʦʮʯʧʨʩʪʫʬʭʰʱʲʳʴʵʶʷʸʹʺʻʼʽʾʿ����������������������������������������߱��ֳ������ݪ��������������������������"};
const u8 PY_mb_shou []= {"���������������������������"};
const u8 PY_mb_shu []= {"����������������������������������������������������������������ˡٿ�������ح���������������"};
const u8 PY_mb_shua []= {"ˢˣ�"};
const u8 PY_mb_shuai []= {"��ˤ˥˦˧�"};
const u8 PY_mb_shuan []= {"˨˩����"};
const u8 PY_mb_shuang[]= {"˪˫ˬ����"};
const u8 PY_mb_shui []= {"ˮ˯˰˵��"};
const u8 PY_mb_shun []= {"˱˲˳˴"};
const u8 PY_mb_shuo []= {"��˵˶˷˸����������"};
const u8 PY_mb_si []= {"˹˺˻˼˽˾˿����������������������ٹ���������������������������"};
const u8 PY_mb_song []= {"��������������������������ݿڡ"};
const u8 PY_mb_sou []= {"�����������������������޴"};
const u8 PY_mb_su []= {"�����������������������������������������"};
const u8 PY_mb_suan []= {"�������"};
const u8 PY_mb_sui []= {"����������������������"};
const u8 PY_mb_sun []= {"������"};
const u8 PY_mb_suo []= {"�����������������������ɯ��������"};
const u8 PY_mb_ta []= {"����������̡̢��̣̤�����������������"};
const u8 PY_mb_tai []= {"̧̨̥̦̩̪̫̬̭��ۢ޷����������"};
const u8 PY_mb_tan []= {"��̴̵̶̷̸̮̯̰̱̲̳̹̺̻̼̽̾̿��۰������������"};
const u8 PY_mb_tang []= {"�������������������������������������������������"};
const u8 PY_mb_tao []= {"����������������������߶��������ػ"};
const u8 PY_mb_te []= {"��߯���"};
const u8 PY_mb_teng []= {"����������"};
const u8 PY_mb_ti []= {"���������������������������������������������"};
const u8 PY_mb_tian []= {"����������������������������"};
const u8 PY_mb_tiao []= {"������������٬������������������"};
const u8 PY_mb_tie []= {"�����������"};
const u8 PY_mb_ting []= {"������ͣͤͥͦͧ͢͡��������������"};
const u8 PY_mb_tong []= {"ͩͫͬͭͮͯͰͱͲͳʹ١��������ͪ���������"};
const u8 PY_mb_tou []= {"͵Ͷͷ͸������"};
const u8 PY_mb_tu []= {"͹ͺͻͼͽ;Ϳ��������ܢݱ������"};
const u8 PY_mb_tuan []= {"���������"};
const u8 PY_mb_tui []= {"��������������"};
const u8 PY_mb_tun []= {"�����������������"};
const u8 PY_mb_tuo []= {"˵������������������������ر٢����������������������"};
const u8 PY_mb_wa []= {"�������������������"};
const u8 PY_mb_wai []= {"������"};
const u8 PY_mb_wan []= {"��������������������������������������ܹݸ��������������"};
const u8 PY_mb_wang []= {"�����������������������������"};
const u8 PY_mb_wei []= {"Ϊλν��Ρ΢ΣΤάΥΦΧΨΩΫέήίΰαβγδεζηθικμξο������������ޱ�����������������������������������"};
const u8 PY_mb_wen []= {"�������������������������������"};
const u8 PY_mb_weng []= {"��������޳"};
const u8 PY_mb_wo []= {"���������������������ݫ��������"};
const u8 PY_mb_wu []= {"�����������������������أ����������������������������������������������������������������������������������"};
const u8 PY_mb_xi []= {"ϣϰϦϷϸ����������������������ϡ��ϢϤϥϧϨϪϫϬϮϯϱϲϴϵ϶���������������ϭϩϳ��������ۭݾ���������������������������������������������"};
const u8 PY_mb_xia []= {"ϹϺϻϼϽϾϿ���������������������������"};
const u8 PY_mb_xian []= {"������������������ϳϴ��������������������������������������ݲ޺������������������������������"};
const u8 PY_mb_xiang []= {"������������������������������������������ܼ������������"};
const u8 PY_mb_xiao []= {"С��Ф��������������������ТУХЦЧ���������������������"};
const u8 PY_mb_xie []= {"ЩЪЫЬЭЮЯабвгдежзийклмѪ��ШҶ��������ޯߢ���������������������"};
const u8 PY_mb_xin []= {"ноп��������������ܰݷ����ض����"};
const u8 PY_mb_xing []= {"��ʡ�����������������������������������ߩ���"};
const u8 PY_mb_xiong []= {"��������������ܺ"};
const u8 PY_mb_xiu []= {"������������������������������������"};
const u8 PY_mb_xu []= {"��������������������������������������ڼ������ޣ������������������"};
const u8 PY_mb_xuan []= {"��ѡ��������������Ѥ��ѣѢ����������������������ȯ"};
const u8 PY_mb_xue []= {"��ѥѦѧѨѩѪ����������"};
const u8 PY_mb_xun []= {"ѰѮѸѶѯѵѫѬѭѱѲѳѴѷۨ����޹������࿣ݡަ����������"};
const u8 PY_mb_ya []= {"��ѿ����ѹ��ѺѻѼѽѾ�����������������������������������"};
const u8 PY_mb_yan []= {"��������������������������������������������������������������������������������ٲ��Ǧ����������ڥ����۱۳ܾ�����������������������������"};
const u8 PY_mb_yang []= {"�������������������������������������������������"};
const u8 PY_mb_yao []= {"Ҫ��ҧҩ����ҡҢ���ңҤҥҦҨҫԿزس��ߺ����ű�����������������������"};
const u8 PY_mb_ye []= {"ҲҳҵҶҹҺҬҭҮүҰұҴҷҸа��������������������"};
const u8 PY_mb_yi []= {"һ��������������������ҼҽҾҿ�������������������������������������������������������������������������β��������٫ڱ������ܲ����޲������߽߮�����������������������������������������������������������������"};
const u8 PY_mb_yin []= {"����ӡ����������������������������ط�۴����ܧ������������������"};
const u8 PY_mb_ying []= {"ӳӰӢӨөӪӫӣӤӥӦӧӬӭӮӯӱӲ��ݺ�����������۫�������������������"};
const u8 PY_mb_yo []= {"Ӵ���"};
const u8 PY_mb_yong []= {"��ӵӶ��ӿӷӸӹӺӻӼӽӾ����ٸ��ܭ�����������"};
const u8 PY_mb_you []= {"��������������������������������������������������������٧ݬݯݵ��������������������"};
const u8 PY_mb_yu []= {"������������������ԡ������������������������������������������������������������ԢԣԤԥԦ��ع�����εξخ��ٶ��������������������������������������������������������������������������"};
const u8 PY_mb_yuan []= {"ԭԪ԰ԱԲԴԵԶԸԹԺԧԨԩԫԬԮԯԳԷ��ܫܾ������������������"};
const u8 PY_mb_yue []= {"��������˵ԻԼԽԾԿ����������������"};
const u8 PY_mb_yun []= {"��Ա�������������������������ܿ��۩����������"};
const u8 PY_mb_za []= {"��������զ����"};
const u8 PY_mb_zai []= {"������������������"};
const u8 PY_mb_zan []= {"���������������������"};
const u8 PY_mb_zang []= {"�����������"};
const u8 PY_mb_zao []= {"������������������������������"};
const u8 PY_mb_ze []= {"��������զ�����������������"};
const u8 PY_mb_zei []= {"��"};
const u8 PY_mb_zen []= {"����"};
const u8 PY_mb_zeng []= {"��������������"};
const u8 PY_mb_zha []= {"��բ����������ագդեզէըթ߸��������������������"};
const u8 PY_mb_zhai []= {"լխծ����ժիկ���"};
const u8 PY_mb_zhan []= {"ռսվչմ��հձղճյնշոպ��ջտ�������"};
const u8 PY_mb_zhang []= {"�������������������������˳������������۵���"};
const u8 PY_mb_zhao []= {"����צ���׳�����گ������������������"};
const u8 PY_mb_zhe []= {"������������������������ߡ��������������"};
const u8 PY_mb_zhen []= {"��������������������������������֡����������������������������"};
const u8 PY_mb_zheng []= {"��֤��������������������֢֣ں����������"};
const u8 PY_mb_zhi []= {"��������ֻ֧ʶִֵֹ��ּֽ֥֭֮־ְֱֲֳֶַָֺֿ֦֪֫֬֯��������������֨֩������������ش��ۤ������������������������������������������������������������"};
const u8 PY_mb_zhong []= {"����������������������ڣ���������"};
const u8 PY_mb_zhou []= {"����������������������������ݧ����������������"};
const u8 PY_mb_zhu []= {"��סעף������������������������������������������פ������٪����ۥ��������������������������������ؼ"};
const u8 PY_mb_zhua []= {"ץצ��"};
const u8 PY_mb_zhuai []= {"קת"};
const u8 PY_mb_zhuan []= {"��רשת׫׬׭�������"};
const u8 PY_mb_zhuang[]= {"��׮ׯװױײ׳״����"};
const u8 PY_mb_zhui []= {"׵׶׷׸׹׺�������"};
const u8 PY_mb_zhun []= {"׻׼����"};
const u8 PY_mb_zhuo []= {"��׽׾׿��������������پ��ߪ������������"};
const u8 PY_mb_zi []= {"���������������������������������֨��������������������������������������"};
const u8 PY_mb_zong []= {"����������������������"};
const u8 PY_mb_zou []= {"������������۸����"};
const u8 PY_mb_zu []= {"����������������������"};
const u8 PY_mb_zuan []= {"��߬������"};
const u8 PY_mb_zui []= {"��������ީ��"};
const u8 PY_mb_zun []= {"��������ߤ"};
const u8 PY_mb_zuo []= {"�����������������������������������"};

//ƴ��������
const py_index py_index3[] = { {"" ,"",(u8*)PY_mb_space},
	{	"2","a",(u8*)PY_mb_a},
	{	"3","e",(u8*)PY_mb_e},
	{	"6","o",(u8*)PY_mb_o},
	{	"24","ai",(u8*)PY_mb_ai},
	{	"26","an",(u8*)PY_mb_an},
	{	"26","ao",(u8*)PY_mb_ao},
	{	"22","ba",(u8*)PY_mb_ba},
	{	"24","bi",(u8*)PY_mb_bi},
	{	"26","bo",(u8*)PY_mb_bo},
	{	"28","bu",(u8*)PY_mb_bu},
	{	"22","ca",(u8*)PY_mb_ca},
	{	"23","ce",(u8*)PY_mb_ce},
	{	"24","ci",(u8*)PY_mb_ci},
	{	"28","cu",(u8*)PY_mb_cu},
	{	"32","da",(u8*)PY_mb_da},
	{	"33","de",(u8*)PY_mb_de},
	{	"34","di",(u8*)PY_mb_di},
	{	"38","du",(u8*)PY_mb_du},
	{	"36","en",(u8*)PY_mb_en},
	{	"37","er",(u8*)PY_mb_er},
	{	"32","fa",(u8*)PY_mb_fa},
	{	"36","fo",(u8*)PY_mb_fo},
	{	"38","fu",(u8*)PY_mb_fu},
	{	"42","ha",(u8*)PY_mb_ha},
	{	"42","ga",(u8*)PY_mb_ga},
	{	"43","ge",(u8*)PY_mb_ge},
	{	"43","he",(u8*)PY_mb_he},
	{	"48","gu",(u8*)PY_mb_gu},
	{	"48","hu",(u8*)PY_mb_hu},
	{	"54","ji",(u8*)PY_mb_ji},
	{	"58","ju",(u8*)PY_mb_ju},
	{	"52","ka",(u8*)PY_mb_ka},
	{	"53","ke",(u8*)PY_mb_ke},
	{	"58","ku",(u8*)PY_mb_ku},
	{	"52","la",(u8*)PY_mb_la},
	{	"53","le",(u8*)PY_mb_le},
	{	"54","li",(u8*)PY_mb_li},
	{	"58","lu",(u8*)PY_mb_lu},
	{	"58","lv",(u8*)PY_mb_lv},
	{	"62","ma",(u8*)PY_mb_ma},
	{	"63","me",(u8*)PY_mb_me},
	{	"64","mi",(u8*)PY_mb_mi},
	{	"66","mo",(u8*)PY_mb_mo},
	{	"68","mu",(u8*)PY_mb_mu},
	{	"62","na",(u8*)PY_mb_na},
	{	"63","ne",(u8*)PY_mb_ne},
	{	"64","ni",(u8*)PY_mb_ni},
	{	"68","nu",(u8*)PY_mb_nu},
	{	"68","nv",(u8*)PY_mb_nv},
	{	"68","ou",(u8*)PY_mb_ou},
	{	"72","pa",(u8*)PY_mb_pa},
	{	"74","pi",(u8*)PY_mb_pi},
	{	"76","po",(u8*)PY_mb_po},
	{	"78","pu",(u8*)PY_mb_pu},
	{	"74","qi",(u8*)PY_mb_qi},
	{	"78","qu",(u8*)PY_mb_qu},
	{	"73","re",(u8*)PY_mb_re},
	{	"74","ri",(u8*)PY_mb_ri},
	{	"78","ru",(u8*)PY_mb_ru},
	{	"72","sa",(u8*)PY_mb_sa},
	{	"73","se",(u8*)PY_mb_se},
	{	"74","si",(u8*)PY_mb_si},
	{	"78","su",(u8*)PY_mb_su},
	{	"82","ta",(u8*)PY_mb_ta},
	{	"83","te",(u8*)PY_mb_te},
	{	"84","ti",(u8*)PY_mb_ti},
	{	"88","tu",(u8*)PY_mb_tu},
	{	"92","wa",(u8*)PY_mb_wa},
	{	"96","wo",(u8*)PY_mb_wo},
	{	"98","wu",(u8*)PY_mb_wu},
	{	"94","xi",(u8*)PY_mb_xi},
	{	"98","xu",(u8*)PY_mb_xu},
	{	"92","ya",(u8*)PY_mb_ya},
	{	"93","ye",(u8*)PY_mb_ye},
	{	"94","yi",(u8*)PY_mb_yi},
	{	"96","yo",(u8*)PY_mb_yo},
	{	"98","yu",(u8*)PY_mb_yu},
	{	"92","za",(u8*)PY_mb_za},
	{	"93","ze",(u8*)PY_mb_ze},
	{	"94","zi",(u8*)PY_mb_zi},
	{	"98","zu",(u8*)PY_mb_zu},
	{	"264","ang",(u8*)PY_mb_ang},
	{	"224","bai",(u8*)PY_mb_bai},
	{	"226","ban",(u8*)PY_mb_ban},
	{	"226","bao",(u8*)PY_mb_bao},
	{	"234","bei",(u8*)PY_mb_bei},
	{	"236","ben",(u8*)PY_mb_ben},
	{	"243","bie",(u8*)PY_mb_bie},
	{	"246","bin",(u8*)PY_mb_bin},
	{	"224","cai",(u8*)PY_mb_cai},
	{	"226","can",(u8*)PY_mb_can},
	{	"226","cao",(u8*)PY_mb_cao},
	{	"242","cha",(u8*)PY_mb_cha},
	{	"243","che",(u8*)PY_mb_che},
	{	"244","chi",(u8*)PY_mb_chi},
	{	"248","chu",(u8*)PY_mb_chu},
	{	"268","cou",(u8*)PY_mb_cou},
	{	"284","cui",(u8*)PY_mb_cui},
	{	"286","cun",(u8*)PY_mb_cun},
	{	"286","cuo",(u8*)PY_mb_cuo},
	{	"324","dai",(u8*)PY_mb_dai},
	{	"326","dan",(u8*)PY_mb_dan},
	{	"326","dao",(u8*)PY_mb_dao},
	{	"334","dei",(u8*)PY_mb_dei},
	{	"343","die",(u8*)PY_mb_die},
	{	"348","diu",(u8*)PY_mb_diu},
	{	"368","dou",(u8*)PY_mb_dou},
	{	"384","dui",(u8*)PY_mb_dui},
	{	"386","dun",(u8*)PY_mb_dun},
	{	"386","duo",(u8*)PY_mb_duo},
	{	"326","fan",(u8*)PY_mb_fan},
	{	"334","fei",(u8*)PY_mb_fei},
	{	"336","fen",(u8*)PY_mb_fen},
	{	"368","fou",(u8*)PY_mb_fou},
	{	"424","gai",(u8*)PY_mb_gai},
	{	"426","gan",(u8*)PY_mb_gan},
	{	"426","gao",(u8*)PY_mb_gao},
	{	"434","gei",(u8*)PY_mb_gei},
	{	"436","gen",(u8*)PY_mb_gan},
	{	"468","gou",(u8*)PY_mb_gou},
	{	"482","gua",(u8*)PY_mb_gua},
	{	"484","gui",(u8*)PY_mb_gui},
	{	"486","gun",(u8*)PY_mb_gun},
	{	"486","guo",(u8*)PY_mb_guo},
	{	"424","hai",(u8*)PY_mb_hai},
	{	"426","han",(u8*)PY_mb_han},
	{	"426","hao",(u8*)PY_mb_hao},
	{	"434","hei",(u8*)PY_mb_hei},
	{	"436","hen",(u8*)PY_mb_hen},
	{	"468","hou",(u8*)PY_mb_hou},
	{	"482","hua",(u8*)PY_mb_hua},
	{	"484","hui",(u8*)PY_mb_hui},
	{	"486","hun",(u8*)PY_mb_hun},
	{	"486","huo",(u8*)PY_mb_huo},
	{	"542","jia",(u8*)PY_mb_jia},
	{	"543","jie",(u8*)PY_mb_jie},
	{	"546","jin",(u8*)PY_mb_jin},
	{	"548","jiu",(u8*)PY_mb_jiu},
	{	"583","jue",(u8*)PY_mb_jue},
	{	"586","jun",(u8*)PY_mb_jun},
	{	"524","kai",(u8*)PY_mb_kai},
	{	"526","kan",(u8*)PY_mb_kan},
	{	"526","kao",(u8*)PY_mb_kao},
	{	"536","ken",(u8*)PY_mb_ken},
	{	"568","kou",(u8*)PY_mb_kou},
	{	"582","kua",(u8*)PY_mb_kua},
	{	"584","kui",(u8*)PY_mb_kui},
	{	"586","kun",(u8*)PY_mb_kun},
	{	"586","kuo",(u8*)PY_mb_kuo},
	{	"524","lai",(u8*)PY_mb_lai},
	{	"526","lan",(u8*)PY_mb_lan},
	{	"526","lao",(u8*)PY_mb_lao},
	{	"534","lei",(u8*)PY_mb_lei},
	{	"543","lie",(u8*)PY_mb_lie},
	{	"546","lin",(u8*)PY_mb_lin},
	{	"548","liu",(u8*)PY_mb_liu},
	{	"568","lou",(u8*)PY_mb_lou},
	{	"583","lue",(u8*)PY_mb_lue},
	{	"586","lun",(u8*)PY_mb_lun},
	{	"586","luo",(u8*)PY_mb_luo},
	{	"624","mai",(u8*)PY_mb_mai},
	{	"626","man",(u8*)PY_mb_man},
	{	"626","mao",(u8*)PY_mb_mao},
	{	"634","mei",(u8*)PY_mb_mei},
	{	"636","men",(u8*)PY_mb_men},
	{	"643","mie",(u8*)PY_mb_mie},
	{	"646","min",(u8*)PY_mb_min},
	{	"648","miu",(u8*)PY_mb_miu},
	{	"668","mou",(u8*)PY_mb_mou},
	{	"624","nai",(u8*)PY_mb_nai},
	{	"626","nan",(u8*)PY_mb_nan},
	{	"626","nao",(u8*)PY_mb_nao},
	{	"634","nei",(u8*)PY_mb_nei},
	{	"636","nen",(u8*)PY_mb_nen},
	{	"643","nie",(u8*)PY_mb_nie},
	{	"646","nin",(u8*)PY_mb_nin},
	{	"648","niu",(u8*)PY_mb_niu},
	{	"683","nue",(u8*)PY_mb_nue},
	{	"686","nuo",(u8*)PY_mb_nuo},
	{	"724","pai",(u8*)PY_mb_pai},
	{	"726","pan",(u8*)PY_mb_pan},
	{	"726","pao",(u8*)PY_mb_pao},
	{	"734","pei",(u8*)PY_mb_pei},
	{	"736","pen",(u8*)PY_mb_pen},
	{	"743","pie",(u8*)PY_mb_pie},
	{	"746","pin",(u8*)PY_mb_pin},
	{	"768","pou",(u8*)PY_mb_pou},
	{	"742","qia",(u8*)PY_mb_qia},
	{	"743","qie",(u8*)PY_mb_qie},
	{	"746","qin",(u8*)PY_mb_qin},
	{	"748","qiu",(u8*)PY_mb_qiu},
	{	"783","que",(u8*)PY_mb_que},
	{	"786","qun",(u8*)PY_mb_qun},
	{	"726","ran",(u8*)PY_mb_ran},
	{	"726","rao",(u8*)PY_mb_rao},
	{	"736","ren",(u8*)PY_mb_ren},
	{	"768","rou",(u8*)PY_mb_rou},
	{	"784","rui",(u8*)PY_mb_rui},
	{	"786","run",(u8*)PY_mb_run},
	{	"786","ruo",(u8*)PY_mb_ruo},
	{	"724","sai",(u8*)PY_mb_sai},
	{	"726","sao",(u8*)PY_mb_sao},
	{	"726","san",(u8*)PY_mb_san},
	{	"736","sen",(u8*)PY_mb_sen},
	{	"742","sha",(u8*)PY_mb_sha},
	{	"743","she",(u8*)PY_mb_she},
	{	"744","shi",(u8*)PY_mb_shi},
	{	"748","shu",(u8*)PY_mb_shu},
	{	"768","sou",(u8*)PY_mb_sou},
	{	"784","sui",(u8*)PY_mb_sui},
	{	"786","sun",(u8*)PY_mb_sun},
	{	"786","suo",(u8*)PY_mb_suo},
	{	"824","tai",(u8*)PY_mb_tai},
	{	"826","tan",(u8*)PY_mb_tan},
	{	"826","tao",(u8*)PY_mb_tao},
	{	"843","tie",(u8*)PY_mb_tie},
	{	"868","tou",(u8*)PY_mb_tou},
	{	"884","tui",(u8*)PY_mb_tui},
	{	"886","tun",(u8*)PY_mb_tun},
	{	"886","tuo",(u8*)PY_mb_tuo},
	{	"924","wai",(u8*)PY_mb_wai},
	{	"926","wan",(u8*)PY_mb_wan},
	{	"934","wei",(u8*)PY_mb_wei},
	{	"936","wen",(u8*)PY_mb_wen},
	{	"942","xia",(u8*)PY_mb_xia},
	{	"943","xie",(u8*)PY_mb_xie},
	{	"946","xin",(u8*)PY_mb_xin},
	{	"948","xiu",(u8*)PY_mb_xiu},
	{	"983","xue",(u8*)PY_mb_xue},
	{	"986","xun",(u8*)PY_mb_xun},
	{	"926","yan",(u8*)PY_mb_yan},
	{	"926","yao",(u8*)PY_mb_yao},
	{	"946","yin",(u8*)PY_mb_yin},
	{	"968","you",(u8*)PY_mb_you},
	{	"983","yue",(u8*)PY_mb_yue},
	{	"986","yun",(u8*)PY_mb_yun},
	{	"924","zai",(u8*)PY_mb_zai},
	{	"926","zan",(u8*)PY_mb_zan},
	{	"926","zao",(u8*)PY_mb_zao},
	{	"934","zei",(u8*)PY_mb_zei},
	{	"936","zen",(u8*)PY_mb_zen},
	{	"942","zha",(u8*)PY_mb_zha},
	{	"943","zhe",(u8*)PY_mb_zhe},
	{	"944","zhi",(u8*)PY_mb_zhi},
	{	"948","zhu",(u8*)PY_mb_zhu},
	{	"968","zou",(u8*)PY_mb_zou},
	{	"984","zui",(u8*)PY_mb_zui},
	{	"986","zun",(u8*)PY_mb_zun},
	{	"986","zuo",(u8*)PY_mb_zuo},
	{	"2264","bang",(u8*)PY_mb_bang},
	{	"2364","beng",(u8*)PY_mb_beng},
	{	"2426","bian",(u8*)PY_mb_bian},
	{	"2426","biao",(u8*)PY_mb_biao},
	{	"2464","bing",(u8*)PY_mb_bing},
	{	"2264","cang",(u8*)PY_mb_cang},
	{	"2364","ceng",(u8*)PY_mb_ceng},
	{	"2424","chai",(u8*)PY_mb_chai},
	{	"2426","chan",(u8*)PY_mb_chan},
	{	"2426","chao",(u8*)PY_mb_chao},
	{	"2436","chen",(u8*)PY_mb_chen},
	{	"2468","chou",(u8*)PY_mb_chou},
	{	"2484","chuai",(u8*)PY_mb_chuai},
	{	"2484","chui",(u8*)PY_mb_chui},
	{	"2486","chun",(u8*)PY_mb_chun},
	{	"2486","chuo",(u8*)PY_mb_chuo},
	{	"2664","cong",(u8*)PY_mb_cong},
	{	"2826","cuan",(u8*)PY_mb_cuan},
	{	"3264","dang",(u8*)PY_mb_dang},
	{	"3364","deng",(u8*)PY_mb_deng},
	{	"3426","dian",(u8*)PY_mb_dian},
	{	"3426","diao",(u8*)PY_mb_diao},
	{	"3464","ding",(u8*)PY_mb_ding},
	{	"3664","dong",(u8*)PY_mb_dong},
	{	"3826","duan",(u8*)PY_mb_duan},
	{	"3264","fang",(u8*)PY_mb_fang},
	{	"3364","feng",(u8*)PY_mb_feng},
	{	"4264","gang",(u8*)PY_mb_gang},
	{	"4364","geng",(u8*)PY_mb_geng},
	{	"4664","gong",(u8*)PY_mb_gong},
	{	"4824","guai",(u8*)PY_mb_guai},
	{	"4826","guan",(u8*)PY_mb_guan},
	{	"4264","hang",(u8*)PY_mb_hang},
	{	"4364","heng",(u8*)PY_mb_heng},
	{	"4664","hong",(u8*)PY_mb_hong},
	{	"4823","huai",(u8*)PY_mb_huai},
	{	"4826","huan",(u8*)PY_mb_huan},
	{	"5426","jian",(u8*)PY_mb_jian},
	{	"5426","jiao",(u8*)PY_mb_jiao},
	{	"5464","jing",(u8*)PY_mb_jing},
	{	"5826","juan",(u8*)PY_mb_juan},
	{	"5264","kang",(u8*)PY_mb_kang},
	{	"5364","keng",(u8*)PY_mb_keng},
	{	"5664","kong",(u8*)PY_mb_kong},
	{	"5824","kuai",(u8*)PY_mb_kuai},
	{	"5826","kuan",(u8*)PY_mb_kuan},
	{	"5264","lang",(u8*)PY_mb_lang},
	{	"5366","leng",(u8*)PY_mb_leng},
	{	"5426","lian",(u8*)PY_mb_lian},
	{	"5426","liao",(u8*)PY_mb_liao},
	{	"5464","ling",(u8*)PY_mb_ling},
	{	"5664","long",(u8*)PY_mb_long},
	{	"5826","luan",(u8*)PY_mb_luan},
	{	"6264","mang",(u8*)PY_mb_mang},
	{	"6364","meng",(u8*)PY_mb_meng},
	{	"6426","mian",(u8*)PY_mb_mian},
	{	"6426","miao",(u8*)PY_mb_miao},
	{	"6464","ming",(u8*)PY_mb_ming},
	{	"6264","nang",(u8*)PY_mb_nang},
	{	"6364","neng",(u8*)PY_mb_neng},
	{	"6426","nian",(u8*)PY_mb_nian},
	{	"6426","niao",(u8*)PY_mb_niao},
	{	"6464","ning",(u8*)PY_mb_ning},
	{	"6664","nong",(u8*)PY_mb_nong},
	{	"6826","nuan",(u8*)PY_mb_nuan},
	{	"7264","pang",(u8*)PY_mb_pang},
	{	"7364","peng",(u8*)PY_mb_peng},
	{	"7426","pian",(u8*)PY_mb_pian},
	{	"7426","piao",(u8*)PY_mb_piao},
	{	"7464","ping",(u8*)PY_mb_ping},
	{	"7426","qian",(u8*)PY_mb_qian},
	{	"7426","qiao",(u8*)PY_mb_qiao},
	{	"7464","qing",(u8*)PY_mb_qing},
	{	"7826","quan",(u8*)PY_mb_quan},
	{	"7264","rang",(u8*)PY_mb_rang},
	{	"7364","reng",(u8*)PY_mb_reng},
	{	"7664","rong",(u8*)PY_mb_rong},
	{	"7826","ruan",(u8*)PY_mb_ruan},
	{	"7264","sang",(u8*)PY_mb_sang},
	{	"7364","seng",(u8*)PY_mb_seng},
	{	"7424","shai",(u8*)PY_mb_shai},
	{	"7426","shan",(u8*)PY_mb_shan},
	{	"7426","shao",(u8*)PY_mb_shao},
	{	"7434","shei",(u8*)PY_mb_shei},
	{	"7436","shen",(u8*)PY_mb_shen},
	{	"7468","shou",(u8*)PY_mb_shou},
	{	"7482","shua",(u8*)PY_mb_shua},
	{	"7484","shui",(u8*)PY_mb_shui},
	{	"7486","shun",(u8*)PY_mb_shun},
	{	"7486","shuo",(u8*)PY_mb_shuo},
	{	"7664","song",(u8*)PY_mb_song},
	{	"7826","suan",(u8*)PY_mb_suan},
	{	"8264","tang",(u8*)PY_mb_tang},
	{	"8364","teng",(u8*)PY_mb_teng},
	{	"8426","tian",(u8*)PY_mb_tian},
	{	"8426","tiao",(u8*)PY_mb_tiao},
	{	"8464","ting",(u8*)PY_mb_ting},
	{	"8664","tong",(u8*)PY_mb_tong},
	{	"8826","tuan",(u8*)PY_mb_tuan},
	{	"9264","wang",(u8*)PY_mb_wang},
	{	"9364","weng",(u8*)PY_mb_weng},
	{	"9426","xian",(u8*)PY_mb_xian},
	{	"9426","xiao",(u8*)PY_mb_xiao},
	{	"9464","xing",(u8*)PY_mb_xing},
	{	"9826","xuan",(u8*)PY_mb_xuan},
	{	"9264","yang",(u8*)PY_mb_yang},
	{	"9464","ying",(u8*)PY_mb_ying},
	{	"9664","yong",(u8*)PY_mb_yong},
	{	"9826","yuan",(u8*)PY_mb_yuan},
	{	"9264","zang",(u8*)PY_mb_zang},
	{	"9364","zeng",(u8*)PY_mb_zeng},
	{	"9424","zhai",(u8*)PY_mb_zhai},
	{	"9426","zhan",(u8*)PY_mb_zhan},
	{	"9426","zhao",(u8*)PY_mb_zhao},
	{	"9436","zhen",(u8*)PY_mb_zhen},
	{	"9468","zhou",(u8*)PY_mb_zhou},
	{	"9482","zhua",(u8*)PY_mb_zhua},
	{	"9484","zhui",(u8*)PY_mb_zhui},
	{	"9486","zhun",(u8*)PY_mb_zhun},
	{	"9486","zhuo",(u8*)PY_mb_zhuo},
	{	"9664","zong",(u8*)PY_mb_zong},
	{	"9826","zuan",(u8*)PY_mb_zuan},
	{	"24264","chang",(u8*)PY_mb_chang},
	{	"24364","cheng",(u8*)PY_mb_cheng},
	{	"24664","chong",(u8*)PY_mb_chong},
	{	"24826","chuan",(u8*)PY_mb_chuan},
	{	"48264","guang",(u8*)PY_mb_guang},
	{	"48264","huang",(u8*)PY_mb_huang},
	{	"54264","jiang",(u8*)PY_mb_jiang},
	{	"54664","jiong",(u8*)PY_mb_jiong},
	{	"58264","kuang",(u8*)PY_mb_kuang},
	{	"54264","liang",(u8*)PY_mb_liang},
	{	"64264","niang",(u8*)PY_mb_niang},
	{	"74264","qiang",(u8*)PY_mb_qiang},
	{	"74664","qiong",(u8*)PY_mb_qiong},
	{	"74264","shang ",(u8*)PY_mb_shang},
	{	"74364","sheng",(u8*)PY_mb_sheng},
	{	"74824","shuai",(u8*)PY_mb_shuai},
	{	"74826","shuan",(u8*)PY_mb_shuan},
	{	"94264","xiang",(u8*)PY_mb_xiang},
	{	"94664","xiong",(u8*)PY_mb_xiong},
	{	"94264","zhang",(u8*)PY_mb_zhang},
	{	"94364","zheng",(u8*)PY_mb_zheng},
	{	"94664","zhong",(u8*)PY_mb_zhong},
	{	"94824","zhuai",(u8*)PY_mb_zhuai},
	{	"94826","zhuan",(u8*)PY_mb_zhuan},
	{	"248264","chuang",(u8*)PY_mb_chuang},
	{	"748264","shuang",(u8*)PY_mb_shuang},
	{	"948264","zhuang",(u8*)PY_mb_zhuang},
};

#endif

#endif
