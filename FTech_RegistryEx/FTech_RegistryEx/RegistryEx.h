//----------------------------------------------------------
// RegistryEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-04-24 09:19
// Modified by William Kim
//----------------------------------------------------------
// shlwapi.h, shlwapi.lib Library를 사용하여 SHDeleteKey와 같은 API를 사용해도 된다.
// 자세한 내용은 http://mindgear.tistory.com/242 참고.
//----------------------------------------------------------
#pragma once

enum KeyRoot { CLASSES_ROOT=0, CURRENT_USER, LOCAL_MACHINE, USERS, CURRENT_CONFIG };
class CRegistryEx
{
public :
	static bool OnAddKey(KeyRoot Root, CString strKey, CString strSubKey);
	static bool OnDeleteKey(KeyRoot Root, CString strKey, CString strSubKey);
	static bool SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString strValue);
	static bool SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, int nValue);
	static bool SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, double dValue);
	static bool GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString &strValue);
	static bool GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, int &nValue);
	static bool GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, double &dValue);

private :
	static bool WriteValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString strValue);
	static bool ReadValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString &strValue);
};

