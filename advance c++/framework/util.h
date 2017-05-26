#pragma once
#ifndef _UNIL_H_
#define _UNIL_H_

#define BIT_CHK( V, N ) (((unsigned char*)V)[N>>3] & (1 << (7-(N&7))))
#define BIT_SET( V, N ) (((unsigned char*)V)[N>>3] |= (1 << (7-(N&7))))
#define BIT_CLR( V, N ) (((unsigned char*)V)[N>>3] &= (~(1 << (7-(N&7)))))

void wait_key( int key );

///
/// \brief 将二进制数据转为16进制字符串
///
/// \param data	数据首址
/// \param size	数据长度（按字符计）
/// \param out 输出缓冲首址
/// \param out_size 缓冲区长度（按字符计）
/// \param flags 标志 （未定义）
/// \return 返回转换了多少字符
///
/// \author albert.xu
/// \date 2015/12/16 17:00
///
size_t bin2hex( char* data, size_t size, char* out, size_t out_size, size_t flags );


#endif // _UNIL_H_