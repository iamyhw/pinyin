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

#define DICTS(x, s) {x, s, sizeof(s)-1}

//���ֵ�/�ʵ䰴������ĸ����,�ɼӿ�����ٶ�
static const ime_dicts_t dicts_a[] = {
    DICTS("a", "����"),
    DICTS("ai", "��������������������������"),
    DICTS("an", "������������������"),
    DICTS("ang", "������"),
    DICTS("ao", "�������������°İ�"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_b[] = {
    DICTS("b", "��������ѱ�Ȳ���ٱ������������߰˰첼"),
    DICTS("ba", "�˰ͰȰǰɰṴ̋ưʰΰϰѰаӰְհ�"),
    DICTS("bai", "�װٰ۰ذڰܰݰ�"),
    DICTS("ban", "�����߰����������"),
    DICTS("bang", "������������������"),
    DICTS("bao", "������������������������������������"),
    DICTS("bei", "������������������������������"),
    DICTS("ben", "����������"),
    DICTS("beng", "�����±ñű�"),
    DICTS("bi", "�ƱǱȱ˱ʱɱұرϱձӱѱݱбֱԱͱױ̱αڱܱ�"),
    DICTS("bian", "�߱�ޱ���������"),
    DICTS("biao", "�����"),
    DICTS("bie", "�����"),
    DICTS("bin", "����������"),
    DICTS("bing", "������������������"),
    DICTS("bo", "����������������������������������������"),
    DICTS("bu", "��������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_c[] = {
    DICTS("c", "���ɳ����Ӵ˳����������ɲ㳧�Ŵγ�����"),
    DICTS("ca", "��"),
    DICTS("cai", "�²ŲĲƲòɲʲǲȲ˲�"),
    DICTS("can", "�βͲвϲѲҲ�"),
    DICTS("cang", "�ֲײԲղ�"),
    DICTS("cao", "�ٲڲܲ۲�"),
    DICTS("ce", "���޲��"),
    DICTS("ceng", "�����"),
    DICTS("cha", "������������ɲ"),
    DICTS("chai", "����"),
    DICTS("chan", "�������������������"),
    DICTS("chang", "������������������������"),
    DICTS("chao", "��������������������"),
    DICTS("che", "������������"),
    DICTS("chen", "�������������³��ĳ�"),
    DICTS("cheng", "�Ƴųɳʳгϳǳ˳ͳ̳γȳѳҳ�"),
    DICTS("chi", "�Գճڳس۳ٳֳ߳޳ݳܳ����"),
    DICTS("chong", "������"),
    DICTS("chou", "�������������"),
    DICTS("chu", "����������������������������������"),
    DICTS("chuai", "��"),
    DICTS("chuan", "��������������"),
    DICTS("chuang", "����������"),
    DICTS("chui", "����������"),
    DICTS("chun", "��������������"),
    DICTS("chuo", "��"),
    DICTS("ci", "�ôʴĴɴȴǴŴƴ˴δ̴�"),
    DICTS("cong", "�ѴӴҴдϴ�"),
    DICTS("cou", "��"),
    DICTS("cu", "�ִٴ״�"),
    DICTS("cuan", "�ڴܴ�"),
    DICTS("cui", "�޴ߴݴ�����"),
    DICTS("cun", "����"),
    DICTS("cuo", "�������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_d[] = {
    DICTS("d", "�Ĵ�ض����Զȶ�絳�ö��ȶ����Ӷ������"),
    DICTS("dai", "������������������������"),
    DICTS("dan", "������������������������������"),
    DICTS("dang", "����������"),
    DICTS("dao", "������������������������"),
    DICTS("de", "�õµ�"),
    DICTS("deng", "�Ƶǵŵȵ˵ʵ�"),
    DICTS("di", "�͵̵εҵϵеӵѵյ׵ֵصܵ۵ݵڵ޵�"),
    DICTS("dian", "���ߵ�������������"),
    DICTS("diao", "�����������"),
    DICTS("die", "��������������"),
    DICTS("ding", "������������������"),
    DICTS("diu", "��"),
    DICTS("dong", "��������������������"),
    DICTS("dou", "����������������"),
    DICTS("du", "�����������¶ĶöʶŶǶȶɶ�"),
    DICTS("duan", "�˶̶ζ϶ж�"),
    DICTS("dui", "�ѶӶԶ�"),
    DICTS("dun", "�ֶضն׶ܶ۶ٶ�"),
    DICTS("duo", "��߶�޶��������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_e[] = {
    DICTS("e", "����������������"),
    DICTS("en", "��"),
    DICTS("er", "����������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_f[] = {
    DICTS("f", "�ַ��������Ÿ�����Ƿ��ʸ��۸��򸺷⸻��"),
    DICTS("fa", "����������������"),
    DICTS("fan", "����������������������������������"),
    DICTS("fang", "���������������·÷ķ�"),
    DICTS("fei", "�ɷǷȷƷʷ˷̷ͷϷзη�"),
    DICTS("fen", "�ַԷ׷ҷշӷطڷٷ۷ݷܷ޷߷�"),
    DICTS("feng", "����������������"),
    DICTS("fo", "��"),
    DICTS("fou", "��"),
    DICTS("fu", "������󸥷�����������������������������������������������������������������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_g[] = {
    DICTS("g", "���������߸ɹظ��﹫�����Ĺܹ����񹲸�"),
    DICTS("ga", "�¸�"),
    DICTS("gai", "�øĸƸǸȸ�"),
    DICTS("gan", "�ɸʸ˸θ̸͸ѸϸҸи�"),
    DICTS("gang", "�Ըոڸٸظ׸ָ۸�"),
    DICTS("gao", "�޸�߸�ݸ�����"),
    DICTS("ge", "����������������������"),
    DICTS("gei", "��"),
    DICTS("gen", "����"),
    DICTS("geng", "��������������"),
    DICTS("gong", "������������������������������"),
    DICTS("gou", "������������������"),
    DICTS("gu", "�����ù¹��������ŹȹɹǹƹĹ̹ʹ˹�"),
    DICTS("gua", "�Ϲιйѹҹ�"),
    DICTS("guai", "�Թչ�"),
    DICTS("guan", "�ع۹ٹڹ׹ݹܹ�߹��"),
    DICTS("guang", "����"),
    DICTS("gui", "������������������"),
    DICTS("gun", "������"),
    DICTS("guo", "������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_h[] = {
    DICTS("h", "�ͻ�󻯺úϻ���ܻغź����򺣻����ƺ�"),
    DICTS("ha", "���"),
    DICTS("hai", "��������������"),
    DICTS("han", "��������������������������������������"),
    DICTS("hang", "������"),
    DICTS("hao", "���������úºźƺ�"),
    DICTS("he", "�ǺȺ̺ϺκͺӺҺ˺ɺԺкʺغֺպ�"),
    DICTS("hei", "�ں�"),
    DICTS("hen", "�ۺܺݺ�"),
    DICTS("heng", "��ߺ���"),
    DICTS("hong", "����������"),
    DICTS("hou", "��������"),
    DICTS("hu", "������������������������������������"),
    DICTS("hua", "������������������"),
    DICTS("huai", "����������"),
    DICTS("huan", "�����������û»�������������"),
    DICTS("huang", "�ĻŻʻ˻ƻ̻ͻȻǻɻлλѻ�"),
    DICTS("hui", "�һֻӻԻջػ׻ڻܻ������߻޻�ݻٻ�"),
    DICTS("hun", "�������"),
    DICTS("huo", "�������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_j[] = {
    DICTS("j", "���ͽ��Ӿ��ҽ�׼������ϻ����ӽ̼��ż�"),
    DICTS("ji", "���������������������������������������������������������������������ƼǼ��ͼ˼ɼ��ʼ����ȼü̼żļ¼�������"),
    DICTS("jia", "�ӼмѼϼҼμԼռ׼ּؼۼݼܼټ޼�Ю"),
    DICTS("jian", "����߼����������������������������������������������������"),
    DICTS("jiang", "��������������������������"),
    DICTS("jiao", "���������������������ǽƽʽȽýŽ½��˽ɽнνϽ̽ѽ;���"),
    DICTS("jie", "�׽Խӽսҽֽڽٽܽ��ݽ޽ؽ߽����������"),
    DICTS("jin", "���������������������������������"),
    DICTS("jing", "��������������������������������������������������"),
    DICTS("jiong", "����"),
    DICTS("jiu", "�������žþľ��¾ƾɾʾ̾ξǾȾ;�"),
    DICTS("ju", "�ӾоѾԾҾϾֽ۾վ׾ھپؾ�޾ܾ߾����ݾ��۾�"),
    DICTS("juan", "��������"),
    DICTS("jue", "��������������"),
    DICTS("jun", "����������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_k[] = {
    DICTS("k", "�ɿ����˿׿ƿڿտ�쿼�̿���������󿹿�"),
    DICTS("ka", "������"),
    DICTS("kai", "����������"),
    DICTS("kan", "��������������"),
    DICTS("kang", "��������������"),
    DICTS("kao", "��������"),
    DICTS("ke", "�����¿ƿÿſĿǿȿɿʿ˿̿Ϳ�"),
    DICTS("ken", "�Ͽѿҿ�"),
    DICTS("keng", "�Կ�"),
    DICTS("kong", "�տ׿ֿ�"),
    DICTS("kou", "�ٿڿۿ�"),
    DICTS("ku", "�ݿ޿߿����"),
    DICTS("kua", "������"),
    DICTS("kuai", "�����"),
    DICTS("kuan", "���"),
    DICTS("kuang", "�����������"),
    DICTS("kui", "����������������������"),
    DICTS("kun", "��������"),
    DICTS("kuo", "��������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_l[] = {
    DICTS("l", "��������·������������������������������"),
    DICTS("la", "��������������"),
    DICTS("lai", "������"),
    DICTS("lan", "������������������������������"),
    DICTS("lang", "��������������"),
    DICTS("lao", "������������������"),
    DICTS("le", "������"),
    DICTS("lei", "����������������������"),
    DICTS("leng", "������"),
    DICTS("li", "��������������������������������������������������������������������"),
    DICTS("lian", "����������������������������"),
    DICTS("liang", "������������������������"),
    DICTS("liao", "������������������������"),
    DICTS("lie", "����������"),
    DICTS("lin", "������������������������"),
    DICTS("ling", "����������������������������"),
    DICTS("liu", "����������������������"),
    DICTS("long", "��������¡��¤¢£"),
    DICTS("lou", "¦¥§¨ª©"),
    DICTS("lu", "¶¬®«¯­±²°³½¼¸¹»µ·¾º´"),
    DICTS("luan", "������������"),
    DICTS("lue", "����"),
    DICTS("lun", "��������������"),
    DICTS("luo", "������������������������"),
    DICTS("lv", "��¿������������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_m[] = {
    DICTS("m", "��������ëû������ôÿ����ĥ��������ĶĿ߼"),
    DICTS("ma", "������������������"),
    DICTS("mai", "������������"),
    DICTS("man", "����������á������"),
    DICTS("mang", "æâäãçå"),
    DICTS("mao", "èëìéêîíïðóñò"),
    DICTS("me", "ô"),
    DICTS("mei", "ûöõü÷ýúøùÿ��þ��������"),
    DICTS("men", "������"),
    DICTS("meng", "����������������"),
    DICTS("mi", "����������������������������"),
    DICTS("mian", "������������������"),
    DICTS("miao", "����������������"),
    DICTS("mie", "����"),
    DICTS("min", "������������"),
    DICTS("ming", "������������"),
    DICTS("miu", "��"),
    DICTS("mo", "����ġģĤĦĥĢħĨĩĭİĪįĮīĬ"),
    DICTS("mou", "Ĳıĳ"),
    DICTS("mu", "ĸĶĵķĴľĿ��ļĹĻ��Ľĺ��"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_n[] = {
    DICTS("n", "��������ũ��������Ů��������ţ����ճ������"),
    DICTS("na", "��������������"),
    DICTS("nai", "����������"),
    DICTS("nan", "������"),
    DICTS("nang", "��"),
    DICTS("nao", "����������"),
    DICTS("ne", "��"),
    DICTS("nei", "����"),
    DICTS("nen", "��"),
    DICTS("neng", "��"),
    DICTS("ni", "����������������������"),
    DICTS("nian", "��������������"),
    DICTS("niang", "����"),
    DICTS("niao", "����"),
    DICTS("nie", "��������������"),
    DICTS("nin", "��"),
    DICTS("ning", "��š������Ţ"),
    DICTS("niu", "ţŤŦť"),
    DICTS("nong", "ũŨŧŪ"),
    DICTS("nu", "ūŬŭ"),
    DICTS("nuan", "ů"),
    DICTS("nue", "űŰ"),
    DICTS("nuo", "ŲŵųŴ"),
    DICTS("nv", "Ů"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_o[] = {
    DICTS("o", "Ŷ"),
    DICTS("ou", "ŷŹŸŻżźŽ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_p[] = {
    DICTS("p", "��ƽ����Ƭ������ƷƤ����ƫ��������ƶ����"),
    DICTS("pa", "ſž����������"),
    DICTS("pai", "������������"),
    DICTS("pan", "����������������"),
    DICTS("pang", "����������"),
    DICTS("pao", "��������������"),
    DICTS("pei", "������������������"),
    DICTS("pen", "����"),
    DICTS("peng", "����������������������������"),
    DICTS("pi", "��������������Ƥ��ƣơ��ƢƥƦƨƧƩ"),
    DICTS("pian", "Ƭƫƪƭ"),
    DICTS("piao", "ƯƮưƱ"),
    DICTS("pie", "ƲƳ"),
    DICTS("pin", "ƴƶƵƷƸ"),
    DICTS("ping", "ƹƽ��ƾƺƻ��ƿƼ"),
    DICTS("po", "����������������"),
    DICTS("pou", "��"),
    DICTS("pu", "������������������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_q[] = {
    DICTS("q", "��ǰ��ȥ��ȫ��Ⱥ����ǿ��ȡ������ȷȨ����"),
    DICTS("qi", "������������������������������������������������������������������������"),
    DICTS("qia", "��ǡǢ"),
    DICTS("qian", "ǧǪǤǨǥǣǦǫǩǰǮǯǬǱǭǳǲǴǷǵǶǸ"),
    DICTS("qiang", "ǺǼǹǻǿǽǾ��"),
    DICTS("qiao", "������������������������������"),
    DICTS("qie", "����������"),
    DICTS("qin", "����������������������"),
    DICTS("qing", "��������������������������"),
    DICTS("qiong", "����"),
    DICTS("qiu", "����������������"),
    DICTS("qu", "����������������ȡȢȣȥȤ"),
    DICTS("quan", "ȦȫȨȪȭȬȩȧȮȰȯ"),
    DICTS("que", "Ȳȱȳȴȸȷȵȶ"),
    DICTS("qun", "ȹȺ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_r[] = {
    DICTS("r", "��������������Ȼ��������ȼȾ������������"),
    DICTS("ran", "ȻȼȽȾ"),
    DICTS("rang", "ȿ��������"),
    DICTS("rao", "������"),
    DICTS("re", "����"),
    DICTS("ren", "��������������������"),
    DICTS("reng", "����"),
    DICTS("ri", "��"),
    DICTS("rong", "��������������������"),
    DICTS("rou", "������"),
    DICTS("ru", "��������������������"),
    DICTS("ruan", "����"),
    DICTS("rui", "������"),
    DICTS("run", "����"),
    DICTS("ruo", "����"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_s[] = {
    DICTS("s", "����ʱ��˵����ˮ����ʮʹ������ʵ��ʽɽ��"),
    DICTS("sa", "������"),
    DICTS("sai", "��������"),
    DICTS("san", "����ɡɢ"),
    DICTS("sang", "ɣɤɥ"),
    DICTS("sao", "ɦɧɨɩ"),
    DICTS("se", "ɫɬɪ"),
    DICTS("sen", "ɭ"),
    DICTS("seng", "ɮ"),
    DICTS("sha", "ɱɳɴɰɯɵɶɷ��"),
    DICTS("shai", "ɸɹ"),
    DICTS("shan", "ɽɾɼ��ɺɿ������ɻ������������դ"),
    DICTS("shang", "����������������"),
    DICTS("shao", "����������������������"),
    DICTS("she", "������������������������"),
    DICTS("shen", "��������������������������������ʲ"),
    DICTS("sheng", "��������ʤ����ʡʥʢʣ"),
    DICTS("shi", "��ʬʧʦʭʫʩʨʪʮʯʱʶʵʰʴʳʷʸʹʼʻʺʿ��������ʾʽ������������������������������������"),
    DICTS("shou", "��������������������"),
    DICTS("shu", "������������������������������������������������������ˡ����������"),
    DICTS("shua", "ˢˣ"),
    DICTS("shuai", "˥ˤ˦˧"),
    DICTS("shuan", "˩˨"),
    DICTS("shuang", "˫˪ˬ"),
    DICTS("shui", "˭ˮ˰˯"),
    DICTS("shun", "˱˳˴˲"),
    DICTS("shuo", "˵˸˷˶"),
    DICTS("si", "˿˾˽˼˹˻˺����������������"),
    DICTS("song", "����������������"),
    DICTS("sou", "��������"),
    DICTS("su", "����������������������"),
    DICTS("suan", "������"),
    DICTS("sui", "����������������������"),
    DICTS("sun", "������"),
    DICTS("suo", "����������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_t[] = {
    DICTS("t", "��ͬ��������ͼ��ͷͨ��������ͳ̨��̫����"),
    DICTS("ta", "����������̡̢̤̣"),
    DICTS("tai", "̨̧̥̦̫̭̬̩̪"),
    DICTS("tan", "̸̵̷̶̴̮̰̯̲̱̳̹̻̺̼̾̿̽"),
    DICTS("tang", "��������������������������"),
    DICTS("tao", "����������������������"),
    DICTS("te", "��"),
    DICTS("teng", "��������"),
    DICTS("ti", "������������������������������"),
    DICTS("tian", "����������������"),
    DICTS("tiao", "������������"),
    DICTS("tie", "������"),
    DICTS("ting", "��͡����ͤͥͣͦͧ͢"),
    DICTS("tong", "ͨͬͮͩͭͯͪͫͳͱͰͲʹ"),
    DICTS("tou", "͵ͷͶ͸"),
    DICTS("tu", "͹ͺͻͼͽͿ;��������"),
    DICTS("tuan", "����"),
    DICTS("tui", "������������"),
    DICTS("tun", "��������"),
    DICTS("tuo", "����������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_w[] = {
    DICTS("w", "Ϊ����������λ��ί����������������Χ����"),
    DICTS("wa", "��������������"),
    DICTS("wai", "����"),
    DICTS("wan", "����������������������������������"),
    DICTS("wang", "��������������������"),
    DICTS("wei", "Σ��΢ΡΪΤΧΥΦΨΩάΫΰαβγέίή��δλζηθξνιμεοκ"),
    DICTS("wen", "��������������������"),
    DICTS("weng", "������"),
    DICTS("wo", "������������������"),
    DICTS("wu", "����������������������������������������������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_x[] = {
    DICTS("x", "ѧ����С������Щ��������ϵϯ������������"),
    DICTS("xi", "Ϧϫ����ϣ������Ϣ��Ϥϧϩ����ϬϡϪ��Ϩ����ϥϰϯϮϱϭϴϲϷϵϸ϶"),
    DICTS("xia", "ϺϹϻ��Ͽ��ϾϽϼ������"),
    DICTS("xian", "ϳ����������������������������������������������������"),
    DICTS("xiang", "����������������������������������������"),
    DICTS("xiao", "����������������С��ТФ��ЧУЦХ"),
    DICTS("xie", "ЩШЪЫЭавбгЯЬдйкжмелиз"),
    DICTS("xin", "����о����п��н����"),
    DICTS("xing", "����������������������������"),
    DICTS("xiong", "��������������"),
    DICTS("xiu", "��������������������"),
    DICTS("xu", "��������������������������������������"),
    DICTS("xuan", "������������ѡѢѤѣ"),
    DICTS("xue", "��ѥѦѨѧѩѪ"),
    DICTS("xun", "ѫѬѰѲѮѱѯѭѵѶѴѸѷѳ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_y[] = {
    DICTS("y", "һ����Ҫ����Ҳ��������ѹԱ��������ԭ����"),
    DICTS("ya", "ѾѹѽѺѻѼ��ѿ����������������"),
    DICTS("yan", "������������������������������������������������������������������"),
    DICTS("yang", "����������������������������������"),
    DICTS("yao", "��������ҢҦҤҥҡң��ҧҨҩҪҫԿ"),
    DICTS("ye", "ҬҭүҮҲұҰҵҶҷҳҹҴҺҸ"),
    DICTS("yi", "һ����ҽ��ҿҼҾ������������������������������������������������������������������������������������������"),
    DICTS("yin", "������������������������������ӡ"),
    DICTS("ying", "ӦӢӤӧӣӥӭӯӫӨөӪӬӮӱӰӳӲ"),
    DICTS("yo", "Ӵ"),
    DICTS("yong", "ӶӵӸӹӺӷ��ӽӾ��ӿ��Ӽӻ��"),
    DICTS("you", "����������������������������������������"),
    DICTS("yu", "����������������������������������������������������Ԧ����������ԡԤ������Ԣ��ԣ������ԥ"),
    DICTS("yuan", "ԩԧԨԪԱ԰ԫԭԲԬԮԵԴԳԯԶԷԹԺԸ"),
    DICTS("yue", "ԻԼ��������Ծ��Խ"),
    DICTS("yun", "������������������������"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_z[] = {
    DICTS("z", "��������������ս����֮��������ֻ������ָ"),
    DICTS("za", "������զ"),
    DICTS("zai", "����������������"),
    DICTS("zan", "��������"),
    DICTS("zang", "������"),
    DICTS("zao", "����������������������������"),
    DICTS("ze", "��������"),
    DICTS("zei", "��"),
    DICTS("zen", "��"),
    DICTS("zeng", "������"),
    DICTS("zha", "����������բագէթըե��"),
    DICTS("zhai", "իժլ��խծկ"),
    DICTS("zhan", "մձճղհնչյոշռսջվ��տպ"),
    DICTS("zhang", "��������������������������������"),
    DICTS("zhao", "��������������������צ"),
    DICTS("zhe", "����������������������"),
    DICTS("zhen", "��������������������������������֡"),
    DICTS("zheng", "��������������������֤֣��֢"),
    DICTS("zhi", "ְֱֲֳִֵֶַָֹֺֻּֽ֧֥֦֪֭֮֨֯֫֬֩��־������������ֿ������������������"),
    DICTS("zhong", "����������������������"),
    DICTS("zhou", "����������������������������"),
    DICTS("zhu", "������������������������������ס��ע��פ��ף��������"),
    DICTS("zhua", "ץ"),
    DICTS("zhuai", "ק"),
    DICTS("zhuan", "רשת׫׭"),
    DICTS("zhuang", "ױׯ׮װ׳״��ײ"),
    DICTS("zhui", "׷׵׶׹׺׸"),
    DICTS("zhun", "׻׼"),
    DICTS("zhuo", "׿׾׽��������������"),
    DICTS("zi", "����������������������������"),
    DICTS("zong", "��������������"),
    DICTS("zou", "��������"),
    DICTS("zu", "����������������"),
    DICTS("zuan", "׬����"),
    DICTS("zui", "��������"),
    DICTS("zun", "����"),
    DICTS("zuo", "��������������"),
    { NULL,  NULL },
};

static const ime_dicts_t **dict_list[26] =
{
    dicts_a, dicts_b, dicts_c, dicts_d, dicts_e, dicts_f, dicts_g, 
    dicts_h, RT_NULL, dicts_j, dicts_k, dicts_l, dicts_m, dicts_n,
    dicts_o, dicts_p, dicts_q, dicts_r, dicts_s, dicts_t,
    RT_NULL, RT_NULL, dicts_w, dicts_x, dicts_y, dicts_z
};

static const char **dicts_second[26] =
{
    "ino","aeiou","aehiou","aeiou","inr","aeou","aeou","aeou",NULL,"iu","aeou","aeiouv","aeiou",
    "aeiouv","u","aeiou","iu","aeiou","aehiou","aeiou",NULL,NULL,"aeou","iu","aeiou","aehiou"
};

#define TERMS(x, n, s) { x, n, s, (sizeof(s)+1)/(n*2+1) }

//���Լ�����ȴ�!
static const ime_terms_t terms_a[] =
{
    TERMS("ay", 2, "��ѽ,����,��ҹ,����,����,����,��ѽ"),
    RT_NULL,
};
static const ime_terms_t terms_b[] =
{
    TERMS("bm", 2, "����"),
    RT_NULL,
};
static const ime_terms_t terms_c[] =
{
    TERMS("ces", 2, "����,����,����,����,��ʿ"),
    TERMS("ceshi", 2, "����,��ʿ,����"),
    TERMS("cf", 2, "����"),
    TERMS("chuf", 2, "����,����,����,����,����,����,����,����"),
    TERMS("chufa", 2, "����,����,����,����,����"),
    TERMS("chufan", 2, "����,����,����,����"),
    TERMS("cfy", 3, "����ҩ"),
    TERMS("chufy", 3, "����ҩ"),
    TERMS("chufangy", 3, "����ҩ"),
    TERMS("chufang", 2, "����,����,����,����"),
    TERMS("ck", 2, "�ο�"),
    RT_NULL,
};
static const ime_terms_t terms_d[] =
{
    TERMS("dc", 2, "����"),
    RT_NULL,
};
static const ime_terms_t terms_e[] =
{
    TERMS("ey", 2, "����"),
    RT_NULL,
};
static const ime_terms_t terms_f[] =
{
    TERMS("fg", 2, "����"),
    RT_NULL,
};
static const ime_terms_t terms_g[] =
{
    TERMS("gx", 2, "����,��Ц,��Ч,����"),
    RT_NULL,
};
static const ime_terms_t terms_h[] =
{
    TERMS("hs", 2, "��ɫ,��ˮ"),
    RT_NULL,
};
static const ime_terms_t terms_j[] =
{
    TERMS("jd", 2, "����,��"),
    RT_NULL,
};
static const ime_terms_t terms_k[] =
{
    TERMS("kl", 2, "����,����"),
    RT_NULL,
};
static const ime_terms_t terms_l[] =
{
    TERMS("ll", 2, "����,����,����"),
    RT_NULL,
};
static const ime_terms_t terms_m[] =
{
    TERMS("mb", 2, "����,Ŀ��,���"),
    RT_NULL,
};
static const ime_terms_t terms_n[] =
{
    TERMS("nn", 2, "����,��Ů"),
    RT_NULL,
};
static const ime_terms_t terms_o[] =
{
    TERMS("oo", 2, "ŶŶ,����"),
    RT_NULL,
};
static const ime_terms_t terms_p[] =
{
    TERMS("pp", 2, "ƥ��,����"),
    RT_NULL,
};
static const ime_terms_t terms_q[] =
{
    TERMS("qq", 2, "����,ǰ��"),
    RT_NULL,
};
static const ime_terms_t terms_r[] =
{
    TERMS("rm", 2, "����,����"),
    RT_NULL,
};
static const ime_terms_t terms_s[] =
{
    TERMS("ss", 2, "����,��ʵ"),
    RT_NULL,
};
static const ime_terms_t terms_t[] =
{
    TERMS("td", 2, "ͨ��,̬��"),
    RT_NULL,
};
static const ime_terms_t terms_w[] =
{
    TERMS("wm", 2, "����,����"),
    RT_NULL,
};
static const ime_terms_t terms_x[] =
{
    TERMS("xw", 2, "ϣ��,��Ϊ"),
    TERMS("xz", 2, "����,����"),
    RT_NULL,
};
static const ime_terms_t terms_y[] =
{
    TERMS("yx", 2, "һ��,��Ϸ"),
    RT_NULL,
};
static const ime_terms_t terms_z[] =
{
    TERMS("zhrm", 4, "�л�����,�߻���ħ"),
    TERMS("zhrmghg", 7, "�л����񹲺͹�,"),
    TERMS("zhrmghggg", 9, "�л����񹲺͹�����,"),
    TERMS("zd", 2, "�ֵ�,�ж�,�ҵ�,���,�Զ�"),
    TERMS("zx", 2, "ִ��,��ϯ,��Щ,����,����,����,����,��ѯ,��ϸ,����,ֻ��,����,װ��,��ѧ"),
    RT_NULL,
};

static const ime_terms_t **dict_terms[26] =
{
    terms_a, terms_b, terms_c, terms_d, terms_e, terms_f, terms_g,
    terms_h, RT_NULL, terms_j, terms_k, terms_l, terms_m, terms_n,
    terms_o, terms_p, terms_q, terms_r, terms_s, terms_t,
    RT_NULL, RT_NULL, terms_w, terms_x, terms_y, terms_z
};

rt_inline int isLower(char c) { return (c >= 'a' && c <= 'z'); }
rt_inline int isUpper(char c) { return (c >= 'A' && c <= 'Z'); }
rt_inline int isLetter(char c) { return (isLower(c) || isUpper(c)); }
rt_inline int isNumber(char c) { return (c >= '0'&&c <= '9'); }
rt_inline char toLower(char c) { return (isUpper(c) ? (c + 32) : c); }
rt_inline char toUpper(char c) { return (isLower(c) ? (c - 32) : c); }

static ime_dicts_t* pinyin_get_dict(char c)
{
    ime_dicts_t *pin = RT_NULL;

    if (isLower(c)) pin = dict_list[c - 'a'];
    else if (isUpper(c)) pin = dict_list[c - 'A'];

    return pin;
}

static ime_terms_t* pinyin_get_terms(char *ptr)
{
    ime_terms_t *tem = RT_NULL;

    if (isLower(*ptr)) tem = dict_terms[*ptr - 'a'];
    else if (isUpper(*ptr)) tem = dict_terms[*ptr - 'A'];

    if (tem == RT_NULL) return RT_NULL;
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
static rt_uint16_t terms_len(char *ci)
{
    rt_uint16_t len = 0;
    char *sc = ci;
    while (*sc) {
        if (*sc == ',') len++;
        sc++;
    }

    if (*(sc - 1) != ',') len++;

    return len;
}

//ȥ���ַ�����ָ�����ַ�
static void string_remove_space(char *str, char c)
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

static char* builtin_strchr(char *str, char c)
{
    while(*str && *str != c) str++;
    return (*str==c)?*str:NULL;
}

static void pinyin_update_zhbuf(ime_pinyin_t *ime)
{
    ime_dicts_t *py = ime->dicts;
    ime_terms_t *tem;
    rt_uint16_t len = 0;
    int match_count;

    ime->zhlen = 0;

    if (!py) return;

    if (ime->inlen >= 2)
    {   //�޳���Чƴ��,ֻ�ж�ǰ������ĸ,�ٶ����ȫ����һ���Ч�ʲ����
        if (!builtin_strchr(dicts_second[ime->inbuf[0] - 'a'], ime->inbuf[1]))
            goto findterms;
    }

    while (py->pin && py->hz)
    {
        if (rt_strlen(py->pin) == ime->inlen)
        {
            if (rt_strcmp(py->pin, ime->inbuf) == 0)
            {
                ime->zhptr = py->hz;
                ime->zhlen = py->len / 2;
                ime->wordcnt = 1;
                ime->page_numbs = (ime->zhlen + (IME_WPP - 1)) / IME_WPP;
                ime->page_index = 0;
                ime->type = IME_TYPE_DICTS;
                return;
            }
        }
        py++;
    }

findterms:
    tem = ime->terms;
    if (tem == RT_NULL) goto carefully_search;

    if (ime->zhlen == 0) //��"�ֵ�"��δ�ҵ�,�ٲ���"�ʵ�"
    {
        if (rt_strlen(tem->pin) == ime->inlen)
        {
            if (rt_strcmp(tem->pin, ime->inbuf) == 0)
            {
                ime->zhptr = tem->ci;
                ime->zhlen = tem->len;
                ime->wordcnt = tem->cnt;
                ime->cnt_per_page = 12 / ime->wordcnt;
                ime->page_numbs = (ime->zhlen + (ime->cnt_per_page - 1)) / ime->cnt_per_page;
                ime->type = IME_TYPE_TERMS;
                return;
            }
        }
    }

carefully_search:
    //����Ҳû���ҵ���ȫƥ��Ĵʻ�,��ô�������������pinyin���Ƿ�������ƴ��,�����,ʹ���ֿ�
    //�����������cesh,û������,��ʱû����ȫƥ���cesh�ֿ�,Ҳû�ж�Ӧ��cesh�ʿ�,����Ϊ�Ҳ������,
    //��ʱ��ʾce���ֿ�ȽϺ���,������Ч�ʻ�ܵ�,��һһ����ƥ������ƴ��!
    match_count = ime->inlen - 1;//��"���"ƥ��!
    py = ime->dicts;
    while (match_count >= 1)
    {   
        char tmp[20];
        rt_memcpy(tmp, ime->inbuf, match_count), tmp[match_count] = '\0';
        while (py->pin && py->hz)
        {
            if (rt_strcmp(py->pin, tmp) == 0)
            {
                ime->zhptr = py->hz;
                ime->zhlen = py->len / 2;
                ime->wordcnt = 1;
                ime->page_numbs = (ime->zhlen + (IME_WPP - 1)) / IME_WPP;
                ime->page_index = 0;
                ime->type = IME_TYPE_DICTS;
                return;
            }
            py++;
        }
        py = ime->dicts;
        match_count--;
    }
}

void pinyin_generate_page(ime_pinyin_t *ime)
{
    char S[32];//���������޶���9��,����ԣ��
    int i;

    ime->wordstr[0] = '\0';//ֻ�����ַ���
    if (ime->zhlen == 0) return;

    if (ime->type == IME_TYPE_DICTS) //�ֵ�
    {
        rt_uint16_t *p = (rt_uint16_t*)ime->zhptr;

        if (((ime->page_index + 1) * IME_WPP) < ime->zhlen) 
            ime->cnt_cur_page = IME_WPP;
        else 
            ime->cnt_cur_page = ime->zhlen - ime->page_index * IME_WPP;
        if (ime->cnt_cur_page == 0) return;
        p += ime->page_index * IME_WPP;
        for (i = 0; i < ime->cnt_cur_page; i++) 
        {
            rt_memcpy(S, p + i, 2), S[2] = '\0';
            sprintf(ime->wordstr, "%s%d.%s ", ime->wordstr, i+1, S);
        }
    } 
    else //if(ime->type==IME_TYPE_TERMS) �ʵ�
    {
        char *p = ime->zhptr;

        if (((ime->page_index + 1) * ime->cnt_per_page) < ime->zhlen) 
            ime->cnt_cur_page = ime->cnt_per_page;
        else 
            ime->cnt_cur_page = ime->zhlen - ime->page_index * ime->cnt_per_page;
        if (ime->cnt_cur_page == 0) return;
        p += ime->page_index * (ime->cnt_per_page * (ime->wordcnt*2+1));
        for (i = 0; i < ime->cnt_cur_page; i++)
        {
            rt_memcpy(S, p+(ime->wordcnt*2+1)*i, ime->wordcnt * 2);
            S[ime->wordcnt * 2] = '\0';
            sprintf(ime->wordstr, "%s%d.%s ", ime->wordstr, i+1, S);
        }
    }
}

void pinyin_getout_zhstring(ime_pinyin_t *ime, char *zhstr, int index)
{
    if (ime->type == IME_TYPE_DICTS) //�ֵ�
    {
        rt_uint16_t *p = (rt_uint16_t*)ime->zhptr;
        p += ime->page_index * IME_WPP;
        rt_memcpy(zhstr, p + index, 2);
        zhstr[2] = '\0';
    } 
    else //if(ime->type==IME_TYPE_TERMS) �ʵ�
    {
        char *p = ime->zhptr;
        p += ime->page_index * (ime->cnt_per_page * (ime->wordcnt * 2 + 1));
        rt_memcpy(zhstr, p + (ime->wordcnt * 2 + 1)*index, ime->wordcnt * 2);
        zhstr[ime->wordcnt * 2] = '\0';
    }
}

void pinyin_getin_letter(ime_pinyin_t *ime, char c)
{
    if(ime->inlen >= 9) return; //����������9��
    ime->inbuf[ime->inlen++] = toLower(c);
    if (ime->inlen == 1) //search dict list
    {
        ime->dicts = pinyin_get_dict(c);
    }
    ime->terms = pinyin_get_terms(ime->inbuf);

    pinyin_update_zhbuf(ime);
    pinyin_generate_page(ime);
}

void pinyin_backspace(ime_pinyin_t *ime)
{
    if (ime->inlen > 0) 
    {
        ime->inlen--;
        ime->inbuf[ime->inlen] = 0;

        if (ime->inlen == 0) {
            ime->dicts = RT_NULL;
            ime->terms = RT_NULL;
        } else {
            ime->terms = pinyin_get_terms(ime->inbuf);
        }
        pinyin_update_zhbuf(ime);
        ime->page_numbs = (ime->zhlen + 8) / 9;
        pinyin_generate_page(ime);
    }
}

void pinyin_page_add(ime_pinyin_t *ime)
{
    if (ime->page_numbs > 1)
    {
        if (ime->page_index > 0)
            ime->page_index -= 1;
        pinyin_generate_page(ime);
    }
}

void pinyin_page_sub(ime_pinyin_t *ime)
{
    if (ime->page_numbs > 1)
    {
        if ((ime->page_index + 1) < ime->page_numbs)
            ime->page_index += 1;
        pinyin_generate_page(ime);
    }
}

void pinyin_init(ime_pinyin_t *ime)
{
    rt_memset(ime, 0, sizeof(ime_pinyin_t));
}
