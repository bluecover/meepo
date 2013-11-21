/***********************************************************************
    filename:   CDCCache.h
    created:    2011/12/17
    author:     ZhaoHao
*************************************************************************/
#pragma once

#include <windows.h>

namespace Meepo
{

// HDC ������ƣ�ժ�� ATL CImage ��Ĵ���

class CDCCache
{
public:
	CDCCache();
	~CDCCache();

	HDC  GetDC();
	void ReleaseDC(HDC hdc);

private:
	enum  { DC_CACHE_SIZE = 20 };
	HDC m_HDCs[DC_CACHE_SIZE];
};

}