//ʹ��ʱ��Ĭ�����Ӿ�̬�⣬��Ҫ���Ӷ�̬�⣬���ڰ�����ͷ�ļ�ǰ�����NDIS_INST_IMPORT_DYN
#ifndef _NDIS_DRIVER_INST_H_INCLUDED
#define _NDIS_DRIVER_INST_H_INCLUDED


#if defined(_NDIS_INST_EXPORTS_STATIC)//���뾲̬��汾
#define NDIS_DRIVER_INST_API

#elif defined(_NDIS_INST_EXPORTS_DYN)//���붯̬��汾
#define NDIS_DRIVER_INST_API _declspec(dllexport)

#elif defined(NDIS_INST_IMPORT_DYN)//ʹ�ö�̬��汾
#define NDIS_DRIVER_INST_API _declspec(dllimport)
#if defined(_DEBUG) || defined(DEBUG)
#pragma comment(lib, "NDISDriverInst_d.lib")
#else
#pragma comment(lib, "NDISDriverInst.lib")
#endif

#else//ʹ�þ�̬��汾(Ĭ��)
#define NDIS_DRIVER_INST_API
#pragma comment(lib, "Setupapi.lib")
#if defined(_DEBUG) || defined(DEBUG)
#pragma comment(lib, "NDISDriverInstLib_d.lib")
#else
#pragma comment(lib, "NDISDriverInstLib.lib")
#endif

#endif


#ifdef __cplusplus
extern "C"
{
#endif

    /*
    ˵����pResult��HRESULT��ָ��
        HRESULT�����ľ��������Ϣ����ʹ��_com_error������ȡ
        �������е���FormatMessage��ȡ
    */

    //************************************
    // brief:    �ж�ָ�������Ƿ��Ѱ�װ
    // name:     IsNDISDriverInstalled
    // param:    const wchar_t * szComponentId          ���ID��INF�ļ���ָ�������ơ�����WDK�Դ���passthru��netsf.inf��ָ������ms_passthru
    // param:    long * pResult                         �����룬�������ʹ�ü�ʾ��
    // return:   NDIS_DRIVER_INST_API int __stdcall     ���Ѱ�װ���򷵻ط�0�����򣬷���0
    // ps:       ������0����δ��װʱ����Ӧ�ж�pResult�Ƿ����������Ϊ�п��ܺ���ִ��ʧ�ܣ����������δ��װ
    //************************************
    NDIS_DRIVER_INST_API int __stdcall IsNDISDriverInstalled(const wchar_t *szComponentId, long *pResult);

    //************************************
    // brief:    ��װ/ж��ָ������
    // name:     InstallNDISDriver/UninstallNDISDriver
    // param:    const wchar_t * szInfFile              ���ڰ�װ������INF�ļ�·��������WDK�Դ���passthru��netsf.inf
    // param:    const wchar_t * szComponentId          �μ�����
    // param:    int * pNeedReboot                      �������غ�����ֵΪ��0�����ʾ��Ҫ����������������
    // param:    long * pResult                         �μ�����
    // return:   NDIS_DRIVER_INST_API int __stdcall     ����װ/ж�سɹ����򷵻ط�0�����򣬷���0
    // ps:       ������0������װ/ж��ʧ��ʱ����Ӧ�ж�pResult�Ƿ����������Ϊ�п��ܺ���ִ��ʧ�ܣ����������ʧ��
    //           ������ʧ�ܣ�Ҳ�п����Ѿ���װ/ж�سɹ�
    //************************************
    NDIS_DRIVER_INST_API int __stdcall InstallNDISDriver(const wchar_t *szInfFile, int *pNeedReboot, long *pResult);
    NDIS_DRIVER_INST_API int __stdcall UninstallNDISDriver(const wchar_t *szComponentId, int *pNeedReboot, long *pResult);


#ifdef __cplusplus
}
#endif


#endif
