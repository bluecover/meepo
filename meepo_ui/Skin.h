/***********************************************************************
    filename:   Skin.h
    created:    2012/6/2
    author:     ZhaoHao
*************************************************************************/
#pragma once

#include "PreHeader.h"
#include "GdiplusHeader.h"
#include "DCCache.h"

namespace Meepo
{

// CSkin 
// �� Gdiplus �е� Image ����һ���װ
// 1. ���ڴ�����һ�����棬��ʼ��ʱ��ͼ����Ƶ�������������ƶ�ʹ�û��棬�Ӷ���߻���Ч��
// 2. ֧�ֻ���ͬһ��ͼƬ�Ĳ�ͬ����

enum EStretchMode
{
    Stretch_Mode_Default,
    Stretch_Mode_Fixed,
    Stretch_Mode_X,
    Stretch_Mode_Y,
    Stretch_Mode_XY,
    Stretch_Mode_Tiled
};

class CStretchOption
{	
public:
    CStretchOption() 
		: m_stretchMode(Stretch_Mode_Default), m_nLeft(0), m_nRight(0), m_nTop(0), m_nBottom(0) 
	{}

    EStretchMode m_stretchMode;
    int m_nLeft;
    int m_nRight;
    int m_nTop;
    int m_nBottom;
};

class CSkin
{
public:
	CSkin();
	~CSkin();

	Gdiplus::Image* GetGdiplusImage() { return m_pGdiplusImage; }
	int GetWidth() const;
	int GetHeight() const;
	bool HasAlphaChannel() const;
	void Load(const StdStringW& strImageFilePath);
    void Load(CRawData& rawData);
	void Draw(HDC hdc, int xDest, int yDest, int destWidth, int destHeight, int xSrc, int ySrc, int srcWidth, int srcHeight, const CStretchOption& stretchOption, int alpha = 255);

private:
    void Init();
	void DrawFixed(HDC destDC, int xDest, int yDest, int xSrc, int ySrc, int srcWidth, int srcHeight, int alpha);
	void DrawFixedYStretchX(HDC destDC, int xDest, int yDest, int destWidth, int destHeight, int xSrc, int ySrc, int srcWidth, int srcHeight, const CStretchOption& stretchOption, int alpha);
	void DrawFixedXStretchY(HDC destDC, int xDest, int yDest, int destWidth, int destHeight, int xSrc, int ySrc, int srcWidth, int srcHeight, const CStretchOption& stretchOption, int alpha);
	void DrawFixedStretchXY(HDC destDC, int xDest, int yDest, int destWidth, int destHeight, int xSrc, int ySrc, int srcWidth, int srcHeight, const CStretchOption& stretchOption, int alpha);
	void TransferBits(HDC destDC, int xDest, int yDest, int destWidth, int destHeight, HDC srcDC, int xSrc, int ySrc, int srcWidth, int srcHeight, int alpha);

	Gdiplus::Image*	m_pGdiplusImage;

	HBITMAP			m_hBitmapBuffer;
	HDC				m_hDCBuffer;
	HBITMAP			m_hOldBitmapOfDCBuffer;

	int				m_nWidth;
	int				m_nHeight; 

	static CDCCache ms_dcCache;
};

}
