/***********************************************************************
    filename:   RawData.h
    created:	2012/6/2
    author:     ZhaoHao
*************************************************************************/
#pragma once

#include <windows.h>

namespace Meepo
{
// Ϊ�˷���ʹ�ã�����һ��load�ڴ����ݵ�wrapper
class CRawData
{
public:
	CRawData() : m_pBuf(0), m_nSize(0) {}

	virtual void* Alloc(unsigned int size) = 0;
	virtual void Dealloc() = 0;

	void* GetBuf();
	unsigned int GetSize();
	char& operator[](int index);


protected:
	void* m_pBuf;
	unsigned int m_nSize;
};

// ʹ�� operator new ���õ�����
class CHeapData : public CRawData
{
public:
	~CHeapData();
	virtual void* Alloc(unsigned int size);
	virtual void Dealloc();
};

// ʹ�� GlobalAlloc ���õ�����
class CGlobalData : public CRawData
{
public:
	CGlobalData();
	~CGlobalData();
	virtual void* Alloc(unsigned int size);
	virtual void Dealloc();

private:
	HGLOBAL m_hGlobal;
};

}
