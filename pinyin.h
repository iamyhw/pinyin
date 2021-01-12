#ifndef __PINYIN_H__
#define __PINYIN_H__

#include <rtthread.h>

#define IME_TYPE_DICTS  0 //字典
#define IME_TYPE_TERMS  1 //词典

#define IME_INLEN_MAX   16
#define IME_WORDSTR_SZ  64
//每页的最多字数是固定的,每页的最多词数根据词语的长度调整
#define IME_WPP         9   //Words Per Page

typedef struct rtgui_dict
{
    char *pin;  //拼音
    rt_uint16_t *hz; //对应的汉字,可以是多个
    rt_uint16_t len; //字数
}ime_dicts_t;

typedef struct rtgui_terms
{
    char *pin;  //拼音
    rt_uint16_t cnt; //词语字数
    rt_uint16_t *ci; //词语,词与词之间用'逗号'分割
    rt_uint16_t len; //词数
}ime_terms_t;

typedef struct ime_pinyin
{
    rt_uint16_t     type;    //查找的是字典还是词典
    ime_dicts_t     *dicts;  //字典列表
    ime_terms_t     *terms;  //词典列表
    rt_uint16_t     inlen, zhlen;   //输入拼音的长度,字库数据的长度
    rt_uint16_t     wordcnt; //字的个数
    rt_uint16_t     cnt_per_page; //只用于词典
    rt_uint16_t     cnt_cur_page;
    rt_uint16_t     page_index; //页索引
    rt_uint16_t     page_numbs; //总页数
    char            *zhptr;
    char            inbuf[IME_INLEN_MAX]; //最多用到9个
    char            wordstr[IME_WORDSTR_SZ]; //待选词条字符串
}ime_pinyin_t;

void pinyin_getout_zhstring(ime_pinyin_t *ime, char *zhstr, int index);
void pinyin_generate_page(ime_pinyin_t *ime);
void pinyin_getin_letter(ime_pinyin_t *ime, char c);
void pinyin_backspace(ime_pinyin_t *ime);
void pinyin_page_add(ime_pinyin_t *ime);
void pinyin_page_sub(ime_pinyin_t *ime);
void pinyin_init(ime_pinyin_t *ime);

#endif
