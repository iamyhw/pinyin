/*
 * Copyright (c) 2020-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: LGPL-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021/01/09     iamyhw       The first version.
 */

#include "pinyin.h"

//���ֵ�/�ʵ䰴������ĸ����,�ɼӿ�����ٶ�
static const ime_dicts_t dicts_a[] =
{
    { "a", "�������������������°�������������������߹�����" },
    { "ai", "���������������������������������������������" },
    { "an", "�����㳧�������������������������������" },
    { "ang", "������" },
    { "ao", "���°����������ð�����������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_b[] =
{
    { "b", "���������ѱ�Ȳ���ٱ������������߰˰첼" },
    { "ba", "�Ѱ˰ɰͰΰ԰հְӰŰưǰȰʰ̰ϰа���������������" },
    { "bai", "�ٰװܰڲ��ذ۰ݰ�����" },
    { "ban", "���������߰����������������" },
    { "bang", "���������������������" },
    { "bao", "�����������������������������������������������" },
    { "be", "���±���������" },
    { "bei", "�������������������������������������������������������" },
    { "ben", "���������������" },
    { "beng", "�ñ����±ı����" },
    { "bi", "�ȱرܱձٱʱڱ۱ϱ˱ƱұǱαɱ̱ͱбѱӱԱֱױ�ذ����ݩ޵�����������������������������������������" },
    { "bian", "��߱������ޱ�������������������������������" },
    { "biao", "�����������������������" },
    { "bie", "�������" },
    { "bin", "������������������������������" },
    { "bing", "������������������������" },
    { "bo", "�����������������������������������������������������������" },
    { "bu", "����������������������߲�����������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_c[] =
{
    { "c", "���ɳ����Ӵ˳����������ɲ㳧�Ŵγ�����" },
    { "ca", "������" },
    { "cai", "�ɲŲĲ˲Ʋòʲ²ǲȲ�" },
    { "can", "�βвϲӲͲѲ����������" },
    { "cang", "�زֲԲղ�" },
    { "cao", "�ݲ۲ٲڲ��������" },
    { "ce", "��߲�����" },
    { "cen", "��" },
    { "ceng", "���" },
    { "cha", "�������������ɲ���������������������" },
    { "chai", "�����٭�����" },
    { "chan", "��������������������������������������������������" },
    { "chang", "�����������������������������������������������������" },
    { "chao", "�������������������½���������" },
    { "che", "�����߳�����������" },
    { "chen", "�³��Ƴĳ������򳻳����������������������" },
    { "cheng", "�ɳ̳Ƴǳг˳�ʢ�ųϳȳͳγѳҳ�ة���������������������" },
    { "chi", "�ֳ߳ݳԳ�سٳ��ܳճ׳ڳ۳޳�����ܯ��߳������������������������������" },
    { "chong", "�ֳ��س���ӿ������������" },
    { "chou", "���������������ٱ������" },
    { "chu", "���������������������������������ءۻ�������������������" },
    { "chuai", "�����������" },
    { "chuan", "������������������������" },
    { "chuang", "��������������" },
    { "chui", "������׵��������" },
    { "chun", "��������������ݻ����" },
    { "chuo", "����������" },
    { "ci", "�˴δ̴ŴƴʴĴôǴȴɴ���������������" },
    { "cong", "�ӴԴϴдѴ����������" },
    { "cou", "������" },
    { "cu", "�ִٴ״����������������" },
    { "cuan", "�۴ڴ�����ߥ����" },
    { "cui", "�ߴ����˥�޴�������������" },
    { "cun", "���������" },
    { "cuo", "�������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_d[] =
{
    { "d", "�Ĵ�ض����Զȶ�絳�ö��ȶ����Ӷ������" },
    { "da", "������������������������������" },
    { "dai", "�������������������������ܤ߰߾����������" },
    { "dan", "��������ʯ������������������������������������������" },
    { "dang", "���������������������" },
    { "dao", "����������������������߶���������" },
    { "de", "�ĵõصµ��" },
    { "deng", "�ȵƵǵ˳εŵɵ������������" },
    { "di", "�ĵصڵ͵е���۵ֵεܵݵ̵ϵѵҵӵԵյٵ�ص��ڮ��ۡ��ݶ���������������������" },
    { "dia", "��" },
    { "dian", "������ߵ���������������������������" },
    { "diao", "��������������������" },
    { "die", "����������������ܦ�������������" },
    { "ding", "������������������������������������" },
    { "diu", "����" },
    { "dong", "����������������������������������" },
    { "dou", "������������������������" },
    { "du", "�ȶ��������ɶŶ¶ƶٶ����öĶǶ�ܶ�������������" },
    { "duan", "�϶˶ζ̶Ͷ������" },
    { "dui", "�ԶӶѶض�������" },
    { "dun", "�ֶܶٶ׶ضնڶ۶���������������" },
    { "duo", "��ȶ��޶߶������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_e[] =
{
    { "e", "�������������������������������ج������ݭ��������������������" },
    { "ei", "��" },
    { "en", "������" },
    { "er", "����������������٦���������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_f[] =
{
    { "f", "�ַ��������Ÿ�����Ƿ��ʸ��۸��򸺷⸻��" },
    { "fa", "��������������������" },
    { "fan", "����������������������������������ެ����������" },
    { "fang", "���ŷ��÷��ķ·�������������������" },
    { "fei", "�ǷʷɷϷηзƷ˷ȷ̷������������������������������" },
    { "fen", "�ַ۷ܷݷ�׷ҷ߷ӷԷշطٷڷ������������" },
    { "feng", "�����������������ٺۺ��������" },
    { "fou", "���" },
    { "fu", "���������򸺸����������������������������������𸿸��������������������������������������������ۮܽ������ݳ����߻����������������������������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_g[] =
{
    { "g", "���������߸ɹظ��﹫�����Ĺܹ����񹲸�" },
    { "ga", "�и��¸����������" },
    { "gai", "�ĸøǸŸƸȽ�ؤ�������" },
    { "gan", "�ɸ˸иҸϸʸθѸ̸͸�Ǭ������ߦ����������������" },
    { "gang", "�ոָ׸ٸڸ۸ܸԸؿ������" },
    { "gao", "�߸����ݸ޸���غھ۬޻��������" },
    { "ge", "������ϸ�����Ǹ��������������ت������ܪ�������������������" },
    { "gen", "����بݢ����" },
    { "geng", "�����������������������" },
    { "gong", "�������������칮�����������������������" },
    { "gou", "�������乷������������ڸ������������������" },
    { "gu", "�Ĺ̹Źǹʹ˹ɹȹ��͹¹üֹ�������������ڬ����������������������������������������" },
    { "gua", "�ҹι����йѹ���ڴ�������" },
    { "guai", "�ֹԹ�" },
    { "guan", "�عܹ۹ٹ��߹ڹݹ޹�����ݸ������������" },
    { "guang", "������������" },
    { "gui", "��������������������Ȳ���������������������" },
    { "gun", "�������������" },
    { "guo", "�����������й����������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_h[] =
{
    { "h", "�ͻ�󻯺úϻ���ܻغź����򺣻����ƺ�" },
    { "ha", "����Ϻ��" },
    { "hai", "�����������������ٿ�������" },
    { "han", "����������������������������������������������������������" },
    { "hang", "�к����������������" },
    { "hao", "�úź��ĺ��ºƸ亾������޶����������" },
    { "he", "�ͺϺӺκ˺պɺֺȺغǺ��źкʺѺҺԺ�ڭ�������������������" },
    { "hei", "�ں�" },
    { "hen", "�ܺݺۺ�" },
    { "heng", "�к���ߺ�޿����" },
    { "hong", "��������������ڧݦޮް����" },
    { "hou", "���������ܩ��������������" },
    { "hu", "�ͻ����������������������˺�Ϸ��������������������������������������������������������" },
    { "hua", "����������������������������" },
    { "huai", "��������������" },
    { "huan", "�������������û�������������ۨۼ��ߧ������������������" },
    { "huang", "�ƻɻĻʻŻȻǻ˻̻ͻλϻл��������������������" },
    { "hui", "��ػһӻԻ�ٻۻֻ�ݻ����黲�׻ڻܻ޻߻����ڶ����ޥ�������������������������" },
    { "hun", "�������ڻ������" },
    { "huo", "�ͻ���������������޽߫������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_j[] =
{
    { "j", "���ͽ��Ӿ��ҽ�׼������ϻ����ӽ̼��ż�" },
    { "ji", "������������������Ǽ���ϵ��Ƽ����ʼ����ü����̼����ȼͼļ����������漪�����������������������������������������¼żɼ˽�آؽ����٥��ڵ��ܸ������ު��ߴ����������������������������������������������������������" },
    { "jia", "�ӼҼܼۼ׼мټؼּڼݼμϼѼԼռ���Ю��٤ۣ�������������������������������" },
    { "jian", "�������������������轥������������߼��ǳ����뽢�����������������������������������������������������������������������" },
    { "jiang", "������ǿ������������������������������������" },
    { "jiao", "�Ͻ̽��ǽнŽ�������У���ͽ��½ѽ����������ýĽƽȽɽʽ˽�ٮ��ܴ������������������������" },
    { "jie", "��׽�ӽڼҽ�ؽ��۽�ֽҽ�߽ܽԽսٽ۽ݽ޽�����뿬��ڦڵ���������������������" },
    { "jin", "���������񾡽������������������������ݣ��������������������" },
    { "jing", "��������������������������������������������������������ݼ������������������" },
    { "jiong", "����������" },
    { "jiu", "�;žɾ��þȾƾ������¾ľǾʾ˾̾�����������������" },
    { "ju", "�߾ݾ־ٳ���۾�޾Ӿ��ؾܹ�۾ϾоѾҾԾվ׾ھ������ڪ��������������������������������������������" },
    { "juan", "��������۲�������������" },
    { "jue", "�������ǽž������������������ާ������������������������" },
    { "jun", "�������������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_k[] =
{
    { "k", "�ɿ����˿׿ƿڿտ�쿼�̿����������󿹿�" },
    { "ka", "��������������" },
    { "kai", "�������������������������" },
    { "kan", "��������������Ƕ٩ݨ������" },
    { "kang", "��������������������" },
    { "kao", "����������������" },
    { "ke", "�ɿ˿ƿ̿Ϳǿſÿºǿ����Ŀȿʿ����������������������������" },
    { "ken", "�Ͽпѿ���" },
    { "keng", "�ӿ��" },
    { "kong", "�׿տؿ�������" },
    { "kou", "�ڿۿٿ���ޢߵ����" },
    { "ku", "���ݿ�޿߿���ܥ����" },
    { "kua", "������٨" },
    { "kuai", "��������ۦ�������" },
    { "kuan", "������" },
    { "kuang", "�����������ڲڿ������������" },
    { "kui", "����������������������ظ���������������������������" },
    { "kun", "��������������������" },
    { "kuo", "��������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_l[] =
{
    { "l", "��������·������������������������������" },
    { "la", "���������������������������" },
    { "lai", "���������������������" },
    { "lan", "����������������������������������������" },
    { "lang", "��������������ݹ����������" },
    { "lao", "���������������������������������������" },
    { "le", "����������߷����" },
    { "lei", "��������������������������ڳ������������" },
    { "leng", "������ܨ�" },
    { "li", "��������������������������������������������������������������������تٳٵ۪����ݰ��޼߿����������������������������������������������������������" },
    { "lia", "��" },
    { "lian", "������������������������������������������������" },
    { "liang", "����������������������ܮݹ�������" },
    { "liao", "��������������������������ޤ������������" },
    { "lie", "�������������������������" },
    { "lin", "���������������������������������������������" },
    { "ling", "��������������������������������۹����������������������" },
    { "liu", "������������½����������µ����������������" },
    { "long", "��¢Ū��¡������£¤���������������" },
    { "lou", "©¶¥¦§¨ª�����������������" },
    { "lu", "·��¶¯½³¼¬«­®°±²´µ¸¹º»¾��ޤߣ����������������������������������" },
    { "lv", "������������������¿�����������������" },
    { "luan", "��������������������" },
    { "lue", "�����" },
    { "lun", "����������������" },
    { "luo", "�����������߿������������������������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_m[] =
{
    { "m", "��������ëû������ôÿ����ĥ��������ĶĿ߼" },
    { "ma", "��ô������������ĦĨ������������" },
    { "mai", "������������۽ݤ��" },
    { "man", "����������������áܬ��������������" },
    { "mang", "æâäãåç��������" },
    { "mao", "ëìðòóñèéêíîï��������������������" },
    { "me", "ô��" },
    { "mei", "ûÿ��úùø÷��üõöýþ����������ݮ���������������" },
    { "men", "��������������" },
    { "meng", "��������������å������ޫ���������" },
    { "meng", "�����" },
    { "mi", "��������������������������������������������������������" },
    { "mian", "����������������������������" },
    { "miao", "�������������������������������" },
    { "mie", "����ؿ�����" },
    { "min", "�������������������������������" },
    { "ming", "��������������ڤ���������" },
    { "miu", "��" },
    { "mo", "��ĥû��ĩģĤ��īĦ��ĪĨðĬ�Ѻ�ġĢħĭĮįİ�����������������������" },
    { "mou", "ĳıĲٰ������������" },
    { "mu", "ĶĿľĸĹģĻ��ķ����ĲĴĵĺļĽ�������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_n[] =
{
    { "n", "��������ũ��������Ů��������ţ����ճ������" },
    { "na", "��������������������������" },
    { "nai", "������������ؾܵ����" },
    { "nan", "������������������" },
    { "nang", "��߭������" },
    { "nao", "����Ŭ������ث������������" },
    { "ne", "������ګ" },
    { "nei", "��������" },
    { "nen", "����" },
    { "neng", "��" },
    { "ni", "��������������������������٣������������������" },
    { "nian", "����ճ������������إ���������" },
    { "niao", "��������������" },
    { "nie", "��������������ؿ����������" },
    { "nin", "��" },
    { "ning", "����š����Ţ���������" },
    { "niu", "ţŤťŦ�������" },
    { "nong", "ũŪŨŧٯ��" },
    { "nou", "��" },
    { "nu", "ūŬŭ��������������" },
    { "nv", "Ů" },
    { "nuan", "ů" },
    { "nue", "Űű" },
    { "nuo", "ŵ��ŲųŴ�������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_o[] =
{
    { "o", "ŷżŶŸŹźŻŽک�������" },
    { "ou", "��ŷżŸŹźŻŽک�����" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_p[] =
{
    { "p", "��ƽ����Ƭ������ƷƤ����ƫ��������ƶ����" },
    { "pa", "���������ǰ�žſ����������" },
    { "pai", "����������������ٽ��" },
    { "pan", "�����ѷ��������������������������" },
    { "pang", "�԰�����������������" },
    { "pao", "������������������������" },
    { "pei", "�����������������������������" },
    { "pen", "������" },
    { "peng", "����������������������������ܡ�����" },
    { "pi", "��Ƥ�������Ƣƣ������������ơƥƦƧƨƩا��������ۯ����ܱ��ߨ����������������������������" },
    { "pian", "Ƭƫ��ƪƭ����������������" },
    { "piao", "ƱƯ��Ʈư��ݳ������������" },
    { "pie", "ƲƳد���" },
    { "pin", "ƷƶƵƴƻƸ���������" },
    { "ping", "ƽ��ƿƾƻ��ƹƺƼ��ٷ�����" },
    { "po", "�������÷��Ӳ�������������۶��������������" },
    { "pou", "������" },
    { "pu", "���������̱������ѱ��������������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_q[] =
{
    { "q", "��ǰ��ȥ��ȫ��Ⱥ����ǿ��ȡ������ȷȨ����" },
    { "qi", "���������������������������������������������������������������������������ؽ��ٹ��ܻ����ݽ����ޭ���������������������������������������������" },
    { "qia", "��ǡ��Ǣ٤������" },
    { "qian", "ǰǧǮǳǩǨǦǱǣǯ��ǴǤǥǪǫǬǭǲǵǶǷǸٻ����ܷ����ݡ�������������������������" },
    { "qiang", "ǿ��ǹ��ǽǻǺǼǾ����������������������" },
    { "qiao", "���ƿ������ǽ���������������������ȸ��ڽ�����������������" },
    { "qie", "������������٤ۧ���������" },
    { "qin", "����������������������������������������������" },
    { "qing", "��������������������������������������������������" },
    { "qiong", "�����������������" },
    { "qiu", "������������������ٴ��������������������������" },
    { "qu", "ȥ��ȡ������������Ȥ����Ȣȣ��ڰ۾��ޡ޾��������������������������" },
    { "quan", "ȫȨȦȰȪȩȧȬȭȮȯڹ���������������" },
    { "que", "ȷȴȱȲȳȵȶȸ������" },
    { "qun", "Ⱥȹ��" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_r[] =
{
    { "r", "��������������Ȼ��������ȼȾ������������" },
    { "ran", "ȻȼȾȽ������" },
    { "rang", "������ȿ�����" },
    { "rao", "�����������" },
    { "re", "������" },
    { "ren", "���������������������������������" },
    { "reng", "����" },
    { "ri", "��" },
    { "rong", "������������������������������" },
    { "rou", "������������" },
    { "ru", "����������������������޸������������" },
    { "ruan", "������" },
    { "rui", "��������ި����" },
    { "run", "����" },
    { "ruo", "����ټ" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_s[] =
{
    { "s", "����ʱ��˵����ˮ����ʮʹ������ʵ��ʽɽ��" },
    { "sa", "������ئ�������" },
    { "sai", "��˼��������" },
    { "san", "��ɢ��ɡ�����" },
    { "sang", "ɣɥɤ�����" },
    { "sao", "ɨ��ɦɧɩܣ����������" },
    { "se", "ɫ��ɪɬ����" },
    { "sen", "ɭ" },
    { "seng", "ɮ" },
    { "sha", "ɳɱɰɶɴɯɲɵɷɼ������������������" },
    { "shai", "ɫɸɹ" },
    { "shan", "ɽ������ɺ���µ�ɻɼɾɿ������������դ��ڨ۷��������������������������" },
    { "shang", "���������������������������" },
    { "shao", "��������������������������ۿ�����������" },
    { "she", "������������������������������ߡ�������" },
    { "shen", "������ʲ���������������������������ڷ��ݷ�������������" },
    { "sheng", "��ʤ��ʡ��ʢ��ʣʥ����������������" },
    { "shi", "��ʱʮʹ��ʵʽʶ����ʯʲʾ��ʷʦʼʩʿ��ʪ��ʳʧ��������ʴʫ��ֳʰ��ʻ��ʨʬʭʸʺ��������������������������ݪ��߱���������������������" },
    { "shou", "���������������������������" },
    { "shu", "����������������������������������������������������������������ˡ��حٿ������������������" },
    { "shua", "ˢˣ�" },
    { "shuai", "˥˧ˤ˦�" },
    { "shuan", "˨˩����" },
    { "shuang", "˫˪ˬ����" },
    { "shui", "ˮ˵˭˯˰" },
    { "shun", "˳˱˲˴" },
    { "shuo", "˵��˶˷˸����������" },
    { "si", "��˼��˹˿��˾��ʳ˽��˺˻������������ٹ����������������������������" },
    { "song", "����������������ڡݿ����������" },
    { "sou", "����������޴�������������" },
    { "su", "�����������������������������������������" },
    { "suan", "�������" },
    { "sui", "��������������������������ݴ��������" },
    { "sun", "������ݥ������" },
    { "suo", "��������ɯ�����������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_t[] =
{
    { "t", "��ͬ��������ͼ��ͷͨ��������ͳ̨��̫����" },
    { "ta", "��������̤��̡̢̣��������������������" },
    { "tai", "̨̧̫̬̥̩̦̪̭ۢ޷߾������������" },
    { "tan", "̸̼̽̿��̴̵̶̷̹̰̲̮̯̱̳̺̻̾۰����������" },
    { "tang", "����������������������������������������������" },
    { "tao", "����������������������ػ߶��������" },
    { "te", "��߯�����" },
    { "teng", "����������" },
    { "ti", "���������������������������������������������" },
    { "tian", "��������������������������" },
    { "tiao", "������������٬�����������������" },
    { "tie", "����������" },
    { "ting", "��ͣͥͦ͢����ͤͧ͡���������������" },
    { "tong", "ͬͨͳͭʹͲͯͰ����ͩͪͫͮͱ١���������������" },
    { "tou", "ͷͶ͸͵����" },
    { "tu", "ͼ��ͻ;ͽ͹Ϳ������ͺܢݱ������" },
    { "tuan", "���������" },
    { "tui", "������������߯��" },
    { "tun", "�����������������" },
    { "tuo", "���������ֶ���������������ر٢������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_w[] =
{
    { "w", "Ϊ����������λ��ί����������������Χ����" },
    { "wa", "���ڰ����������������" },
    { "wai", "����" },
    { "wan", "����������������������������������������ܹݸ������������" },
    { "wang", "����������������â�������������" },
    { "wei", "ΪλίΧάΨ��΢ΰδ��Σβνιζθκα��ΥΤηγΡΦΩΫέήεμξο������������ޱ���������������������������������" },
    { "wen", "�����������������������������" },
    { "weng", "��������޳" },
    { "wo", "��������������������ݫ���������" },
    { "wu", "�������������������������������������������������������������أ����������������������������������������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_x[] =
{
    { "x", "ѧ����С������Щ��������ϵϯ������������" },
    { "xi", "ϵϯ��ϰϸ����ϲϴϳϡϷ϶ϣϢϮ��ϩ��ϤϧϪ����������������ϥϦϨϫϬϭϱ������ۭ��ݾ������������������������������������������������������������" },
    { "xia", "��������ϼ��ϹϺϻϽϾϿ���������������������" },
    { "xian", "���������޼���������������ϴ����ϳ����������������������������ݲ޺�������" },
    { "xiang", "���������������罵������������������������ܼ��������������" },
    { "xiao", "С����ЧЦУ������ФТ������������Х�����������������������" },
    { "xie", "Щ��дблЭеҶѪжмЬЪавзйк��ШЫЮЯги��������ޯߢ�����������������" },
    { "xin", "������по��Ѱ��н����ضܰ������" },
    { "xing", "������������ʡ������������������������ߩ����" },
    { "xiong", "��������������ܺ" },
    { "xiu", "�������������޳���������������������" },
    { "xu", "����������������������������������������ڼ����ޣ��������������������" },
    { "xuan", "ѡ��������ȯ����ѢѣѤ������������������������������" },
    { "xue", "ѧѪ��ѩѨѥѦ����������" },
    { "xun", "ѵѮѸѶѰѭѲ�翣ѫѬѯѱѳѴѷ��ۨ����ަ޹���������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_y[] =
{
    { "y", "һ����Ҫ����Ҳ��������ѹԱ��������ԭ����" },
    { "ya", "ѹ��ѽ��ѿ����ѼƥѺѻѾ�������������������������������" },
    { "yan", "����������������������������������Ǧ����������������������������������������ٲ��������۱۳ܾ�����������������������������������������" },
    { "yang", "�������������������������������������������������" },
    { "yao", "ҪҩԼҡ��ҧ��ҫ�ս�ű����ҢңҤҥҦҨԿزسߺ������������������������" },
    { "ye", "ҲҵҳҶҺҹҰүұа����ҬҭҮҴҷҸק��������������" },
    { "yi", "һ����������ҽ��������������������������������������������ҼҾҿ��������������������������������������������������٫ڱ����ܲ����޲������߽߮���������������������������������������������������������������" },
    { "yin", "������ӡ��������������������������ط۴����ܧ���������������������" },
    { "ying", "ӦӰӲӪӢӳӭӣӤӥӧӨөӫӬӮӯӱ��۫����ݺ��������������������������" },
    { "yo", "��Ӵ�" },
    { "yong", "������ӵӿӼӹӶӷӸӺӻӽӾ��ٸ��ܭ�����������" },
    { "you", "��������������������������������������������٧ݬݯݵ��������������������������������" },
    { "yu", "����������������Ԥ����������������������εξ������������������������������������������ԡԢԣԥԦ��خع��ٶ���������������������������������������������������������������������������������" },
    { "yuan", "ԱԭԲԴԪԶԸԺԵԮ԰ԹԧԨԩԫԬԯԳԷ��ܫܾ��������������������" },
    { "yue", "��˵ԽԼ��ԾԻ��Կ����������������" },
    { "yun", "��Ա���Ⱦ�������������������۩ܿ�������������" },
    { RT_NULL, RT_NULL },
};
static const ime_dicts_t dicts_z[] =
{
    { "z", "��������������ս����֮��������ֻ������ָ" },
    { "za", "����������զ��" },
    { "zai", "��������������������" },
    { "zan", "���������������������" },
    { "zang", "�������������" },
    { "zao", "������������������������������" },
    { "ze", "���������զ�����������������" },
    { "zen", "����" },
    { "zeng", "����������������" },
    { "zha", "����ըբա����������գդեզէթ����߸��������������" },
    { "zhai", "կ����ժխի�Լ�լծ���" },
    { "zhan", "սչվռճ��հձղմյնշոպջտ�������" },
    { "zhang", "����������������������������������۵��������" },
    { "zhao", "�������г�����צ�����׳�����گ��������" },
    { "zhe", "������������������������ߡ��������������" },
    { "zhen", "������������������������������������������������������������" },
    { "zheng", "��������֤����֢��֣����������֡ں��������" },
    { "zhi", "֮����ֻ��ֱָֹ֧֯����־ֵ֪ʶְֲִֽ��ֳ֦֬����֫��ַ��ֶֺּֿ֥֭֨֩��������������ش��ۤ���������������������������������������������������������������" },
    { "zhong", "����������������������ڣ���������" },
    { "zhou", "����������������������������ݧ����������������" },
    { "zhu", "��ע��ס����������������פ��ף����������������������������٪ۥ����������������������������������" },
    { "zhua", "ץ��" },
    { "zhuai", "תҷק" },
    { "zhuan", "תר��ש׫׬׭�������" },
    { "zhuang", "װ״׳ׯײ��׮ױ����" },
    { "zhui", "׷׶׵׸׹׺�����" },
    { "zhun", "׼��׻���" },
    { "zhuo", "����׽����׾׿������������پ��ߪ��������������" },
    { "zi", "����������������֨���������������������������������������������������������" },
    { "zong", "����������������������" },
    { "zou", "������������۸����" },
    { "zu", "����������������������" },
    { "zuan", "��׬��߬����" },
    { "zui", "������Ѿ���ީ" },
    { "zun", "����ߤ����" },
    { "zuo", "������������������������������������" },
    { RT_NULL,  RT_NULL },
};

static const ime_dicts_t **dict_list[26] =
{
    dicts_a, dicts_b, dicts_c, dicts_d, dicts_e, dicts_f, dicts_g,
    dicts_h, RT_NULL, dicts_j, dicts_k, dicts_l, dicts_m, dicts_n,
    dicts_o, dicts_p, dicts_q, dicts_r, dicts_s, dicts_t,
    RT_NULL, RT_NULL, dicts_w, dicts_x, dicts_y, dicts_z
};

//���Լ������ȴ�!
static const ime_terms_t terms_a[] =
{
    { "ay", 2, "��ѽ,����" },
    RT_NULL,
};
static const ime_terms_t terms_b[] =
{
    { "bm", 2, "����" },
    RT_NULL,
};
static const ime_terms_t terms_c[] =
{
    { "cf", 2, "����" },
    { "chuf", 2, "����,����,����,����,����,����,����,����" },
    { "chufa", 2, "����,����,����,����,����" },
    { "chufan", 2, "����,����,����,����" },
    { "cfy", 3, "����ҩ" },
    { "chufy", 3, "����ҩ" },
    { "chufangy", 3, "����ҩ" },
    { "chufang", 2, "����,����,����,����" },
    { "ck", 2, "�ο�" },
    RT_NULL,
};
static const ime_terms_t terms_d[] =
{
    { "dc", 2, "����" },
    RT_NULL,
};
static const ime_terms_t terms_e[] =
{
    { "ey", 2, "����" },
    RT_NULL,
};
static const ime_terms_t terms_f[] =
{
    { "fg", 2, "����" },
    RT_NULL,
};
static const ime_terms_t terms_g[] =
{
    { "gx", 2, "����,��Ц,��Ч,����" },
    RT_NULL,
};
static const ime_terms_t terms_h[] =
{
    { "hs", 2, "��ɫ,��ˮ" },
    RT_NULL,
};
static const ime_terms_t terms_j[] =
{
    { "jd", 2, "����,��" },
    RT_NULL,
};
static const ime_terms_t terms_k[] =
{
    { "kl", 2, "����,����" },
    RT_NULL,
};
static const ime_terms_t terms_l[] =
{
    { "ll", 2, "����,����,����" },
    RT_NULL,
};
static const ime_terms_t terms_m[] =
{
    { "mb", 2, "����,Ŀ��,���" },
    RT_NULL,
};
static const ime_terms_t terms_n[] =
{
    { "nn", 2, "����,��Ů" },
    RT_NULL,
};
static const ime_terms_t terms_o[] =
{
    { "oo", 2, "ŶŶ,����" },
    RT_NULL,
};
static const ime_terms_t terms_p[] =
{
    { "pp", 2, "ƥ��,����" },
    RT_NULL,
};
static const ime_terms_t terms_q[] =
{
    { "qq", 2, "����,ǰ��" },
    RT_NULL,
};
static const ime_terms_t terms_r[] =
{
    { "rm", 2, "����,����" },
    RT_NULL,
};
static const ime_terms_t terms_s[] =
{
    { "ss", 2, "����,��ʵ" },
    RT_NULL,
};
static const ime_terms_t terms_t[] =
{
    { "td", 2, "ͨ��,̬��" },
    RT_NULL,
};
static const ime_terms_t terms_w[] =
{
    { "wm", 2, "����,����" },
    RT_NULL,
};
static const ime_terms_t terms_x[] =
{
    { "xpx", 3, "������,С����" },
    { "xw", 2, "ϣ��,��Ϊ" },
    { "xz", 2, "����,����" },
    RT_NULL,
};
static const ime_terms_t terms_y[] =
{
    { "yx", 2, "һ��,��Ϸ" },
    RT_NULL,
};
static const ime_terms_t terms_z[] =
{
    { "zhrm", 4, "�л�����,�߻���ħ"},
    { "zhrmghg", 7, "�л����񹲺͹�,"},
    { "zhrmghggg", 9, "�л����񹲺͹�����,"},
    { "zx", 2, "ִ��,��ϯ,��Щ,����,����,����,����,��ѯ,��ϸ,����,ֻ��,����,װ��,��ѧ" },
    RT_NULL,
};


static const ime_terms_t **dict_terms[26] =
{
    terms_a, terms_b, terms_c, terms_d, terms_e, terms_f, terms_g,
    terms_h, RT_NULL, terms_j, terms_k, terms_l, terms_m, terms_n,
    terms_o, terms_p, terms_q, terms_r, terms_s, terms_t,
    RT_NULL, RT_NULL, terms_w, terms_x, terms_y, terms_z
};

rt_inline int isLower(char c)
{
    return (c >= 'a' && c <= 'z');
}
rt_inline int isUpper(char c)
{
    return (c >= 'A' && c <= 'Z');
}
rt_inline int isLetter(char c)
{
    return (isLower(c) || isUpper(c));
}
rt_inline int isNumber(char c)
{
    return (c >= '0' && c <= '9');
}
rt_inline char toLower(char c)
{
    return (isUpper(c) ? (c + 32) : c);
}
rt_inline char toUpper(char c)
{
    return (isLower(c) ? (c - 32) : c);
}

static ime_dicts_t *pinyin_get_dict(char c)
{
    ime_dicts_t *pin = RT_NULL;

    if (isLower(c)) pin = dict_list[c - 'a'];
    else if (isUpper(c)) pin = dict_list[c - 'A'];

    return pin;
}

ime_terms_t *pinyin_get_terms(char *ptr)
{
    ime_terms_t *tem = RT_NULL;

    if (isLower(*ptr)) tem = dict_terms[*ptr - 'a'];
    else if (isUpper(*ptr)) tem = dict_terms[*ptr - 'A'];

    int len = rt_strlen(ptr);

    while (tem->pin && tem->ci)
    {
        if (rt_strlen(tem->pin) == len)
        {
            if (rt_strcmp(tem->pin, ptr) == 0) return tem;
        }
        tem++;
    }
    return RT_NULL;
}

//ͳ����','�ָ��Ĵ��������
rt_uint16_t terms_len(char *ci)
{
    rt_uint16_t len = 0;
    char *sc = ci;
    while (*sc)
    {
        if (*sc == ',') len++;
        sc++;
    }

    if (*(sc - 1) != ',') len++;

    return len;
}

//ȥ���ַ�����ָ�����ַ�
void string_remove_space(char *str, char c)
{
    char *s = str;
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != c) s[j++] = str[i];
    }
    s[j] = '\0';

    str = s;
}
static void pinyin_update_zhbuf(input_method_t *ime)
{
    ime_dicts_t *py = ime->dicts;
    rt_uint16_t *buf = ime->zhbuf;
    rt_uint16_t len = 0;

    ime->zhlen = 0;

    if (!py) return;

    while (py->pin && py->hz)
    {
        if (rt_strlen(py->pin) == ime->inlen)
        {
            if (rt_strcmp(py->pin, ime->inbuf) == 0)
            {
                len = rt_strlen(py->hz);
                rt_memcpy(ime->zhbuf, py->hz, len);
                ime->zhlen = len / 2;
                ime->page_numbs = (ime->zhlen + (IME_WPP - 1)) / IME_WPP;
                ime->page_index = 0;
                ime->wordcnt = 1;
                ime->type = IME_TYPE_DICTS;
                return;
            }
        }
        py++;
    }

    ime_terms_t *tem = ime->terms;
    if (tem == RT_NULL) return;

    if (ime->zhlen == 0) //��"�ֵ�"��δ�ҵ�,�ٲ���"�ʵ�"
    {
        if (rt_strlen(tem->pin) == ime->inlen)
        {
            if (rt_strcmp(tem->pin, ime->inbuf) == 0)
            {
                len = rt_strlen(tem->ci);
                rt_memcpy(ime->zhbuf, tem->ci, len);
                string_remove_space(ime->zhbuf, ' '); //ȥ���ո�
                ime->zhlen = terms_len(tem->ci);
                ime->wordcnt = tem->cnt;
                ime->cnt_per_page = 12 / ime->wordcnt;
                ime->page_numbs = (ime->zhlen + (ime->cnt_per_page - 1)) / ime->cnt_per_page;
                ime->type = IME_TYPE_TERMS;
            }
        }
    }
}

void pinyin_generate_page(input_method_t *ime)
{
#define S ime->s

    if (ime->zhlen == 0) return;
    rt_memset(S, 0, sizeof(S));

    if (ime->type == IME_TYPE_DICTS) //�ֵ�
    {
        rt_uint16_t *p = ime->zhbuf;

        if (((ime->page_index + 1) * IME_WPP) < ime->zhlen)
            ime->cnt_cur_page = IME_WPP;
        else
            ime->cnt_cur_page = ime->zhlen - ime->page_index * IME_WPP;
        if (ime->cnt_cur_page == 0) return;
        p += ime->page_index * IME_WPP;
        for (int i = 0; i < ime->cnt_cur_page; i++) 
        {
            rt_memcpy(S[i], p + i, 2);
            sprintf(ime->wordstr, "%s%d.%s ", ime->wordstr, i+1, S[i]);
        }
    }
    else //if(ime->type==IME_TYPE_TERMS) �ʵ�
    {
        char *p = ime->zhbuf;
        rt_uint16_t start = 0, index = 0;

        if (((ime->page_index + 1) * ime->cnt_per_page) < ime->zhlen)
            ime->cnt_cur_page = ime->cnt_per_page;
        else
            ime->cnt_cur_page = ime->zhlen - ime->page_index * ime->cnt_per_page;
        if (ime->cnt_cur_page == 0) return;
        start = ime->page_index * ime->cnt_per_page;
        while (*p)
        {
            if (index == start) break;
            if (*p == ',') index++;
            p++;
        }

        for (int i = 0; i < ime->cnt_cur_page; i++)
        {
            rt_memcpy(S[i], p, ime->wordcnt * 2);
            sprintf(ime->wordstr, "%s%d.%s ", ime->wordstr, i+1, S[i]);
            while (*p)
            {
                if (*p == ',' || *p == ' ')
                {
                    p++;
                    break;
                }
                p++;
            }
        }
    }
}

void pinyin_getout_zhstring(input_method_t *ime, char *zhstr, int index)
{
    if (index < 0  || index >= ime->cnt_cur_page) return;

    if (ime->type == IME_TYPE_DICTS)
    {
        rt_uint16_t *p = ime->zhbuf;
        p += ime->page_index * IME_WPP;

        if (index > ime->cnt_cur_page) return;
        rt_memcpy(zhstr, p + index, 2);
    }
    else
    {
        char *p = ime->zhbuf;
        rt_uint16_t start = 0, k = 0;

        if (index > ime->cnt_cur_page) return;
        rt_memcpy(zhstr, ime->s[index], ime->wordcnt * 2);
    }
}

void pinyin_getin_letter(input_method_t *ime, char c)
{
    if(ime->inlen >= 9) return; //�����������9��
    ime->inbuf[ime->inlen++] = toLower(c);
    if (ime->inlen == 1) //search dict list
    {
        ime->dicts = pinyin_get_dict(c);
    }
    ime->terms = pinyin_get_terms(ime->inbuf);
    rt_memset(ime->zhbuf, 0, IME_ZHBUF_MAX);
    pinyin_update_zhbuf(ime);

    if(ime->zhlen >= IME_ZHBUF_MAX) //�ж��ֵ��С�Ƿ�Ϸ�
        rt_kprintf("The dictionary cache set is too small!\n");

    rt_memset(ime->wordstr, 0, IME_WORDSTR_SZ);
    pinyin_generate_page(ime);
}

void pinyin_backspace(input_method_t *ime)
{
    if (ime->inlen > 0)
    {
        ime->inlen--;
        ime->inbuf[ime->inlen] = 0;
        rt_memset(ime->zhbuf, 0, IME_ZHBUF_MAX);

        if (ime->inlen == 0)
        {
            ime->dicts = RT_NULL;
            ime->terms = RT_NULL;
        }
        else
        {
            ime->terms = pinyin_get_terms(ime->inbuf);
        }
        pinyin_update_zhbuf(ime);
        ime->page_numbs = (ime->zhlen + 8) / 9;
        rt_memset(ime->wordstr, 0, IME_WORDSTR_SZ);
        pinyin_generate_page(ime);
    }
}

void pinyin_page_add(input_method_t *ime)
{
    if (ime->page_numbs > 1)
    {
        if (ime->page_index > 0)
            ime->page_index -= 1;
        rt_memset(ime->wordstr, 0, IME_WORDSTR_SZ);
        pinyin_generate_page(ime);
    }
}

void pinyin_page_sub(input_method_t *ime)
{
    if (ime->page_numbs > 1)
    {
        if ((ime->page_index + 1) < ime->page_numbs)
            ime->page_index += 1;
        rt_memset(ime->wordstr, 0, IME_WORDSTR_SZ);
        pinyin_generate_page(ime);
    }
}

void pinyin_init(input_method_t *ime)
{
    rt_memset(ime, 0, sizeof(input_method_t));
}
