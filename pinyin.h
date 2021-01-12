#ifndef __PINYIN_H__
#define __PINYIN_H__

#include <rtthread.h>

#define IME_TYPE_DICTS  0 //�ֵ�
#define IME_TYPE_TERMS  1 //�ʵ�

#define IME_INLEN_MAX   16
#define IME_WORDSTR_SZ  64
//ÿҳ����������ǹ̶���,ÿҳ�����������ݴ���ĳ��ȵ���
#define IME_WPP         9   //Words Per Page

typedef struct rtgui_dict
{
    char *pin;  //ƴ��
    rt_uint16_t *hz; //��Ӧ�ĺ���,�����Ƕ��
    rt_uint16_t len; //����
}ime_dicts_t;

typedef struct rtgui_terms
{
    char *pin;  //ƴ��
    rt_uint16_t cnt; //��������
    rt_uint16_t *ci; //����,�����֮����'����'�ָ�
    rt_uint16_t len; //����
}ime_terms_t;

typedef struct ime_pinyin
{
    rt_uint16_t     type;    //���ҵ����ֵ仹�Ǵʵ�
    ime_dicts_t     *dicts;  //�ֵ��б�
    ime_terms_t     *terms;  //�ʵ��б�
    rt_uint16_t     inlen, zhlen;   //����ƴ���ĳ���,�ֿ����ݵĳ���
    rt_uint16_t     wordcnt; //�ֵĸ���
    rt_uint16_t     cnt_per_page; //ֻ���ڴʵ�
    rt_uint16_t     cnt_cur_page;
    rt_uint16_t     page_index; //ҳ����
    rt_uint16_t     page_numbs; //��ҳ��
    char            *zhptr;
    char            inbuf[IME_INLEN_MAX]; //����õ�9��
    char            wordstr[IME_WORDSTR_SZ]; //��ѡ�����ַ���
}ime_pinyin_t;

void pinyin_getout_zhstring(ime_pinyin_t *ime, char *zhstr, int index);
void pinyin_generate_page(ime_pinyin_t *ime);
void pinyin_getin_letter(ime_pinyin_t *ime, char c);
void pinyin_backspace(ime_pinyin_t *ime);
void pinyin_page_add(ime_pinyin_t *ime);
void pinyin_page_sub(ime_pinyin_t *ime);
void pinyin_init(ime_pinyin_t *ime);

#endif
