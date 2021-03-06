#ifndef _COMPONENT_H_INCLUDED
#define _COMPONENT_H_INCLUDED


#include "Common.h"


HRESULT GetPnpID (__in LPCWSTR lpszInfFile, __deref_out_opt LPWSTR *lppszPnpID);
HRESULT InstallSpecifiedComponent (__in LPCWSTR lpszInfFile, __in LPCWSTR lpszPnpID, const GUID *pguidClass);
HRESULT UninstallComponent ( __in LPCWSTR lpszInfId);


#endif
