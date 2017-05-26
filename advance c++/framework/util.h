#pragma once
#ifndef _UNIL_H_
#define _UNIL_H_

#define BIT_CHK( V, N ) (((unsigned char*)V)[N>>3] & (1 << (7-(N&7))))
#define BIT_SET( V, N ) (((unsigned char*)V)[N>>3] |= (1 << (7-(N&7))))
#define BIT_CLR( V, N ) (((unsigned char*)V)[N>>3] &= (~(1 << (7-(N&7)))))

void wait_key( int key );

///
/// \brief ������������תΪ16�����ַ���
///
/// \param data	������ַ
/// \param size	���ݳ��ȣ����ַ��ƣ�
/// \param out ���������ַ
/// \param out_size ���������ȣ����ַ��ƣ�
/// \param flags ��־ ��δ���壩
/// \return ����ת���˶����ַ�
///
/// \author albert.xu
/// \date 2015/12/16 17:00
///
size_t bin2hex( char* data, size_t size, char* out, size_t out_size, size_t flags );


#endif // _UNIL_H_