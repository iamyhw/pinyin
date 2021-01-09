#ifndef __PINYIN_H__
#define __PINYIN_H__

#include <rtthread.h>

#define IME_TYPE_DICTS  0 //�ֵ�
#define IME_TYPE_TERMS  1 //�ʵ�

#define IME_INLEN_MAX   16
#define IME_ZHBUF_MAX   256
#define IME_WORDSTR_SZ  128
//ÿҳ����������ǹ̶���,ÿҳ�����������ݴ���ĳ��ȵ���
#define IME_WPP         9   //Words Per Page

typedef struct ime_dicts
{
    char *pin;  //ƴ��
    rt_uint16_t *hz; //��Ӧ�ĺ���,�����Ƕ��
} ime_dicts_t;

typedef struct ime_terms
{
    char *pin;  //ƴ��
    rt_uint16_t cnt; //��������
    rt_uint16_t *ci; //����,�����֮����'����'�ָ�
} ime_terms_t;

typedef struct input_method
{
    rt_uint16_t  type;    //���ҵ����ֵ仹�Ǵʵ�
    ime_dicts_t  *dicts;  //�ֵ��б�
    ime_terms_t  *terms;  //�ʵ��б�
    rt_uint16_t  inlen, zhlen;   //�������ĳ���,�ֿ�ĳ���
    rt_uint16_t  wordcnt; //�ֵĸ���
    rt_uint16_t  cnt_per_page; //ֻ���ڴʵ�
    rt_uint16_t  cnt_cur_page;
    rt_uint16_t  page_index; //ҳ����
    rt_uint16_t  page_numbs; //��ҳ��
    char         inbuf[IME_INLEN_MAX]; //����õ�9��
    rt_uint16_t  zhbuf[IME_ZHBUF_MAX]; //�������110��,ע�����ĸ���!
    char         wordstr[IME_WORDSTR_SZ]; //��ѡ�����ַ���
    char         s[9][20];//��ѡ�ִ�,�̶����9��
} input_method_t;

void pinyin_getout_zhstring(input_method_t *ime, char *zhstr, int index);
void pinyin_generate_page(input_method_t *ime);
void pinyin_getin_letter(input_method_t *ime, char c);
void pinyin_backspace(input_method_t *ime);
void pinyin_page_add(input_method_t *ime);
void pinyin_page_sub(input_method_t *ime);
void pinyin_init(input_method_t *ime);

#endif
