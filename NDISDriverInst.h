//ʹ��ʱ��Ĭ�����Ӿ�̬�⣬��Ҫ���Ӷ�̬�⣬���ڰ�����ͷ�ļ�ǰ�����NDIS_INST_IMPORT_DYN
#ifndef _NDIS_DRIVER_INST_H_INCLUDED
#define _NDIS_DRIVER_INST_H_INCLUDED



#if defined(_NDIS_INST_EXPORTS_STATIC)//���뾲̬��
#define NDIS_DRIVER_INST_API

#elif defined(_NDIS_INST_EXPORTS_DYN)//���붯̬��
#define NDIS_DRIVER_INST_API _declspec(dllexport)

#elif defined(NDIS_INST_IMPORT_DYN)//ʹ�ö�̬��
#define NDIS_DRIVER_INST_API _declspec(dllimport)
#if defined(_DEBUG) || defined(DEBUG)
#pragma comment(lib, "NDISDriverInst_d.lib")
#else
#pragma comment(lib, "NDISDriverInst.lib")
#endif

#else//ʹ�þ�̬��(Ĭ��)
#define NDIS_DRIVER_INST_API
#pragma comment(lib, "Setupapi.lib")
#if defined(_DEBUG) || defined(DEBUG)
#pragma comment(lib, "NDISDriverInstLib_d.lib")
#else//if defined(_DEBUG) || defined(DEBUG)
#pragma comment(lib, "NDISDriverInstLib.lib")
#endif//if defined(_DEBUG) || defined(DEBUG)

#endif//if defined(_NDIS_INST_EXPORTS_STATIC)



#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
typedef __success(return >= 0) long HRESULT;
#endif // !_HRESULT_DEFINED


#if !defined(S_OK)
#define S_OK (0L)
#endif



#ifdef __cplusplus
extern "C"
{
#endif

    /*
    ˵����HRESULT�����ľ��������Ϣ����ʹ��_com_error������ȡ
        �������е���FormatMessage��ȡ
        �򵥵ģ�S_OK��ʾ�ɹ��������ʾ����
    */

    enum NDIS_INST_STATE
    {
        NDIS_INSTALLED,
        NDIS_NOT_INSTALLED,
        NDIS_QUERY_ERROR,
    };

    //��������
    enum NDIS_DEV_CLASS
    {
        DEV_NETCLIENT,          //�ͻ���
        DEV_NETSERVICE,         //����
        DEV_NETTRANS,           //Э��
    };

    /************************************************************************
    brief:          �ж�ָ�������Ƿ��Ѱ�װ
    param:          DevCls                              ��������
    param:          szComponentId                       ���ID��INF�ļ���ָ�������ơ�����WDK�Դ���passthru��netsf.inf��ָ������ms_passthru
    param:          pResult                             �����롣�������ʹ�ü�ʾ��
    return:         NDIS_DRIVER_INST_API NDIS_INST_STATE __stdcall
    history:        2015/07/13
    remarks:
    ************************************************************************/
    NDIS_DRIVER_INST_API NDIS_INST_STATE __stdcall IsNDISDriverInstalled(const NDIS_DEV_CLASS DevCls, const wchar_t *szComponentId, HRESULT *pResult);


    /************************************************************************
    brief:          ��װ/ж��ָ������
    param:          DevCls                              �μ�IsNDISDriverInstalled
    param:          szInfFile                           ���ڰ�װ������INF�ļ�·��������WDK�Դ���passthru��netsf.inf
    param:          szComponentId                       �μ�IsNDISDriverInstalled
    param:          pNeedReboot                         �����ɹ����غ�����ֵΪ��0�����ʾ��Ҫ����������������
    return:         NDIS_DRIVER_INST_API HRESULT __stdcall
    history:        2015/07/13
    remarks:
    ************************************************************************/
    NDIS_DRIVER_INST_API HRESULT __stdcall InstallNDISDriver(const NDIS_DEV_CLASS DevCls, const wchar_t *szInfFile, int *pNeedReboot);
    NDIS_DRIVER_INST_API HRESULT __stdcall UninstallNDISDriver(const wchar_t *szComponentId, int *pNeedReboot);


#ifdef __cplusplus
}
#endif


#endif
