# pinyin

## 1、介绍

这是一个中文的拼音输入法,基于快速的字典/词典检索算法而实现.

### 1.1 目录结构

| 名称 | 说明 |
| ---- | ---- |
| pinyin.c | 输入法源文件 |
| pinyin.h | 输入法头文件 |

### 1.2 许可证

pinyin package 遵循 LGPLv2.1 许可，详见 `LICENSE` 文件。

### 1.3 依赖

对操作系统无依赖, 对硬件平台无依赖, 对硬件资源Flash空间有需求(取决于字典大小), RAM不小于1K!

## 2、如何打开 pinyin

使用 pinyin package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    miscellaneous packages --->
        [*] A Chinese Pinyin input method.
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 pinyin

在打开 pinyin package 后，当进行 bsp 编译时，它会被加入到 bsp 工程中进行编译。

### 3.1、创建拼音输入法对象
```
static input_method_t imepy;
```
### 3.2、初始化对象
```
//void pinyin_init(input_method_t *ime);
pinyin_init(&imepy);
```
### 3.3、给输入法对象传入拼音字符串
```
//void pinyin_getin_letter(input_method_t *ime, char c);
pinyin_getin_letter(&imepy, c);
```
参数c: 取值字母 a-z,A-Z

### 3.4、通过对象的一些成员变量获取检索结果
|对象成员           |描述                     |
|-------------------|-------------------------|
|imepy.type         |当前检索的是字库还是词库 | 
|imepy.dicts        |字库指针                 | 
|imepy.terms        |词库指针                 |
|imepy.zhlen        |检索到的数据的长度       |
|imepy.wordcnt      |检索到的数据的字词个数   | 
|imepy.page_numbs   |待选条目页数             |
|imepy.page_index   |待选条目页索引           |
|imepy.cnt_per_page |每页待选条目数量         |
|imepy.cnt_cur_page |当前页待选条目数量       |
|imepy.inbuf[]      |存放着录入的拼音字符串   |
|imepy.zhbuf[]      |存放着检索到的数据       |
|imepy.wordstr      |带编号的待选条目         |
|imepy.s[9][20]     |不带编号的待选条目       |

(1)wordstr中的数据组织为 1.只 2.置 3.值 4.至 5.止 6.肢 7.之 8.指 9.直 //字典
   数组s[]中的数据组织为 [只] [置] [值] [至] [止] [肢] [之] [指] [直]

(2)wordstr中的数据组织为 1.上海 2.伤害 3.商户 4.商会 5.上火 6.上号 //词典
   数组s[]中的数据组织为 [上海] [伤害] [商户] [商会] [上火] [上号]

这样的组织形式非常方便与GUI系统对接, 用户可以显示imepy.wordstr到GUI.
如果仅仅处理数据,可以使用impy.s[].

### 3.5、获取字或词
```
//void pinyin_getout_zhstring(input_method_t *ime, char *zhstr, int index);
rt_uint16_t zh[16] = {0};
pinyin_getout_zhstring(&imepy, zh, 3); //以上面(1)例子为例,返回"至"
```
这个接口函数就是直接取的imepy.s[3]的值.
区别是使用接口函数时,参数*zhstr可以传入外部缓冲地址,便于应用中使用,

### 3.6、翻页待选条目
使用下面这两个接口函数进行翻页,如果存在多页的话!
```
void pinyin_page_add(input_method_t *ime); //加一页,类似右翻页
void pinyin_page_sub(input_method_t *ime); //减一页,类似左翻页
```
如果调用了翻页接口函数了,可以再调用下面的函数更新page内容
```
void pinyin_generate_page(input_method_t *ime);
```
如果用户自己重新实现了翻页功能,需要手动调用该函数刷新page!

### 3.6、取消输入的拼音
可以调用下面的接口函数对输入的字符串退格,即去除最后一个录入,一次只能取消一个字符.
```
void pinyin_backspace(input_method_t *ime);
```

### 3.7、pinyin输入法支持的字词典数据格式
pinyin输入法可以同时支持字典和词典数据结构.
|字典|一个拼音|对应多个字|支持定长编码,如GB码      |
|词典|一个拼音|对应多个词|词语长度不限,以'逗号'分隔|

## 4、注意事项
一般字典是固定的,词典可以灵活设置,需要注意词典的词条总长度,防止zhbuf[]溢出
一个词语的长度(字数)也与s[9][20]有关系,默认可以安全处理9个字长的词条,
如果最大词条长度超过9个字,应该增大s[]数组,例如s[9][50].

## 5、联系方式 & 感谢

* 维护：iamyhw
* 主页：https://github.com/RT-Thread-packages/pinyin
