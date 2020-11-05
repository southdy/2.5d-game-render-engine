/* -------------------------------------------------------------------------
//	�ļ���		��	shell_t.h
//	������		��	fenghewen
//	����ʱ��	��	2009-11-26 11:11:11
//	��������	��	shell�Ļ��ඨ�壬������Ⱦ���ֵ���ǣ������ṩ���ֹ��ܽӿ�
//
// -----------------------------------------------------------------------*/
#ifndef __SHELL_H__
#define __SHELL_H__
#include "../represent_common/common.h"

struct KRepresentConfig;

//shell
struct KPRIMITIVE_INDEX
{
	UINT	uImage;		// ͼ��ID
	INT		nFrame;		// ͼ��֡���
	INT		nRenderStyle;
};

struct KPRIMITIVE_INDEX_LIST
{
	KPRIMITIVE_INDEX		sIndex;	// ͼԪ��������
	KPRIMITIVE_INDEX_LIST*	pNext;
};

class IKShell
{
public:
	struct KLight
	{
		INT		m_nX,m_nY,m_nZ;
		DWORD   m_dwColor;
		INT	    m_nRadius;
	};
	virtual void	Release() = 0;
	virtual bool	Create(HWND hWnd, int nWidth, int nHeight, bool& bFullScreen, const KRepresentConfig* pRepresentConfig) = 0;
	virtual bool	Reset(int nWidth, int nHeight, bool bFullScreen, bool bNotAdjustStyle = true) = 0;
	virtual void*	Get3DDevice() = 0;
	virtual bool	OverLoad() = 0;
	virtual bool	CreateAFont(LPCSTR pszFontFile, DWORD CharaSet, int nId) = 0;
	virtual void	OutputText(int nFontId, const WCHAR* psText, int nCount = -1, int nX = (-2147483647 - 1), int nY = (-2147483647 - 1), DWORD Color = 0xff000000, int nLineWidth = 0, int nZ = -32767, DWORD BorderColor = 0, const RECT* pClipRect = 0) = 0;
	virtual DWORD	SetAdjustColorList(DWORD* puColorList, DWORD uCount) = 0;
	virtual int		OutputRichText(int nFontId, void* pParam, const WCHAR* psText, int nCount = -1, int nLineWidth = 0, const RECT* pClipRect = 0) = 0;
	virtual int		LocateRichText(int nX, int nY, int nFontId, void* pParam, LPCSTR psText, int nCount = -1, int nLineWidth = 0) = 0;
	virtual void	ReleaseAFont(int nId) = 0;
	virtual DWORD	CreateImage(LPCSTR pszName, int nWidth, int nHeight, DWORD nType) = 0;
	virtual void	FreeImage(LPCSTR pszImage) = 0;
	virtual void	FreeAllImage() = 0;
	virtual void*	GetBitmapDataBuffer(LPCSTR pszImage, void* pInfo) = 0;
	virtual void	ReleaseBitmapDataBuffer(LPCSTR pszImage, void* pBuffer) = 0;
	virtual bool	GetImageParam(LPCSTR pszImage, void* pImageData, DWORD nType, bool no_cache = false) = 0;
	virtual bool	GetImageFrameParam(LPCSTR pszImage, int nFrame, KPOINT* pOffset, KPOINT* pSize, DWORD nType, bool no_cache = false) = 0;
	virtual int		GetImagePixelAlpha(LPCSTR pszImage, int nFrame, int nX, int nY, int nType) = 0;
	virtual HRESULT ConverSpr(char* pFileName, char* pFileNameTo, int nType) = 0;
	virtual void	SetImageStoreBalanceParam(int nNumImage, DWORD uCheckPoint = 1000) = 0;
	// ����ÿ֡�������ļ�����
	// nNumOfTask ÿ֡����ý��ĸ���
	virtual VOID	SetTaskLimit(UINT uNumOfTask) = 0;
	// ����ý�建��ռ�����
	// uSize �������� ����λM��
	virtual VOID	SetMediaSpaceLimit(UINT uSize) = 0;
	// ����ý�建��ʱ��
	// uSize ����ʱ�� ����λ�룩
	virtual VOID	SetMediaTimeLimit(UINT uSize) = 0;
	virtual void	DrawPrimitives(int nPrimitiveCount, void* pPrimitives, DWORD uGenre, int bSinglePlaneCoord, KPRIMITIVE_INDEX_LIST** pStandBy = 0) = 0;
	virtual void	DrawPrimitivesOnImage(int nPrimitiveCount, void* pPrimitives, DWORD uGenre, LPCSTR pszImage, DWORD uImage, DWORD& nImagePosition, int bForceDrawFlag = false) = 0;
	virtual void	ClearImageData(LPCSTR pszImage, DWORD uImage, DWORD nImagePosition) = 0;
	virtual bool	ImageNeedReDraw(char* szFileName, DWORD& uImage, DWORD& nPos, int& bImageExist) = 0;
	virtual void	LookAt(int nX, int nY, int nZ, int nAdj) = 0;
	virtual void	LookAtEx(D3DXVECTOR3& vecCamera, D3DXVECTOR3& vecLookAt) = 0;
	virtual bool	CopyDeviceImageToImage(LPCSTR pszName, int nDeviceX, int nDeviceY, int nImageX, int nImageY, int nWidth, int nHeight) = 0;
	virtual bool	RepresentBegin(int bClear, DWORD Color) = 0;
	virtual void	RepresentEnd() = 0;
	virtual void	AddLight(KLight Light) = 0;
	virtual void	ViewPortCoordToSpaceCoord(int& nX,	int& nY, int nZ) = 0;
	virtual int		AdviseRepresent(void*) = 0;
	virtual int		UnAdviseRepresent(void*) = 0;
	virtual bool	SaveScreenToFile(LPCSTR pszName, DWORD eType, DWORD nQuality) = 0;
	virtual int		GetRepresentParam(DWORD lCommand, int& lParam, DWORD& uParam) = 0;
	virtual int		SetRepresentParam(DWORD lCommand, int lParam, DWORD uParam) = 0;
	virtual void*	CreateRepresentObject(DWORD uGenre, LPCSTR pObjectName, int nParam1, int nParam2) = 0;
	virtual void*	Create3DEffectObject(LPCSTR szFileName) = 0;
	virtual void*	Create3DEffectObjectEx(LPCSTR szFileName) = 0;
	virtual void*	GetJpgImage(const char cszName[], unsigned uRGBMask16 = ((unsigned)-1)) = 0;
	virtual void	ReleaseImage(void* pImage) = 0;
	virtual void	ReleaseImage(char* pszImage) = 0;
	virtual int		PreLoad(DWORD uType, const char cszName[], int nReserve) = 0;
	virtual void	ReleaseAllImages() = 0;
	// ���õ�ǰ¼�񲥷��� 
	virtual void	SetJxPlayer(IJXReplay* pJxPlayer) = 0;
	// ���õ�ǰ�ǵڼ�֡
	virtual void	SetCurFrame(int nCurFrame) = 0;
	// ���õ�ǰ�ǵڼ�֡, �͵�ǰ¼�����״̬��֮����Ҫ�������������Ϊ�˱�������ڲ��ܼ�ʱ����ʱ�ᵼ�³����������
	virtual void	SetCurFrame(int nCurFrame, int nJxReplayerState) = 0;
	//zjq add 09.2.9	��¶ddraw��dds���ⲿʹ��
#ifdef _SNDA_IGW_
	virtual LPDIRECTDRAW GetIDirectDraw() = 0;
	virtual LPDIRECTDRAWSURFACE GetIDirectDrawSurface() = 0;
	virtual D3DPRESENT_PARAMETERS* GetD3DRepresentParam() = 0;
#endif
	//end add
};

#endif