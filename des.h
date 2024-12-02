#ifndef DES_H
#define DES_H

#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

/**
 *子密钥
*/
extern std::string desKeys[20];

/**
*数据初始置换表
*/
extern int T1[8][8];

/**
*密钥初始置换表
*/
extern int T2[8][7];

/**
*密钥循环左移位数表
*/
extern int T3[16];

/**
*密钥压缩置换表
*/
extern int T4[8][6];

/**
*数据扩展表
*/
extern int T5[8][6];

/**
*S盒置换表
*/
extern int S[8][4][16];

/**
*P盒置换表
*/
extern int P[4][8];


/**
*最终置换表
*/
extern int T6[8][8];

/**
*最终置换函数 64位->64位
*函数说明：s为完成最后一轮循环得到的64为数据
*返回值为密文或明文
*/
std::string final_permutation(std::string s);

/**
*P盒置换函数 32位->32位
*函数说明：s为S盒的输出
*/
std::string P_box(std::string s);

/**
*S盒置换函数 48位->32位
*函数说明：s为48位数据
*返回值为32位
*/
std::string S_box(std::string s);

/**
*异或运算函数
*要求位数相同
*/
std::string desXOR(std::string s1, std::string s2);

/**
*数据扩展函数 32->48
*函数说明：s为数据的右半部分 32位
*扩展成48位的输出
*/
std::string plaintext_righthalf_extended_permutation(std::string s);

/**
*密钥压缩置换函数 56位->48位
*函数说明：s为56为的密钥
*输出为48位的子密钥
*/
std::string secret_key_compression_replacement(std::string s);

/**
*密钥循环左移函数 56位->56位
*函数说明：k为左移位数 s为密钥
*返回值位数不变
*/
std::string secret_ket_left_move(int k, std::string s);

/**
*密钥初始置换函数 64位->56位
*函数说明：s为64位的初始密钥
*返回值为56位
*/
std::string secret_key_initial_permutation(std::string s);

/**
*明文初始置换函数 64位->64位
*函数说明：s为初始明文 64位
*返回值为6位
*/
std::string plaintext_initial_permutation(std::string s);

/**
*16进制转2进制函数
*函数说明：s为16进制字符串
*返回为2进制字符串
*/
std::string des_H(std::string s);

/**
*2进制转16进制函数
*str为2进制字符串
*返回值为16进制字符串
*/
std::string des_G(std::string str);

/**

*封装函数f
*str1:32位数据 str2:48位的子密钥
*函数说明：接收32位数据和48位的子密钥 产生一个32位的输出
*/
std::string des_f(std::string str1, std::string str2);


/**
*子密钥生成函数
*函数说明：s为给定的密钥
*生成16个子密钥
*/
void des_generateKeys(std::string s);

/**
*明文字符串转换成0/1字符串
*/
std::string des_StrToBitStr(std::string str);

/**
*0/1字符串装换为字符形式的字符串
*/
std::string des_BitStrToStr(std::string bstr);

std::string chardeel(std::string& str1);

/**
*DES加密函数
*函数说明：str1为64位的给定明文
*返回值为64位的密文*/
std::string des_encrypt(std::string str1, std::string str2);

/**
*解密函数
*str1为密文 str2为密钥
*输出明文*/
std::string des_decrypt(std::string str,std::string str2);
#endif // DES_H
