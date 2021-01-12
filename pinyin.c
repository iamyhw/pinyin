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

//½«×Öµä/´Êµä°´ÕÕÊ××ÖÄ¸·ÖÀà,¿É¼Ó¿ì²éÕÒËÙ¶È
static const ime_dicts_t dicts_a[] = {
    DICTS("a", "°¢°¡"),
    DICTS("ai", "°¥°§°¦°£°¤°¨°©°«°ª°¬°®°¯°­"),
    DICTS("an", "°²°±°°°³°¶°´°¸°·°µ"),
    DICTS("ang", "°¹°º°»"),
    DICTS("ao", "°¼°½°¾°¿°À°Á°Â°Ä°Ã"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_b[] = {
    DICTS("b", "²»²¿±¾±í°Ñ±ä±È²¢±ð°Ù±¨±£²¡±±±»²½±ß°Ë°ì²¼"),
    DICTS("ba", "°Ë°Í°È°Ç°É°Å°Ì°Æ°Ê°Î°Ï°Ñ°Ð°Ó°Ö°Õ°Ô"),
    DICTS("bai", "°×°Ù°Û°Ø°Ú°Ü°Ý°Þ"),
    DICTS("ban", "°â°à°ã°ä°ß°á°å°æ°ì°ë°é°ç°è°í°ê"),
    DICTS("bang", "°î°ï°ð°ó°ñ°ò°ö°ø°ô°ù°õ°÷"),
    DICTS("bao", "°ü°ú°û°ý±¢±¦±¥±£±¤±¨±§±ª±«±©±¬°þ±¡ÆÙ"),
    DICTS("bei", "±°±­±¯±®±±±´±·±¸±³±µ±¶±»±¹±º±²"),
    DICTS("ben", "±¼±¾±½±¿º»"),
    DICTS("beng", "±À±Á±Â±Ã±Å±Ä"),
    DICTS("bi", "±Æ±Ç±È±Ë±Ê±É±Ò±Ø±Ï±Õ±Ó±Ñ±Ý±Ð±Ö±Ô±Í±×±Ì±Î±Ú±Ü±Û"),
    DICTS("bian", "±ß±à±Þ±á±â±å±ã±ä±é±æ±ç±è"),
    DICTS("biao", "±ë±ê±ì±í"),
    DICTS("bie", "±ï±î±ð±ñ"),
    DICTS("bin", "±ö±ò±ó±õ±ô±÷"),
    DICTS("bing", "±ù±ø±û±ü±ú±þ±ý²¢²¡"),
    DICTS("bo", "²¦²¨²£²§²±²¤²¥²®²µ²¯²´²ª²¬²°²©²³²«²­²²²·"),
    DICTS("bu", "²¹²¸²¶²»²¼²½²À²¿²º²¾"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_c[] = {
    DICTS("c", "²ú³É³ö³¤´Ó´Ë³£´¦³µ³¡´«²É²ã³§²Å´Î³æ³ý²é²î"),
    DICTS("ca", "²Á"),
    DICTS("cai", "²Â²Å²Ä²Æ²Ã²É²Ê²Ç²È²Ë²Ì"),
    DICTS("can", "²Î²Í²Ð²Ï²Ñ²Ò²Ó"),
    DICTS("cang", "²Ö²×²Ô²Õ²Ø"),
    DICTS("cao", "²Ù²Ú²Ü²Û²Ý"),
    DICTS("ce", "²á²à²Þ²â²ß"),
    DICTS("ceng", "²ã²äÔø"),
    DICTS("cha", "²æ²å²é²ç²è²ë²ì²ê²í²ï²îÉ²"),
    DICTS("chai", "²ð²ñ²ò"),
    DICTS("chan", "²ô²ó²÷²ö²ø²õ²ú²ù²û²ü"),
    DICTS("chang", "²ý²þ³¦³¢³¥³£³§³¡³¨³©³«³ª"),
    DICTS("chao", "³­³®³¬³²³¯³°³±³³³´´Â"),
    DICTS("che", "³µ³¶³¹³¸³·³º"),
    DICTS("chen", "³»³¾³¼³À³Á³½³Â³¿³Ä³Ã"),
    DICTS("cheng", "³Æ³Å³É³Ê³Ð³Ï³Ç³Ë³Í³Ì³Î³È³Ñ³Ò³Ó"),
    DICTS("chi", "³Ô³Õ³Ú³Ø³Û³Ù³Ö³ß³Þ³Ý³Ü³â³à³ã³á"),
    DICTS("chong", "³ä³å³æ³ç³è"),
    DICTS("chou", "³é³ð³ñ³ë³î³í³ï³ê³ì³ó³ò³ô"),
    DICTS("chu", "³ö³õ³ý³ø³ü³ú³û³÷³ù´¡´¢³þ´¦´¤´¥´£Ðó"),
    DICTS("chuai", "´§"),
    DICTS("chuan", "´¨´©´«´¬´ª´­´®"),
    DICTS("chuang", "´³´¯´°´²´´"),
    DICTS("chui", "´µ´¶´¹´·´¸"),
    DICTS("chun", "´º´»´¿´½´¾´¼´À"),
    DICTS("chuo", "´Á"),
    DICTS("ci", "´Ã´Ê´Ä´É´È´Ç´Å´Æ´Ë´Î´Ì´Í"),
    DICTS("cong", "´Ñ´Ó´Ò´Ð´Ï´Ô"),
    DICTS("cou", "´Õ"),
    DICTS("cu", "´Ö´Ù´×´Ø"),
    DICTS("cuan", "´Ú´Ü´Û"),
    DICTS("cui", "´Þ´ß´Ý´à´ã´á´â´ä"),
    DICTS("cun", "´å´æ´ç"),
    DICTS("cuo", "´ê´è´é´ì´ë´í"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_d[] = {
    DICTS("d", "µÄ´óµØ¶¯µ½¶Ô¶È¶àµçµ³µÃ¶¨µÈ¶·µ±¶Ó¶¼µã´úµÀ"),
    DICTS("dai", "´ô´õ´ö´ú´ø´ýµ¡´ù´û´ü´þ´÷"),
    DICTS("dan", "µ¤µ¥µ£µ¢µ¦µ¨µ§µ©µ«µ®µ¯µ¬µ­µ°µª"),
    DICTS("dang", "µ±µ²µ³µ´µµ"),
    DICTS("dao", "µ¶µ¼µºµ¹µ·µ»µ¸µ½µ¿µÁµÀµ¾"),
    DICTS("de", "µÃµÂµÄ"),
    DICTS("deng", "µÆµÇµÅµÈµËµÊµÉ"),
    DICTS("di", "µÍµÌµÎµÒµÏµÐµÓµÑµÕµ×µÖµØµÜµÛµÝµÚµÞµÙ"),
    DICTS("dian", "µàµáµßµäµãµâµçµèµéµêµæµëµíµìµîµå"),
    DICTS("diao", "µóµðµòµïµñµõµöµô"),
    DICTS("die", "µùµøµüµýµþµúµû"),
    DICTS("ding", "¶¡¶£¶¢¶¤¶¥¶¦¶©¶¨¶§"),
    DICTS("diu", "¶ª"),
    DICTS("dong", "¶«¶¬¶­¶®¶¯¶³¶±¶²¶°¶´"),
    DICTS("dou", "¶¼¶µ¶·¶¶¶¸¶¹¶º¶»"),
    DICTS("du", "¶½¶¾¶Á¶¿¶À¶Â¶Ä¶Ã¶Ê¶Å¶Ç¶È¶É¶Æ"),
    DICTS("duan", "¶Ë¶Ì¶Î¶Ï¶Ð¶Í"),
    DICTS("dui", "¶Ñ¶Ó¶Ô¶Ò"),
    DICTS("dun", "¶Ö¶Ø¶Õ¶×¶Ü¶Û¶Ù¶Ý"),
    DICTS("duo", "¶à¶ß¶á¶Þ¶ä¶â¶ã¶ç¶é¶æ¶è¶å"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_e[] = {
    DICTS("e", "¶ï¶í¶ð¶ë¶ì¶ê¶î¶ò¶ó¶ñ¶ö¶õ¶ô"),
    DICTS("en", "¶÷"),
    DICTS("er", "¶ù¶ø¶û¶ú¶ý¶ü¶þ·¡"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_f[] = {
    DICTS("f", "·Ö·¢·½·¨·´·Å¸´·ç·À·Ç·þ·Ê¸±·Û¸®·ò¸º·â¸»·­"),
    DICTS("fa", "·¢·¦·¥·£·§·¤·¨·©"),
    DICTS("fan", "·«·¬·­·ª·²·¯·°·³·®·±·´·µ·¸·º·¹·¶··"),
    DICTS("fang", "·½·»·¼·À·Á·¿·¾·Â·Ã·Ä·Å"),
    DICTS("fei", "·É·Ç·È·Æ·Ê·Ë·Ì·Í·Ï·Ð·Î·Ñ"),
    DICTS("fen", "·Ö·Ô·×·Ò·Õ·Ó·Ø·Ú·Ù·Û·Ý·Ü·Þ·ß·à"),
    DICTS("feng", "·á·ç·ã·â·è·å·é·æ·ä·ë·ê·ì·í·ï·î"),
    DICTS("fo", "·ð"),
    DICTS("fou", "·ñ"),
    DICTS("fu", "·ò·ô·õ·ó¸¥·ü·ö·÷·þ·ý·ú¸¡¸¢·û¸¤·ù¸£·ø¸§¸¦¸®¸«¸©¸ª¸¨¸­¸¯¸¸¸¼¸¶¸¾¸º¸½¸À¸·¸´¸°¸±¸µ¸»¸³¸¿¸¹¸²"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_g[] = {
    DICTS("g", "¸ö¹ú¹¤¹ý¸ß¸É¹Ø¸÷¸ï¹«¸ù¸ü¸Ä¹Ü¹â¹ã¹û¸ñ¹²¸ã"),
    DICTS("ga", "¸Â¸Á"),
    DICTS("gai", "¸Ã¸Ä¸Æ¸Ç¸È¸Å"),
    DICTS("gan", "¸É¸Ê¸Ë¸Î¸Ì¸Í¸Ñ¸Ï¸Ò¸Ð¸Ó"),
    DICTS("gang", "¸Ô¸Õ¸Ú¸Ù¸Ø¸×¸Ö¸Û¸Ü"),
    DICTS("gao", "¸Þ¸á¸ß¸à¸Ý¸â¸ã¸å¸ä¸æ"),
    DICTS("ge", "¸ê¸í¸ç¸ì¸ë¸î¸é¸è¸ó¸ï¸ñ¸ð¸ô¸ö¸÷¸õ¿©"),
    DICTS("gei", "¸ø"),
    DICTS("gen", "¸ù¸ú"),
    DICTS("geng", "¸ü¸ý¸û¸þ¹¡¹¢¹£"),
    DICTS("gong", "¹¤¹­¹«¹¦¹¥¹©¹¬¹§¹ª¹¨¹®¹¯¹°¹²¹±"),
    DICTS("gou", "¹´¹µ¹³¹·¹¶¹¹¹º¹¸¹»"),
    DICTS("gu", "¹À¹¾¹Ã¹Â¹Á¹½¹¼¹¿¹Å¹È¹É¹Ç¹Æ¹Ä¹Ì¹Ê¹Ë¹Í"),
    DICTS("gua", "¹Ï¹Î¹Ð¹Ñ¹Ò¹Ó"),
    DICTS("guai", "¹Ô¹Õ¹Ö"),
    DICTS("guan", "¹Ø¹Û¹Ù¹Ú¹×¹Ý¹Ü¹á¹ß¹à¹Þ"),
    DICTS("guang", "¹â¹ã¹ä"),
    DICTS("gui", "¹é¹ç¹ê¹æ¹ë¹è¹å¹ì¹î¹ï¹í¹ô¹ñ¹ó¹ð¹ò"),
    DICTS("gun", "¹õ¹ö¹÷"),
    DICTS("guo", "¹ù¹ø¹ú¹û¹ü¹ý"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_h[] = {
    DICTS("h", "ºÍ»áºó»¯ºÃºÏ»¹»îºÜ»ØºÅºÁ»¨»òº£»°ºì»ð»Æº¦"),
    DICTS("ha", "¸ò¹þ"),
    DICTS("hai", "º¢º¡º£º¥º§º¦º¤"),
    DICTS("han", "º¨º©º¬ºªº¯º­º®º«º±º°ººº¹ºµº·º´º¸º¶º³º²"),
    DICTS("hang", "º¼º½ÐÐ"),
    DICTS("hao", "ºÁºÀº¿º¾ºÃºÂºÅºÆºÄ"),
    DICTS("he", "ºÇºÈºÌºÏºÎºÍºÓºÒºËºÉºÔºÐºÊºØºÖºÕº×"),
    DICTS("hei", "ºÚºÙ"),
    DICTS("hen", "ºÛºÜºÝºÞ"),
    DICTS("heng", "ºàºßºãºáºâ"),
    DICTS("hong", "ºäºåºæºëºìºêºéºçºè"),
    DICTS("hou", "ºîºíºïºðºóºñºò"),
    DICTS("hu", "ºõºôºö»¡ºüºúºøºþºùº÷ºýºû»¢»£»¥»§»¤»¦"),
    DICTS("hua", "»¨»ª»©»¬»«»¯»®»­»°"),
    DICTS("huai", "»³»²»´»±»µ"),
    DICTS("huan", "»¶»¹»·»¸»º»Ã»Â»½»»»Á»¼»À»¾»¿"),
    DICTS("huang", "»Ä»Å»Ê»Ë»Æ»Ì»Í»È»Ç»É»Ð»Î»Ñ»Ï"),
    DICTS("hui", "»Ò»Ö»Ó»Ô»Õ»Ø»×»Ú»Ü»ã»á»ä»æ»å»â»ß»Þ»à»Ý»Ù»Û"),
    DICTS("hun", "»è»ç»é»ë»ê»ì"),
    DICTS("huo", "»í»î»ð»ï»ò»õ»ñ»ö»ó»ô"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_j[] = {
    DICTS("j", "¼¶¾Í½ø¼Ó¾­¼Ò½á½×¼ä¼þ¼°½â½Ï»ú¾ü½Ó½Ì¼«¾Å¼û"),
    DICTS("ji", "¼¥»÷¼¢»ø»ú¼¡¼¦¼£¼§»ý»ù¼¨¼©»û»þ»ü¼¤¼°¼ª¼³¼¶¼´¼«¼±¼²¼¬¼¯¼µ¼­¼®¼¸¼º¼·¼¹¼Æ¼Ç¼¿¼Í¼Ë¼É¼¼¼Ê¼Á¼¾¼È¼Ã¼Ì¼Å¼Ä¼Â¼À¼»¼½½å"),
    DICTS("jia", "¼Ó¼Ð¼Ñ¼Ï¼Ò¼Î¼Ô¼Õ¼×¼Ö¼Ø¼Û¼Ý¼Ü¼Ù¼Þ¼ÚÐ®"),
    DICTS("jian", "¼é¼â¼á¼ß¼ä¼ç¼è¼æ¼à¼ã¼ê¼å¼ð¼ó¼í¼ë¼ñ¼õ¼ô¼ì¼ï¼ò¼î¼û¼þ½¨½¤½£¼ö¼ú½¡½§½¢½¥½¦¼ù¼ø¼ü¼ý"),
    DICTS("jiang", "½­½ª½«½¬½©½®½²½±½°½¯½³½µ½´"),
    DICTS("jiao", "½»½¼½¿½½½¾½º½·½¹½¶½¸½Ç½Æ½Ê½È½Ã½Å½Â½Á½Ë½É½Ð½Î½Ï½Ì½Ñ½Í¾õ½À"),
    DICTS("jie", "½×½Ô½Ó½Õ½Ò½Ö½Ú½Ù½Ü½à½á½Ý½Þ½Ø½ß½ã½â½é½ä½æ½ì½ç½ê½ë½è"),
    DICTS("jin", "½í½ñ½ï½ð½ò½î½ó½ö½ô½÷½õ¾¡¾¢½ü½ø½ú½þ½ý½û½ù"),
    DICTS("jing", "¾©¾­¾¥¾£¾ª¾§¾¦¾¬¾¤¾«¾¨¾®¾±¾°¾¯¾»¾¶¾·¾º¾¹¾´¾¸¾³¾²¾µ"),
    DICTS("jiong", "¾¼¾½"),
    DICTS("jiu", "¾À¾¿¾¾¾Å¾Ã¾Ä¾Á¾Â¾Æ¾É¾Ê¾Ì¾Î¾Ç¾È¾Í¾Ë"),
    DICTS("ju", "¾Ó¾Ð¾Ñ¾Ô¾Ò¾Ï¾Ö½Û¾Õ¾×¾Ú¾Ù¾Ø¾ä¾Þ¾Ü¾ß¾æ¾ã¾ç¾å¾Ý¾à¾â¾Û¾á"),
    DICTS("juan", "¾ê¾è¾é¾í¾ë¾î¾ì"),
    DICTS("jue", "¾ï¾ö¾÷¾ñ¾ø¾ó¾ò¾ô¾ð"),
    DICTS("jun", "¾ü¾ý¾ù¾û¾ú¿¡¿¤¾þ¿£¿¥¿¢"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_k[] = {
    DICTS("k", "¿É¿ª¿´¿Ë¿×¿Æ¿Ú¿Õ¿à¿ì¿¼¿Ì¿¿¿ö¿éÀ§¿í¿ó¿¹¿¨"),
    DICTS("ka", "¿§¿¦¿¨"),
    DICTS("kai", "¿ª¿«¿­¿®¿¬"),
    DICTS("kan", "¼÷¿¯¿±¿°¿²¿³¿´"),
    DICTS("kang", "¿µ¿¶¿·¿¸¿º¿¹¿»"),
    DICTS("kao", "¿¼¿½¿¾¿¿"),
    DICTS("ke", "¿À¿Á¿Â¿Æ¿Ã¿Å¿Ä¿Ç¿È¿É¿Ê¿Ë¿Ì¿Í¿Î"),
    DICTS("ken", "¿Ï¿Ñ¿Ò¿Ð"),
    DICTS("keng", "¿Ô¿Ó"),
    DICTS("kong", "¿Õ¿×¿Ö¿Ø"),
    DICTS("kou", "¿Ù¿Ú¿Û¿Ü"),
    DICTS("ku", "¿Ý¿Þ¿ß¿à¿â¿ã¿á"),
    DICTS("kua", "¿ä¿å¿æ¿è¿ç"),
    DICTS("kuai", "¿é¿ì¿ë¿ê"),
    DICTS("kuan", "¿í¿î"),
    DICTS("kuang", "¿ï¿ð¿ñ¿ö¿õ¿ó¿ò¿ô"),
    DICTS("kui", "¿÷¿ù¿ø¿ú¿ü¿û¿ý¿þÀ¢À£À¡"),
    DICTS("kun", "À¤À¥À¦À§"),
    DICTS("kuo", "À©À¨À«Àª"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_l[] = {
    DICTS("l", "ÁËÀ´Á¿ÀíÂ·ÀïÂÛÁ½ÀûÁìÁ÷Á¦Á¢ÁÏÁ¬ÀÏÁùÂÖÀàÁÐ"),
    DICTS("la", "À¬À­À²À®À°À¯À±"),
    DICTS("lai", "À´À³Àµ"),
    DICTS("lan", "À¼À¹À¸À·À»À¶À¾À½ÀºÀÀÀ¿ÀÂÀÁÀÃÀÄ"),
    DICTS("lang", "ÀÉÀÇÀÈÀÅÀÆÀÊÀË"),
    DICTS("lao", "ÀÌÀÍÀÎÀÏÀÐÀÑÀÔÀÓÀÒ"),
    DICTS("le", "ÀÖÀÕÁË"),
    DICTS("lei", "À×ÀØÀÝÀÚÀÙÀÜÀßÀáÀàÀÛÀÞ"),
    DICTS("leng", "ÀâÀãÀä"),
    DICTS("li", "ÀåÀæÀêÀëÀòÀçÀìÁ§ÀèÀéÀñÀîÀïÁ¨ÀíÀðÁ¦ÀúÀ÷Á¢ÀôÀöÀûÀøÁ¤ÀýÁ¥ÀþÀóÀõÀùÁ£ÀüÁ¡"),
    DICTS("lian", "Á¬Á±Á¯Á°Á«ÁªÁ®Á­Á²Á³Á·Á¶ÁµÁ´"),
    DICTS("liang", "Á©Á¼Á¹ÁºÁ¸Á»Á½ÁÁÁÂÁ¾ÁÀÁ¿"),
    DICTS("liao", "ÁÊÁÉÁÆÁÄÁÅÁÈÁÎÁÃÁÇÁÍÁÏÁÌ"),
    DICTS("lie", "ÁÐÁÓÁÒÁÔÁÑ"),
    DICTS("lin", "ÁÚÁÖÁÙÁÜÁÕÁØÁ×ÁÛÁÝÁßÁÞÁà"),
    DICTS("ling", "ÁæÁéÁëÁáÁèÁåÁêÁçÁâÁãÁäÁìÁîÁí"),
    DICTS("liu", "ÁïÁõÁ÷ÁôÁðÁòÁóÁñÁöÁøÁù"),
    DICTS("long", "ÁúÁüÁýÁûÂ¡ÁþÂ¤Â¢Â£"),
    DICTS("lou", "Â¦Â¥Â§Â¨ÂªÂ©"),
    DICTS("lu", "Â¶Â¬Â®Â«Â¯Â­Â±Â²Â°Â³Â½Â¼Â¸Â¹Â»ÂµÂ·Â¾ÂºÂ´"),
    DICTS("luan", "ÂÏÂÍÂÎÂÐÂÑÂÒ"),
    DICTS("lue", "ÂÓÂÔ"),
    DICTS("lun", "ÂÕÂØÂ×ÂÙÂÚÂÖÂÛ"),
    DICTS("luo", "ÂÞÂÜÂßÂàÂáÂâÂÝÂãÂåÂçÂæÂä"),
    DICTS("lv", "ÂËÂ¿ÂÀÂÂÂÃÂÁÂÅÂÆÂÄÂÉÂÇÂÊÂÌÂÈ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_m[] = {
    DICTS("m", "ÃæÃüÃÇÃñÃ«Ã»Ã×Ã÷ÂíÃ´Ã¿ÃÅÃûÄ¥ÃÀÃÜÃçÂúÄ¶Ä¿ß¼"),
    DICTS("ma", "ÂèÂéÂíÂêÂëÂìÂîÂðÂï"),
    DICTS("mai", "ÂñÂòÂõÂóÂôÂö"),
    DICTS("man", "ÂùÂøÂ÷ÂúÂüÃ¡ÂýÂþÂû"),
    DICTS("mang", "Ã¦Ã¢Ã¤Ã£Ã§Ã¥"),
    DICTS("mao", "Ã¨Ã«Ã¬Ã©ÃªÃ®Ã­Ã¯Ã°Ã³Ã±Ã²"),
    DICTS("me", "Ã´"),
    DICTS("mei", "Ã»Ã¶ÃµÃ¼Ã·Ã½ÃºÃ¸Ã¹Ã¿ÃÀÃ¾ÃÃÃÁÃÄÃÂ"),
    DICTS("men", "ÃÅÃÆÃÇ"),
    DICTS("meng", "ÃÈÃËÃÊÃÍÃÉÃÌÃÏÃÎ"),
    DICTS("mi", "ÃÖÃÔÃÕÃÑÃÓÃÒÃ×ÃÐÃÚÃÙÃØÃÜÃÝÃÛ"),
    DICTS("mian", "ÃßÃàÃÞÃâÃãÃäÃáÃåÃæ"),
    DICTS("miao", "ÃçÃèÃéÃëÃìÃêÃîÃí"),
    DICTS("mie", "ÃðÃï"),
    DICTS("min", "ÃñÃóÃòÃöÃõÃô"),
    DICTS("ming", "ÃûÃ÷ÃùÃúÃøÃü"),
    DICTS("miu", "Ãý"),
    DICTS("mo", "ºÑÃþÄ¡Ä£Ä¤Ä¦Ä¥Ä¢Ä§Ä¨Ä©Ä­Ä°ÄªÄ¯Ä®Ä«Ä¬"),
    DICTS("mou", "Ä²Ä±Ä³"),
    DICTS("mu", "Ä¸Ä¶ÄµÄ·Ä´Ä¾Ä¿ÄÁÄ¼Ä¹Ä»ÄÀÄ½ÄºÄÂ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_n[] = {
    DICTS("n", "ÄêÄÜÄÚÄÇÅ©ÄãÄÏÄÑÄØÅ®ÄàÄÄÄÃÄîÅ£ÄþÄÔÕ³ÄáÄÉàÅ"),
    DICTS("na", "ÄÃÄÄÄÇÄÉÄÈÄÆÄÅ"),
    DICTS("nai", "ÄËÄÌÄÊÄÎÄÍ"),
    DICTS("nan", "ÄÐÄÏÄÑ"),
    DICTS("nang", "ÄÒ"),
    DICTS("nao", "ÄÓÄÕÄÔÄÖÄ×"),
    DICTS("ne", "ÄØ"),
    DICTS("nei", "ÄÚÄÙ"),
    DICTS("nen", "ÄÛ"),
    DICTS("neng", "ÄÜ"),
    DICTS("ni", "ÄÝÄáÄàÄßÄÞÄãÄâÄæÄäÄçÄå"),
    DICTS("nian", "ÄéÄêÄíÄìÄëÄîÄè"),
    DICTS("niang", "ÄïÄð"),
    DICTS("niao", "ÄñÄò"),
    DICTS("nie", "ÄóÄùÄôÄöÄ÷ÄøÄõ"),
    DICTS("nin", "Äú"),
    DICTS("ning", "ÄþÅ¡ÄüÄûÄýÅ¢"),
    DICTS("niu", "Å£Å¤Å¦Å¥"),
    DICTS("nong", "Å©Å¨Å§Åª"),
    DICTS("nu", "Å«Å¬Å­"),
    DICTS("nuan", "Å¯"),
    DICTS("nue", "Å±Å°"),
    DICTS("nuo", "Å²ÅµÅ³Å´"),
    DICTS("nv", "Å®"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_o[] = {
    DICTS("o", "Å¶"),
    DICTS("ou", "Å·Å¹Å¸Å»Å¼ÅºÅ½"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_p[] = {
    DICTS("p", "ÅúÆ½ÅÐÅäÆ¬ÅÉÆÆÅÅÆ·Æ¤ÅçÅÌÆ«ÆÀÅÂÅàÆÕÆ¶ÅÜÅÚ"),
    DICTS("pa", "Å¿Å¾ÅÀ°ÒÅÃÅÁÅÂ"),
    DICTS("pai", "ÅÄÅÇÅÅÅÆÅÉÅÈ"),
    DICTS("pan", "ÅËÅÊÅÌÅÍÅÐÅÑÅÎÅÏ"),
    DICTS("pang", "ÅÒÅÓÅÔÅÕÅÖ"),
    DICTS("pao", "Å×ÅÙÅØÅÚÅÛÅÜÅÝ"),
    DICTS("pei", "ÅÞÅßÅãÅàÅâÅáÅæÅåÅä"),
    DICTS("pen", "ÅçÅè"),
    DICTS("peng", "ÅêÅéÅëÅóÅíÅïÅðÅîÅôÅìÅñÅòÅõÅö"),
    DICTS("pi", "±ÙÅúÅ÷ÅûÅøÅüÅùÆ¤ÅþÆ£Æ¡ÅýÆ¢Æ¥Æ¦Æ¨Æ§Æ©"),
    DICTS("pian", "Æ¬Æ«ÆªÆ­"),
    DICTS("piao", "Æ¯Æ®Æ°Æ±"),
    DICTS("pie", "Æ²Æ³"),
    DICTS("pin", "Æ´Æ¶ÆµÆ·Æ¸"),
    DICTS("ping", "Æ¹Æ½ÆÀÆ¾ÆºÆ»ÆÁÆ¿Æ¼"),
    DICTS("po", "ÆÂÆÃÆÄÆÅÆÈÆÆÆÉÆÇ"),
    DICTS("pou", "ÆÊ"),
    DICTS("pu", "¸¬ÆÍÆËÆÌÆÎÆÐÆÏÆÑÆÓÆÔÆÒÆÖÆÕÆ×ÆØ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_q[] = {
    DICTS("q", "ÆðÇ°ÆäÈ¥ÆøÈ«ÆÚÈºÇéÇøÇ¿ÇÐÈ¡ÆßÇóÇåÈ·È¨ÇÒÇà"),
    DICTS("qi", "ÆßÆãÆÞÆâÆàÆÜÆÝÆÚÆÛÆáÆîÆëÆäÆæÆçÆíÆêÆéÆèÆïÆåÆìÆòÆóÆñÆôÆðÆøÆýÆùÆúÆûÆüÆõÆöÆ÷"),
    DICTS("qia", "ÆþÇ¡Ç¢"),
    DICTS("qian", "Ç§ÇªÇ¤Ç¨Ç¥Ç£Ç¦Ç«Ç©Ç°Ç®Ç¯Ç¬Ç±Ç­Ç³Ç²Ç´Ç·ÇµÇ¶Ç¸"),
    DICTS("qiang", "ÇºÇ¼Ç¹Ç»Ç¿Ç½Ç¾ÇÀ"),
    DICTS("qiao", "ÇÄÇÃÇÂÇÁÇÇÇÈÇÅÇÆÇÉÇÎÇÍÇÏÇÌÇËÇÊ"),
    DICTS("qie", "ÇÐÇÑÇÒÇÓÇÔ"),
    DICTS("qin", "Ç×ÇÖÇÕÇÛÇØÇÙÇÝÇÚÇÜÇÞÇß"),
    DICTS("qing", "ÇàÇâÇáÇãÇäÇåÇéÇçÇèÇæÇêÇëÇì"),
    DICTS("qiong", "ÇîÇí"),
    DICTS("qiu", "ÇðÇñÇïÇôÇóÇöÇõÇò"),
    DICTS("qu", "ÇøÇúÇýÇüÇùÇûÇ÷ÇþÈ¡È¢È£È¥È¤"),
    DICTS("quan", "È¦È«È¨ÈªÈ­È¬È©È§È®È°È¯"),
    DICTS("que", "È²È±È³È´È¸È·ÈµÈ¶"),
    DICTS("qun", "È¹Èº"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_r[] = {
    DICTS("r", "ÈËÈçÈÕÈÏÈëÈÎÈÈÈ»ÈÝÈÃÈóÈõÈ¼È¾ÈÀÈÆÈÊÈÜÈÐÈÔ"),
    DICTS("ran", "È»È¼È½È¾"),
    DICTS("rang", "È¿ÈÂÈÀÈÁÈÃ"),
    DICTS("rao", "ÈÄÈÅÈÆ"),
    DICTS("re", "ÈÇÈÈ"),
    DICTS("ren", "ÈËÈÊÈÉÈÌÈÐÈÏÈÎÈÒÈÑÈÍ"),
    DICTS("reng", "ÈÓÈÔ"),
    DICTS("ri", "ÈÕ"),
    DICTS("rong", "ÈÖÈÞÈ×ÈÙÈÝÈÜÈØÈÛÈÚÈß"),
    DICTS("rou", "ÈáÈàÈâ"),
    DICTS("ru", "ÈçÈãÈåÈæÈäÈêÈéÈèÈëÈì"),
    DICTS("ruan", "ÈîÈí"),
    DICTS("rui", "ÈïÈñÈð"),
    DICTS("run", "ÈòÈó"),
    DICTS("ruo", "ÈôÈõ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_s[] = {
    DICTS("s", "ÊÇÉÏÊ±ÉúËµÉçÉîË®ËùÈýÊ®Ê¹ÊÂÊýËÄÊµÉÙÊ½É½ÊÖ"),
    DICTS("sa", "ÈöÈ÷Èø"),
    DICTS("sai", "ÈûÈùÈúÈü"),
    DICTS("san", "ÈýÈþÉ¡É¢"),
    DICTS("sang", "É£É¤É¥"),
    DICTS("sao", "É¦É§É¨É©"),
    DICTS("se", "É«É¬Éª"),
    DICTS("sen", "É­"),
    DICTS("seng", "É®"),
    DICTS("sha", "É±É³É´É°É¯ÉµÉ¶É·ÏÃ"),
    DICTS("shai", "É¸É¹"),
    DICTS("shan", "É½É¾É¼ÉÀÉºÉ¿ÉÁÉÂÉÇÉ»ÉÈÉÆÉÉÉÃÉÅÉÄÕ¤"),
    DICTS("shang", "ÉËÉÌÉÊÉÑÉÎÉÍÉÏÉÐ"),
    DICTS("shao", "ÉÓÉÒÉÕÉÔÉ×ÉÖÉØÉÙÉÛÉÜÉÚ"),
    DICTS("she", "ÉÝÉÞÉàÉßÉáÉèÉçÉäÉæÉâÉåÉã"),
    DICTS("shen", "ÉêÉìÉíÉëÉðÉïÉéÉîÉñÉòÉóÉôÉöÉõÉøÉ÷Ê²"),
    DICTS("sheng", "ÉýÉúÉùÉüÊ¤ÉûÉþÊ¡Ê¥Ê¢Ê£"),
    DICTS("shi", "³×Ê¬Ê§Ê¦Ê­Ê«Ê©Ê¨ÊªÊ®Ê¯Ê±Ê¶ÊµÊ°Ê´Ê³Ê·Ê¸Ê¹Ê¼Ê»ÊºÊ¿ÊÏÊÀÊËÊÐÊ¾Ê½ÊÂÊÌÊÆÊÓÊÔÊÎÊÒÊÑÊÃÊÇÊÁÊÊÊÅÊÍÊÈÊÄÊÉËÆ"),
    DICTS("shou", "ÊÕÊÖÊØÊ×ÊÙÊÜÊÞÊÛÊÚÊÝ"),
    DICTS("shu", "ÊéÊãÊåÊàÊâÊáÊçÊèÊæÊäÊßÊëÊêÊìÊîÊòÊðÊóÊñÊíÊïÊõÊùÊøÊöÊ÷ÊúË¡ÊüÊýÊûÊþÊô"),
    DICTS("shua", "Ë¢Ë£"),
    DICTS("shuai", "Ë¥Ë¤Ë¦Ë§"),
    DICTS("shuan", "Ë©Ë¨"),
    DICTS("shuang", "Ë«ËªË¬"),
    DICTS("shui", "Ë­Ë®Ë°Ë¯"),
    DICTS("shun", "Ë±Ë³Ë´Ë²"),
    DICTS("shuo", "ËµË¸Ë·Ë¶"),
    DICTS("si", "Ë¿Ë¾Ë½Ë¼Ë¹Ë»ËºËÀËÈËÄËÂËÅËÇËÃËÁ"),
    DICTS("song", "ËÉËËËÊËÏËÎËÐËÍËÌ"),
    DICTS("sou", "ËÔËÑËÒËÓ"),
    DICTS("su", "ËÕËÖË×ËßËàËØËÙËÚËÜËÝËÛ"),
    DICTS("suan", "ËáËâËã"),
    DICTS("sui", "ËäËçËåËæËèËêËîËìËéËíËë"),
    DICTS("sun", "ËïËðËñ"),
    DICTS("suo", "ËôËóËòËõËùË÷ËöËø"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_t[] = {
    DICTS("t", "ËûÍ¬ËüÌáÌâÌåÍ¼ÌìÍ·Í¨ÌõÌØÍÁÍÅÍ³Ì¨ËýÌ«Ì×Ìú"),
    DICTS("ta", "ËýËûËüËúËþÌ¡Ì¢Ì¤Ì£"),
    DICTS("tai", "Ì¥Ì¨Ì§Ì¦Ì«Ì­Ì¬Ì©Ìª"),
    DICTS("tan", "Ì®Ì°Ì¯Ì²Ì±Ì³Ì¸ÌµÌ·Ì¶Ì´Ì¹Ì»ÌºÌ¾Ì¿Ì½Ì¼"),
    DICTS("tang", "ÌÀÌÆÌÃÌÄÌÁÌÂÌÅÌÇÌÈÌÊÌÉÌÌÌË"),
    DICTS("tao", "ÌÎÌÐÌÍÌÏÌÓÌÒÌÕÌÔÌÑÌÖÌ×"),
    DICTS("te", "ÌØ"),
    DICTS("teng", "ÌÛÌÚÌÜÌÙ"),
    DICTS("ti", "ÌÞÌÝÌàÌßÌäÌáÌâÌãÌåÌëÌêÌéÌèÌæÌç"),
    DICTS("tian", "ÌìÌíÌïÌñÌðÌîÌóÌò"),
    DICTS("tiao", "µ÷ÌôÌõÌöÌ÷Ìø"),
    DICTS("tie", "ÌùÌúÌû"),
    DICTS("ting", "ÌüÍ¡ÌýÌþÍ¢Í¤Í¥Í£Í¦Í§"),
    DICTS("tong", "Í¨Í¬Í®Í©Í­Í¯ÍªÍ«Í³Í±Í°Í²Í´"),
    DICTS("tou", "ÍµÍ·Í¶Í¸"),
    DICTS("tu", "Í¹ÍºÍ»Í¼Í½Í¿Í¾ÍÀÍÁÍÂÍÃ"),
    DICTS("tuan", "ÍÄÍÅ"),
    DICTS("tui", "ÍÆÍÇÍÈÍËÍÉÍÊ"),
    DICTS("tun", "¶ÚÍÌÍÍÍÎ"),
    DICTS("tuo", "ÍÐÍÏÍÑÍÔÍÓÍÕÍÒÍ×ÍÖÍØÍÙ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_w[] = {
    DICTS("w", "ÎªÎÒÎÞÎÊÍâÎåÎ»ÎïÎ¯ÍêÎÂÍòÎÄÍùÎäÎñÍõÎ§ÎóÍí"),
    DICTS("wa", "ÍÛÍÞÍÚÍÝÍÜÍßÍà"),
    DICTS("wai", "ÍáÍâ"),
    DICTS("wan", "ÍäÍåÍãÍèÍêÍæÍçÍéÍðÍìÍíÍñÍïÍîÍëÍòÍó"),
    DICTS("wang", "ÍôÍöÍõÍøÍùÍ÷ÍýÍüÍúÍû"),
    DICTS("wei", "Î£ÍþÎ¢Î¡ÎªÎ¤Î§Î¥Î¦Î¨Î©Î¬Î«Î°Î±Î²Î³Î­Î¯Î®ÎÀÎ´Î»Î¶Î·Î¸Î¾Î½Î¹Î¼ÎµÎ¿Îº"),
    DICTS("wen", "ÎÂÎÁÎÄÎÆÎÅÎÃÎÇÎÉÎÈÎÊ"),
    DICTS("weng", "ÎÌÎËÎÍ"),
    DICTS("wo", "ÎÎÎÐÎÑÎÏÎÒÎÖÎÔÎÕÎÓ"),
    DICTS("wu", "ÎÚÎÛÎØÎ×ÎÝÎÜÎÙÎÞÎãÎâÎáÎßÎàÎåÎçÎéÎëÎäÎêÎæÎèÎðÎñÎìÎïÎóÎòÎîÎí"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_x[] = {
    DICTS("x", "Ñ§ÏÂÐÐÐ¡ÏßÐÔÐÂÐ©ÏëÐÄÏòÏàÏµÏ¯ÏÖÎ÷ÐÞÏóÏÈÐÎ"),
    DICTS("xi", "Ï¦Ï«Î÷ÎüÏ£ÎôÎöÎùÏ¢ÎþÏ¤Ï§Ï©ÎøÎúÏ¬Ï¡ÏªÎýÏ¨ÎõÎûÏ¥Ï°Ï¯Ï®Ï±Ï­Ï´Ï²Ï·ÏµÏ¸Ï¶"),
    DICTS("xia", "ÏºÏ¹Ï»ÏÀÏ¿ÏÁÏ¾Ï½Ï¼ÏÂÏÅÏÄ"),
    DICTS("xian", "Ï³ÏÉÏÈÏËÏÆÏÇÏÊÏÐÏÒÏÍÏÌÏÑÏÏÏÎÏÓÏÔÏÕÏØÏÖÏßÏÞÏÜÏÝÏÚÏÛÏ×ÏÙ"),
    DICTS("xiang", "ÏçÏàÏãÏáÏæÏäÏåÏâÏêÏéÏèÏíÏìÏëÏòÏïÏîÏóÏñÏð"),
    DICTS("xiao", "ÏüÏûÏôÏõÏúÏöÏùÏýÐ¡ÏþÐ¢Ð¤ÏøÐ§Ð£Ð¦Ð¥"),
    DICTS("xie", "Ð©Ð¨ÐªÐ«Ð­Ð°Ð²Ð±Ð³Ð¯Ð¬Ð´Ð¹ÐºÐ¶Ð¼ÐµÐ»Ð¸Ð·"),
    DICTS("xin", "ÐÄÐÃÐ¾ÐÁÐÀÐ¿ÐÂÐ½ÐÅÐÆ"),
    DICTS("xing", "ÐËÐÇÐÊÐÉÐÈÐÌÐÏÐÎÐÍÐÑÐÓÐÕÐÒÐÔ"),
    DICTS("xiong", "Ð×ÐÖÐÙÐÚÐØÐÛÐÜ"),
    DICTS("xiu", "ËÞÐÝÐÞÐßÐàÐãÐåÐäÐâÐá"),
    DICTS("xu", "ÐçÐëÐéÐêÐèÐæÐìÐíÐñÐòÐðÐôÐ÷ÐøÐïÐöÐõÐîÓõ"),
    DICTS("xuan", "ÐùÐûÐúÐþÐüÐýÑ¡Ñ¢Ñ¤Ñ£"),
    DICTS("xue", "Ï÷Ñ¥Ñ¦Ñ¨Ñ§Ñ©Ñª"),
    DICTS("xun", "Ñ«Ñ¬Ñ°Ñ²Ñ®Ñ±Ñ¯Ñ­ÑµÑ¶Ñ´Ñ¸Ñ·Ñ³"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_y[] = {
    DICTS("y", "Ò»ÓÐÓÃÒªÒÔÓÚÒ²ÑùÒåÓëÓÉÑ¹Ô±ÔÂÒâÓÖÔËÔ­ÓÍÑé"),
    DICTS("ya", "Ñ¾Ñ¹Ñ½ÑºÑ»Ñ¼ÑÀÑ¿ÑÁÑÂÑÄÑÃÑÆÑÅÑÇÑÈ"),
    DICTS("yan", "ÑÊÑÌÑÍÑÉÑËÑÓÑÏÑÔÑÒÑØÑ×ÑÐÑÎÑÖÑÑÑÕÑÙÑÜÑÚÑÛÑÝÑáÑåÑâÑäÑçÑÞÑéÑèÑßÑæÑãÑà"),
    DICTS("yang", "ÑëÑêÑíÑìÑïÑòÑôÑîÑðÑñÑóÑöÑøÑõÑ÷ÑùÑú"),
    DICTS("yao", "½ÄÑýÑüÑûÒ¢Ò¦Ò¤Ò¥Ò¡Ò£ÑþÒ§Ò¨Ò©ÒªÒ«Ô¿"),
    DICTS("ye", "Ò¬Ò­Ò¯Ò®Ò²Ò±Ò°ÒµÒ¶Ò·Ò³Ò¹Ò´ÒºÒ¸"),
    DICTS("yi", "Ò»ÒÁÒÂÒ½ÒÀÒ¿Ò¼Ò¾ÒÇÒÄÒÊÒËÒÌÒÈÒÆÒÅÒÃÒÉÒÍÒÒÒÑÒÔÒÓÒÏÒÐÒÎÒåÒÚÒäÒÕÒéÒàÒÙÒìÒÛÒÖÒëÒØÒ×ÒïÒèÒßÒæÒêÒîÒÝÒâÒçÒÞÒáÒãÒíÒÜ"),
    DICTS("yin", "ÒòÒõÒöÒðÒñÒôÒóÒ÷ÒúÒùÒøÒüÒýÒûÒþÓ¡"),
    DICTS("ying", "Ó¦Ó¢Ó¤Ó§Ó£Ó¥Ó­Ó¯Ó«Ó¨Ó©ÓªÓ¬Ó®Ó±Ó°Ó³Ó²"),
    DICTS("yo", "Ó´"),
    DICTS("yong", "Ó¶ÓµÓ¸Ó¹ÓºÓ·ÓÀÓ½Ó¾ÓÂÓ¿ÓÁÓ¼Ó»ÓÃ"),
    DICTS("you", "ÓÅÓÇÓÄÓÆÓÈÓÉÓÌÓÊÓÍÓËÓÎÓÑÓÐÓÏÓÖÓÒÓ×ÓÓÓÕÓÔ"),
    DICTS("yu", "ÓØÓÙÓåÓÚÓèÓàÓÛÓãÓáÓéÓæÓçÓäÓâÓÞÓÜÓÝÓßÓëÓîÓìÓðÓêÓíÓïÓñÔ¦ÓóÓýÓôÓüÓøÔ¡Ô¤ÓòÓûÓ÷Ô¢ÓùÔ£ÓöÓúÓþÔ¥"),
    DICTS("yuan", "Ô©Ô§Ô¨ÔªÔ±Ô°Ô«Ô­Ô²Ô¬Ô®ÔµÔ´Ô³Ô¯Ô¶Ô·Ô¹ÔºÔ¸"),
    DICTS("yue", "Ô»Ô¼ÔÂÔÀÔÃÔÄÔ¾ÔÁÔ½"),
    DICTS("yun", "ÔÆÔÈÔÇÔÅÔÊÔÉÔÐÔËÔÎÔÍÔÏÔÌ"),
    { NULL, NULL },
};
static const ime_dicts_t dicts_z[] = {
    DICTS("z", "ÔÚÕâÖ÷ÖÐÖÖ×ÅÕùÕ½×÷ÕýÖ®ÖÆÖØ×éÖÎÖ»×Ó×ÔÖÊÖ¸"),
    DICTS("za", "ÔÑÔÓÔÒÕ¦"),
    DICTS("zai", "ÔÖÔÕÔÔÔ×ÔØÔÙÔÚ×Ð"),
    DICTS("zan", "ÔÛÔÜÔÝÔÞ"),
    DICTS("zang", "ÔßÔàÔá"),
    DICTS("zao", "ÔâÔãÔäÔçÔæÔéÔèÔåÔîÔíÔìÔëÔïÔê"),
    DICTS("ze", "ÔòÔñÔóÔð"),
    DICTS("zei", "Ôô"),
    DICTS("zen", "Ôõ"),
    DICTS("zeng", "ÔöÔ÷Ôù"),
    DICTS("zha", "ÔûÔüÔúÔýÔþÕ¢Õ¡Õ£Õ§Õ©Õ¨Õ¥×õ"),
    DICTS("zhai", "Õ«ÕªÕ¬µÔÕ­Õ®Õ¯"),
    DICTS("zhan", "Õ´Õ±Õ³Õ²Õ°Õ¶Õ¹ÕµÕ¸Õ·Õ¼Õ½Õ»Õ¾ÕÀÕ¿Õº"),
    DICTS("zhang", "³¤ÕÅÕÂÕÃÕÄÕÁÕÇÕÆÕÉÕÌÕÊÕÈÕÍÕËÕÏÕÎ"),
    DICTS("zhao", "ÕÐÕÑÕÒÕÓÕÙÕ×ÕÔÕÕÕÖÕØ×¦"),
    DICTS("zhe", "ÕÚÕÛÕÜÕÝÕÞÕßÕàÕâÕãÕá×Å"),
    DICTS("zhen", "ÕêÕëÕìÕäÕæÕèÕåÕçÕéÕïÕíÕîÕóÕñÕòÕðÖ¡"),
    DICTS("zheng", "ÕùÕ÷ÕúÕõÕøÕöÕôÕüÕûÕýÖ¤Ö£ÕþÖ¢"),
    DICTS("zhi", "Ö®Ö§Ö­Ö¥Ö¨Ö¦ÖªÖ¯Ö«Ö¬Ö©Ö´Ö¶Ö±ÖµÖ°Ö²Ö³Ö¹Ö»Ö¼Ö·Ö½Ö¸ÖºÖÁÖ¾ÖÆÖÄÖÎÖËÖÊÖÅÖ¿ÖÈÖÂÖÀÖÌÖÏÖÇÖÍÖÉÖÃ"),
    DICTS("zhong", "ÖÐÖÒÖÕÖÑÖÓÖÔÖ×ÖÖÖÙÖÚÖØ"),
    DICTS("zhou", "ÖÝÖÛÖßÖÜÖÞÖàÖáÖâÖãÖäÖæÖçÖåÖè"),
    DICTS("zhu", "ÖìÖïÖêÖéÖîÖíÖëÖñÖòÖðÖ÷ÖôÖóÖöÖõ×¡Öú×¢Öü×¤Öù×£ÖøÖûÖþÖý"),
    DICTS("zhua", "×¥"),
    DICTS("zhuai", "×§"),
    DICTS("zhuan", "×¨×©×ª×«×­"),
    DICTS("zhuang", "×±×¯×®×°×³×´´±×²"),
    DICTS("zhui", "×·×µ×¶×¹×º×¸"),
    DICTS("zhun", "×»×¼"),
    DICTS("zhuo", "×¿×¾×½×À×Æ×Â×Ç×Ã×Ä×Á"),
    DICTS("zi", "×Î×È×É×Ë×Ê×Í×Ì×Ñ×Ó×Ï×Ò×Ö×Ô×Õ"),
    DICTS("zong", "×Ú×Û×Ø×Ù×××Ü×Ý"),
    DICTS("zou", "×Þ×ß×à×á"),
    DICTS("zu", "×â×ã×ä×å×ç×è×é×æ"),
    DICTS("zuan", "×¬×ë×ê"),
    DICTS("zui", "×ì×î×ï×í"),
    DICTS("zun", "×ð×ñ"),
    DICTS("zuo", "×ò×ó×ô×÷×ø×ù×ö"),
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

//Çë×Ô¼ºÌí¼ÓÈÈ´Ê!
static const ime_terms_t terms_a[] =
{
    TERMS("ay", 2, "°¥Ñ½,°¢ÒÌ,°¾Ò¹,°¥ßÏ,°²ÒÝ,°´ÔÂ,°¡Ñ½"),
    RT_NULL,
};
static const ime_terms_t terms_b[] =
{
    TERMS("bm", 2, "±¦Âí"),
    RT_NULL,
};
static const ime_terms_t terms_c[] =
{
    TERMS("ces", 2, "²âÊÔ,²ÞËù,²âËã,²âËÙ,²ßÊ¿"),
    TERMS("ceshi", 2, "²âÊÔ,²ßÊ¿,²àÊÒ"),
    TERMS("cf", 2, "´¦·½"),
    TERMS("chuf", 2, "´¦·½,³ý·¨,´¦·£,³ö·¢,´¥·¢,³ý·Ç,³ø·¿,´¦·Ö"),
    TERMS("chufa", 2, "´¦·½,´¥·¢,³ö·¢,´¦·£,³ý·¨"),
    TERMS("chufan", 2, "´¦·½,´¥·¸,³õ·¸,³ö·¹"),
    TERMS("cfy", 3, "´¦·½Ò©"),
    TERMS("chufy", 3, "´¦·½Ò©"),
    TERMS("chufangy", 3, "´¦·½Ò©"),
    TERMS("chufang", 2, "´¦·½,³ø·¿,³ö·Ã,³õ·À"),
    TERMS("ck", 2, "²Î¿¼"),
    RT_NULL,
};
static const ime_terms_t terms_d[] =
{
    TERMS("dc", 2, "¶¯³µ"),
    RT_NULL,
};
static const ime_terms_t terms_e[] =
{
    TERMS("ey", 2, "öùÓã"),
    RT_NULL,
};
static const ime_terms_t terms_f[] =
{
    TERMS("fg", 2, "·¢¹â"),
    RT_NULL,
};
static const ime_terms_t terms_g[] =
{
    TERMS("gx", 2, "¸ßÐË,¸ãÐ¦,¸ßÐ§,¸ßÐÂ"),
    RT_NULL,
};
static const ime_terms_t terms_h[] =
{
    TERMS("hs", 2, "ºìÉ«,ºéË®"),
    RT_NULL,
};
static const ime_terms_t terms_j[] =
{
    TERMS("jd", 2, "¼¦µ°,¼òµ¥"),
    RT_NULL,
};
static const ime_terms_t terms_k[] =
{
    TERMS("kl", 2, "¿ìÀÖ,¿¼ÂÇ"),
    RT_NULL,
};
static const ime_terms_t terms_l[] =
{
    TERMS("ll", 2, "ÀíÂÛ,Á¦Á¿,ÁÄÁÄ"),
    RT_NULL,
};
static const ime_terms_t terms_m[] =
{
    TERMS("mb", 2, "Ã÷°×,Ä¿±ê,Ãæ°ü"),
    RT_NULL,
};
static const ime_terms_t terms_n[] =
{
    TERMS("nn", 2, "ÄãÄØ,ÄÐÅ®"),
    RT_NULL,
};
static const ime_terms_t terms_o[] =
{
    TERMS("oo", 2, "Å¶Å¶,àÞàÞ"),
    RT_NULL,
};
static const ime_terms_t terms_p[] =
{
    TERMS("pp", 2, "Æ¥Åä,ÆÅÆÅ"),
    RT_NULL,
};
static const ime_terms_t terms_q[] =
{
    TERMS("qq", 2, "ÇëÇó,Ç°ÆÚ"),
    RT_NULL,
};
static const ime_terms_t terms_r[] =
{
    TERMS("rm", 2, "ÈËÃñ,ÈËÃÇ"),
    RT_NULL,
};
static const ime_terms_t terms_s[] =
{
    TERMS("ss", 2, "ÊÔÊÔ,ÊÂÊµ"),
    RT_NULL,
};
static const ime_terms_t terms_t[] =
{
    TERMS("td", 2, "Í¨µÀ,Ì¬¶È"),
    RT_NULL,
};
static const ime_terms_t terms_w[] =
{
    TERMS("wm", 2, "ÎÒÃÇ,ÍâÃæ"),
    RT_NULL,
};
static const ime_terms_t terms_x[] =
{
    TERMS("xw", 2, "Ï£Íû,ÐÐÎª"),
    TERMS("xz", 2, "ÏÖÔÚ,ÏÂÔØ"),
    RT_NULL,
};
static const ime_terms_t terms_y[] =
{
    TERMS("yx", 2, "Ò»ÏÂ,ÓÎÏ·"),
    RT_NULL,
};
static const ime_terms_t terms_z[] =
{
    TERMS("zhrm", 4, "ÖÐ»ªÈËÃñ,×ß»ðÈëÄ§"),
    TERMS("zhrmghg", 7, "ÖÐ»ªÈËÃñ¹²ºÍ¹ú,"),
    TERMS("zhrmghggg", 9, "ÖÐ»ªÈËÃñ¹²ºÍ¹ú¹ú¸è,"),
    TERMS("zd", 2, "×Öµä,ÖÐ¶Ï,ÕÒµ½,Õë¶Ô,×Ô¶¯"),
    TERMS("zx", 2, "Ö´ÐÐ,Ö÷Ï¯,ÕâÐ©,×ÜÏß,ÏÖÔÚ,ÖÐÐÄ,×îÐÂ,×ÉÑ¯,×ÐÏ¸,×ÔÐÐ,Ö»Ðè,ÔÚÏß,×°ÐÞ,ÖÐÑ§"),
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

//Í³¼ÆÒÔ','·Ö¸ôµÄ´ÊÓïµÄÌõÊý
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

//È¥³ý×Ö·û´®ÖÐÖ¸¶¨µÄ×Ö·û
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
    {   //ÌÞ³ýÎÞÐ§Æ´Òô,Ö»ÅÐ¶ÏÇ°Á½¸ö×ÖÄ¸,ÔÙ¶à¾ÍÓëÈ«¼ìË÷Ò»±éµÄÐ§ÂÊ²î²»¶àÁË
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

    if (ime->zhlen == 0) //ÔÚ"×Öµä"ÖÐÎ´ÕÒµ½,ÔÙ²éÕÒ"´Êµä"
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
    //ÖÁ´ËÒ²Ã»ÓÐÕÒµ½ÍêÈ«Æ¥ÅäµÄ´Ê»ã,ÄÇÃ´³¢ÊÔËÑË÷¼üÈëµÄpinyinÖÐÊÇ·ñÓÐÍêÕûÆ´Òô,Èç¹ûÓÐ,Ê¹ÓÃ×Ö¿â
    //ÀýÈçÊäÈëµÄÊÇcesh,Ã»ÊäÈëÍê,ÕâÊ±Ã»ÓÐÍêÈ«Æ¥ÅäµÄcesh×Ö¿â,Ò²Ã»ÓÐ¶ÔÓ¦µÄcesh´Ê¿â,ÎóÈÏÎªÕÒ²»µ½½á¹û,
    //´ËÊ±ÏÔÊ¾ceµÄ×Ö¿â±È½ÏºÏÀí,ËÑË÷µÄÐ§ÂÊ»áºÜµÍ,¼´Ò»Ò»³¢ÊÔÆ¥ÅäÍêÕûÆ´Òô!
    match_count = ime->inlen - 1;//´Ó"´Î×î³¤"Æ¥Åä!
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
    char S[32];//´ÊÓï×ÖÊýÏÞ¶¨ÔÚ9¸ö,ÁôµãÔ£Á¿
    int i;

    ime->wordstr[0] = '\0';//Ö»ÓÃ×÷×Ö·û´®
    if (ime->zhlen == 0) return;

    if (ime->type == IME_TYPE_DICTS) //×Öµä
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
    else //if(ime->type==IME_TYPE_TERMS) ´Êµä
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
    if (ime->type == IME_TYPE_DICTS) //×Öµä
    {
        rt_uint16_t *p = (rt_uint16_t*)ime->zhptr;
        p += ime->page_index * IME_WPP;
        rt_memcpy(zhstr, p + index, 2);
        zhstr[2] = '\0';
    } 
    else //if(ime->type==IME_TYPE_TERMS) ´Êµä
    {
        char *p = ime->zhptr;
        p += ime->page_index * (ime->cnt_per_page * (ime->wordcnt * 2 + 1));
        rt_memcpy(zhstr, p + (ime->wordcnt * 2 + 1)*index, ime->wordcnt * 2);
        zhstr[ime->wordcnt * 2] = '\0';
    }
}

void pinyin_getin_letter(ime_pinyin_t *ime, char c)
{
    if(ime->inlen >= 9) return; //×î´óÔÊÐí¼üÈë9¸ö
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
